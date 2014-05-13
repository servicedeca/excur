<?php

/**
 * @file
 */
?>
<div class="row">
  <div class="span3">
    <h2><?php print t('Popular guides'); ?></h2>
  </div>
</div>
<?php foreach ($rows as $id => $row): ?>
  <div class="row">
    <?php print $row; ?>
  </div>
  <div class="space20"></div>
<?php endforeach; ?>
