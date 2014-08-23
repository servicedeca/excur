
<h1><?php print $offer['title'];?></h1>
<?php print render($image);?>
<?php print render($guide_image);?>
<?php print $offer['guide_name'];?>
<h2><?php print $offer['offer'];?></h2>
<?php print t('Number')?><?php print $offer['id'];?></h3>
<?php print t('Date')?><?php print $offer['date'];?></h3>
<?php print $offer['duration'];?></h3>
<?php print $offer['city_name'];?>
<?php print $offer['country_name'];?></h3>
<?php print $offer['ticket_type'] ?></h3>
<?php print $offer['price'] ?>
<?php print $offer['currency'] ?></h3>
<?php print render($form);?>