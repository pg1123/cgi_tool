<?php
$z[0]=Array("field","",47,75);
$z[0][4]['name']="typeurl";
$z[1]=Array("field","",78,108);
$z[1][4]['name']="typename";
$z[2]=Array("field","",131,159);
$z[2][4]['name']="typeurl";
$z[3]=Array("field","",162,192);
$z[3][4]['name']="typename";
$z[4]=Array("sql","\r\n        <a href=\"[field:id runphp='yes'] \$id=@me; @me='/plus/list.php?tid='.\$id; [/field:id]\" class=\"btit\">[field:typename/]</a>\r\n        <div class=\"snavfl clearfix\">\r\n        [field:id runphp='yes']\r\n                global \$dsql;\r\n                \$id=@me;\r\n                \$sql='Select * from dede_arctype where reid='.\$id.' ORDER BY id limit 0,20';\r\n                \$dsql->SetQuery(\$sql);\r\n                \$dsql->Execute();\r\n                while(\$row = \$dsql->GetArray()){\r\n                    \$url = str_replace(\"{cmspath}\",\"\",\$row['typedir']);\r\n                    \$str .='<a href=\"/plus/list.php?tid='.\$row[id].'\">'.\$row['typename'].'</a>';\r\n                    @me = \$str;\r\n                }                      \r\n                if(@me == \$id){\r\n                  @me ='';\r\n                }\r\n         [/field:id]\r\n         </div>\r\n      ",251,1173);
$z[4][4]['sql']="select * from dede_arctype where reid =~id~";

?>