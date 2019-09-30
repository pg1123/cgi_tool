<?php
$z[0]=Array("global","",377,403);
$z[0][4]['name']="cfg_webname";
$z[1]=Array("field","",404,423);
$z[1][4]['name']="title";
$z[2]=Array("global","",444,476);
$z[2][4]['name']="cfg_templets_skin";
$z[3]=Array("global","",545,577);
$z[3][4]['name']="cfg_templets_skin";
$z[4]=Array("global","",672,704);
$z[4][4]['name']="cfg_templets_skin";
$z[5]=Array("include","",1422,1457);
$z[5][4]['filename']="head.htm";
$z[6]=Array("php"," if(!\$_GET['orderby']) { echo 'class=\"this\"'; } ",5800,5869);
$z[7]=Array("field","",5903,5923);
$z[7][4]['name']="typeid";
$z[8]=Array("php"," if(\$_GET['orderby']=='lastpost') { echo 'class=\"this\"'; } ",5956,6036);
$z[9]=Array("field","",6070,6090);
$z[9][4]['name']="typeid";
$z[10]=Array("php"," if(\$_GET['orderby']=='zan') { echo 'class=\"this\"'; } ",6154,6229);
$z[11]=Array("field","",6263,6283);
$z[11][4]['name']="typeid";
$z[12]=Array("php"," if(\$_GET['orderby']=='click') { echo 'class=\"this\"'; } ",6342,6419);
$z[13]=Array("field","",6453,6473);
$z[13][4]['name']="typeid";
$z[14]=Array("php"," if(\$_GET['orderby']=='scores') { echo 'class=\"this\"'; } ",6534,6612);
$z[15]=Array("field","",6646,6666);
$z[15][4]['name']="typeid";
$z[16]=Array("list","\n             <div class=\"border\">\n              <div class=\"grid-demo\"> <a href=\"[field:arcurl/]\" class=\"show\"> <img src=\"[field:picname function='thumb(@me,450,300)'/]\" /><!-- [field:picname/] -->\n                <div class=\"shadow\" style=\"display:none;\"> [field:title/] </div>\n                </a>\n                <div class=\"cgiarc\">\n                  <h3><a href=\"[field:arcurl/]\">[field:title/]</a></h3>\n                  <div class=\"tag\"><strong><!-- <a href=\"#\" target=\"_blank\">超写实</a> <a href=\"#\" target=\"_blank\">模型</a> <a href=\"#\" target=\"_blank\">预售</a> <a href=\"#\" target=\"_blank\">场景</a> </li> -->\n                    \n\n[field:id runphp='yes']\nglobal \$cfg_cmspath;\n\$tags = GetTags(@me);\n\$revalue = '';\n\$tags = explode(',', \$tags);\nforeach(\$tags as \$key => \$value){\n  if(\$value){\n    //\$revalue .= '<a href=\"'.\$cfg_cmspath.'/tags.php?/'.\$value.'/\">'.\$value.'</a> ';\n    \$revalue .= '<a href=\"javascript:;\">'.\$value.'</a> ';\n  }\n}\n@me = \$revalue;\n[/field:id] \n\n\n                    \n                  </strong></div>\n\n\n                  <div class=\"action\"> <span><i class=\"fa fa-eye\" aria-hidden=\"true\"></i>[field:click /]</span><span><i class=\"fa fa-commenting-o\" aria-hidden=\"true\"></i> [field:id function='cnum(@me)'/]</span><span class=\"handok\"><i class=\"fa fa-thumbs-o-up\" aria-hidden=\"true\"></i>[field:id function='zan(@me)'/]</span></div>\n                </div>\n              </div>\n        </div>\n      ",6785,8261);
$z[16][4]['pagesize']="50";
$z[17]=Array("pagelist","",8341,8412);
$z[17][4]['listsize']="5";
$z[17][4]['listitem']="info,index,end,pre,next,pageno";
$z[18]=Array("include","",8464,8499);
$z[18][4]['filename']="foot.htm";
$z[19]=Array("global","",8536,8568);
$z[19][4]['name']="cfg_templets_skin";

?>