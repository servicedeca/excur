<?php

/**
 * @file
 */
?>

<div class="row">
  <div class="span9">
    <h2>
      <?php print t('Cities'); ?>
    </h2>
  </div>
</div>
<div class="row">
  <?php foreach ($rows as $id => $row): ?>
    <div class="span2">
      <?php print $row; ?>
    </div>

    <?php if (($id + 1) % 24 == 0): ?>
      <div class="space20"></div>
    <?php endif; ?>
  <?php endforeach; ?>
</div>
