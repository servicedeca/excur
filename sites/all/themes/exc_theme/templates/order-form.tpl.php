<h2>
  <?php print t('Parameters of your order'); ?>
</h2>
<?php print render($form['venue']); ?>
<?php print render($form['language']); ?>

<h2>
  <?php print t('Your contact details');?>
</h2>
<?php print render($form['name']);?>
<?php print render($form['email']);?>
<?php print render($form['phone']);?>

<h2>
  <?php print t('The contact details of the tourist'); ?>
</h2>
<?php print render($form['tourist_name']);?>
<?php print render($form['tourist_email']);?>
<?php print render($form['tourist_phone']);?>

<?php print drupal_render_children($form); ?>
