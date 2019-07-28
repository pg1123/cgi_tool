<li class="layui-nav-item">
    <a href="{dede:field name='typeurl'/}" >{dede:field name='typename' /}</a>
    <dd>
    {dede:sql sql='select * from dede_arctype where reid =~id~ '}
        <a href="[field:typelink/]" class="btit">[field:typename/]</a>
        <div class="snavfl clearfix">
        [field:id runphp='yes']
                global $dsql;
                $id=@me;
                $sql='Select * from dede_arctype where reid='.$id.' ORDER BY id limit 0,20';
                $dsql->SetQuery($sql);
                $dsql->Execute();
                while($row = $dsql->GetArray()){
                    $url = str_replace("{cmspath}","",$row['typedir']);
                    $str .='<a href="'.$url.'" style="display: block;width: 90%;padding-left: 10%;text-align: left;line-height: 30px;">'.$row['typename'].'</a>';
                    @me = $str;
                }                      
                if(@me == $id){
                  @me ='';
                }
         [/field:id]
         </div>
      {/dede:sql}
    </dd>
  </li>