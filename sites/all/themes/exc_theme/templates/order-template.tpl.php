<div class="row">
  <div class="span12">
    <h1><?php print $offer['title']; ?></h1>
  </div>
  <?php if (!empty($image)): ?>
    <div class="span5 order-template-image">
      <?php print render($image); ?>
    </div>
    <div class="span4 order-template-info well">
      <h2>
        <?php print $offer['offer']; ?>
      </h2>
      <h3>
        <i class="fa fa-th-list"></i>
        <b><?php print t('Order number') . ': '; ?></b>
        <?php print $offer['id']; ?>
      </h3>
      <h3>
        <i class="fa fa-calendar"></i>
        <b><?php print t('Date') . ': '; ?></b>
        <?php print $offer['date']; ?>
      </h3>
      <h3>
        <i class="fa fa-clock-o"></i>
        <b><?php print t('Duration') . ': '; ?></b>
        <?php print $offer['duration']; ?>
      </h3>
      <h3>
        <i class="fa fa-map-marker"></i>
        <?php print $offer['city_name']; ?>
        <?php print $offer['country_name']; ?>
      </h3>
    </div>
  <?php else: ?>
    <div class="span4 order-template-info well">
      <h2>
        <?php print $offer['offer']; ?>
      </h2>
      <h3>
        <i class="fa fa-th-list"></i>
        <b><?php print t('Order number') . ': '; ?></b>
        <?php print $offer['id']; ?>
      </h3>
      <h3>
        <i class="fa fa-calendar"></i>
        <b><?php print t('Date') . ': '; ?></b>
        <?php print $offer['date']; ?>
      </h3>
      <h3>
        <i class="fa fa-clock-o"></i>
        <b><?php print t('Duration') . ': '; ?></b>
        <?php print $offer['duration']; ?>
      </h3>
      <h3>
        <i class="fa fa-map-marker"></i>
        <?php print $offer['city_name']; ?>
        <?php print $offer['country_name']; ?>
      </h3>
    </div>
    <div class="span5 order-template-image"></div>
  <?php endif; ?>
  <div class="span3 order-template-gid">
    <div class="pane-content">
      <div class="side-block guide-block">
        <?php print render($guide_image); ?>
        <div class="name">
          <?php print $offer['guide_name'];; ?>
        </div>
      </div>
    </div>
  </div>
</div>
<div class="space30"></div>
<div class="row">
  <?php print render($form); ?>
  <div class="span3">
    <div class="price well">
      <h3>
        <b><?php print t('Tickets') . ': '; ?></b>
        <?php foreach ($tickets as $ticket): ?>
          <br />
          <?php print $ticket; ?>
        <?php endforeach; ?>
      </h3>
      <h3>
        <b><?php print t('Price') . ': '; ?></b>
        <?php print $offer['price']; ?>
        <?php print $offer['currency']; ?>
      </h3>
    </div>
    <div>
      <button id="excur-offer-order" class="btn">
        <?php print t('Reserve'); ?>
      </button>
    </div>
  </div>
</div>
