<?php
$z[0]=Array("field","",46,74);
$z[0][4]['name']="typeurl";
$z[1]=Array("field","",77,107);
$z[1][4]['name']="typename";
$z[2]=Array("field","",129,157);
$z[2][4]['name']="typeurl";
$z[3]=Array("field","",160,190);
$z[3][4]['name']="typename";
$z[4]=Array("sql","\n        <a href=\"[field:id runphp='yes'] \$id=@me; @me='/plus/list.php?tid='.\$id; [/field:id]\" class=\"btit\">[field:typename/]</a>\n        <div class=\"snavfl clearfix\">\n        [field:id runphp='yes']\n                global \$dsql;\n                \$id=@me;\n                \$sql='Select * from dede_arctype where reid='.\$id.' ORDER BY id limit 0,20';\n                \$dsql->SetQuery(\$sql);\n                \$dsql->Execute();\n                while(\$row = \$dsql->GetArray()){\n                    \$url = str_replace(\"{cmspath}\",\"\",\$row['typedir']);\n                    \$str .='<a href=\"/plus/list.php?tid='.\$row[id].'\">'.\$row['typename'].'</a>';\n                    @me = \$str;\n                }                      \n                if(@me == \$id){\n                  @me ='';\n                }\n         [/field:id]\n         </div>\n      ",246,1149);
$z[4][4]['sql']="select * from dede_arctype where reid =~id~";

?>