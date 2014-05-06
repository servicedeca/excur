<?php if (!empty($blocks)): ?>
  <div id="main-text-blocks">
    <h2>
      <?php print t('Advantages');?>
    </h2>
    <?php foreach($blocks as $block): ?>
      <div class="text-block">
        <?php print $block; ?>
      </div>
    <?php endforeach; ?>
  </div>
<?php endif; ?>
