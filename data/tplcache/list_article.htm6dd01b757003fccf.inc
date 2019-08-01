<?php
$z[0]=Array("global","",405,437);
$z[0][4]['name']="cfg_templets_skin";
$z[1]=Array("global","",502,534);
$z[1][4]['name']="cfg_templets_skin";
$z[2]=Array("global","",629,661);
$z[2][4]['name']="cfg_templets_skin";
$z[3]=Array("global","",1410,1442);
$z[3][4]['name']="cfg_templets_skin";
$z[4]=Array("global","",1533,1565);
$z[4][4]['name']="cfg_templets_skin";
$z[5]=Array("channelartlist","\n  <li class=\"layui-nav-item\">\n    <!-- <a href=\"{dede:field name='typeurl'/}\" >{dede:field name='typename' /}</a> -->\n    <a href=\"javascript:;\" >{dede:field name='typename' /}</a>\n    <dl class=\"layui-nav-child snav\">\n    <dd>\n    {dede:sql sql='select * from dede_arctype where reid =~id~ '}\n        <a href=\"javascript:;\" class=\"btit\">[field:typename/]</a>\n        <div class=\"snavfl clearfix\">\n        [field:id runphp='yes']\n                global \$dsql;\n                \$id=@me;\n                \$sql='Select * from dede_arctype where reid='.\$id.' ORDER BY id limit 0,20';\n                \$dsql->SetQuery(\$sql);\n                \$dsql->Execute();\n                while(\$row = \$dsql->GetArray()){\n                    \$url = str_replace(\"{cmspath}\",\"\",\$row['typedir']);\n                    \$str .='<a href=\"/plus/list.php?tid='.\$id.'\">'.\$row['typename'].'</a>';\n                    @me = \$str;\n                }                      \n                if(@me == \$id){\n                  @me ='';\n                }\n         [/field:id]\n         </div>\n      {/dede:sql}\n    </dd>\n    </dl>\n  </li>\n  ",1692,2951);
$z[5][4]['typeid']="top";
$z[5][4]['row']="10";
$z[5][4]['currentstyle']="<li class='nactive'><a href='~typelink~' ~rel~><span>~typename~</span></a></li>";
$z[6]=Array("php","\n  require_once(DEDEMEMBER.\"/config.php\");\n  if(checkLogin()){\n    echo '\n    <li class=\"layui-nav-item layui-nav-item1 usera\" lay-unselect=\"\"> <a href=\"javascript:;\"><img src=\"/templets/cgi/images/noavatar.gif\" class=\"layui-nav-img\">'.\$uid.'</a><dl class=\"layui-nav-child\"><dd><a href=\"/\">个人中心</a></dd><dd><a id=\"login_out\" href=\"/member/index_do.php?fmdo=login&dopost=exit\">退出</a></dd></dl></li>';\n  }\n  ",2954,3393);
$z[7]=Array("php","\n  require_once(DEDEMEMBER.\"/config.php\");\n  if(!checkLogin()){\n    echo '\n    <div class=\"login\"><a href=\"#\" onclick=\"logintc()\">登录</a>|<a href=\"#\" onclick=\"design()\">注册</a></div>';\n  }\n",3403,3619);
$z[8]=Array("list","\n             <div class=\"border\">\n              <div class=\"grid-demo\"> <a href=\"[field:arcurl/]\" class=\"show\"> <img src=\"[field:picname/]\" />\n                <div class=\"shadow\" style=\"display:none;\"> [field:title/] </div>\n                </a>\n                <div class=\"cgiarc\">\n                  <h3><a href=\"[field:arcurl/]\">[field:title/]</a></h3>\n                  <div class=\"tag\"><strong><a href=\"#\" target=\"_blank\">超写实</a> <a href=\"#\" target=\"_blank\">模型</a> <a href=\"#\" target=\"_blank\">预售</a> <a href=\"#\" target=\"_blank\">场景</a> </li></strong></div>\n                  <div class=\"action\"> <span><i class=\"fa fa-eye\" aria-hidden=\"true\"></i>[field:click /]</span><span><i class=\"fa fa-commenting-o\" aria-hidden=\"true\"></i> [field:id function='cnum(@me)'/]</span><span class=\"handok\"><i class=\"fa fa-thumbs-o-up\" aria-hidden=\"true\"></i>[field:goodpost /]</span></div>\n                </div>\n              </div>\n        </div>\n      ",8286,9281);
$z[8][4]['pagesize']="50";
$z[9]=Array("pagelist","",9361,9432);
$z[9][4]['listsize']="5";
$z[9][4]['listitem']="info,index,end,pre,next,pageno";

?>