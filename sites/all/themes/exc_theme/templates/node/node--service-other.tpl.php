<?php

/**
 * @file
 */
?>
<article id="node-<?php print $node->nid; ?>">
  <div class="side-block">
    <?php print $title ?>
    <div class="space10"></div>
    <?php print render($image); ?>
    <div class="space10"></div>
    <?php print t('Price')?>
    <?php print $price ?>
  </div>
</article>
