<div class="side-block">
  <div class="info">
    <p>
      <i class="fa fa-map-marker"></i>
      <?php print $placement; ?>
    </p>
    <p>
      <i class="fa fa-clock-o"></i>
      <?php print $duration; ?>
    </p>
    <p>
      <i class="fa fa-language"></i>
      <?php print t('Languages') . ':'; ?>
      <?php foreach($languages as $lang):  ?>
        <i class="flag flag-<?php print $lang; ?>"></i>
      <?php endforeach; ?>
    </p>
  </div>
  <div class="do-offer">
    <div class="price">
      <strong>
        <?php print t('From') . ' ' . $price; ?>
        <?php print $currency; ?>
       </strong>
    </div>
    <button class="btn">
      <strong>
        <?php print t('Reserve'); ?>
      </strong>
    </button>
  </div>
</div>
