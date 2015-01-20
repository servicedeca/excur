<?php

/**
 * @file
 */
?>
<div class="col-xs-12 excur-list-content">
  <a href="<?php print url('node/' . $node->nid); ?>">
    <div class="col-xs-3 excur-list-image">
      <?php print render($content['field_image']); ?>
    </div>
  </a>
  <div class="col-xs-7 excur-list-infoblock">
    <div class="col-xs-10 excur-list-title">
      <a href="<?php print url('node/' . $node->nid); ?>">
        <div class="excur-list-name">
          <?php print $title; ?>
        </div>
      </a>
    </div>
    <div class="col-xs-4 excur-list-info">
      <?php if (!empty($rating)): ?>
        <div class="col-xs-12 excur-list-star">
          <?php print $icon_star; ?>
          <?php print $rating; ?>
        </div>
      <?php endif; ?>
      <div class="col-xs-12 excur-list-time">
        <?php print $icon_time; ?>
        <?php print $content['field_duration']['#items'][0]['safe_value']; ?>
      </div>
    </div>
    <div class="col-xs-8 excur-list-info">
      <a href="<?php print url('user/' . $guide['uid']); ?>">
        <div class="col-xs-4 excur-list-gid photo">
          <?php print $guide['image']; ?>
        </div>
        <div class="col-xs-4 excur-list-gid-name">
          <div class="pop-excur-gid">
            <?php print t('Guide'); ?>
            <div class="pop-excur-gid-name">
              <?php print $guide['title']; ?>
            </div>
          </div>
        </div>
      </a>
      <div class="col-xs-4 excur-list-lang">
        <div class="pop-excur-gid">
          <?php print t('Languages'); ?>
          <div class="pop-excur-gid-name">
            <?php foreach($languages as $lang):  ?>
              <i class="flag flag-<?php print $lang; ?>"></i>
            <?php endforeach; ?>
          </div>
        </div>
      </div>
    </div>
  </div>
  <div class="col-xs-2 excur-list-priceblock">
    <div class="col-xs-12 excur-list-price">
      <div class="excur-price">
        <?php print $price; ?>
        <span class="currency"><?php print $currency; ?></span>
      </div>
    </div>
    <div class="col-xs-12 excur-list-button">
      <a href="<?php print url('node/' . $node->nid); ?>" class="button-go">
        <?php print t('Book'); ?>
      </a>
    </div>
  </div>
</div>
