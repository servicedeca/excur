<?php

/**
 * @file
 */
?>
<div class="<?php print $classes; ?>">
  <?php if ($exposed): ?>
    <div class="view-filters">
      <?php print $exposed; ?>
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

  <?php if ($pager): ?>
    <div class="col-xs-12 navigation-bg">
      <?php print $pager; ?>
    </div>
  <?php endif; ?>
</div>
