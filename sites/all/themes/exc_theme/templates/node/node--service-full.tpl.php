<?php

/**
 * @file
 */
?>
<article id="node-<?php print $node->nid; ?>" class="contextual-links-region">
  <?php print render($title_prefix); ?>
  <h1>
    <?php print $title; ?>
  </h1>
  <?php print render($title_suffix); ?>
  <?php if (!empty($images)): ?>
    <div class="fotorama" data-nav="thumbs" data-autoplay="true" data-keyboard="true" data-loop="true" data-swipe="true">
      <?php foreach($images as $image): ?>
        <?php print $image; ?>
      <?php endforeach; ?>
    </div>
  <?php endif; ?>
  <h2 class="node-description">
    <?php print t('Description'); ?>
  </h2>
  <?php hide($content['comments']); ?>
  <?php hide($content['links']); ?>
  <?php print render($content); ?>
  <h2 id="reservation" class="node-description">
    <?php print t('Reservation'); ?>
  </h2>
</article>
