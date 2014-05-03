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

}(jQuery));
