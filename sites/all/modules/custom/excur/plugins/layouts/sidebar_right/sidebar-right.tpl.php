<?php
/**
 * @file
 *
 * Template (admin) for the ob-glossary layout.
 */
?>
<?php if (!empty($content['top'])) : ?>
  <div class="row">
    <div class="span12">
      <?php print $content['top']; ?>
    </div>
  </div>
<?php endif; ?>

<div class="row">
  <div class="span9">
    <?php if (!empty($content['content_center'])) : ?>
      <?php print $content['content_center']; ?>
    <?php endif; ?>
  </div>
  <div class="span3">
    <?php if (!empty($content['content_left'])) : ?>
      <?php print $content['content_left']; ?>
    <?php endif; ?>
  </div>
</div>
