  <div class="booking-card">
    <div class="row">
      <div class="span2 booking-card-image">
        <?php if (!empty($image)): ?>
          <?php print $image; ?>
        <?php endif; ?>
      </div>
      <div class="span4 booking-card-body">
        <h2><?php print $title;?></h2>
        <h3><i class="fa fa-th-list"></i>&nbsp<b><?php print t('Order number'); ?>:</b>&nbsp<?php print $id;?>
        </h3>
        <h3><i class="fa fa-calendar"></i>&nbsp<b><?php print t('Date'); ?>:</b>&nbsp<?php print $data; ?>
        </h3>
        <div class="booking-card-guide-name"><?php print $guide; ?></div>
        <div class="img-circle booking-card-guide"><?php print $guide_image;?> </div>
      </div>
      <div class="span3 booking-card-status">
        <p class="booking-card-status-inner"><?php print $status; ?><p>
        <div class="tag booking-card-button"><?php print $details; ?></div>
      </div>
    </div>
  </div>
<div class="space20"></div>
