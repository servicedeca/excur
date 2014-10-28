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
  <div class="span3">
    <div class="panel panel-default">
      <div class="panel-heading">
        <h2>
          <?php print t('Your contact details'); ?>
        </h2>
      </div>
      <div class="panel-body">
        <h3>
          <i class="fa fa-user"></i>
          <b><?php print t('Name') . ': '; ?></b>
          <?php print $offer['name'] ?>
        </h3>
        <h3>
          <i class="fa fa fa-envelope"></i>
          <b><?php print t('E-mail') . ': '; ?></b>
          <?php print $offer['email'] ?>
        </h3>
        <h3>
          <i class="fa fa-mobile"></i>
          <b><?php print t('Phone') . ': '; ?></b>
          <?php print $offer['phone'] ?>
        </h3>
      </div>
    </div>
  </div>
  <div class="span3">
    <div class="panel panel-default">
      <div class="panel-heading">
        <h2>
          <?php print t('The contact details of the tourist'); ?>
        </h2>
      </div>
      <div class="panel-body">
        <h3>
          <i class="fa fa-user"></i>
          <b><?php print t('Name') . ': '; ?></b>
          <?php print $offer['tourist_name'] ?>
        </h3>
        <h3>
          <i class="fa fa fa-envelope"></i>
          <b><?php print t('E-mail') . ': '; ?></b>
          <?php print $offer['tourist_email'] ?>
        </h3>
        <h3>
          <i class="fa fa-mobile"></i>
          <b><?php print t('Phone') . ': '; ?></b>
          <?php print $offer['tourist_phone'] ?>
        </h3>
      </div>
    </div>
  </div>
  <div class="span3">
    <div class="panel panel-default">
      <div class="panel-heading">
        <h2>
          <?php print t('Parameters of your order'); ?>
        </h2>
      </div>
      <div class="panel-body">
        <h3>
          <i class="fa fa-map-marker"></i>
          <b><?php print t('Venue') . ': '; ?></b>
          <?php print $offer['venue'] ?>
        </h3>
        <h3>
          <i class="fa fa-clock-o"></i>
          <b><?php print t('Start time') . ': '; ?></b>
          <?php print $offer['time'] ?>
        </h3>
        <h3>
          <i class="fa fa-language"></i>
          <b><?php print t('Language') . ': '; ?></b>
          <?php print $offer['language'] ?>
        </h3>
      </div>
    </div>
  </div>
  <div class="span3">
    <div class="price well">
      <h3>
        <b><?php print t('Type of ticket') . ': '; ?></b>
        <?php print $offer['ticket_type'] ?>
      </h3>
      <h3>
        <b><?php print t('Price') . ': '; ?></b>
        <?php print $offer['price'] ?>
        <?php print $offer['currency'] ?>
      </h3>
    </div>
    <?php print render($form); ?>
  </div>
</div>
