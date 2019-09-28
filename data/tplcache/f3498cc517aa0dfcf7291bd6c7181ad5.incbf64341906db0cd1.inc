<?php
$z[0]=Array("arcurl","",76,91);
$z[1]=Array("imgsrc","",117,169);
$z[1][4]['function']="MakeImgThumb(@me,300,190)";
$z[2]=Array("description","",230,251);
$z[3]=Array("title","",384,399);
$z[4]=Array("title","",401,416);
$z[5]=Array("id","\r\nglobal \$cfg_cmspath;\r\n\$tags = GetTags(@me);\r\n\$revalue = '';\r\n\$tags = explode(',', \$tags);\r\nforeach(\$tags as \$key => \$value){\r\n  if(\$value){\r\n    //\$revalue .= '<a href=\"'.\$cfg_cmspath.'/tags.php?/'.\$value.'/\">'.\$value.'</a> ';\r\n    \$revalue .= '<a href=\"javascript:;\">'.\$value.'</a> ';\r\n  }\r\n}\r\n@me = \$revalue;\r\n",883,1231);
$z[5][4]['runphp']="yes";
$z[6]=Array("click","",1410,1425);
$z[7]=Array("id","",1491,1523);
$z[7][4]['function']="cnum(@me)";
$z[8]=Array("id","",1603,1634);
$z[8][4]['function']="zan(@me)";

?>