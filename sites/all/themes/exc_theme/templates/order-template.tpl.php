<?php
/*var_dump($order);
var_dump($node);*/?>
<div style="width:800px; height:440px;">
  <h1><?php print $offer['title'];?></h1>
    <div style="width:320px; height:220px;position:absolute;" >
      <?php print render($image);?>
    </div>
    <div style="width:320px; height:170px;margin-top:220px;position:absolute;" >
      <h3><b>Ваш гид:</b></h3>
      <?php print render($guide_image);?>
      <?php print $offer['guide_name'];?>
    </div>
    <div style="width:480px; height:390px;margin-left:320px;position:absolute;">
      <h2><?php print $offer['offer'];?></h2>
     <div style=" width:480px; height:300px;margin-left:0px;position:absolute;margin-top:0px;"></div>
      <h3 style="padding: 5px 0;"><b><?php print t('Number')?>:</b>&nbsp<?php print $offer['id'];?></h3>
      <h3 style="padding: 5px 0;"><b><?php print t('Date')?>:</b>&nbsp<?php print $offer['date'];?></h3>
      <h3 style="padding: 5px 0;"><b>Продолжительность:</b>&nbsp<?php print $offer['duration'];?></h3>
      <h3 style="padding: 5px 0;"><b>Место:</b>&nbsp<?php print $offer['city_name'];?> <?php print $offer['country_name'];?></h3>
      <h3 style="padding: 5px 0;"><b>Тип билета:</b>&nbsp<?php print $offer['ticket_type'] ?></h3>
      <h3 style="padding: 5px 0;"><b>Цена:</b>&nbsp<?php print $offer['price'] ?>
      <?php print $offer['currency'] ?></h3>
    </div>

</div>


<?php print render($form);?>