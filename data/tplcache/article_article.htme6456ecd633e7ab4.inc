<?php
$z[0]=Array("global","",457,489);
$z[0][4]['name']="cfg_templets_skin";
$z[1]=Array("global","",554,586);
$z[1][4]['name']="cfg_templets_skin";
$z[2]=Array("global","",833,865);
$z[2][4]['name']="cfg_templets_skin";
$z[3]=Array("channelartlist","\n      <li class=\"layui-nav-item\">\n        <!-- <a href=\"{dede:field name='typeurl'/}\" >{dede:field name='typename' /}</a> -->\n        <a href=\"javascript:;\" >{dede:field name='typename' /}</a>\n        <dl class=\"layui-nav-child snav\">\n        <dd>\n        {dede:sql sql='select * from dede_arctype where reid =~id~ '}\n            <a href=\"[field:typelink/]\" class=\"btit\">[field:typename/]</a>\n            <div class=\"snavfl clearfix\">\n            [field:id runphp='yes']\n                    global \$dsql;\n                    \$id=@me;\n                    \$sql='Select * from dede_arctype where reid='.\$id.' ORDER BY id limit 0,20';\n                    \$dsql->SetQuery(\$sql);\n                    \$dsql->Execute();\n                    while(\$row = \$dsql->GetArray()){\n                        \$url = str_replace(\"{cmspath}\",\"\",\$row['typedir']);\n                        \$str .='<a href=\"'.\$url.'\">'.\$row['typename'].'</a>';\n                        @me = \$str;\n                    }                      \n                    if(@me == \$id){\n                      @me ='';\n                    }\n             [/field:id]\n             </div>\n          {/dede:sql}\n        </dd>\n        </dl>\n      </li>\n      ",1005,2367);
$z[3][4]['typeid']="top";
$z[3][4]['row']="10";
$z[3][4]['currentstyle']="<li class='nactive'><a href='~typelink~' ~rel~><span>~typename~</span></a></li>";
$z[4]=Array("field","",2593,2612);
$z[4][4]['name']="title";
$z[5]=Array("field","",3130,3157);
$z[5][4]['name']="phpurl";
$z[6]=Array("field","",3181,3204);
$z[6][4]['name']="id";
$z[7]=Array("field","",3209,3233);
$z[7][4]['name']="mid";
$z[8]=Array("field","",3238,3266);
$z[8][4]['name']="channel";
$z[9]=Array("field","",3557,3575);
$z[9][4]['name']="body";
$z[10]=Array("global","",3774,3806);
$z[10][4]['name']="cfg_templets_skin";

?>