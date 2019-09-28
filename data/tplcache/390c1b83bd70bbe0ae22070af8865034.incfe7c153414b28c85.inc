<?php
$z[0]=Array("arcurl","",76,91);
$z[1]=Array("litpic","",117,132);
$z[2]=Array("description","",193,214);
$z[3]=Array("title","",347,362);
$z[4]=Array("title","",364,379);
$z[5]=Array("id","\r\nglobal \$cfg_cmspath;\r\n\$tags = GetTags(@me);\r\n\$revalue = '';\r\n\$tags = explode(',', \$tags);\r\nforeach(\$tags as \$key => \$value){\r\n  if(\$value){\r\n    //\$revalue .= '<a href=\"'.\$cfg_cmspath.'/tags.php?/'.\$value.'/\">'.\$value.'</a> ';\r\n    \$revalue .= '<a href=\"javascript:;\">'.\$value.'</a> ';\r\n  }\r\n}\r\n@me = \$revalue;\r\n",846,1194);
$z[5][4]['runphp']="yes";
$z[6]=Array("click","",1373,1388);
$z[7]=Array("id","",1454,1486);
$z[7][4]['function']="cnum(@me)";
$z[8]=Array("id","",1566,1597);
$z[8][4]['function']="zan(@me)";

?>