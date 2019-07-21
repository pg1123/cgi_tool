<?php
$z[0]=Array("field","",36,64);
$z[0][4]['name']="typeurl";
$z[1]=Array("field","",82,112);
$z[1][4]['name']="typename";
$z[2]=Array("sql","\r\n        <dl style=\"position: relative;height: 30px\">\r\n        <a href='[field:typelink/]' target='_self'\r\n        title=\"[field:typename/]\" style=\"width: 90%;padding-left:10%;text-align:left;line-height: 30px\">[field:typename/]</a>\r\n        <div id=\"sanji\" class=\"hide\" style=\"position: absolute;width: 200px;left: 200px;background: #0D6598;\">\r\n        [field:id runphp='yes']\r\n                global \$dsql;\r\n                \$id=@me;\r\n                \$sql='Select * from dede_arctype where reid='.\$id.' ORDER BY id limit 0,20';\r\n                \$dsql->SetQuery(\$sql);\r\n                \$dsql->Execute();\r\n                while(\$row = \$dsql->GetArray()){\r\n                    \$url = str_replace(\"{cmspath}\",\"\",\$row['typedir']);\r\n                    \$str .='<a href=\"'.\$url.'\" style=\"display: block;width: 90%;padding-left: 10%;text-align: left;line-height: 30px;\">'.\$row['typename'].'</a>';\r\n                    @me = \$str;\r\n                }                      \r\n                if(@me == \$id){\r\n                  @me ='';\r\n                }\r\n          [/field:id]\r\n        </div>\r\n      </dl>\r\n      ",201,1377);
$z[2][4]['sql']="select * from dede_arctype where reid =~id~";

?>