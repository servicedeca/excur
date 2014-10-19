<div class="row comment-item">
  <div class="span1">
    <div class="comment-image">
      <?php print render($user_image) ?>
    </div>
  </div>
  <div class="span8 comment-content">
    <p class="comment-name">
      <?php print $name ?>
      <?php if (!empty($guide_rating)): ?>
        <span class="comment-ratings">
          <span>
            <?php print t('Guide mark') . ': '; ?>
          </span>
          <span class="rating-number">
            <?php print $guide_rating; ?>
          </span>
        </span>
      <?php endif; ?>
      <?php if (!empty($service_rating)): ?>
        <span class="comment-ratings">
          <span>
            <?php print t('Excursion mark') . ': '; ?>
          </span>
          <span class="rating-number">
            <?php print $service_rating; ?>
          </span>
        </span>
      <?php endif; ?>
    </p>
    <p>
      <?php print $date ?>
    </p>
    <p class="comment-text">
      <?php print $comments?>
    </p>
  </div>
</div>
