<?php

/**
 * @file
 */
?>

<section class="pop-excur">
  <div class="pop-excur-content">
    <h1 class="pop-title title-country">
      <?php print t('Most popular excursions'); ?>
    </h1>
    <h2 class="pop-title-prefix">
      <?php print $country; ?>
    </h2>
    <div id="owl-demo" class="owl-carousel owl-theme">
      <?php foreach ($rows as $id => $row): ?>
        <div class="item">
          <?php print $row; ?>
        </div>
      <?php endforeach; ?>
    </div>
  </div>
</section>
