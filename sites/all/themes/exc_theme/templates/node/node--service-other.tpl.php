<?php

/**
 * @file
 */
?>
<article id="node-<?php print $node->nid; ?>">
  <div class="side-block">
    <div class="row">
      <?php print $title ?>
    </div>
    <div class="row">
      <?php print render($image); ?>
    </div>
    <div class="row">
      <?php print t('price')?>
      <?php print $price ?>
    </div>
  </div>
</article>
