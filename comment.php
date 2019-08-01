<?php
/**
 * 评论插件-爱资料
 * @by apizl.com apiziliao@gmail.com
 * @desc QQ群:556985916 QQ:925054824 插件更新:https://www.apizl.com
 */
require_once(dirname(__FILE__) . "/include/common.inc.php");
require_once DEDEINC . "/arc.partview.class.php";
session_start();
define('APIZL_PLUG_TABLE_LIST', 'dede_apizl_comment');

$type = isset($_POST['type']) ? $_POST['type'] : '';
$view = isset($_POST['view']) ? $_POST['view'] : '';
$to_id = isset($_POST['to_id']) ? $_POST['to_id'] : '0';
$username = isset($_POST['username']) ? $_POST['username'] : '';
$url = isset($_POST['url']) ? $_POST['url'] : '';
$content = isset($_POST['content']) ? $_POST['content'] : '';
$email = isset($_POST['email']) ? $_POST['email'] : '';

if ($type == 'send') {
    if (empty($view)) {
        json('文档错误!', 0);
    }
    if (!is_numeric($view)) {
        json('文档错误!', 0);
    }
    $title = getTitle($view);
    if (empty($title)) {
        json('不存在的文档!', 0);
    }
    if (!is_numeric($to_id)) {
        json('回复错误!', 0);
    }
    $username = dataDispose($username);
    $content = dataDispose($content);
    if ($content == '') {
        json('评论不能为空！', 0);
    }
    if (mb_strlen($content) < 20) {
        json('评论内容少于20字！', 0);
    }
    if (addComment($view, $to_id, $username, $email, $url, $content)) {
        json('评论成功!', 1);
    } else {
        json('评论失败!', 0);
    }

}

if ($type == 'get_count') {
    json('ok', 1, commentCount($view));
}
//踩和顶
if ($type == 'pd') {
    $id = isset($_POST['id']) ? $_POST['id'] : '';
    $click = isset($_POST['click']) ? $_POST['click'] : '';
    if (!is_numeric($id)) {
        json('操作错误!', 0);
    }
    $number = $_SESSION['pd_number_' . $id];
    if (!in_array($click, ['up', 'down'])) {
        json('操作类型错误!', 0);
    }
    if ($number >= 1) {
        json('已经顶或踩过了~~~', 0);
    }
    if (empty($number)) {
        $_SESSION['pd_number_' . $id] = 1;
    }
    $sql = '';
    if ($click == 'up') {
        $sql = "update  `dede_apizl_comment` set up_click=up_click+1 where id={$id}";
    }
    if ($click == 'down') {
        $sql = "update  `dede_apizl_comment` set down_click=down_click+1 where id={$id}";
    }
    if ($dsql->ExecuteNoneQuery($sql)) {
        json('操作成功', 1);
    } else {
        json('操作失败', 0);
    }

}

if ($type == "list") {
    $fpagesize = getKeyValue("fpagesize");
    $fpagesize = !empty($fpagesize) ? $fpagesize : '10';
    $size = $fpagesize;
    $page = isset($_POST['page']) ? $_POST['page'] : '';
    $viewId = isset($_POST['view']) ? $_POST['view'] : '';
    if (!is_numeric($viewId)) {
        json('文章有误!', 0);
    }
    $limit = $page * $size;
    $row = getRows(APIZL_PLUG_TABLE_LIST, "view_id='{$viewId}' and to_id=0 and state='正常' limit {$limit},$size ", 'id,add_time,content,username,up_click,down_click,user_url');
    for ($i = 0; $i < count($row); $i++) {
        $result = getRows(APIZL_PLUG_TABLE_LIST, "view_id='{$viewId}' and to_id={$row[$i]['id']} and state='正常'", 'id,add_time,content,username,up_click,down_click');
        for ($g = 0; $g < count($result); $g++) {
            $result[$g]['add_time'] = date('Y-m-d H:i', $result[$g]['add_time']);
        }
        $row[$i]['pid'] = $result;
        $row[$i]['number'] = ($i + 1);
        $row[$i]['add_time'] = date('Y-m-d H:i', $row[$i]['add_time']);
        $row[$i]['user_url'] = !empty($row[$i]['user_url']) ? "http://" . $row[$i]['user_url'] : '#frmSumbit';
        $row[$i]['user_images'] = !empty($row[$i]['user_images']) ? $row[$i]['user_url'] : 'https://www.apizl.com/static/comment/images/user.png';
    }
    json('ok', 1, $row);
}

function getIP()
{
    if (getenv('HTTP_CLIENT_IP')) {
        $ip = getenv('HTTP_CLIENT_IP');
    } elseif (getenv('HTTP_X_FORWARDED_FOR')) {
        $ip = getenv('HTTP_X_FORWARDED_FOR');
    } elseif (getenv('HTTP_X_FORWARDED')) {
        $ip = getenv('HTTP_X_FORWARDED');
    } elseif (getenv('HTTP_FORWARDED_FOR')) {
        $ip = getenv('HTTP_FORWARDED_FOR');
    } elseif (getenv('HTTP_FORWARDED')) {
        $ip = getenv('HTTP_FORWARDED');
    } else {
        $ip = $_SERVER['REMOTE_ADDR'];
    }
    return $ip;
}

function commentCount($view)
{
    global $dsql;
    $sql = "select count(*) as count from dede_apizl_comment where view_id='{$view}' and state='正常'";
    $result = $dsql->Getone($sql);
    if (empty($result)) {
        return 0;
    }
    return $result['count'];

}

function addComment($view, $toId, $username, $email, $url, $content)
{
    global $dsql;
    $ip = getIP();
    $userAgent = isset($_SERVER['HTTP_USER_AGENT']) ? $_SERVER['HTTP_USER_AGENT'] : '';
    $hash = hash('sha256', $view);
    $time = time();
    $sql = "INSERT INTO `dede_apizl_comment` (`ip`, `useragent`, `to_id`, `hash`, `view_id`, `url`, `type`, `username`, `user_url`, `user_email`, `user_images`, `content`, `add_time`, `edit_time`, `up_click`, `down_click`, `state`) VALUES ('{$ip}', '{$userAgent}', $toId, '{$hash}', {$view}, '', '文章', '{$username}', '{$url}', '{$email}', '', '{$content}', '{$time}', '{$time}', 0, 0, '待审核');";
    return $dsql->ExecuteNoneQuery($sql);

}

function getKeyValue($key)
{
    global $dsql;
    $result = $dsql->GetOne("SELECT * FROM `dede_apizl_comment_setting` WHERE `key`='$key'");
    if ($result) {
        return isset($result['value']) ? $result['value'] : '';
    }
    return '';
}

function dataDispose(&$data)
{
    $data = htmlentities($data);
    return $data;
}

function getTitle($aid)
{
    global $dsql;
    $result = $dsql->GetOne("SELECT * FROM `#@__archives` WHERE `id`='$aid'");
    return isset($result['title']) ? $result['title'] : '';
}

function json($msg, $code = 0, $result = [])
{
    $data = [
        'msg' => $msg,
        'code' => $code,
        'result' => $result
    ];
    echo json_encode($data);
    exit();
}


function getOne($table = APIZL_MYSQL_LIST, $where = '')
{
    global $dsql;
    if (empty($where)) {
        return false;
    } else {
        $where = ' where ' . $where;
    }
    return $dsql->GetOne('SELECT * FROM `' . APIZL_MYSQL_LIST . '` ' . $where);
}

function getRows($table = APIZL_MYSQL_LIST, $where = '', $select = '*')
{
    global $dsql;
    if (!empty($where)) {
        $where = ' where ' . $where;
    }
    $dsql->SetQuery("SELECT {$select} FROM `" . $table . "` {$where}");
    $dsql->Execute('dd');
    $allRow = array();
    while ($row = $dsql->GetArray('dd')) {
        $allRow[] = $row;
    }
    return $allRow;
}