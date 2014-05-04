<?php if (!empty($images)): ?>
  <ul id="main-slider" class="slides">
    <?php foreach($images as $image): ?>
      <li>
        <?php print $image; ?>
      </li>
    <?php endforeach; ?>
  </ul>
<?php endif; ?>
