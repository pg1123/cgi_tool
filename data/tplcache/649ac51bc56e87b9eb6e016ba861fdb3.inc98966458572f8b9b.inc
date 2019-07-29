<?php
$z[0]=Array("reid","",9,22);
$z[1]=Array("typename","",37,54);
$z[2]=Array("id","\r\n                global \$dsql;\r\n                \$id=@me;\r\n                \$sql='Select * from dede_arctype where reid='.\$id.' ORDER BY id limit 0,20';\r\n                \$dsql->SetQuery(\$sql);\r\n                \$dsql->Execute();\r\n                while(\$row = \$dsql->GetArray()){\r\n                    \$url = str_replace(\"{cmspath}\",\"\",\$row['typedir']);\r\n                    \$str .='<a href=\"/plus/list.php?tid='.\$id.'\">'.\$row['typename'].'</a>';\r\n                    @me = \$str;\r\n                }                      \r\n                if(@me == \$id){\r\n                  @me ='';\r\n                }\r\n         ",107,748);
$z[2][4]['runphp']="yes";

?>