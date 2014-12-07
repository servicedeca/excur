<?php

/**
 * @file
 */
?>

<a href="#">
  <?php print $image; ?>
</a>
<div class="pop-excur-row">
  <div class="col-xs-3 pop-excur-star">
    <?php print $icon_star; ?>
    <?php print $rating; ?>
  </div>
  <div class="col-xs-9 pop-excur-language">
    <?php foreach ($langs as $lang): ?>
      <i class="flag flag-<?php print $lang; ?>"></i>
    <?php endforeach; ?>
  </div>
</div>
<div class="pop-excur-name">
  <?php print $title; ?>
</div>
<div class="pop-excur-row-next">
  <div class="col-xs-6 pop-excur-time">
    <?php print $icon_time; ?>
    <?php print $duration; ?>
  </div>
  <div class="col-xs-6 pop-excur-gid">
    <div class="pop-excur-gid">
      <?php print t('Guide'); ?>
      <a href="<?php print $guide_url; ?>">
        <div class="pop-excur-gid-name">
          <?php print $guide; ?>
        </div>
      </a>
    </div>
  </div>
</div>
<div class="pop-excur-price">
  <?php print $price; ?>
  <span class="currency">
    <?php print $currency; ?>
  </span>
</div>
<?php print $read_more; ?>
