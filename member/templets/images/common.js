$(function(){	
	//ͼƬ�Ľ���
	$(".listpic a").hover(function(){
		$(this).find("img").animate({"opacity":"0.6"},200)
	},function(){
		$(this).find("img").animate({"opacity":"1"},150)
	});
})

$(function(){	
	//�Ŷ�ͼƬ����
	$(".teamlist a").hover(function(){
		$(this).find("img").animate({"opacity":"0.6"},200)
	},function(){
		$(this).find("img").animate({"opacity":"1"},150)
	});
})

$(function(){	
	//���ʦ
	$(".uesrlist a").hover(function(){
		$(this).find("img").animate({"opacity":"0.6"},200)
	},function(){
		$(this).find("img").animate({"opacity":"1"},150)
	});
})

$(function(){	
	//ר��
	$(".zfpic a").hover(function(){
		$(this).find("img").animate({"opacity":"0.6"},200)
	},function(){
		$(this).find("img").animate({"opacity":"1"},150)
	});
})

$(function(){	
	//��������
	$(".imglink a").hover(function(){
		$(this).find("img").animate({"opacity":"0.6"},200)
	},function(){
		$(this).find("img").animate({"opacity":"1"},150)
	});
})

$(function(){	
	//�Ŷ��б�
	$(".teamdl a").hover(function(){
		$(this).find("img").animate({"opacity":"0.6"},200)
	},function(){
		$(this).find("img").animate({"opacity":"1"},150)
	});
	
	//���ʦ�б�
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
	//�����б�
	$(".friend li span a").hover(function(){
		$(this).find("img").animate({"opacity":"0.6"},200)
	},function(){
		$(this).find("img").animate({"opacity":"1"},150)
	});
})

$(function(){	
	//���������л�
	$(".nav li a").click(function(){
		$(".nav li a.selected").removeClass("selected")
		$(this).addClass("selected");
	})	
	$(".classlink").each(function(i,n){
		$(this).find("li:first").css({"background":"none"});
	});
})	

$(function(){
	//������������
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
		//�����û������˵�
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
	//��ҳ
	$(".nli a").click(function(){
		$(".nli a.selected").removeClass("selected")
		$(this).addClass("selected");
	})	
	//��ҳ����
	var d_w=$('.page').width();
	var l
	l=(1100 - d_w)/2; 
	$('.page').css({"position":"relative","left":l+"px"}); 
	
	//��ҳ����1
	var d_w=$('.page1').width();
	var l
	l=(875 - d_w)/2; 
	$('.page1').css({"position":"relative","left":l+"px"});
	
	//��ҳ����2
	var d_w=$('.page2').width();
	var l
	l=(875 - d_w)/2; 
	$('.page2').css({"position":"relative","left":l+"px"});
	
})	

$(function() {
	//ͼƬ��ʱ����
	$("img").lazyload({
	placeholder : "/web/images/grey.gif",
	effect : "fadeIn"
	});
});



$(function(){	
	//λ���б���ȡ��
	$(".position li:last").css({"background":"none"});
	$(".navclass li:last").css({"background":"none"});
})	

$(function(){	
	//�б�ҳ����
	$(".navclass li a").click(function(){
		$(".navclass li a.selected").removeClass("selected")
		$(this).addClass("selected");
	})	
})	

$(function(){	
	//�û����Ĳ˵�
	$(".navclass li a").click(function(){
		$(".navclass li a.selected").removeClass("selected")
		$(this).addClass("selected");
	})	
})	


$(function(){	
	//����
	$(".uleftnav dd a").click(function(){
		$(".uleftnav dd a.uafter").removeClass("uafter")
		$(this).addClass("uafter");
	})	
})	

$(function(){	
	//���л�����
	$(".mapdl dt:odd a").addClass("otherbg");
})	

$(function(){	
	//���л�����
	$(".nlistleft li:odd").addClass("libg");
})	

$(function(){	
	//���л�����
	$(".joblist li:odd").addClass("libg");
	$(".ujoblist li:odd").addClass("libg");
	$(".ujoblist1 li:odd").addClass("libg");
	$(".ujoblist2 li:even").addClass("libg");
})	

$(function(){	
	//����
	$(".classnav li a").click(function(){
		$(".classnav li a.selected").removeClass("selected")
		$(this).addClass("selected");
	})	
})

///////////// ��ҳͼƬ�л� ///////////////
$(function(){
	var itmeNum = $(".pictitle li").size();
	var startNum = 0;
	var mytime;
	//���hoverʱ��ķ���
	$(".picbtn li a").hover(function(){
		startNum = $(".picbtn li a").index($(this));
		clearInterval(mytime);
		switchImg($(this));
	},function(){
		//��������ͼƬ�Զ��л�	
		runMyTime();
	})
	//���������󶨵ķ���
	$(".picbtn li a").click(function(){
		switchImg($(this));
	})	
	//ͼƬ��ʱ�Զ��л�
	runMyTime();
	//�л�ͼƬ�ķ���
	function slicePic(){
		$(".picbtn li a:eq(" + startNum + ")").trigger("click");
		if( startNum == itmeNum - 1){
			startNum = 0;
		}else{
			startNum++;
		}
	}
	/*������ʱ��*/
	function runMyTime(){
		mytime = setInterval(function(){
		slicePic()
		},1500);
	}
	/*�����л���js*/
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
//	//��ҳ����
//	if(document.getElementById("index") && isIndex){document.getElementById("index").className='selected';}
//})
var typename;
