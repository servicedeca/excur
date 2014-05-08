<?php if (!empty($blocks)): ?>
  <div class="row">
    <div class="span12">
      <h2>
        <?php print t('Advantages');?>
      </h2>
    </div>
  </div>
  <div class="row">
    <?php foreach($blocks as $block): ?>
      <div class="advantages-text-block span3">
        <?php print $block; ?>
      </div>
    <?php endforeach; ?>
  </div>
  <div class="space30"></div>
<?php endif; ?>
