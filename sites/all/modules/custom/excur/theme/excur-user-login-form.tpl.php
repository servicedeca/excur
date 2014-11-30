<div class="formenter" id="user-login-custom">
  <div class="col-sm-12 modal-registration-item">
    <?php print $icon_email; ?>
    <?php print render($form['name']); ?>
  </div>
  <div class="col-xs-12 modal-registration-item">
    <?php print $icon_password; ?>
    <?php print render($form['pass']); ?>
  </div>
  <div class="col-xs-12 modal-registration-item">
    <div class="col-xs-8 col-xs-offset-1 modal-registration-button">
      <a class="button-pay registration-button">
        <?php print t('Sign in'); ?>
      </a>
    </div>
  </div>
</div>

<div class="element-hidden">
  <?php print drupal_render_children($form);?>
</div>
