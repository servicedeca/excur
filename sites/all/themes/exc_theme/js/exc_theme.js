(function ($) {

  Drupal.behaviors.excurSlider = {
    attach: function(context, settings) {
      $slider = $('.slider1');
      if ($slider[0] != undefined) {
        $slider.flexslider();
      }
    }
  };

  Drupal.behaviors.excurTextOnSlider = {
    attach: function(context, settings) {
      // Titles
      var $title = $('.title-wrapper');
      var $clSpan = $title.closest('[class^="span"]');
      var left = $title.width() * 100 / $clSpan.width() / 2;
      $title.css('left', 50 - left + '%');

      // Search form.
      var $form = $('#slider-search-form');
      var $closestSpan = $form.closest('[class^="span"]');
      left = $form.width() * 100 / $closestSpan.width() / 2;
      $form.css('left', 50 - left + '%');
    }
  };

  Drupal.behaviors.excurResponsiveMenu = {
    attach: function(context, settings) {
      $('.nav-responsive').on('change', function() {
        window.location = $(this).val();
      });
    }
  };

  Drupal.behaviors.excurSearchIcon = {
    attach: function(context, settings) {
      $('.search-box a.search-icon').click(function(e) {
        e.preventDefault();

        $(this).closest('form').find('input[type="submit"]').click();
      });
    }
  };

  Drupal.behaviors.excurScrollTo = {
    attach: function(context, settings) {
      excurScrollTo('.do-offer button', '#reservation', 1000);
    }
  };

  Drupal.behaviors.excurSelect = {
    attach: function(context, settings) {
      var currency = $('#edit-currency');
      if( /Android|webOS|iPhone|iPad|iPod|BlackBerry/i.test(navigator.userAgent) ) {
        currency.selectpicker('mobile');
      }
      else {
        currency.selectpicker();
      }

      currency.change(function() {
        $('#excur-currency-choice-form input[type="submit"]').click();
      });
    }
  };

  function excurScrollTo(from, to, time) {
    $(from).click(function (){
      $('html, body').animate({
        scrollTop: $(to).offset().top
      }, time);
    });
  }

}(jQuery));
