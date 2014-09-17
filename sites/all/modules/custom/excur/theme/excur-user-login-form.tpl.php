<?php print render($form['name'])?>
<?php print render($form['pass'])?>
<?php print l(t('Forgot your password?'),'user/password');?>
<?php print drupal_render_children($form);?>
