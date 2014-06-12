<?php if (!empty($blocks)): ?>
  <div class="row">
    <?php foreach($blocks as $id => $block): ?>
      <div class="advantages-text-block span4 ">
        <?php print $block; ?>
      </div>
      <?php if (($id + 1) % 3 == 0): ?>
        <div class="space20"></div>
      <?php endif; ?>
    <?php endforeach; ?>
  </div>
  <div class="space30"></div>
<?php endif; ?>
