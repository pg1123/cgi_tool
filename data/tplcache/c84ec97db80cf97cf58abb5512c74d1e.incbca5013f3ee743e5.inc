<?php
$z[0]=Array("field","",50,78);
$z[0][4]['name']="typeurl";
$z[1]=Array("field","",81,111);
$z[1][4]['name']="typename";
$z[2]=Array("field","",152,182);
$z[2][4]['name']="typename";
$z[3]=Array("sql","\n            <a href=\"[field:typelink/]\" class=\"btit\">[field:typename/]</a>\n            <div class=\"snavfl clearfix\">\n            [field:id runphp='yes']\n                    global \$dsql;\n                    \$id=@me;\n                    \$sql='Select * from dede_arctype where reid='.\$id.' ORDER BY id limit 0,20';\n                    \$dsql->SetQuery(\$sql);\n                    \$dsql->Execute();\n                    while(\$row = \$dsql->GetArray()){\n                        \$url = str_replace(\"{cmspath}\",\"\",\$row['typedir']);\n                        \$str .='<a href=\"'.\$url.'\">'.\$row['typename'].'</a>';\n                        @me = \$str;\n                    }                      \n                    if(@me == \$id){\n                      @me ='';\n                    }\n             [/field:id]\n             </div>\n          ",250,1148);
$z[3][4]['sql']="select * from dede_arctype where reid =~id~";

?>