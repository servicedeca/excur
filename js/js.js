   
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
  