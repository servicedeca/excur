<div class="booking-card">
  <div class="row">
    <?php if (!empty($image)): ?>
      <div class="span2 booking-card-image">
        <?php print $image; ?>
      </div>
    <?php endif; ?>
    <div class="span4 booking-card-body">
      <h2>
        <?php print $title;?>
      </h2>
      <h3>
        <i class="fa fa-th-list"></i>
        <b><?php print t('Order number') . ': '; ?></b>
        <?php print $id;?>
      </h3>
      <h3>
        <i class="fa fa-calendar"></i>
        <b><?php print t('Date') . ': '; ?></b>
        <?php print $data; ?>
      </h3>
      <div class="booking-card-guide-name">
        <?php print $guide; ?>
      </div>
      <div class="img-circle booking-card-guide">
        <?php print $guide_image;?>
      </div>
    </div>
    <div class="span3 booking-card-status">
      <p class="booking-card-status-inner">
        <?php print $status; ?>
      <p>
      <div class="tag booking-card-button">
        <?php print $details; ?>
      </div>
    </div>
  </div>
</div>
<div class="space20"></div>
