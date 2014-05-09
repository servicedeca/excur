(function ($) {

  Drupal.behaviors.excurMainSlider = {
    attach: function(context, settings) {
      $('#main-slider').skdslider({
        delay:5000,
        animationSpeed: 2000,
        showNextPrev:true,
        showPlayButton:false,
        autoSlide:true,
        animationType: 'sliding'
      });

      $('#responsive').change(function(){
        $('#responsive_wrapper').width($(this).val());
      });
    }
  };

  Drupal.behaviors.excurSetTitle = {
    attach: function(context, settings) {
      var $title = $('.title-wrapper');
      var $clSpan = $title.closest('[class^="span"]');
      var marginLeft = $title.width() * 100 / $clSpan.width() / 2;
      $title.css('margin-left', 50 - marginLeft + '%');
    }
  };

  Drupal.behaviors.excurSetSearchForm = {
    attach: function(context, settings) {
      var $title = $('#slider-search-form');
      var $clSpan = $title.closest('[class^="span"]');
      var marginLeft = $title.width() * 100 / $clSpan.width() / 2;
      $title.css('margin-left', 50 - marginLeft + '%');
    }
  };

}(jQuery));
