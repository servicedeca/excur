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
<div class="row">
  <div class="span3">
    <?php foreach ($rows as $id => $row): ?>
      <div<?php if ($classes_array[$id]) { print ' class="' . $classes_array[$id] .'"';  } ?>>
        <?php print $row; ?>
      </div>
    <?php endforeach; ?>
  </div>
</div>