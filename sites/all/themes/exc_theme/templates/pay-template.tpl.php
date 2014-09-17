<div class="row order-template-content-background">
  <div class="span12 order-template-title">
    <h1><?php print $offer['title']; ?></h1>
  </div>
  <div class="row">
    <?php if (!empty($image)): ?>
      <div class="span5 order-template-image">
        <?php print render($image); ?>
      </div>
      <div class="span4 order-template-info">
        <h2><?php print $offer['offer']; ?></h2>

        <h3><i class="fa fa-th-list"></i>&nbsp<b><?php print t('Order number'); ?>:</b>&nbsp<?php print $offer['id']; ?>
        </h3>

        <h3><i class="fa fa-calendar"></i>&nbsp<b><?php print t('Date'); ?>:</b>&nbsp<?php print $offer['date']; ?></h3>

        <h3><i class="fa fa-clock-o"></i>&nbsp<b><?php print t('Duration'); ?>
            :</b>&nbsp<?php print $offer['duration']; ?></h3>

        <h3><i
            class="fa fa-map-marker">&nbsp&nbsp</i><b><?php print $offer['city_name']; ?> <?php print $offer['country_name']; ?>
        </h3>
      </div>
    <?php else: ?>
      <div class="span4 order-template-info">
        <h2><?php print $offer['offer']; ?></h2>

        <h3><i class="fa fa-th-list"></i>&nbsp<b><?php print t('Order number'); ?>:</b>&nbsp<?php print $offer['id']; ?>
        </h3>

        <h3><i class="fa fa-calendar"></i>&nbsp<b><?php print t('Date'); ?>:</b>&nbsp<?php print $offer['date']; ?></h3>

        <h3><i class="fa fa-clock-o"></i>&nbsp<b><?php print t('Duration'); ?>
            :</b>&nbsp<?php print $offer['duration']; ?></h3>

        <h3><i
            class="fa fa-map-marker">&nbsp&nbsp</i><b><?php print $offer['city_name']; ?> <?php print $offer['country_name']; ?>
        </h3>
      </div>
      <div class="span5 order-template-image"></div>
    <?php endif; ?>
    <div class="span3 order-template-gid">
      <div class="pane-content">
        <div class="side-block guide-block">
          <?php print render($guide_image); ?>
          <h2 class="order-template-gid-name"><?php print $offer['guide_name']; ?></h2>
        </div>
      </div>
    </div>
  </div>
</div>
<div class="row">
  <div class="span10 pay-template-content-bottom">
    <div class="row">
      <div class="span6 pay-template-content-form1">
        <div class="panel panel-default">
          <div class="panel-heading pay-h1">
            <h1>
              <?php print t('Your contact details'); ?>
            </h1>
          </div>
          <div class="panel-body">
            <h3><i class="fa fa-user"></i>&nbsp&nbsp<b><?php print t('Name'); ?>:</b>&nbsp<?php print $offer['name'] ?>
            </h3>

            <h3><i class="fa fa fa-envelope"></i>&nbsp<b><?php print t('E-mail'); ?>
                :</b>&nbsp<?php print $offer['email'] ?></h3>

            <h3>&nbsp<i class="fa fa-mobile"></i>&nbsp&nbsp<b><?php print t('Phone'); ?>
                :</b>&nbsp<?php print $offer['phone'] ?></h3>
          </div>
        </div>
      </div>
      <div class="span6 pay-template-content-form2">
        <div class="panel panel-default">
          <div class="panel-heading pay-h1">
            <h1>
              <?php print t('The contact details of the tourist'); ?>
            </h1>
          </div>
          <div class="panel-body">
            <h3><i class="fa fa-user"></i>&nbsp&nbsp<b><?php print t('Name'); ?>
                :</b>&nbsp<?php print $offer['tourist_name'] ?></h3>

            <h3><i class="fa fa fa-envelope"></i>&nbsp<b><?php print t('E-mail'); ?>
                :</b>&nbsp<?php print $offer['tourist_email'] ?></h3>

            <h3>&nbsp<i class="fa fa-mobile"></i>&nbsp&nbsp<b><?php print t('Phone'); ?>
                :</b>&nbsp<?php print $offer['tourist_phone'] ?></h3>
          </div>
        </div>
      </div>
    </div>
    <div class="row pay-template-paddingbot">
      <div class="span6 pay-template-content-form3">
        <div class="panel panel-default">
          <div class="panel-heading pay-h1">
            <h1>
              <?php print t('Parameters of your order'); ?>
            </h1>
          </div>
          <div class="panel-body">
            <h3><i class="fa fa-map-marker"></i>&nbsp&nbsp&nbsp<b><?php print t('Venue'); ?>
                :</b>&nbsp<?php print $offer['venue'] ?></h3>

            <h3><i class="fa fa-clock-o"></i>&nbsp&nbsp&nbsp<b><?php print t('Start time  '); ?>
                :</b>&nbsp<?php print $offer['time'] ?></h3>

            <h3><i class="fa fa-language"></i>&nbsp&nbsp<b><?php print t('Language'); ?>
                :</b>&nbsp<?php print $offer['language'] ?></h3>
          </div>
        </div>
      </div>
      <div class="span6 order-template-content-forms">
        <div class="side-block">
          <div class="do-offer do-offer-pay ">
            <div class="price">
              <strong>
                <h3><b><?php print t('Type of ticket'); ?>:</b>&nbsp<?php print $offer['ticket_type'] ?></h3>

                <h2>
                  <b><?php print t('Price'); ?>:</b>&nbsp<?php print $offer['price'] ?>
                  <?php print $offer['currency'] ?>
                </h2>
              </strong>
            </div>
          </div>
        </div>
        <?php print render($form); ?>
      </div>
    </div>
  </div>
</div>
