(function ($) {

  Drupal.behaviors.excurSlider = {
    attach: function(context, settings) {
      $('.slider1').flexslider();
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

}(jQuery));
