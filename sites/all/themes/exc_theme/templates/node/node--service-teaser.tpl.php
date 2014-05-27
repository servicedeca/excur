<?php

/**
 * @file
 */
?>
<article id="node-<?php print $node->nid; ?>" class="contextual-links-region row">
  <?php print render($title_prefix); ?>
  <?php print render($title_suffix); ?>
  <div class="span2">
    <?php print render($content['field_image']); ?>
  </div>
  <div class="span6">
    <h3><?php print render($content['title_field']); ?></h3>
    <?php print render($content['body']); ?>
    <div class="read-more">
      <?php print $read_more; ?>
    </div>
    <div class="tag">
      <i class="fa fa-clock-o"></i>
      <?php print $content['field_duration']['#items'][0]['safe_value']; ?>
    </div>
    <div class="tag">
      <?php print t('From') . ' ' . $price; ?>
      <?php print $currency; ?>
    </div>
  </div>
  <div class="span1 guide">
    <div class="img-border">
      <?php print $guide['image']; ?>
    </div>
    <?php print $guide['title']; ?>
  </div>
</article>
