<div id="comment_rating">
  <?php if (!empty($comments)): ?>
    <?php print $comments; ?>
  <?php endif ?>
  <?php if (!empty($form)): ?>
    <?php print t('To write a comment, please enter the ticket number.');?>
    <?php print $form; ?>
  <?php endif ?>
  <?php if(!empty($login)): ?>
  <div class="offer-login">
    <?php print $login; ?>
  </div>
  <?php endif ?>
</div>
