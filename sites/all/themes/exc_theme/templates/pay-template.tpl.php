<div class="span3">
  <?php print render($image);?>
</div>
<div class="span5">
  <h1>
    <?php print $offer['title'];?>
  </h1>
</div>
<div class="span5">
  <h2>
   <?php print t('Order number');?> <?php print $offer['id'];?>
  </h2>
</div>
<div class="span5", id="guide_image">
  <?php print render($guide_image);?>
</div>
<div class="span5" id="guide_name">
  <?php print $offer['guide_name'];?>
</div>
<div class="space10">
  <h1>
    <?php print t('Parameters of your order'); ?>
  </h1>
</div>
<div class="span10">
  <h2><?php print $offer['language'];?></h2>
</div>
<h2><?php print $offer['offer'];?></h2>
<h3><?php print $offer['date'];?></h3>
<h3><?php print $offer['duration'];?></h3>
<h3><?php print $offer['city_name'];?></h3>
<h3><?php print $offer['country_name'];?></h3>

<h3><?php print $offer['ticket_type'] ?></h3>
<h3><?php print $offer['price'] ?></h3>
<h3><?php print $offer['currency'] ?></h3>
<h3><?php print $offer['venue'] ?></h3>
<h3><?php print $offer['name'] ?></h3>
<h3><?php print $offer['email'] ?></h3>
<h3><?php print $offer['phone'] ?></h3>
<h3><?php print $offer['tourist_name'] ?></h3>
<h3><?php print $offer['tourist_email'] ?></h3>
<h3><?php print $offer['tourist_phone'] ?></h3>
<?php print render($form);?>