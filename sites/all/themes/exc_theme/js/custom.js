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
        var $trueForm = $(this).closest('form');
        $('.form-actions input.form-submit', $trueForm).click();
      });
    }
  };

  Drupal.behaviors.excurCustomUserRegister = {
    attach: function(context, settings) {
      $('#user-register-custom a.registration-button').once().click(function() {
        var $trueForm = $(this).closest('form');
        $('.form-actions input.form-submit', $trueForm).click();
      });
    }
  };

  Drupal.behaviors.excurCustomUserRegister = {
    attach: function(context, settings) {
      $('.hover').once().hover(function() {
        $(this).addClass('flip');
      }, function() {
        $(this).removeClass('flip');
      });
    }
  };

  Drupal.behaviors.excurContinentCode = {
    attach: function(context, settings) {
      $('body').once('continent-id', function() {
        if (Drupal.settings.continentCode != undefined) {
          $('body').attr('id', Drupal.settings.continentCode);
        }
      });
    }
  };

})(jQuery, Drupal, this, this.document);
