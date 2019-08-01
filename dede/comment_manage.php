<?php
/**
 * 评论插件-爱资料
 * @by apizl.com apiziliao@gmail.com
 * @desc QQ群:556985916 QQ:925054824 插件更新:https://www.apizl.com
 */
set_time_limit(0);
require_once(dirname(__FILE__) . "/config.php");
require_once(DEDEINC . "/oxwindow.class.php");
require_once(DEDEINC . "/channelunit.class.php");
require_once(DEDEADMIN . "/inc/inc_archives_functions.php");
define('APIZL_PLUG_VERSION', '1.1.0');
define('APIZL_PLUG_NAME', '评论插件爱资料v' . APIZL_PLUG_VERSION);
define('APIZL_PLUG_TABLE_LIST', 'dede_apizl_comment');
define('APIZL_PLUG_TABLE_SETTING', 'dede_apizl_comment_setting');
$size = getKeyValue('PAGE_SIZE');
if (empty($size)) {
    $size = 50;
    addKeyValue('PAGE_SIZE', 50);
}
define('APIZL_PAGE_SIZE', $size);

$type = isset($_POST['type']) ? $_POST['type'] : '';
$page = isset($_GET['page']) ? $_GET['page'] : 1;
$page = $page <= 0 ? 1 : $page;
$page = $page - 1;
$limit = $page * $size;
$countResult = $dsql->GetOne('SELECT count(*) as count FROM `dede_apizl_comment`');
$count = $countResult['count'];
$dsql->SetQuery("SELECT ac.*,a.title FROM `dede_apizl_comment` ac left join `#@__archives` a on ac.view_id=a.id  order by ac.id desc limit {$limit},{$size}");
$dsql->Execute('dd');
$allRow = [];
while ($row = $dsql->GetArray('dd')) {
    // if (empty($row['url'])) {
    //     updateComment($row['view_id'], $row['id']);
    // }
//print_r(111);exit;
    if ($row['state'] == '正常') {
        $row['state_name'] = '<font style="color:green;">正常</font>';
    }
    if ($row['state'] == '删除') {
        $row['state_name'] = '<font style="color:red;">删除</font>';
    }
    if ($row['state'] == '待审核') {
        $row['state_name'] = '<font style="color:#0000ff;">删除</font>';
    }
    $allRow[] = $row;
}
if ($type == 'setting') {
    $host = isset($_POST['host']) ? $_POST['host'] : '';
    $size = isset($_POST['size']) ? $_POST['size'] : '';
    addKeyValue('HOST_URL', $host);
    addKeyValue('PAGE_SIZE', $size);
    ShowMsg('保存成功', './comment_manage.php', 0);
    exit;

}

if ($type == 'statePush') {
    $id = isset($_POST['id']) ? $_POST['id'] : '';
    $result = $dsql->GetOne("SELECT * FROM `dede_apizl_comment` WHERE `id`='$id'");
    if ($result['state'] == '正常') {
        $sql = "update  dede_apizl_comment set `state`='删除' where `id`='{$id}'";
    };
    if ($result['state'] == '待审核' || $result['state'] == '删除') {
        $sql = "update  dede_apizl_comment set `state`='正常' where `id`='{$id}'";
    }
    if ($dsql->ExecuteNoneQuery($sql)) {
        json('审核成功!', 1);
    } else {
        json('审核失败!', 0);
    }
}

if ($type == 'deleteComment') {
    $id = isset($_POST['id']) ? $_POST['id'] : '';
    $result = $dsql->GetOne("SELECT * FROM `dede_apizl_comment` WHERE `id`='$id'");
    if (empty($result)) {
        json('不存在评论', 0);
    }
    $data = array('state' => '删除');
    if (updateSql(APIZL_PLUG_TABLE_LIST, $data, "id={$id}")) {
        json('删除成功!', 1);
    } else {
        json('删除失败!', 0);
    }
}

/**
 * 更新comment
 * @param $viewid
 * @param $id
 * @return bool
 */
function updateComment($viewid, $id)
{
    $url = MakeArt($viewid);
    if (strpos($url, '//')) {
        $data = [
            'url' => $url
        ];
        updateSql(APIZL_PLUG_TABLE_LIST, $data, ' id =' . $id);
        return true;
    } else {
        $url = getKeyValue('HOST_URL') . $url;
        $data = [
            'url' => $url
        ];
        updateSql(APIZL_PLUG_TABLE_LIST, $data, ' id =' . $id);
        return true;
    }
}

function getKeyValue($key)
{
    global $dsql;
    $result = $dsql->GetOne("SELECT * FROM `" . APIZL_PLUG_TABLE_SETTING . "`  WHERE `key`='$key'");
    if ($result) {
        return isset($result['value']) ? $result['value'] : '';
    }
    return '';
}

function addKeyValue($key, $value)
{
    global $dsql;
    $result = $dsql->GetOne("SELECT * FROM `" . APIZL_PLUG_TABLE_SETTING . "` WHERE `key`='$key'");
    if ($result) {
        $sql = "update  " . APIZL_PLUG_TABLE_SETTING . " set `value`='{$value}' where `key`='{$key}'";
        $dsql->ExecuteNoneQuery($sql);
    }
    $sql = "INSERT INTO `" . APIZL_PLUG_TABLE_SETTING . "` (`key`, `value`) VALUES ('$key', '$value'); ";
    $dsql->ExecuteNoneQuery($sql);
}

function getTitle($aid)
{
    global $dsql;
    $result = $dsql->GetOne("SELECT * FROM `#@__archives` WHERE `id`='$aid'");
    return isset($result['title']) ? $result['title'] : '';
}

function addSql($table, $data)
{
    global $dsql;
    if (empty($data)) {
        return false;
    }
    $sql = "insert into `{$table}`";
    $sql .= "(";
    $sql1 = "";
    $sql2 = "";
    $i = 0;
    $count = count($data);
    foreach ($data as $key => $value) {
        if ($i < $count - 1) {
            $sql1 .= "`{$key}`,";
            $sql2 .= "'{$value}',";
        } else {
            $sql1 .= "`{$key}`";
            $sql2 .= "'{$value}'";
        }
        $i++;
    }
    $sql .= "{$sql1} )values( {$sql2} )";
    return $dsql->ExecuteNoneQuery($sql);
}

function updateSql($table, $data, $where)
{
    global $dsql;
    if (empty($data)) {
        return false;
    }
    $sql = "update `{$table}` set ";
    $sql1 = "";
    $i = 0;
    $count = count($data);
    foreach ($data as $key => $value) {
        if ($i < $count - 1) {
            $sql1 .= "`{$key}`='$value',";
        } else {
            $sql1 .= "`{$key}`='$value'";
        }
        $i++;
    }
    $sql .= " $sql1 ";
    if (!empty($where)) {
        $sql .= ' where ' . $where;
    }
    return $dsql->ExecuteNoneQuery($sql);

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

function limitShow($count, $size, $page)
{
    if ($page == 0) {
        $page = 1;
    } else {
        $page = $page + 1;
    }
    $list = '';
    $list .= '<li><a href="' . limitUrl(['page' => 1]) . '">首页</a></li>';
    $showSize = 3;
    $row = ceil($count / $size);
    if ($page == 1) { //start
        $list .= '<li class="active"><a href="#">1</a></li>';
        if ($row >= $showSize) {
            $list .= '<li><a href="' . limitUrl(['page' => 2]) . '">2</a></li>';
            $list .= '<li><a href="' . limitUrl(['page' => 3]) . '">3</a></li>';
        }
    } else if ($page < $row) { //next
        $pageUp = $page - 1;
        $pageDown = $page + 1;
        if ($page != 0) {
            $list .= '<li><a href="' . limitUrl(['page' => $pageUp]) . '">' . $pageUp . '</a></li>';
        }
        $list .= '<li class="active"><a href="#">' . $page . '</a></li>';
        if ($page <= $row) {
            $list .= '<li><a href="' . limitUrl(['page' => $pageDown]) . '">' . $pageDown . '</a></li>';
        }
    } else if ($page == $row) { //no
        if ($row >= 3) {
            $list .= '<li><a href="' . limitUrl(['page' => ($page - 2)]) . '">' . ($page - 2) . '</a></li>';
            $list .= '<li><a href="' . limitUrl(['page' => ($page - 1)]) . '">' . ($page - 1) . '</a></li>';
            $list .= '<li class="active"><a href="#">' . $page . '</a></li>';
        }
    }
    $list .= '<li><a href="#">总数:' . $count . ' 页:' . $row . '</a></li>';//总数
    $list .= '<li><a href="' . limitUrl(['page' => $row]) . '">末页</a></li>';
    return $list;
}

function limitUrl($data = [])
{
    $get = $_GET;
    if (count($data) > 0) {
        foreach ($data as $k => $v) {
            $get[$k] = $v;
        }
    }
    $url = http_build_query($get);
    return '?' . $url;
}

?>

<html>
<head>
    <link rel="stylesheet" href="https://cdn.bootcss.com/bootstrap/3.3.7/css/bootstrap.min.css"
          integrity="sha384-BVYiiSIFeK1dGmJRAkycuHAHRg32OmUcww7on3RYdg4Va+PmSTsz/K68vbdEjh4u" crossorigin="anonymous">

    <!-- 可选的 Bootstrap 主题文件（一般不用引入） -->
    <link rel="stylesheet" href="https://cdn.bootcss.com/bootstrap/3.3.7/css/bootstrap-theme.min.css"
          integrity="sha384-rHyoN1iRsVXV4nD0JutlnGaslCJuC7uwjduW9SVrLvRYooPp2bWYgmgJQIXwl/Sp" crossorigin="anonymous">

    <script src='https://apps.bdimg.com/libs/jquery/2.1.4/jquery.min.js'></script>
    <!-- 最新的 Bootstrap 核心 JavaScript 文件 -->
    <script src="https://cdn.bootcss.com/bootstrap/3.3.7/js/bootstrap.min.js"
            integrity="sha384-Tc5IQib027qvyjSMfHjOMaLkfuWVxZxUPnCJA7l2mCWNIpG9mGCD8wGNIcPD7Txa"
            crossorigin="anonymous"></script>
    <title><?php echo APIZL_PLUG_NAME; ?></title>
</head>
<body style="padding-left: 20px;">
<h4><?php echo APIZL_PLUG_NAME; ?></h4>

<ul id="myTab" class="nav nav-tabs">
    <li class="active">
        <a href="#home" data-toggle="tab">Home</a>
    </li>
    <li><a href="#setting" data-toggle="tab">设置</a></li>

    <li><a href="#other" data-toggle="tab">说明</a></li>
</ul>
<div id="myTabContent" class="tab-content">
    <div class="tab-pane fade  in active" id="home">
        <div class="col-lg-12 form-inline" style="margin-top: 20px;">
            <span>选择评论审核</span>
        </div>

        <div class="col-lg-12">
            <nav aria-label="...">
                <ul class="pagination">
                    <?php echo limitShow($count, $size, $page); ?>
                </ul>
            </nav>
            <table class='table table-hover'>
                <thead>
                <tr>
                    <td class="col-lg-4">标题</td>
                    <td class="col-lg-2">评论</td>
                    <td class="col-lg-2">用户名</td>
                    <td class="col-lg-2">时间</td>
                    <td class="col-lg-2">状态</td>
                    <td class="col-lg-4">操作</td>
                </tr>
                </thead>
                <tbody>
                <?php for ($i = 0; $i < count($allRow); $i++) { ?>
                    <tr>
                        <td><a href="<?php echo $allRow[$i]['url']; ?>"
                               target="_blank"><?php echo $allRow[$i]['title']; ?></a></td>
                        <td>
                            <p title="<?php echo $allRow[$i]['content']; ?>"><?php echo mb_substr($allRow[$i]['content'], 0, 20, "UTF-8"); ?></p>
                        </td>
                        <td><?php echo $allRow[$i]['username']; ?></td>
                        <td><?php echo date('y-m-d H:i:s', $allRow[$i]['add_time']); ?></td>
                        <td><?php echo $allRow[$i]['state_name']; ?></td>
                        <td>
                            <?php if ($allRow[$i]['state'] != '正常') { ?>
                                <a href="javascript:statePush(<?php echo $allRow[$i]['id']; ?>)"
                                   class="btn btn-success">通过</a>
                            <?php } ?>
                            <a href="javascript:deleteComment(<?php echo $allRow[$i]['id']; ?>)"
                               class="btn btn-default">删除</a>
                        </td>
                    </tr>
                <?php } ?>
                </tbody>
            </table>
        </div>
    </div>

    <div class="tab-pane fade form-inline" id="setting">
        <form method="post">
            <div class="col-lg-12" style="margin-top: 10px;">
                <label>网站域名</label>
                <input type="text" class="form-control" name="host" value="<?php echo getKeyValue("HOST_URL"); ?>"
                       placeholder="http://www.apizl.com">
            </div>
            <div class="col-lg-12" style="margin-top: 10px;">
                <label>页面数量</label>
                <input type="text" class="form-control" name="size" value="<?php echo getKeyValue("PAGE_SIZE"); ?>"
                       placeholder="10">
            </div>
            <div class="col-lg-12">
                <input type="hidden" name="type" value="setting">
                <input type="submit" class="btn btn-success" value="保存">
            </div>
        </form>
    </div>
    <div class="tab-pane fade" id="other">
        <h4>说明:</h4>
        <span class="col-lg-12">开发团队:爱资料</span>
        <span class="col-lg-12">官方网站:<a href="https://www.apizl.com" target="_blank">https://www.apizl.com</a></span>
        <span class="col-lg-12">插件交流:  QQ群:556985916 QQ:925054824</span>
        <h4>使用说明:</h4>
        <span class="col-lg-12">插件更新地址:<a href="https://www.apizl.com/category/list-374.html" target="_blank">https://www.apizl.com/category/list-374.html</a></span>
    </div>
</div>
<script type="text/javascript">
    function delete_list(id) {
        $.ajax({
            type: "POST", url: "",
            data: {id: id, type: 'delete_list'},
            dataType: "json",
            success: function (data) {
                if (data.code == 1) {
                    alert('url:' + data.result['url'] + "\r\n" + 'result:' + data.result['result']);
                    window.location = '';
                } else {
                    alert(data.msg);
                }
            }
        });
    }

    function statePush(id) {
        $.ajax({
            type: "POST", url: "",
            data: {id: id, type: 'statePush'},
            dataType: "json",
            success: function (data) {
                if (data.code == 1) {
                    window.location = '';
                } else {
                    alert(data.msg);
                }
            }
        });
    }


    function deleteComment(id) {
        if (!confirm('是否删除?')) {
            return;
        }
        $.ajax({
            type: "POST", url: "",
            data: {id: id, type: 'deleteComment'},
            dataType: "json",
            success: function (data) {
                if (data.code == 1) {
                    window.location = '';
                } else {
                    alert(data.msg);
                }
            }
        });
    }

</script>
</body>
</html>