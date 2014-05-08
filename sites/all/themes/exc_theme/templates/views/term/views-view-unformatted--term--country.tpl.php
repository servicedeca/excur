<?php

/**
 * @file
 * Default simple view template to display a list of rows.
 *
 * @ingroup views_templates
 */
?>
<div class="row">
  <div class="span12">
    <h2>
      <?php print t('Countries'); ?>
    </h2>
  </div>
</div>
<div class="row">
  <?php foreach ($rows as $id => $row): ?>
    <div class="span2">
      <?php print $row; ?>
    </div>
  <?php endforeach; ?>
</div>
