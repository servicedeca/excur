<?php
/**
 * @file.
 */
?>
<div class="col-xs-12 excur-comment">
  <div class="col-xs-2 excur-comment-item">
    <?php print render($user_image) ?>
    <p><?php print $name ?></p>
  </div>
  <div class="col-xs-10">
    <div class="excur-comment-body">
      <div class="excur-coment-head">
        <?php if (!empty($service_rating)): ?>
          <span class="rating">
            <span class="rating-excur"><?php print $service_rating; ?>
            </span>
            <?php print t('Excursion'); ?>
          </span>
        <?php endif; ?>
        <?php if (!empty($guide_rating)): ?>
          <span class="rating">
            <span class="rating-guide"><?php print $guide_rating; ?>
            </span><?php print t('Guide'); ?>
          </span>
        <?php endif; ?>
        <div class="excur-comment-date"><?php print $date ?>
        </div>
      </div>
      <?php print $comments?>
    </div>
  </div>
</div>
