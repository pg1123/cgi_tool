<?php
function litimgurls($imgid=0)
{
    global $lit_imglist,$dsql;
    //获取附加表
    $row = $dsql->GetOne("SELECT c.addtable FROM #@__archives AS a LEFT JOIN #@__channeltype AS c 
                                                            ON a.channel=c.id where a.id='$imgid'");
    $addtable = trim($row['addtable']);
    
    //获取图片附加表imgurls字段内容进行处理
    $row = $dsql->GetOne("Select imgurls From `$addtable` where aid='$imgid'");
    
    //调用inc_channel_unit.php中ChannelUnit类
    $ChannelUnit = new ChannelUnit(2,$imgid);
    
    //调用ChannelUnit类中GetlitImgLinks方法处理缩略图
    $lit_imglist = $ChannelUnit->GetlitImgLinks($row['imgurls']);
    
    //返回结果
    return $lit_imglist;
}


function cnum($id)
{
global $dsql;
$row = $dsql->GetOne("Select count(id) as c from dede_feedback where aid='$id'");
$num=$row['c'];
if($num==0)$num=' 0';
return $num;
}

function zan($aid)
{
    global $dsql;
    $row = $dsql->GetOne("Select id,zan From dede_archives where id='".$aid."'");
    return !empty($row['zan']) ? $row['zan'] : '0 ';
}



function thumb($imgurl, $width, $height, $bg = true)  
{
    global $cfg_mainsite,$cfg_multi_site;
    //$thumb = eregi("http://",$imgurl) ? str_replace($cfg_mainsite,'',$imgurl) : $imgurl;
    $thumb = $imgurl;
    //print_r($imgurl);exit;
    list($thumbname,$extname) = explode('.',$thumb);  
    $newthumb = $thumbname.'_'.$width.'_'.$height.'.'.$extname;  
    if(!$thumbname || !$extname || !file_exists(DEDEROOT.$thumb)) return $imgurl;  
    if(!file_exists(DEDEROOT.$newthumb))  
    {  
    include_once DEDEINC.'/image.func.php';  
    if($bg==true)  
    {  
    ImageResizeNew(DEDEROOT.$thumb, $width, $height, DEDEROOT.$newthumb);  
    }  
    else 
    {  
    ImageResize(DEDEROOT.$thumb, $width, $height, DEDEROOT.$newthumb);  
    }  
    }  
    return $cfg_multi_site=='Y'?$cfg_mainsite.$newthumb:$newthumb;  
}

