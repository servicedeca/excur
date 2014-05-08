<?php

/**
 * @file
 * Default simple view template to display a list of rows.
 *
 * @ingroup views_templates
 */
?>
<div class="row">
  <?php foreach ($rows as $id => $row): ?>
    <div class="span4">
      <?php print $row; ?>
    </div>
    <?php if (($id + 1) % 3 == 0): ?>
      <div class="space20"></div>
    <?php endif; ?>
  <?php endforeach; ?>
</div>
