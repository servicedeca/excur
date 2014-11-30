(function ($, Drupal, window, document, undefined) {

  Drupal.behaviors.excurLanguageSwitcher = {
    attach: function(context, settings) {
      $('.drop-lang label').click(function() {
        window.location = ($(this).data('url'));
      });
    }
  }

})(jQuery, Drupal, this, this.document);
