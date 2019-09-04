<?php
$z[0]=Array("id","\r\n        \$id=@me; \r\n        @me='/plus/list.php?tid='.\$id; \r\n         \r\n         ",9,125);
$z[0][4]['runphp']="yes";
$z[1]=Array("typename","",140,157);
$z[2]=Array("id","\r\n                global \$dsql;\r\n                \$id=@me;\r\n                \$sql='Select * from dede_arctype where reid='.\$id.' ORDER BY id limit 0,20';\r\n                \$dsql->SetQuery(\$sql);\r\n                \$dsql->Execute();\r\n                while(\$row = \$dsql->GetArray()){\r\n                    \$url = str_replace(\"{cmspath}\",\"\",\$row['typedir']);\r\n                    \$str .='<a href=\"/plus/list.php?tid='.\$row[id].'\">'.\$row['typename'].'</a>';\r\n                    @me = \$str;\r\n                }                      \r\n                if(@me == \$id){\r\n                  @me ='';\r\n                }\r\n         ",210,856);
$z[2][4]['runphp']="yes";

?>