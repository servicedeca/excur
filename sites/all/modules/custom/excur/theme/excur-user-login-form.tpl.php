<div class="formenter" id="user-login-custom">
  <div class="col-sm-12 modal-registration-item">
    <?php print $icon_email; ?>
    <input type="text" id="user-login-custom-email" class="form-control modal-registration-form" placeholder="<?php print t('Email'); ?>">
  </div>
  <div class="col-xs-12 modal-registration-item">
    <?php print $icon_password; ?>
    <input type="password" id="user-login-custom-password" class="form-control modal-registration-form" placeholder="<?php print t('Password'); ?>">
  </div>
  <div class="col-xs-12 modal-registration-item">
    <div class="col-xs-8 col-xs-offset-1 modal-registration-button">
      <a class="button-pay registration-button">
        <?php print t('Login'); ?>
      </a>
    </div>
  </div>
</div>

<div class="element-hidden">
<?php print drupal_render_children($form);?>
</div>
