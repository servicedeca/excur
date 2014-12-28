<?php if (!empty($offers)): ?>
  <h3 id="excur-all-offers" class="col-xs-12 title-offer">
    <?php print t('All offers');?>
  </h3>
  <?php foreach($offers as $offer): ?>
    <?php print render($offer); ?>
  <?php endforeach; ?>
<?php endif; ?>
