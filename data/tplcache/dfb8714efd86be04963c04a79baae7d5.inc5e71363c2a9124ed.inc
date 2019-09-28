<?php
$z[0]=Array("arcurl","",76,91);
$z[1]=Array("picname","",117,163);
$z[1][4]['function']="thumb(@me,450,300)";
$z[2]=Array("description","",224,245);
$z[3]=Array("title","",378,393);
$z[4]=Array("title","",395,410);
$z[5]=Array("id","\r\nglobal \$cfg_cmspath;\r\n\$tags = GetTags(@me);\r\n\$revalue = '';\r\n\$tags = explode(',', \$tags);\r\nforeach(\$tags as \$key => \$value){\r\n  if(\$value){\r\n    //\$revalue .= '<a href=\"'.\$cfg_cmspath.'/tags.php?/'.\$value.'/\">'.\$value.'</a> ';\r\n    \$revalue .= '<a href=\"javascript:;\">'.\$value.'</a> ';\r\n  }\r\n}\r\n@me = \$revalue;\r\n",466,814);
$z[5][4]['runphp']="yes";
$z[6]=Array("click","",993,1008);
$z[7]=Array("id","",1074,1106);
$z[7][4]['function']="cnum(@me)";
$z[8]=Array("id","",1186,1217);
$z[8][4]['function']="zan(@me)";

?>