<?php if (!empty($blocks)): ?>
  <div id="main-text-blocks">
    <h2>
      <?php print t('Advantages');?>
    </h2>
    <?php foreach($blocks as $block): ?>
      <div class="text-block">
        <div class="text-block-title">
          <?php print $block['title']; ?>
        </div>
        <div class="text-block-text">
          <?php print $block['text']; ?>
        </div>
      </div>
    <?php endforeach; ?>
  </div>
<?php endif; ?>
