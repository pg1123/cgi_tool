<a href="11111" class="btit">[field:typename/]</a>
        <div class="snavfl clearfix">
        [field:id runphp='yes']
                global $dsql;
                $id=@me;
                $sql='Select * from dede_arctype where reid='.$id.' ORDER BY id limit 0,20';
                $dsql->SetQuery($sql);
                $dsql->Execute();
                while($row = $dsql->GetArray()){
                    $url = str_replace("{cmspath}","",$row['typedir']);
                    $str .='<a href="'.$url.'">'.$row['typename'].'</a>';
                    @me = $str;
                }                      
                if(@me == $id){
                  @me ='';
                }
         [/field:id]
         </div>