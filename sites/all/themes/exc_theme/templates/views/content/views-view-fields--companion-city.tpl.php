<div class="span2 side-block">
  <div>
    <?php print render($image); ?>
  </div>
  <div>
    <?php print render($title); ?>
  </div>
  <div>
    <?php print t('From') . ' ' . $price; ?>
    <?php print $currency; ?>
  </div>
  <div>
    <i class="fa fa-language"></i>
    <?php print t('Languages') . ':'; ?>
    <?php foreach($languages as $lang):  ?>
      <i class="flag flag-<?php print $lang; ?>"></i>
    <?php endforeach; ?>
  </div>
</div>
