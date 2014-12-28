<?php
/**
 * @file.
 */
?>
<div class="col-xs-12 excur-offer-type ">
  <div class="col-xs-12 excur-offer-title"><?php print $form['#data']['title']; ?></div>
  <div class="col-xs-6 excur-offer-info">
    <p class="excur-offer-text">Каждый день с 18.00 до 20.00
    </p>
  </div>
  <div class="col-xs-6 excur-offer-info">
    <p class="excur-offer-text"><?php print t('Duration') . ' ' . $form['#data']['duration']; ?></p>
  </div>
  <?php print render($form['tickets']); ?>
  <?php if ($form['tickets']['#type'] == 'data'): ?>
    <div class="col-xs-12 excur-offer-item-sum">
      <div class="col-xs-4 col-xs-offset-5 excur-offer-item-sum-prefix">
        <?php print t('Total price: ');?>
      </div>
      <div class="col-xs-3 excur-offer-item-sum-inner">
        0
        <span class="currency white-curency">
          <?php print $form['#data']['currency']; ?>
        </span>
      </div>
    </div>
  <?php endif; ?>
  <div class="col-xs-8 excur-offer-date">
    <?php print render($form['date']); ?>
  </div>
  <div class="col-xs-4 excur-order-button">
    <?php print render($form['submit']); ?>
    <a href="#" class="button-go" id="excur-offer-button" data-toggle="modal" data-target=".bs-example">Забронировать</a>
  </div>
  <?php print drupal_render_children($form); ?>
</div>