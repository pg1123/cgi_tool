$(function(){
        
    $(".show").hover(function() {
      $(this).children(".shadow").show();
    }, function() {
      $(this).children(".shadow").hide();
    });


    layui.use('element', function(){
      var element = layui.element; //导航的hover效果、二级菜单等功能，需要依赖element模块
      
      //监听导航点击
      element.on('nav(demo)', function(elem){
        //console.log(elem)
        layer.msg(elem.text());
      });
    });


    layui.use(['form','upload', 'laydate','laypage', 'layer'], function(){
      var form = layui.form,
      layer = layui.layer,
      laydate = layui.laydate;
    });

    //登录弹窗
    $('.denglu').on('click', function(event) {
        event.preventDefault();
        layer.open({
            type: 1,
            title: '用户登录',
            shadeClose: true,
            shade: 0.8,
            area: ['400px', 'auto'],
            content: $('#logintc') //iframe的url
        });
    });

    //注册弹窗
    $('.zhuce').on('click', function(event) {
        layer.open({
            type: 1,
            title: '用户注册',
            shadeClose: true,
            shade: 0.8,
            area: ['400px', 'auto'],
            content: $('#design') //iframe的url
        });
    });

    $('#login_button').on('click', function(e){
        e.preventDefault();
        var url = '/member/index_do.php';
        var username = $('#login_name').val();
        var password = $('#login_password').val();
        var vdcode = $('#vdcode').val();
        var data = {
            fmdo: "login",
            dopost: "login",
            gourl: "",
            userid: username,
            pwd: password,
            vdcode: vdcode,
            keeptime: 86400
        };
        $.post(url, data, function(data,status){
            //alert(data);
            if(data.indexOf("成功登录") >= 0){
                  //alert('登陆成功,页面跳转中..请稍后');
                  location.reload();
              }else if(data.indexOf("用户名不存在") >= 0){
                  alert("用户名不存在！");
              }else if(data.indexOf("验证码错误") >= 0){
                //toastr.error("验证码错误！");
                 alert("验证码错误!");
              }else if(data.indexOf("为空") >= 0){
                  alert("密码不能为空！");
              }else if(data.indexOf("密码错误") >= 0){
                  alert("密码错误！");
              }else if(data.indexOf("admin") >= 0){
                  alert("你输入的用户名:admin 不合法！");
              }else {
                  alert("登录不成功，请确认您的cookie是否已开启!");
            }

        });
    });

    $('#reg_button').on('click', function(e){
        e.preventDefault();
        var url = '/member/reg_new.php';
        var username = $('#reg_name').val();
        var password = $('#reg_password').val();
        var repassword = $('#reg_repassword').val();
        var email = $('#reg_email').val();
        var vdcode = $('#vdcode_reg').val();
        var data = {
            mtype: "个人",
            step: 1,
            fmdo: "user",
            dopost: "regbase",
            userid: username,
            uname: username,
            userpwd: password,
            userpwdok: repassword,
            email: email,
            vdcode: vdcode,
        };
        $.post(url, data, function(data,status){
            if(data.indexOf("注册成功") >= 0){
                  location.reload();
              }else if(data.indexOf("用户名已经存在") >= 0){
                  alert("用户名已经存在！");
              }else if(data.indexOf("验证码错误") >= 0){
                 alert("验证码错误!");
              }else if(data.indexOf("你的用户名或密码过短，不允许注册") >= 0){
                  alert("你的用户名或密码过短，不允许注册！");
              }else if(data.indexOf("你两次输入的密码不一致") >= 0){
                  alert("你两次输入的密码不一致");
              }else if(data.indexOf("Email格式不正确") >= 0){
                  alert("Email格式不正确！");
              }else {
                  alert("注册失败!");
            }
        });
    });

    ///member/index_do.php?fmdo=login&dopost=exit
    $('#login_out').on('click', function(e){
            e.preventDefault();
            var url = '/member/index_do.php';
            var data = {
                fmdo: "login",
                dopost: "exit",
            };
            $.post(url, data, function(data,status){
                //alert(data);
                if(data.indexOf("成功") >= 0){
                      //alert('登陆成功,页面跳转中..请稍后');
                      location.reload();
                  }
            });
    });

    $('.changeCode').on('click', function(event) {
        event.preventDefault();
        var num =   new Date().getTime();
        var rand = Math.round(Math.random() * 10000);
        num = num + rand;
        $('#ver_code').css('visibility','visible');
        if ($("#vdimgck_reg")[0]) {
          $("#vdimgck_reg")[0].src = "/include/vdimgck.php?tag=" + num;
        }
        if ($("#vdimgck")[0]) {
          $("#vdimgck")[0].src = "/include/vdimgck.php?tag=" + num;
        }
        return false;
    });


    $(".up").on('click', function(e){
        e.preventDefault();
        //alert(111);
        var zan = $(this).find("a");
        var span = $(this).find("span");
        var id = $(this).attr("rel"); //对应id
        zan.fadeOut(300); //渐隐效果
        $.ajax({
            type:"POST",
            url:"/zan.php",
            data:"id="+id,
            cache:false, //不缓存此页面
            success:function(data){
                //alert(data);
                if (data == '赞过了..') {
                  zan.html(data);
                } else {
                  span.html(data);
                }
                zan.fadeIn(300); //渐显效果
            }
        });
        return false;
    });

    $('.lg_download').on('click', function(event) {
        event.preventDefault();
        layer.open({
            type: 1,
            title: '下载链接',
            shadeClose: true,
            shade: 0.8,
            area: ['400px', 'auto'],
            content: $('#getLink') //iframe的url
        });
    });


});
