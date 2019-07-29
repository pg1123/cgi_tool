<?php
$z[0]=Array("global","",457,489);
$z[0][4]['name']="cfg_templets_skin";
$z[1]=Array("global","",554,586);
$z[1][4]['name']="cfg_templets_skin";
$z[2]=Array("global","",833,865);
$z[2][4]['name']="cfg_templets_skin";
$z[3]=Array("channelartlist","\n  <li class=\"layui-nav-item\">\n    <!-- <a href=\"{dede:field name='typeurl'/}\" >{dede:field name='typename' /}</a> -->\n    <a href=\"javascript:;\" >{dede:field name='typename' /}</a>\n    <dl class=\"layui-nav-child snav\">\n    <dd>\n    {dede:sql sql='select * from dede_arctype where reid =~id~ '}\n        <a href=\"javascript:;\" class=\"btit\">[field:typename/]</a>\n        <div class=\"snavfl clearfix\">\n        [field:id runphp='yes']\n                global \$dsql;\n                \$id=@me;\n                \$sql='Select * from dede_arctype where reid='.\$id.' ORDER BY id limit 0,20';\n                \$dsql->SetQuery(\$sql);\n                \$dsql->Execute();\n                while(\$row = \$dsql->GetArray()){\n                    \$url = str_replace(\"{cmspath}\",\"\",\$row['typedir']);\n                    \$str .='<a href=\"/plus/list.php?tid='.\$id.'\">'.\$row['typename'].'</a>';\n                    @me = \$str;\n                }                      \n                if(@me == \$id){\n                  @me ='';\n                }\n         [/field:id]\n         </div>\n      {/dede:sql}\n    </dd>\n    </dl>\n  </li>\n  ",991,2250);
$z[3][4]['typeid']="top";
$z[3][4]['row']="10";
$z[3][4]['currentstyle']="<li class='nactive'><a href='~typelink~' ~rel~><span>~typename~</span></a></li>";
$z[4]=Array("php","\n  require_once(DEDEMEMBER.\"/config.php\");\n  if(checkLogin()){\n    echo '\n    <li class=\"layui-nav-item layui-nav-item1 usera\" lay-unselect=\"\"> <a href=\"javascript:;\"><img src=\"/templets/cgi/images/noavatar.gif\" class=\"layui-nav-img\">'.\$uid.'</a><dl class=\"layui-nav-child\"><dd><a href=\"/\">个人中心</a></dd><dd><a id=\"login_out\" href=\"/member/index_do.php?fmdo=login&dopost=exit\">退出</a></dd></dl></li>';\n  }\n  ",2253,2692);
$z[5]=Array("field","",2799,2818);
$z[5][4]['name']="title";
$z[6]=Array("field","",3336,3363);
$z[6][4]['name']="phpurl";
$z[7]=Array("field","",3387,3410);
$z[7][4]['name']="id";
$z[8]=Array("field","",3415,3439);
$z[8][4]['name']="mid";
$z[9]=Array("field","",3444,3472);
$z[9][4]['name']="channel";
$z[10]=Array("field"," @me = \$id = @me; \n\$dsql = new dedesql(); \n\$row = \$dsql->GetOne(\"Select count(id) as c from dede_feedback where aid='\$id'\"); \n@me = \$row['c'] ? \$row['c'] : 0; \n",3610,3818);
$z[10][4]['name']="id";
$z[10][4]['runphp']="’yes’";
$z[11]=Array("field","",3898,3920);
$z[11][4]['name']="goodpost";
$z[12]=Array("field","",3988,4006);
$z[12][4]['name']="body";
$z[13]=Array("global","",4205,4237);
$z[13][4]['name']="cfg_templets_skin";

?>