(function($) {

Drupal.behaviors.rhNode = {
  attach: function (context, settings) {

    // The drupalSetSummary method required for this behavior is not available
    // on some pages, so we need to make sure this
    // behavior is processed only if drupalSetSummary is defined.
    if (typeof jQuery.fn.drupalSetSummary == 'undefined') {
      return;
    }
    // Set the summary for the settings form.
    $('fieldset.rabbit-hole-settings-form').drupalSetSummary(function() {
      var $rabbitHoleAction = $('.rabbit-hole-action-setting input:checked');

      // Get the label of the selected action.
      var summary = $('label[for=' + $rabbitHoleAction.attr('id') + ']').text();
      return Drupal.checkPlain(summary);
    });

  }
}

})(jQuery);
