<li class="layui-nav-item"><a href="{dede:field name='typeurl'/}"  rel='dropmenu'>{dede:field name='typename' /}</a>
    <div id="erji" class="erji hide" style="position: absolute;width: 200px">
    {dede:sql sql='select * from dede_arctype where reid =~id~ '}
        <dl style="position: relative;height: 30px">
        <a href='[field:typelink/]' target='_self'
        title="[field:typename/]" style="width: 90%;padding-left:10%;text-align:left;line-height: 30px">[field:typename/]</a>
        <div id="sanji" class="hide" style="position: absolute;width: 200px;left: 200px;background: #0D6598;">
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
      </dl>
      {/dede:sql}
    </div>
  </li>