<?php if($rating_widget && $rating_widget_guide): ?>
  <?php print t('Rating services'); ?>
  <?php print render($rating_widget) ?>
  <?php print t('Rating guide'); ?>
  <?php print render($rating_widget_guide) ?>
<?php endif?>
<?php  print render($content['comments']) ?>
<?php  print render($content['comment_form']) ?>
