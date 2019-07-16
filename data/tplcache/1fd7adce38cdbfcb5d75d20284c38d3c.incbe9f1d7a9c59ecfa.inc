<?php
$z[0]=Array("typelink","",71,88);
$z[1]=Array("typename","",129,146);
$z[2]=Array("typename","",218,235);
$z[3]=Array("id","\r\n                        global \$dsql;\r\n                        \$id=@me;\r\n                        \$sql='Select * from ywcm_arctype where reid='.\$id.' ORDER BY id limit 0,20';\r\n                        \$dsql->SetQuery(\$sql);\r\n                        \$dsql->Execute();\r\n                        while(\$row = \$dsql->GetArray()){\r\n                            \$url = str_replace(\"{cmspath}\",\"\",\$row['typedir']);\r\n                            \$str .='<a href=\"'.\$url.'\" style=\"display: block;width: 90%;padding-left: 10%;text-align: left;line-height: 30px;\">'.\$row['typename'].'</a>';\r\n                            @me = \$str;\r\n                        }                      \r\n                        if(@me == \$id){ //避免3级栏目为空时 写出分类ID，这里加以判断 \r\n                          @me ='';\r\n                        }\r\n                  ",377,1266);
$z[3][4]['runphp']="yes";

?>