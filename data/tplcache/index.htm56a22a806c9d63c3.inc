<?php
$z[0]=Array("global","",375,401);
$z[0][4]['name']="cfg_webname";
$z[1]=Array("global","",423,455);
$z[1][4]['name']="cfg_templets_skin";
$z[2]=Array("global","",607,639);
$z[2][4]['name']="cfg_templets_skin";
$z[3]=Array("include","",899,934);
$z[3][4]['filename']="head.htm";
$z[4]=Array("arclist","\r\n                <div class=\"layui-col-xs3\">\r\n                    <div class=\"grid-demo\">\r\n                      <a href=\"[field:arcurl/]\" class=\"show\"> <img src=\"[field:picname function='thumb(@me,460,300)'/]\" /><span class=\"new\">最新</span>\r\n                      <div class=\"shadow\" style=\"display:none;\"> [field:description /] </div>\r\n                      </a>\r\n                    </div>\r\n                </div>\r\n                ",1235,1754);
$z[4][4]['row']="500";
$z[4][4]['pagesize']="4";
$z[4][4]['titlelen']="50";
$z[4][4]['orderby']="rand";
$z[5]=Array("channelartlist","\r\n          <div class=\"cginew\">\r\n            <div class=\"tit clearfix\">\r\n            <h2>{dede:field name='typename'/}</h2>\r\n            <a href=\"{dede:field name='typeurl'/}\">查看更多</a>\r\n          </div>\r\n\r\n        <div class=\"layui-tab-item\">\r\n          <div class=\"layui-row\">\r\n\r\n        {dede:arclist titlelen='60' row='5'}\r\n              <div class=\"border\">\r\n              <div class=\"grid-demo\"> <a href=\"[field:arcurl/]\" class=\"show\"> <img src=\"[field:picname function='thumb(@me,450,300)'/]\" /><span class=\"new\">最新</span>\r\n                <div class=\"shadow\" style=\"display:none;\"> [field:description /] </div>\r\n                </a>\r\n                <div class=\"cgiarc\">\r\n                  <h3><a href=\"[field:arcurl/]\">[field:title /]</a></h3>\r\n                  <div class=\"tag\"><strong><!-- <a href=\"#\">插画</a></strong><strong><a href=\"#\">手绘</a></strong><strong><a href=\"#\">绘画</a></strong><strong><a href=\"#\">教程</a></strong><strong><a href=\"#\">场景</a></strong><strong><a href=\"#\">全景</a> -->\r\n[field:id runphp='yes']\r\nglobal \$cfg_cmspath;\r\n\$tags = GetTags(@me);\r\n\$revalue = '';\r\n\$tags = explode(',', \$tags);\r\nforeach(\$tags as \$key => \$value){\r\n  if(\$value){\r\n    //\$revalue .= '<a href=\"'.\$cfg_cmspath.'/tags.php?/'.\$value.'/\">'.\$value.'</a> ';\r\n    \$revalue .= '<a href=\"javascript:;\">'.\$value.'</a> ';\r\n  }\r\n}\r\n@me = \$revalue;\r\n[/field:id] \r\n\r\n                  </strong></div>\r\n                  <div class=\"action\"> <span><i class=\"fa fa-eye\" aria-hidden=\"true\"></i>[field:click /]</span><span><i class=\"fa fa-commenting-o\" aria-hidden=\"true\"></i> [field:id function='cnum(@me)'/]</span><span class=\"handok\"><i class=\"fa fa-thumbs-o-up\" aria-hidden=\"true\"></i>[field:id function='zan(@me)'/]</span></div>\r\n                </div>\r\n              </div>\r\n              </div>\r\n        {/dede:arclist}\r\n\r\n          </div>\r\n        </div>\r\n      </div>\r\n    ",1808,3752);
$z[6]=Array("arclist","\r\n            <div class=\"layui-col-xs3\">\r\n              <div class=\"grid-demo\"> <a href=\"[field:arcurl/]\" class=\"show\"> <img src=\"[field:picname function='thumb(@me,450,300)'/]\" />\r\n            <div class=\"shadow\" style=\"display:none;\"> [field:description /] </div></a>\r\n                <div class=\"cgiarc\">\r\n                  <div class=\"cgiarc1\">\r\n                  <h3><a href=\"#\" title=\"[field:title /]\">[field:title /]</a></h3>\r\n                  <div class=\"tag\"><strong>\r\n[field:id runphp='yes']\r\nglobal \$cfg_cmspath;\r\n\$tags = GetTags(@me);\r\n\$revalue = '';\r\n\$tags = explode(',', \$tags);\r\nforeach(\$tags as \$key => \$value){\r\n  if(\$value){\r\n    //\$revalue .= '<a href=\"'.\$cfg_cmspath.'/tags.php?/'.\$value.'/\">'.\$value.'</a> ';\r\n    \$revalue .= '<a href=\"javascript:;\">'.\$value.'</a> ';\r\n  }\r\n}\r\n@me = \$revalue;\r\n[/field:id] \r\n\r\n\r\n                    \r\n                  </strong></div>\r\n                  </div>\r\n                  <div class=\"action\"> <span><i class=\"fa fa-eye\" aria-hidden=\"true\"></i>[field:click /]</span><span><i class=\"fa fa-commenting-o\" aria-hidden=\"true\"></i>[field:id function='cnum(@me)'/]</span><span class=\"handok\"><i class=\"fa fa-thumbs-o-up\" aria-hidden=\"true\"></i>[field:id function='zan(@me)'/]</span></div>\r\n                </div>\r\n              </div>\r\n            </div>\r\n            ",3953,5341);
$z[6][4]['row']="9999";
$z[6][4]['titlelen']="42";
$z[6][4]['orderby']="click";
$z[7]=Array("include","",9635,9670);
$z[7][4]['filename']="foot.htm";
$z[8]=Array("global","",9689,9721);
$z[8][4]['name']="cfg_templets_skin";
$z[9]=Array("field","",10416,10443);
$z[9][4]['name']="typeid";

?>