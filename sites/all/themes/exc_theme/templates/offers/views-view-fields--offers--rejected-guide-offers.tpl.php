<div class="booking-card">
  <div class="row">
    <?php if (!empty($image)): ?>
      <div class="span2 booking-card-image">
        <?php print $image; ?>
      </div>
    <?php endif; ?>
    <div class="span3 booking-card-body">
      <h2>
        <?php print $title; ?>
      </h2>
      <h3>
        <i class="fa fa-th-list"></i>
        <b><?php print t('Order number') . ': '; ?></b>
        <?php print $id; ?>
      </h3>
      <h3>
        <i class="fa fa-calendar"></i>
        <b><?php print t('Date') . ': '; ?></b>
        <?php print $date; ?>
      </h3>
    </div>
    <div class="span4 booking-card-status">
      <?php print $fields['status']->content; ?>
      <div class="tag order-card-button">
        <?php print $details; ?>
      </div>
    </div>
  </div>
</div>
<div class="space20"></div>
