<?php if($comments):?>
  <?php print $comments; ?>
<?php endif ?>
<?php if($form):?>
  <?php print t('To write a comment, please enter the ticket number.');?>
  <?php print $form; ?>
<?php endif ?>