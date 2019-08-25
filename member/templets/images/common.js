$(function(){	
	//图片的渐变
	$(".listpic a").hover(function(){
		$(this).find("img").animate({"opacity":"0.6"},200)
	},function(){
		$(this).find("img").animate({"opacity":"1"},150)
	});
})

$(function(){	
	//团队图片渐变
	$(".teamlist a").hover(function(){
		$(this).find("img").animate({"opacity":"0.6"},200)
	},function(){
		$(this).find("img").animate({"opacity":"1"},150)
	});
})

$(function(){	
	//设计师
	$(".uesrlist a").hover(function(){
		$(this).find("img").animate({"opacity":"0.6"},200)
	},function(){
		$(this).find("img").animate({"opacity":"1"},150)
	});
})

$(function(){	
	//专访
	$(".zfpic a").hover(function(){
		$(this).find("img").animate({"opacity":"0.6"},200)
	},function(){
		$(this).find("img").animate({"opacity":"1"},150)
	});
})

$(function(){	
	//友情链接
	$(".imglink a").hover(function(){
		$(this).find("img").animate({"opacity":"0.6"},200)
	},function(){
		$(this).find("img").animate({"opacity":"1"},150)
	});
})

$(function(){	
	//团队列表
	$(".teamdl a").hover(function(){
		$(this).find("img").animate({"opacity":"0.6"},200)
	},function(){
		$(this).find("img").animate({"opacity":"1"},150)
	});
	
	//设计师列表
	$(".designerimg a").hover(function(){
		$(this).find("img").animate({"opacity":"0.6"},200)
	},function(){
		$(this).find("img").animate({"opacity":"1"},150)
	});
	
	$(".designerlist dd cite a").hover(function(){
		$(this).find("img").animate({"opacity":"0.6"},200)
	},function(){
		$(this).find("img").animate({"opacity":"1"},150)
	});
	//交友列表
	$(".friend li span a").hover(function(){
		$(this).find("img").animate({"opacity":"0.6"},200)
	},function(){
		$(this).find("img").animate({"opacity":"1"},150)
	});
})

$(function(){	
	//顶部导航切换
	$(".nav li a").click(function(){
		$(".nav li a.selected").removeClass("selected")
		$(this).addClass("selected");
	})	
	$(".classlink").each(function(i,n){
		$(this).find("li:first").css({"background":"none"});
	});
})	

$(function(){
	//顶部下拉导航
	if($(".navmore").size() > 0){
		
	var _left = $(".navmore").offset().left-0;
	var _top = $(".navmore").offset().top+41;
	var c,d;
	$(".navmorelist").css({left:_left,top:_top});
	$(".navmore").mouseover(function(){
		$(".navmorelist").slideDown();

	});
	
	$(document).mousemove(function(e){
		if((!$(e.target).parents(".navmore").size() && !$(e.target).is('.navmore')) && (!$(e.target).parents('.navmorelist').size()&& !$(e.target).is('.navmorelist'))){
			$(".navmorelist").fadeOut(200);
		}
	})
	$(window).resize(function(){
		var _left = $(".navmore").offset().left-0;
	    var _top = $(".navmore").offset().top+41;
		$(".navmorelist").css({left:_left,top:_top});
	});
	
	}
})


$(function(){
	if($(".loginin").size() > 0){
		//顶部用户下拉菜单
		var _left = $(".loginin").offset().left-0;
		var _top = $(".loginin").offset().top+53;
		var c,d;
		$(".usercenter").css({left:_left,top:_top});
		$(".loginin").mouseover(function(){
		$(".usercenter").slideDown();
		});
		
		$(document).mousemove(function(e){
			if((!$(e.target).parents(".loginin").size() && !$(e.target).is('.loginin')) && (!$(e.target).parents('.usercenter').size()&& !$(e.target).is('.usercenter'))){
				$(".usercenter").fadeOut(200);
			}
		})
		$(window).resize(function(){
			var _left = $(".loginin").offset().left-0;
			var _top = $(".loginin").offset().top+53;
			$(".usercenter").css({left:_left,top:_top});
		});	
	}
})

$(function(){	
	//分页
	$(".nli a").click(function(){
		$(".nli a.selected").removeClass("selected")
		$(this).addClass("selected");
	})	
	//分页居中
	var d_w=$('.page').width();
	var l
	l=(1100 - d_w)/2; 
	$('.page').css({"position":"relative","left":l+"px"}); 
	
	//分页居中1
	var d_w=$('.page1').width();
	var l
	l=(875 - d_w)/2; 
	$('.page1').css({"position":"relative","left":l+"px"});
	
	//分页居中2
	var d_w=$('.page2').width();
	var l
	l=(875 - d_w)/2; 
	$('.page2').css({"position":"relative","left":l+"px"});
	
})	

$(function() {
	//图片延时加载
	$("img").lazyload({
	placeholder : "/web/images/grey.gif",
	effect : "fadeIn"
	});
});



$(function(){	
	//位置列表背景取消
	$(".position li:last").css({"background":"none"});
	$(".navclass li:last").css({"background":"none"});
})	

$(function(){	
	//列表页导航
	$(".navclass li a").click(function(){
		$(".navclass li a.selected").removeClass("selected")
		$(this).addClass("selected");
	})	
})	

$(function(){	
	//用户中心菜单
	$(".navclass li a").click(function(){
		$(".navclass li a.selected").removeClass("selected")
		$(this).addClass("selected");
	})	
})	


$(function(){	
	//分类
	$(".uleftnav dd a").click(function(){
		$(".uleftnav dd a.uafter").removeClass("uafter")
		$(this).addClass("uafter");
	})	
})	

$(function(){	
	//隔行换背景
	$(".mapdl dt:odd a").addClass("otherbg");
})	

$(function(){	
	//隔行换背景
	$(".nlistleft li:odd").addClass("libg");
})	

$(function(){	
	//隔行换背景
	$(".joblist li:odd").addClass("libg");
	$(".ujoblist li:odd").addClass("libg");
	$(".ujoblist1 li:odd").addClass("libg");
	$(".ujoblist2 li:even").addClass("libg");
})	

$(function(){	
	//分类
	$(".classnav li a").click(function(){
		$(".classnav li a.selected").removeClass("selected")
		$(this).addClass("selected");
	})	
})

///////////// 首页图片切换 ///////////////
$(function(){
	var itmeNum = $(".pictitle li").size();
	var startNum = 0;
	var mytime;
	//鼠标hover时候的方法
	$(".picbtn li a").hover(function(){
		startNum = $(".picbtn li a").index($(this));
		clearInterval(mytime);
		switchImg($(this));
	},function(){
		//重新启动图片自动切换	
		runMyTime();
	})
	//给触发器绑定的方法
	$(".picbtn li a").click(function(){
		switchImg($(this));
	})	
	//图片定时自动切换
	runMyTime();
	//切换图片的方法
	function slicePic(){
		$(".picbtn li a:eq(" + startNum + ")").trigger("click");
		if( startNum == itmeNum - 1){
			startNum = 0;
		}else{
			startNum++;
		}
	}
	/*启动定时器*/
	function runMyTime(){
		mytime = setInterval(function(){
		slicePic()
		},1500);
	}
	/*控制切换的js*/
	function switchImg(obj){
		var $this = obj.parent();
		if(!$(this).hasClass("active")){
			$(".picbtn li a").removeClass("active");
			$this.find("a").addClass("active");
			$(".pictitle li").addClass("imgoff");
			//$(".imgtoplist ." + $this.attr("attr")).removeClass("imgoff").addClass("imgon");
			$(".pictitle ." + $this.attr("attr")).removeClass("imgoff").addClass("imgon");
		}
		$(".imgtoplist a").hide();
		$(".imgtoplist ." + $this.attr("attr")).show();
	}
})
//$(function(){
//	//首页高亮
//	if(document.getElementById("index") && isIndex){document.getElementById("index").className='selected';}
//})
var typename;
