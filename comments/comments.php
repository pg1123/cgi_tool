<?php
/**
 *
 * Ajax评论
 *
 * @version        $Id: feedback_ajax.php 1 15:38 2010年7月8日Z tianya $
 * @package        DedeCMS.Site
 * @copyright      Copyright (c) 2007 - 2010, DesDev, Inc.
 * @license        http://help.dedecms.com/usersguide/license.html
 * @link           http://www.dedecms.com
 */
require_once(dirname(__FILE__).'/../include/common.inc.php');
require_once(DEDEINC.'/channelunit.func.php');
AjaxHead();

if($cfg_feedback_forbid=='Y') exit('系统已经禁止评论功能！');

$aid = intval($aid);
if(empty($aid)) exit('没指定评论文档的ID，不能进行操作！');

include_once(DEDEINC.'/memberlogin.class.php');
$cfg_ml = new MemberLogin();

if(empty($dopost)) $dopost = '';
$page = empty($page) || $page<1 ? 1 : intval($page);
$pagesize = 100;

/*----------------------
获得指定页的评论内容
function getlist(){ }
----------------------*/
if($dopost=='getlist')
{
    $totalcount = GetList($page);
    GetPageList($pagesize, $totalcount);
    exit();
}
/*----------------------
发送评论
function send(){ }
----------------------*/
else if($dopost=='send')
{
    require_once(DEDEINC.'/charset.func.php');
    //检查验证码
    if($cfg_ml->M_ID < 1 && $cfg_feedback_guest == 'Y' && $cfg_feedback_ck == 'Y')
    {
        $svali = strtolower(trim(GetCkVdValue()));
        if(strtolower($validate) != $svali || $svali=='')
        {
            ResetVdValue();
			err('验证码错误，请点击验证码图片更新验证码！');
        }
    }
	$pid = $comment_parent;
    $arcRow = GetOneArchive($aid);
    if(empty($arcRow['aid']))
    {
		err('无法查看未知文档的评论!');
    }
    if(isset($arcRow['notpost']) && $arcRow['notpost']==1)
    {
        err('这篇文档禁止评论!');
    }
    
    if( $cfg_soft_lang != 'utf8' )
    {
		$msg = iconv( "UTF-8", "gb2312//IGNORE" , $msg);
        $msg = UnicodeUrl2Gbk($msg);
		if(!empty($username)) $username = iconv( "UTF-8", "gb2312//IGNORE" , $username);
        if(!empty($username)) $username = UnicodeUrl2Gbk($username);
    }
    //词汇过滤检查
    if( $cfg_notallowstr != '' )
    {
        if(preg_match("#".$cfg_notallowstr."#i", $msg))
        {
            err('评论内容含有禁用词汇！');
        }
    }
    if( $cfg_replacestr != '' )
    {
        $msg = preg_replace("#".$cfg_replacestr."#i", '***', $msg);
    }
    if( empty($msg) )
    {
		err('评论内容可能不合法或为空！');
    }
	if($cfg_feedback_guest == 'N' && $cfg_ml->M_ID < 1)
	{
		err('管理员禁用了游客评论，请先登录！');
	}
    //检查用户
    $username = empty($username) ? '游客' : $username;
    if(empty($notuser)) $notuser = 0;
    if($notuser==1)
    {
        $username = $cfg_ml->M_ID > 0 ? '匿名' : '游客';
    }
    else if($cfg_ml->M_ID > 0)
    {
        $username = $cfg_ml->M_UserName;
    }
    else if($username!='' && $pwd!='')
    {
        $rs = $cfg_ml->CheckUser($username, $pwd);
        if($rs==1)
        {
            $dsql->ExecuteNoneQuery("Update `#@__member` set logintime='".time()."',loginip='".GetIP()."' where mid='{$cfg_ml->M_ID}'; ");
        }
        $cfg_ml = new MemberLogin();
    }
    
    //检查评论间隔时间
    $ip = GetIP();
    $dtime = time();
    if(!empty($cfg_feedback_time))
    {
        //检查最后发表评论时间，如果未登陆判断当前IP最后评论时间
        $where = ($cfg_ml->M_ID > 0 ? "WHERE `mid` = '$cfg_ml->M_ID' " : "WHERE `ip` = '$ip' ");
        $row = $dsql->GetOne("SELECT dtime FROM `#@__feedback` $where ORDER BY `id` DESC ");
        if(is_array($row) && $dtime - $row['dtime'] < $cfg_feedback_time)
        {
            ResetVdValue();
			err('管理员设置了评论间隔时间，请稍等休息一下！');
        }
    }

    extract($arcRow, EXTR_SKIP);
	
	$msg=htmlspecialchars_decode($msg);
	$msg=preg_replace('/on.+\".+\"/i', '', $msg);
	// 删除除img外的其他标签
	$comment_content=trim(strip_tags($msg,'<img>'));
	$msg=htmlspecialchars($comment_content);
	if (empty($msg)) {
		err('非法评论，已记录IP！');
	}
    //保存评论内容
	$pid = !empty($pid) ? $pid : 0 ;
    $ischeck = ($cfg_feedbackcheck=='Y' ? 0 : 1);

    $inquery = "INSERT INTO `#@__feedback`(`aid`,`username`,`ip`,`ischeck`,`dtime`,`mid`,`pid`,`msg`)
                   VALUES ('$aid','$username','$ip','$ischeck','$dtime', '{$cfg_ml->M_ID}','$pid','$msg'); ";
    $rs = $dsql->ExecuteNoneQuery($inquery);
    if( !$rs )
    {
		err('发表评论出错了！');
    }
    $newid = $dsql->GetLastID();

    //给用户增加积分
    if($cfg_ml->M_ID > 0)
    {
        #api{{
        if(defined('UC_API') && @include_once DEDEROOT.'/api/uc.func.php')
        {
            //同步积分
            uc_credit_note($cfg_ml->M_LoginID, $cfg_sendfb_scores);
            
            //推送事件
            $arcRow = GetOneArchive($aid);
            $feed['icon'] = 'thread';
            $feed['title_template'] = '<b>{username} 在网站发表了评论</b>';
            $feed['title_data'] = array('username' => $cfg_ml->M_UserName);
            $feed['body_template'] = '<b>{subject}</b><br>{message}';
            $url = !strstr($arcRow['arcurl'],'http://') ? ($cfg_basehost.$arcRow['arcurl']) : $arcRow['arcurl'];        
            $feed['body_data'] = array('subject' => "<a href=\"".$url."\">$arcRow[arctitle]</a>", 'message' => cn_substr(strip_tags(preg_replace("/\[.+?\]/is", '', $msg)), 150));
            $feed['images'][] = array('url' => $cfg_basehost.'/images/scores.gif', 'link'=> $cfg_basehost);
            uc_feed_note($cfg_ml->M_LoginID,$feed); unset($arcRow);
        }
        #/aip}}
        $dsql->ExecuteNoneQuery("UPDATE `#@__member` set scores=scores+{$cfg_sendfb_scores} WHERE mid='{$cfg_ml->M_ID}' ");
        $row = $dsql->GetOne("SELECT COUNT(*) AS nums FROM `#@__feedback` WHERE `mid`='".$cfg_ml->M_ID."'");
        $dsql->ExecuteNoneQuery("UPDATE `#@__member_tj` SET `feedback`='$row[nums]' WHERE `mid`='".$cfg_ml->M_ID."'");
    }
    $_SESSION['sedtime'] = time();
    if($ischeck==0)
    {
		err('成功发表评论，但需审核后才会显示你的评论！');
    }
    else
    {
        $spaceurl = '#';
        if($cfg_ml->M_ID > 0) $spaceurl = "{$cfg_memberurl}/index.php?uid=".urlencode($cfg_ml->M_LoginID);
        $id = $newid;
        $msg = stripslashes($msg);
        $msg = str_replace('<', '&lt;', $msg);
        $msg = str_replace('>', '&gt;', $msg);
        $msg = RemoveXSS(Quote_replace($msg));

        global $dsql, $aid, $pagesize, $cfg_templeturl;
		$row = $dsql->GetOne("SELECT * FROM `#@__member` WHERE mid={$cfg_ml->M_ID} ");
		$row['face'] = empty($row['face']) ? '/comments/avatar.jpg' : $row['face'];
		$row['uname'] = empty($row['uname']) ? $username : $row['uname'];
		$row['uname'] = empty($row['uname']) ? '游客' : $row['uname'];
?>
<li class="comment byuser comment-author-<?php echo $id; ?> even thread-even depth-1 parent" id="comment-<?php echo $id; ?>">
	<div id="div-comment-<?php echo $id; ?>">
		<div class="comment-author vcard">
			<img src="<?php echo $row['face']; ?>" class="func-um_user gravatar avatar avatar-60 um-avatar um-avatar-uploaded" width="60" height="60" alt="<?php echo $row['userid']; ?>"/>
		</div>
		<div class="comment-body">
			<div class="comment-text">
				<p>
					<?php echo ubb($msg); ?>
				</p>
			</div>
			<div class="nickname">
				<?php echo $row['uname']; ?>
				<span class="comment-time"><?php echo GetDateTimeMk($dtime); ?></span>
				<a rel='nofollow' class='comment-reply-link' href="javascript:;" onclick='return addComment.moveForm( "div-comment-<?php echo $id; ?>", "<?php echo $id; ?>", "respond", "<?php echo $aid; ?>" )' aria-label='回复给<?php echo $row['uname']; ?>'>回复</a>
			</div>
		</div>
	</div>
</li>
<?php
    }
    exit();
}

/**
 *  读取列表内容
 *
 * @param     int  $page  页码
 * @return    string
 */
function GetList($page=1)
{
	global $dsql, $aid, $pagesize, $cfg_templeturl,$cfg_cmspath;

    $row = $dsql->GetOne("SELECT COUNT(*) AS dd FROM `#@__feedback` WHERE aid='$aid' AND ischeck='1' ");
    $totalcount = (empty($row['dd']) ? 0 : $row['dd']);
    $startNum = $pagesize * ($page-1);
    if($startNum > $totalcount)
    {
        echo "参数错误！";
        return $totalcount;
    }
	
	$sql = "SELECT fb.*,mb.userid,mb.uname,mb.face FROM `#@__feedback` fb LEFT JOIN `#@__member` mb ON mb.mid = fb.mid WHERE fb.aid = $aid AND fb.ischeck = 1 ORDER BY fb.id DESC ";

	$dsql->SetQuery($sql);
	$dsql->Execute();
	while($row = $dsql->GetArray())
	{
		$arr[]=$row;
	}
	$new = array();
	foreach($arr as $v){
        $fields['msg'] = str_replace('<', '&lt;', $fields['msg']);
        $fields['msg'] = str_replace('>', '&gt;', $fields['msg']);
        $fields['msg'] = RemoveXSS(Quote_replace($fields['msg']));
		$v['uname'] = empty($v['uname']) ? $v['username'] : $v['uname'];
		$v['uname'] = empty($v['uname']) ? '游客' : $v['uname'];
		$v['face'] = empty($v['face']) ? '/comments/avatar.jpg' : $v['face'];
		$new[$v['pid']][] = $v;
	}

    $i = 0;
    $j = 0;
    $a = true;
    $p[$i] = 0;
    $q[$j] = $i;
    while($a){
        $next = false;
        $i = $q[$j];
        $var = $new[$i];
        if(!isset($p[$i])){
            $p[$i] = 0;
        }
        if($p[$i] == count($var)){
            echo '</ul>';
        }else{
            for($k=$p[$i]; $k<count($var);$k++){
                if($k == 0 && $var[$k]['pid'] != 0)
                    echo '<ul class="children">';
$var[$k]['dtime'] = GetDateTimeMk($var[$k]['dtime']);
echo <<<TPL
<li class="comment byuser comment-author-{$var[$k]['id']} even thread-even depth-1 parent" id="comment-{$var[$k]['id']}">
	<div id="div-comment-{$var[$k]['id']}">
		<div class="comment-author vcard">
			<img src="{$var[$k]['face']}" class="func-um_user gravatar avatar avatar-60 um-avatar um-avatar-uploaded" width="60" height="60" alt="{$var[$k]['userid']}"/>
		</div>
		<div class="comment-body">
			<div class="comment-text">
				<p>
					{$var[$k]['msg']}
				</p>
			</div>
			<div class="nickname">
				{$var[$k]['uname']}
				<span class="comment-time">{$var[$k]['dtime']}</span>
				<a rel='nofollow' class='comment-reply-link' href="javascript:;" onclick='return addComment.moveForm( "div-comment-{$var[$k]['id']}", "{$var[$k]['id']}", "respond", "{$var[$k]['aid']}" )' aria-label='回复给{$var[$k]['uname']}'>回复</a>
			</div>
		</div>
	</div>
TPL;
                $p[$i]++;
                if(isset($new[$var[$k]['id']])){
                    $i = $var[$k]['id'];
                    $j++;
                    $q[$j] = $i;
                    $next = true;
                    break;
                }
                echo '</li>';
                if($k == count($var)-1){
                    echo '</ul>';
                }
            }
        }
        if($next){
            continue;
        }
        $j--;
        if($j < 0){
            break;
        }
    }

    return $totalcount;            
}

/**
 *  获取分页列表
 *
 * @param     int  $pagesize  显示条数
 * @param     int  $totalcount  总数
 * @return    string
 */
function GetPageList($pagesize, $totalcount)
{
    global $page;
    $curpage = empty($page) ? 1 : intval($page);
    $allpage = ceil($totalcount / $pagesize);
    if($allpage < 2) 
    {
        echo '';
        return ;
    }
    echo "
<div id='commetpages'>";
  echo "<span>总: {$allpage} 页/{$totalcount} 条评论</span> ";
  $listsize = 5;
  $total_list = $listsize * 2 + 1;
  $totalpage = $allpage;
  $listdd = '';
  if($curpage-1 > 0 )
  {
  echo "<a href='#commettop' onclick='LoadCommets(".($curpage-1).");'>上一页</a> ";
  }
  if($curpage >= $total_list)
  {
  $j = $curpage - $listsize;
  $total_list = $curpage + $listsize;
  if($total_list > $totalpage)
  {
  $total_list = $totalpage;
  }
  }
  else
  {
  $j = 1;
  if($total_list > $totalpage) $total_list = $totalpage;
  }
  for($j; $j <= $total_list; $j++)
  {
  echo ($j==$curpage ? "<strong>$j</strong> " : "<a href='#commettop' onclick='LoadCommets($j);'>{$j}</a> ");
  }
  if($curpage+1 <= $totalpage )
  {
  echo "<a href='#commettop' onclick='LoadCommets(".($curpage+1).");'>下一页</a> ";
  }
  echo "</div>
";
}
function err($ErrMsg) {
    header('HTTP/1.1 405 Method Not Allowed');
    echo $ErrMsg;
    exit;
}