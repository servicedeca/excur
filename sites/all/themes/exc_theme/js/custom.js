(function ($, Drupal, window, document, undefined) {

  Drupal.behaviors.excurLanguageSwitcher = {
    attach: function(context, settings) {
      $('#language-switcher label').click(function() {
        window.location = $(this).data('url');
      });
    }
  };

  Drupal.behaviors.excurCurrencySwitcher = {
    attach: function(context, settings) {
      $('#currency-switcher label').click(function() {
        $.cookie('excur_currency', $(this).data('currency'), {expires: 86400, path: '/'});
        location.reload();
      });
    }
  };

})(jQuery, Drupal, this, this.document);
