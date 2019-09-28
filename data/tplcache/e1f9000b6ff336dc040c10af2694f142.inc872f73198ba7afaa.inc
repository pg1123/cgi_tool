<?php
$z[0]=Array("arcurl","",68,83);
$z[1]=Array("picname","",109,125);
$z[2]=Array("title","",189,203);
$z[3]=Array("arcurl","",300,315);
$z[4]=Array("title","",317,331);
$z[5]=Array("id","\nglobal \$cfg_cmspath;\n\$tags = GetTags(@me);\n\$revalue = '';\n\$tags = explode(',', \$tags);\nforeach(\$tags as \$key => \$value){\n  if(\$value){\n    //\$revalue .= '<a href=\"'.\$cfg_cmspath.'/tags.php?/'.\$value.'/\">'.\$value.'</a> ';\n    \$revalue .= '<a href=\"javascript:;\">'.\$value.'</a> ';\n  }\n}\n@me = \$revalue;\n",580,916);
$z[5][4]['runphp']="yes";
$z[6]=Array("click","",1066,1081);
$z[7]=Array("id","",1148,1180);
$z[7][4]['function']="cnum(@me)";
$z[8]=Array("id","",1260,1291);
$z[8][4]['function']="zan(@me)";

?>