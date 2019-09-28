<?php
$z[0]=Array("arcurl","",76,91);
$z[1]=Array("picname","",117,163);
$z[1][4]['function']="thumb(@me,100,100)";
$z[2]=Array("description","",224,245);
$z[3]=Array("title","",378,393);
$z[4]=Array("title","",395,410);
$z[5]=Array("id","\r\nglobal \$cfg_cmspath;\r\n\$tags = GetTags(@me);\r\n\$revalue = '';\r\n\$tags = explode(',', \$tags);\r\nforeach(\$tags as \$key => \$value){\r\n  if(\$value){\r\n    //\$revalue .= '<a href=\"'.\$cfg_cmspath.'/tags.php?/'.\$value.'/\">'.\$value.'</a> ';\r\n    \$revalue .= '<a href=\"javascript:;\">'.\$value.'</a> ';\r\n  }\r\n}\r\n@me = \$revalue;\r\n",877,1225);
$z[5][4]['runphp']="yes";
$z[6]=Array("click","",1404,1419);
$z[7]=Array("id","",1485,1517);
$z[7][4]['function']="cnum(@me)";
$z[8]=Array("id","",1597,1628);
$z[8][4]['function']="zan(@me)";

?>