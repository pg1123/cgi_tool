<?php
$z[0]=Array("arcurl","",68,83);
$z[1]=Array("picname","",109,155);
$z[1][4]['function']="thumb(@me,366,284)";
$z[2]=Array("picname","",164,180);
$z[3]=Array("title","",244,258);
$z[4]=Array("arcurl","",355,370);
$z[5]=Array("title","",372,386);
$z[6]=Array("id","\nglobal \$cfg_cmspath;\n\$tags = GetTags(@me);\n\$revalue = '';\n\$tags = explode(',', \$tags);\nforeach(\$tags as \$key => \$value){\n  if(\$value){\n    //\$revalue .= '<a href=\"'.\$cfg_cmspath.'/tags.php?/'.\$value.'/\">'.\$value.'</a> ';\n    \$revalue .= '<a href=\"javascript:;\">'.\$value.'</a> ';\n  }\n}\n@me = \$revalue;\n",635,971);
$z[6][4]['runphp']="yes";
$z[7]=Array("click","",1121,1136);
$z[8]=Array("id","",1203,1235);
$z[8][4]['function']="cnum(@me)";
$z[9]=Array("id","",1315,1346);
$z[9][4]['function']="zan(@me)";

?>