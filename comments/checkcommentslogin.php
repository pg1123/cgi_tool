<?php
/**
 * @version        $Id: ajax_feedback.php 1 8:38 2010年7月9日Z tianya $
 * @package        DedeCMS.Member
 * @copyright      Copyright (c) 2007 - 2010, DesDev, Inc.
 * @license        http://help.dedecms.com/usersguide/license.html
 * @link           http://www.dedecms.com
 */
require_once(dirname(__FILE__).'/config.php');
AjaxHead();
if($myurl == '')//未登录
{
	if($cfg_feedback_guest == 'N' && $cfg_ml->M_ID < 1)//不允许匿名评论
	{
$html = <<<TPL
<div class="comment-form-comment">
	<textarea disabled="disabled" placeholder="需要登录才能发表评论" id="comment" name="msg" class="ipt" rows="4"></textarea>
</div>
<div class="form-submit">
	<div class="form-submit-text pull-left"><a onclick="design()" title="注册" href="#">注册</a>&nbsp;&nbsp;<a onclick="logintc()" title="登录" href="#">登录</a></div>
	<input name="submit" type="submit" id="must-submit" class="submit" value="发表" disabled="disabled">
	<input type="button" id="cancel-comment-reply-link" class="submit" value="取消" style="display:none;">
</div>
TPL;
echo $html;
	}//允许匿名评论
	else
	{
$html = <<<TPL
<div class="comment-form-comment">
	<textarea id="comment" name="msg" class="ipt" rows="4"></textarea>
</div>
<div class="form-submit">
	<div class="form-submit-text pull-left"><input class="ipt2" name="username" id="username" value="" placeholder="昵称" type="text"><input class="ipt3" name="validate" id="validate" value="" placeholder="验证码" type="text"><img src= "/include/vdimgck.php" id="validateimg" style="float:left;cursor:pointer"  onclick="this.src='/include/vdimgck.php?tag='+Math.random();" title="点击我更换图片" alt="点击我更换图片"/></div>
	<input name="submit" type="submit" id="must-submit" class="submit" value="发表">
	<input type="button" id="cancel-comment-reply-link" class="submit" value="取消" style="display:none;">
</div>
TPL;
echo $html;
	}
}//已登录
else
{
$facepic = empty($cfg_ml->M_Face) ? '/comments/avatar.jpg' : $cfg_ml->M_Face;
$html = <<<TPL
<div class="comment-form-comment">
	<textarea id="comment" name="msg" class="ipt" rows="4"></textarea>
</div>
<div class="form-submit">
	<div class="form-submit-text pull-left">
		<img src="{$facepic}" class="func-um_user gravatar avatar avatar-60 um-avatar um-avatar-default" width="60" height="60">
		<span><a target="_blank" href="{$cfg_memberurl}">{$cfg_ml->M_UserName}</a></span>
		<input type="hidden" name="username" value="{$cfg_ml->M_UserName}"/>
	</div>
	<input name="submit" type="submit" id="must-submit" class="submit" value="发表">
	<input type="button" id="cancel-comment-reply-link" class="submit" value="取消" style="display:none;">
</div>
TPL;
echo $html;
}

