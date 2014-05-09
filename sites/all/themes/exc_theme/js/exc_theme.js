(function ($) {

  Drupal.behaviors.excurSlider = {
    attach: function(context, settings) {
      $('.slider1').flexslider();
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
