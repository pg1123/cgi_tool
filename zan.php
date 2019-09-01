<?php
require_once (dirname(__FILE__) . "/include/common.inc.php");
$ip =getip(); //获取用户IP
$id = $_POST['id'];
if(!isset($id) || empty($id)) exit;

$check = $_POST['check'];


//查询已赞过的IP
$dsql->SetQuery("SELECT ip FROM dede_zan WHERE aid='".$id."' and ip='$ip'");
$dsql->Execute();
$count = $dsql->GetTotalRow();

if($count==0){ //如果没有记录

$dsql->ExecuteNoneQuery("update dede_archives set zan=zan+1 where id='$id'; ");//写入赞数

$dsql->ExecuteNoneQuery("insert into dede_zan (aid,ip) values ('$id','$ip'); ");//写入IP,及被赞的AID


}else{
    //echo "赞过了..";
    $dsql->ExecuteNoneQuery("update dede_archives set zan=zan-1 where id='$id'; ");//写入赞数
    $dsql->ExecuteNoneQuery("delete from dede_zan where ip='$ip' and aid='$id' ");//删除IP,及被赞的AID

}

$rows = $dsql->GetOne("Select zan from dede_archives where id='".$id."'");//获取被赞的数量
$zan = $rows['zan'];//获取赞数值
echo $zan;