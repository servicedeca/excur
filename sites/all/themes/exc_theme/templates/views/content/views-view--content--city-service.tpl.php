<?php

/**
 * @file
 */
?>
<div class="<?php print $classes; ?>">
<?php print render($title_prefix); ?>
<h2><?php print t('Services'); ?></h2>
<?php print render($title_suffix); ?>
<?php if ($header): ?>
  <div class="view-header">
    <?php print $header; ?>
  </div>
<?php endif; ?>

<?php if ($exposed): ?>
  <div class="view-filters">
    <?php print $exposed; ?>
  </div>
<?php endif; ?>

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

<?php if ($pager): ?>
  <?php print $pager; ?>
<?php endif; ?>
</div>
