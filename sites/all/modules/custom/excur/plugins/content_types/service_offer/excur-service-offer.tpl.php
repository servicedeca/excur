<?php if (!empty($offers)): ?>
  <div class="offers">
    <?php foreach($offers as $offer): ?>
      <?php print render($offer); ?>
    <?php endforeach; ?>
  </div>
<?php endif; ?>
