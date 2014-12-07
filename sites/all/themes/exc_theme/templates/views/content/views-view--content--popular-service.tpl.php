<?php

/**
 * @file
 */
?>

<?php if ($attachment_before): ?>
  <div class="attachment attachment-before">
    <?php print $attachment_before; ?>
  </div>
<?php endif; ?>

<?php if ($rows): ?>
  <div class="view-content">
    <?php print $rows; ?>
  </div>
<?php elseif ($empty): ?>
  <div class="view-empty">
    <?php print $empty; ?>
  </div>
<?php endif; ?>
