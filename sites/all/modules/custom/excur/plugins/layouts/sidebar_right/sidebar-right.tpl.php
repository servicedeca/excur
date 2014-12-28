<?php
/**
 * @file
 *
 * Template (admin) for the ob-glossary layout.
 */
?>
<div class="bg_parralax topline" data-type="background" data-speed="10" style="background-position: 50% 0px;">
  <div class="continent-name"></div>
</div>
<div class="bgf">
  <?php if (!empty($content['breadcrumb'])) : ?>
    <?php print $content['breadcrumb']; ?>
  <?php endif; ?>
  <div class="excur-body">
    <?php if (!empty($content['top'])) : ?>
      <?php print $content['top']; ?>
    <?php endif; ?>
    <?php if (!empty($content['content_center'])) : ?>
      <div class="col-xs-9 padding">
        <?php print $content['content_center']; ?>
      </div>
    <?php endif; ?>
    <?php if (!empty($content['content_right'])) : ?>
      <div class="col-xs-3 padding">
        <?php print $content['content_right']; ?>
      </div>
    <?php endif; ?>
  </div>
</div>
