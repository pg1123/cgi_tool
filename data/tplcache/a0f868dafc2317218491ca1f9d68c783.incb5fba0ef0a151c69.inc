<?php
$z[0]=Array("arcurl","",76,91);
$z[1]=Array("litpic","",117,132);
$z[2]=Array("picname","",152,198);
$z[2][4]['function']="thumb(@me,100,100)";
$z[3]=Array("description","",255,276);
$z[4]=Array("title","",409,424);
$z[5]=Array("title","",426,441);
$z[6]=Array("id","\r\nglobal \$cfg_cmspath;\r\n\$tags = GetTags(@me);\r\n\$revalue = '';\r\n\$tags = explode(',', \$tags);\r\nforeach(\$tags as \$key => \$value){\r\n  if(\$value){\r\n    //\$revalue .= '<a href=\"'.\$cfg_cmspath.'/tags.php?/'.\$value.'/\">'.\$value.'</a> ';\r\n    \$revalue .= '<a href=\"javascript:;\">'.\$value.'</a> ';\r\n  }\r\n}\r\n@me = \$revalue;\r\n",908,1256);
$z[6][4]['runphp']="yes";
$z[7]=Array("click","",1435,1450);
$z[8]=Array("id","",1516,1548);
$z[8][4]['function']="cnum(@me)";
$z[9]=Array("id","",1628,1659);
$z[9][4]['function']="zan(@me)";

?>