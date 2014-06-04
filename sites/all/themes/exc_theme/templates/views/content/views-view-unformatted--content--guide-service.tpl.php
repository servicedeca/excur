<?php

/**
 * @file
 */
?>
<?php foreach ($rows as $id => $row): ?>
  <?php print $row; ?>
  <?php if ($id != count($rows) - 1): ?>
    <hr>
  <?php endif; ?>
<?php endforeach; ?>
