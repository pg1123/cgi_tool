<?php
$z[0]=Array("arcurl","",76,91);
$z[1]=Array("litpic","",117,132);
$z[2]=Array("picname","",154,200);
$z[2][4]['function']="thumb(@me,100,100)";
$z[3]=Array("description","",257,278);
$z[4]=Array("title","",411,426);
$z[5]=Array("title","",428,443);
$z[6]=Array("id","\r\nglobal \$cfg_cmspath;\r\n\$tags = GetTags(@me);\r\n\$revalue = '';\r\n\$tags = explode(',', \$tags);\r\nforeach(\$tags as \$key => \$value){\r\n  if(\$value){\r\n    //\$revalue .= '<a href=\"'.\$cfg_cmspath.'/tags.php?/'.\$value.'/\">'.\$value.'</a> ';\r\n    \$revalue .= '<a href=\"javascript:;\">'.\$value.'</a> ';\r\n  }\r\n}\r\n@me = \$revalue;\r\n",910,1258);
$z[6][4]['runphp']="yes";
$z[7]=Array("click","",1437,1452);
$z[8]=Array("id","",1518,1550);
$z[8][4]['function']="cnum(@me)";
$z[9]=Array("id","",1630,1661);
$z[9][4]['function']="zan(@me)";

?>