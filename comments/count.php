<?php
require_once(dirname(__FILE__)."/../include/common.inc.php");
if(isset($aid)) $arcID = $aid;

$cid = empty($cid)? 1 : intval(preg_replace("/[^-\d]+[^\d]/",'', $cid));
$arcID = $aid = empty($arcID)? 0 : intval(preg_replace("/[^\d]/",'', $arcID));

if($aid==0) exit();

$row = $db->GetOne("select count(*) as fc from `#@__feedback` where aid='{$aid}'");
if(!is_array($row))
{
	echo "document.write('0');";
}else
{
	echo "document.write('".$row['fc']."');";
}
exit();