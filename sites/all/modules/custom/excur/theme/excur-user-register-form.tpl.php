<div class="formreg" id="user-register-custom">
  <div class="col-sm-12 modal-registration-item">
    <?php print $icon_name; ?>
    <?php print render($form['field_name']); ?>
  </div>
  <div class="col-xs-12 modal-registration-item">
    <?php print $icon_email; ?>
    <?php print render($form['account']['mail']); ?>
<!--    <input type="text" id="user-register-custom-email" class="form-control modal-registration-form" placeholder="--><?php //print t('Email'); ?><!--">-->
  </div>
  <div class="col-xs-12 modal-registration-item">
    <?php print $icon_password; ?>
    <?php print render($form['account']['pass']['pass1']); ?>
<!--    <input type="password" id="user-register-custom-password" class="form-control modal-registration-form" placeholder="--><?php //print t('Password'); ?><!--">-->
  </div>
  <div class="col-xs-12 modal-registration-item">
    <?php print $icon_password ?>
    <?php print render($form['account']['pass']['pass2']); ?>
<!--    <input type="password" id="user-register-custom-confirm-password" class="form-control modal-registration-form" placeholder="--><?php //print t('Confirm password'); ?><!--">-->
  </div>
  <div class="col-xs-12 modal-registration-item">
    <?php print render($form['field_language']); ?>
<!--    <input type="text" id="user-register-custom-language" class="form-control modal-registration-form" placeholder="--><?php //print t('Native language'); ?><!--">-->
  </div>
  <div class="col-xs-12 modal-registration-item">
    <div class="checkbox modal-confirm-check">
      <?php print render($form['field_agreement']); ?>
    </div>
  </div>
  <div class="col-xs-12 modal-registration-item">
    <div class="col-xs-8 col-xs-offset-1 modal-registration-button">
      <a class="button-pay registration-button">
        <?php print t('Sign up'); ?>
      </a>
    </div>
  </div>
</div>

<div class="element-hidden">
  <?php print drupal_render_children($form);?>
</div>
