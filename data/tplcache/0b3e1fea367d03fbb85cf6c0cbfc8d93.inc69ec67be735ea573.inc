<?php
$z[0]=Array("field","",42,70);
$z[0][4]['name']="typeurl";
$z[1]=Array("field","",73,103);
$z[1][4]['name']="typename";
$z[2]=Array("sql","\r\n        <a href=\"[field:typelink/]\" class=\"btit\">[field:typename/]</a>\r\n        <div class=\"snavfl clearfix\">\r\n        [field:id runphp='yes']\r\n                global \$dsql;\r\n                \$id=@me;\r\n                \$sql='Select * from dede_arctype where reid='.\$id.' ORDER BY id limit 0,20';\r\n                \$dsql->SetQuery(\$sql);\r\n                \$dsql->Execute();\r\n                while(\$row = \$dsql->GetArray()){\r\n                    \$url = str_replace(\"{cmspath}\",\"\",\$row['typedir']);\r\n                    \$str .='<a href=\"'.\$url.'\">'.\$row['typename'].'</a>';\r\n                    @me = \$str;\r\n                }                      \r\n                if(@me == \$id){\r\n                  @me ='';\r\n                }\r\n         [/field:id]\r\n         </div>\r\n      ",162,1003);
$z[2][4]['sql']="select * from dede_arctype where reid =~id~";

?>