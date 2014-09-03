<div class="row-fluid order-template-content-background">
  <div class="span12 order-template-title">
    <h1><?php print $offer['title'];?></h1>
  </div>
  <div class="row-fluid">
    <div class="span5 order-template-image">
      <?php print render($image);?>
    </div>
    <div class="span4 order-template-info">
      <h2><?php print $offer['offer'];?></h2>
      <h3><i class="fa fa-th-list"></i>&nbsp<b><?php print t('Order number');?>:</b>&nbsp<?php print $offer['id'];?></h3>
      <h3><i class="fa fa-calendar"></i>&nbsp<b><?php print t('Date');?>:</b>&nbsp<?php print $offer['date'];?></h3>
      <h3><i class="fa fa-clock-o"></i>&nbsp<b><?php print t('Duration');?>:</b>&nbsp<?php print $offer['duration'];?></h3>
      <h3><i class="fa fa-map-marker">&nbsp&nbsp</i><b><?php print $offer['city_name'];?> <?php print $offer['country_name'];?></h3>
    </div>
    <div class="span3 order-template-gid">
      <div class="pane-content">
        <div class="side-block guide-block">
          <?php print render($guide_image);?>
          <h2 class="order-template-gid-name"><?php print $offer['guide_name'];?></h2>
        </div>
      </div>
    </div>
  </div>
</div>
<?php print render($form);?>
	<div class="order-template-ticket">
        <div class="side-block">
          <div class="do-offer do-offer-pay">
            <div class="price">
              <strong>
                <h3><b><?php print t('Type of ticket');?>:</b>&nbsp<?php print $offer['ticket_type'] ?></h3>
                <h2><b><?php print t('Price');?>:</b>&nbsp<?php print $offer['price'] ?>
                  <?php print $offer['currency'] ?></h2>
              </strong>
            </div>
          </div>
        </div>
      </div>  