<?php hide($form['step_1']['language']); ?>
<?php hide($form['actions']); ?>
<?php print drupal_render_children($form);?>
<?php print render($form['actions']); ?>