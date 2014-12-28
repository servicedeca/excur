<?php

/**
 * @file
 */
?>
<a href="<?php print url("node/$node->nid"); ?>">
  <div class="other-excur-guide-item">
    <?php print render($image); ?>
    <div class="pop-excur-name">
      <?php print $title ?>
    </div>
    <?php if (!empty($currency) && !empty($price)):?>
      <div class="pop-excur-price other-excur-price">
        <?php print $price; ?>
        <span class="currency"><?php print $currency; ?></span>
      </div>
    <?php endif;?>
  </div>
</a>