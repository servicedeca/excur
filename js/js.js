  
    $(document).ready(function() {

      //Sort random function
      function random(owlSelector){
        owlSelector.children().sort(function(){
            return Math.round(Math.random()) - 0.5;
        }).each(function(){
          $(this).appendTo(owlSelector);
        });
      }

      $("#owl-demo").owlCarousel({
        navigation: true,
        navigationText: [
        "",
        ""
        ],
        //Call beforeInit callback, elem parameter point to $("#owl-demo")
        beforeInit : function(elem){
          random(elem);
        }
      });
    });



	$(document).ready(function(){
		$(".reg-item").click(function(){
			if($(this).attr('class')  ==  'reg-item' ) {
				$('.reg-item').removeClass('reg-active');
				$(this).addClass('reg-active');
			}
		})
	});


	function showOrHide(check, cat) {
		check = document.getElementById(check);
		cat = document.getElementById(cat);
		if (check.checked) cat.style.display = "inline";
		else cat.style.display = "none";
	}


	$(document).ready(function() {
		$('.icon-minus').click(function () {
			var $input = $(this).parent().find('input');
			var count = parseInt($input.val()) - 1;
			count = count < 1 ? 1 : count;
			$input.val(count);
			$input.change();
			return false;
		});
		$('.icon-plus').click(function () {
			var $input = $(this).parent().find('input');
			$input.val(parseInt($input.val()) + 1);
			$input.change();
			return false;
		});
	});
  
jQuery(document).ready(function(){
	$objWindow = $(window);
	$('div[data-type="background"]').each(function(){
		var $bgObj = $(this);
		$(window).scroll(function() {
			var yPos = -($objWindow.scrollTop() / $bgObj.data('speed')); 
			var coords = '50% '+ yPos + 'px';
            // Animate the background
			 $bgObj.css({ backgroundPosition: coords });
           
		});
		
	});
});

	$(document).ready(function(){

		$('.hover').hover(function(){
			$(this).addClass('flip');
		},function(){
			$(this).removeClass('flip');
		});

		// set up block configuration
		$('.block .action').click(function(){
			$('.block').addClass('flip');
		});
		$('.block .edit-submit').click(function(e){
			$('.block').removeClass('flip');

			// why not update that list for fun?
			$('#list-title').text($('#form_title').val());
			$('#list-items').empty();
			for (var num = $('#form_items').val(); num >= 1; num--) {
				$('#list-items').append('<li>Super seller</li>');
			}
			e.preventDefault();
		});
	});
    
