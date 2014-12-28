<?php
/**
 * @file
 */
?>
<div class="col-xs-12 excur-contacts">
  <?php if (!empty($city) && !empty($country)):?>
    <div class="col-xs-12 excur-contacts-item-item">
      <img src="<?php print file_create_url(EXCUR_FRONT_THEME_PATH . '/images/place.png');?>"  class="iconplace excur-contacts-iconplace">
      <span><?php print $city; ?></span>
      <div class="excur-contacts-city"><?php print $country; ?></div>
    </div>
  <?php endif; ?>
  <?php if (!empty($rating)):?>
    <div class="col-xs-12 excur-contacts-item">
      <?php if (!empty($rating_widget)): ?>
        <?php print $rating_widget; ?>
      <?php endif; ?>
      <img src="<?php print file_create_url(EXCUR_FRONT_THEME_PATH . '/images/star.png');?>" class="iconstar excur-contacts-icon">&nbsp;&nbsp;&nbsp;<?php print $rating; ?>
    </div>
  <?php endif; ?>
  <?php if (!empty($duration)):?>
    <div class="col-xs-12 excur-contacts-item">
      <img src="<?php print file_create_url(EXCUR_FRONT_THEME_PATH . '/images/time.png');?>" class="icont">&nbsp;&nbsp;&nbsp;<?php print $duration; ?>
    </div>
  <?php endif; ?>
  <?php if (!empty($languages)):?>
    <div class="col-xs-12 excur-contacts-itemnh">
      <?php foreach($languages as $lang):  ?>
        <img src="<?php print file_create_url(EXCUR_FRONT_THEME_PATH . '/images/blank.gif');?>" class="flag flag-<?php print $lang; ?>"/>
      <?php endforeach; ?>
    </div>
  <?php endif; ?>
  <?php if (!empty($price) && !empty($currency)):?>
    <div class="col-xs-12 excur-contacts-item-price">
      <div class="excur-contacts-price">
        <span class="currency"><?php print t('from');?></span>
        <?php print $price; ?>
        <span class="currency"> <?php print $currency; ?></span>
        <p class="prefix-excur-price"><?php print t('for a group');?></p>
      </div>
    </div>
  <?php endif; ?>
  <div class="col-xs-12 excur-contacts-button">
    <a href="#excur-all-offers" class="button-go" id="excur-order-button">
      <?php print t('Reserve'); ?>
    </a>
  </div>
</div>
