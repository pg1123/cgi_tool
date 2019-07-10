layui.use('element', function(){
  var element = layui.element; //导航的hover效果、二级菜单等功能，需要依赖element模块
  
  //监听导航点击
  element.on('nav(demo)', function(elem){
    //console.log(elem)
    layer.msg(elem.text());
  });


  layui.use(['form','upload', 'laydate','laypage', 'layer'], function(){
    var form = layui.form,
    layer = layui.layer,
    laydate = layui.laydate;
  });



});


//登录弹窗
  function logintc(){
      layer.open({
        type: 1,
        title: '用户登录',
        shadeClose: true,
        shade: 0.8,
        area: ['400px', 'auto'],
        content: $('#logintc') //iframe的url
      });
  }


  //注册弹窗^M
function design(){
    layer.open({
        type: 1,
        title: '用户注册',
        shadeClose: true,
        shade: 0.8,
        area: ['400px', 'auto'],
        content: $('#design') //iframe的url
              
    });
}


$(function(){

    $(".show").hover(function() {
      $(this).children(".shadow").show();
    }, function() {
      $(this).children(".shadow").hide();
    });


    var winH = $(window).height(); //页面可视区域高度
    var i = 4;
    var isbool=true;//触发开关，防止多次调用事件
    $(window).scroll(function() {
        var pageH = $(document.body).height();
        var scrollT = $(window).scrollTop(); //滚动条top
        var aa = (pageH - winH - scrollT) / winH;
        if (aa < 0.02 && isbool==true) {
              //isbool=false;
              push();

        }
    });

    function push() {
      $.getJSON("/e/extend/cmsdxmore.php",{page:i,cd:1},function(json){
          if(json){
              var str = "";
              $.each(json, function(index, array) {

                   // str = str + '<div class="layui-col-xs3">';
                   // str = str + '<div class="grid-demo"> <a href="' + array['titleurl'] + '" class="show"> <img src="'+ array['titlepic'] +'" /></a>';
                   // str = str + '<div class="cgiarc">';
                   // str = str + '<div class="cgiarc1">';
                   // str = str + '<h3><a href="' + array['titleurl'] + '" title="' + array['title'] + '">' + array['title'] +  '</a></h3>';
                   // str = str + '<div class="tag tag1"><strong>标签</strong><strong>标签</strong><strong>标签</strong><strong>标签</strong><strong>标签</strong></div>';
                   // str = str + '</div>';
                   // str = str + '<div class="action"> <span><i class="fa fa-eye" aria-hidden="true"></i>' +array['onclick']+ '</span><span><i class="fa fa-commenting-o" aria-hidden="true"></i>'+ array['plnum'] +'</span><span class="handok"><i class="fa fa-thumbs-o-up" aria-hidden="true"></i>'+array['diggtop']+'</span></div>';
                   // str = str + '</div>';
                   // str = str + '</div>';
                   // str = str + '</div>';

                   str =  '<div class="layui-col-xs3"><div class="grid-demo"> <a href="' + array['titleurl'] + '" class="show"> <img src="'+ array['titlepic'] +'" /></a><div class="cgiarc"><div class="cgiarc1"><h3><a href="' + array['titleurl'] + '" title="' + array['title'] + '">'  + array['title'] +  '</a></h3><div class="tag tag1"><strong>标签</strong><strong>标签</strong><strong>标签</strong><strong>标签</strong><strong>标签</strong></div></div><div class="action"> <span><i class="fa fa-eye" aria-hidden="true"></i>' +array['onclick']+ '</span><span><i class="fa fa-commenting-o" aria-hidden="true"></i>'+ array['plnum'] +'</span><span class="handok"><i class="fa fa-thumbs-o-up" aria-hidden="true"></i><span class="num">'+array['diggtop']+'</span></span></div></div></div></div>';


                  $('#LAY_demo1').append(str);
                  //isbool=false;
              });
              i++;
            } else {
                $(".nodata").show().html("别滚动了，已经到底了。。。");
                return false;
            }
        });
    }


    $('.login_button').on('click', function(e){
            e.preventDefault();
            var url = '/e/member/doaction.php';
            var username = $('#login_name').val();
            var password = $('#login_password').val();
            var data = {
                ecmsfrom:9,
                lifetime:3600,
                username:username,
                password:password,
                enews:"login", //login
                tobind:"0"
            };
            $.post(url, data, function(data,status){
                if(data.indexOf("登录成功") >= 0){
                      //alert('登陆成功,页面跳转中..请稍后');
                      location.reload();
                  }else if(data.indexOf("您的用户名或密码有误") >= 0){
                      alert("您的用户名或密码有误");
                  }else if(data.indexOf("审核") >= 0){
                     alert("您的帐号还未通过审核!");
                  }else if(data.indexOf("为空") >= 0){
                      alert("用户名和密码不能为空");
                  }else {
                      alert("登录不成功，请确认您的cookie是否已开启!");
                }

            });
    });


    $('.login_out').on('click', function(e){
            e.preventDefault();
            var url = '/e/member/doaction.php';
            var data = {
                ecmsfrom:9,
                enews:"exit", //login
            };
            $.post(url, data, function(data,status){
                if(data.indexOf("成功") >= 0){
                      location.reload();
                  }

            });
    });


    $('.reg_button').on('click', function(e){
            e.preventDefault();
            var url = '/e/member/doaction.php';
            var username = $('#reg_name').val();
            var password = $('#reg_password').val();
            var repassword = $('#reg_repassword').val();
            var email = $('#reg_email').val();
            var data = {
                ecmsfrom:9,
                lifetime:3600,
                username:username,
                password:password,
                repassword:repassword,
                email:email,
                enews:"register", //login
                tobind:"0"
            };
            $.post(url, data, function(data,status){
                if(data.indexOf("注册成功") >= 0){
                      alert('注册成功');
                      location.reload();
                  }else if(data.indexOf("不一致") >= 0){
                      alert("二次密码不一致");
                  }else if(data.indexOf("已被注册") >= 0){
                     alert("此用户名已被注册，请重填！");
                  }else if(data.indexOf("为空") >= 0){
                      alert("用户名，密码与邮箱不能为空");
                  }else if(data.indexOf("邮箱已被") >= 0){
                      alert("此邮箱已被注册");
                  }else if(data.indexOf("用户名长度有误") >= 0){
                      alert("用户名长度有误");
                  }else if(data.indexOf("字符") >= 0){
                      alert("用户名不能包含特殊字符");
                  }else if(data.indexOf("您输入的邮箱有误") >= 0){
                      alert("您输入的邮箱有误");
                  }else if(data.indexOf("您已登录，不能注册帐号") >= 0){
                      alert("您已登录，不能注册帐号");
                  }else if(data.indexOf("密码位数不够或过长") >= 0){
                      alert("密码位数不够或过长");
                  }else {
                      alert("注册失败，请重新输入！");
                }

            });
    });



    $(".fa-thumbs-o-up").click(function(event){ 
        event.preventDefault();
        var mythis = $(this); 
        var classid = mythis.data("classid"); 
        var id = mythis.data("id");
        var dig = mythis.data("dig") + 1;
            
        $.ajax({ 
          type:"GET", 
          url:"/e/public/digg/", 
          data:{"classid":classid,"id":id,"dotop":1,"doajax":1,"ajaxarea":"diggnum"}, 
          dataType:"text", 
          success:function(data){
            if(data.indexOf("您已提交过") >= 0){
                   alert('您已赞过');
              }else{
                mythis.parent(".handok").find('.num').text(dig);
                return;
              }
          } 
        }); 
      }); 




})


