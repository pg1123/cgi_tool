<?php
$z[0]=Array("arcurl","",69,84);
$z[1]=Array("picname","",110,156);
$z[1][4]['function']="thumb(@me,366,284)";
$z[2]=Array("description","",252,273);
$z[3]=Array("arcurl","",373,388);
$z[4]=Array("title","",390,405);
$z[5]=Array("id","\r\nglobal \$cfg_cmspath;\r\n\$tags = GetTags(@me);\r\n\$revalue = '';\r\n\$tags = explode(',', \$tags);\r\nforeach(\$tags as \$key => \$value){\r\n  if(\$value){\r\n    //\$revalue .= '<a href=\"'.\$cfg_cmspath.'/tags.php?/'.\$value.'/\">'.\$value.'</a> ';\r\n    \$revalue .= '<a href=\"javascript:;\">'.\$value.'</a> ';\r\n  }\r\n}\r\n@me = \$revalue;\r\n",687,1035);
$z[5][4]['runphp']="yes";
$z[6]=Array("click","",1164,1179);
$z[7]=Array("id","",1246,1278);
$z[7][4]['function']="cnum(@me)";
$z[8]=Array("id","",1358,1389);
$z[8][4]['function']="zan(@me)";

?>