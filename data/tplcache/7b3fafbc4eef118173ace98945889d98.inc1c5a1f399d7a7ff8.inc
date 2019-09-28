<?php
$z[0]=Array("arcurl","",68,83);
$z[1]=Array("picname","",109,155);
$z[1][4]['function']="thumb(@me,366,284)";
$z[2]=Array("title","",219,233);
$z[3]=Array("arcurl","",330,345);
$z[4]=Array("title","",347,361);
$z[5]=Array("id","\nglobal \$cfg_cmspath;\n\$tags = GetTags(@me);\n\$revalue = '';\n\$tags = explode(',', \$tags);\nforeach(\$tags as \$key => \$value){\n  if(\$value){\n    //\$revalue .= '<a href=\"'.\$cfg_cmspath.'/tags.php?/'.\$value.'/\">'.\$value.'</a> ';\n    \$revalue .= '<a href=\"javascript:;\">'.\$value.'</a> ';\n  }\n}\n@me = \$revalue;\n",610,946);
$z[5][4]['runphp']="yes";
$z[6]=Array("click","",1096,1111);
$z[7]=Array("id","",1178,1210);
$z[7][4]['function']="cnum(@me)";
$z[8]=Array("id","",1290,1321);
$z[8][4]['function']="zan(@me)";

?>