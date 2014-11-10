<div class="excur-offer-offer-form">
  <div class="head">
    <?php print $form['#data']['title']; ?>
  </div>
  <div class="details">
    <div class="row">
      <div class="span3 info">
        <?php print t('Duration') . ': ' . $form['#data']['duration']; ?>
      </div>
      <div class="span3 tickets">
        <?php print render($form['tickets']); ?>
        <?php if ($form['tickets']['#type'] == 'data'): ?>
          <div>
            <?php print t('Total price: ');?>
            <span class="total-price">0</span>
            <?php print $form['#data']['currency']; ?>
          </div>
        <?php endif; ?>
      </div>
      <div class="span3">
        <?php print render($form['date']); ?>
      </div>
    </div>
  </div>
  <div class="row">
    <div class="span7"></div>
    <div class="span2 right">
      <?php print render($form['submit']); ?>
    </div>
  </div>
  <div class="element-hidden">
    <?php print drupal_render_children($form); ?>
  </div>
</div>
