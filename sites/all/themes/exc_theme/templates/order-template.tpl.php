<?php
/*var_dump($order);
var_dump($node);*/?>
<h1><?php print $offer['title'];?></h1>
<h2><?php print $offer['id'];?></h2>
<h2><?php print $offer['offer'];?></h2>
<h3><?php print $offer['date'];?></h3>
<h3><?php print $offer['duration'];?></h3>
<h3><?php print $offer['city_name'];?></h3>
<h3><?php print $offer['country_name'];?></h3>
<h3><?php print $offer['guide_image'];?></h3>
<h3><?php print $offer['guide_name'];?></h3>
<h3><?php print $offer['ticket_type'] ?></h3>
<h3><?php print $offer['price'] ?></h3>
<h3><?php print $offer['currency'] ?></h3>
<?php print render($image);?>
<?php print render($guide_image);?>
<h1> <?php print t('Parameters of your order'); ?></h1>
<?php print render($form);?>
<h1> <?php print t('Your contact details'); ?></h1>
<h1> <?php print t('The contact details of the tourist'); ?></h1>