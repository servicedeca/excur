(function ($, Drupal, window, document, undefined) {

  Drupal.behaviors.excurLanguageSwitcher = {
    attach: function(context, settings) {
      $('#language-switcher label').once().click(function() {
        window.location = $(this).data('url');
      });
    }
  };

  Drupal.behaviors.excurCurrencySwitcher = {
    attach: function(context, settings) {
      $('#currency-switcher label').once().click(function() {
        $.cookie('excur_currency', $(this).data('currency'), {expires: 86400, path: '/'});
        location.reload();
      });
    }
  };

  Drupal.behaviors.excurCustomUserLogin = {
    attach: function(context, settings) {
      $('#user-login-custom a.registration-button').once().click(function() {
        var $this = $(this);
        var email = $this.closest('#user-login-custom').find('#user-login-custom-email').val();
        var password = $this.closest('#user-login-custom').find('#user-login-custom-password').val();
        console.log(email);
        console.log(password);

        var $trueForm = $this.closest('form');
        console.log($trueForm);
        $('.form-item-name input', $trueForm).val(email);
        $('.form-item-pass input', $trueForm).val(password);
        $('.form-actions input.form-submit').click();
      });
    }
  };

})(jQuery, Drupal, this, this.document);
