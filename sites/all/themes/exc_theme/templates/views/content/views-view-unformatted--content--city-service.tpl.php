<?php

/**
 * @file
 */
?>
<h2><?php print t('Services'); ?></h2>
<?php foreach ($rows as $id => $row): ?>
  <?php print $row; ?>
  <?php if ($id != count($rows) - 1): ?>
    <hr>
  <?php endif; ?>
<?php endforeach; ?>
