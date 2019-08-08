<?php
$z[0]=Array("typeurl","",9,25);
$z[1]=Array("typename","",40,57);
$z[2]=Array("id","\n                global \$dsql;\n                \$id=@me;\n                \$sql='Select * from dede_arctype where reid='.\$id.' ORDER BY id limit 0,20';\n                \$dsql->SetQuery(\$sql);\n                \$dsql->Execute();\n                while(\$row = \$dsql->GetArray()){\n                    \$url = str_replace(\"{cmspath}\",\"\",\$row['typedir']);\n                    \$str .='<a href=\"/plus/list.php?tid='.\$row[id].'\">'.\$row['typename'].'</a>';\n                    @me = \$str;\n                }                      \n                if(@me == \$id){\n                  @me ='';\n                }\n         ",108,740);
$z[2][4]['runphp']="yes";

?>