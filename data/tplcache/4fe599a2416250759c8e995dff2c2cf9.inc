<div class="border">
              <div class="grid-demo"> <a href="[field:arcurl/]" class="show"> <img src="[field:picname function='thumb(@me,366,284)'/]" /><span class="new">最新</span>
                <div class="shadow" style="display:none;"> [field:description /] </div>
                </a>
                <div class="cgiarc">
                  <h3><a href="[field:arcurl/]">[field:title /]</a></h3>
                  <div class="tag"><strong><!-- <a href="#">插画</a></strong><strong><a href="#">手绘</a></strong><strong><a href="#">绘画</a></strong><strong><a href="#">教程</a></strong><strong><a href="#">场景</a></strong><strong><a href="#">全景</a> -->
[field:id runphp='yes']
global $cfg_cmspath;
$tags = GetTags(@me);
$revalue = '';
$tags = explode(',', $tags);
foreach($tags as $key => $value){
  if($value){
    //$revalue .= '<a href="'.$cfg_cmspath.'/tags.php?/'.$value.'/">'.$value.'</a> ';
    $revalue .= '<a href="javascript:;">'.$value.'</a> ';
  }
}
@me = $revalue;
[/field:id] 

                  </strong></div>
                  <div class="action"> <span><i class="fa fa-eye" aria-hidden="true"></i>[field:click /]</span><span><i class="fa fa-commenting-o" aria-hidden="true"></i> [field:id function='cnum(@me)'/]</span><span class="handok"><i class="fa fa-thumbs-o-up" aria-hidden="true"></i>[field:id function='zan(@me)'/]</span></div>
                </div>
              </div>
              </div>