<?php if (!empty($images)): ?>
  <div class="slider1 flexslider">
    <ul class="slides">
      <?php foreach($images as $image): ?>
        <li>
          <?php print $image; ?>
        </li>
      <?php endforeach; ?>
    </ul>

    <ul class="flex-direction-nav">
      <li>
        <a class="flex-prev" href="#"><?php print t('Previous'); ?></a>
      </li>
      <li>
        <a class="flex-next" href="#"><?php print t('Next'); ?></a>
      </li>
    </ul>
  </div>
  <div class="space30"></div>
  <?php if (!empty($text)): ?>
    <h1 id="text-special"><?php print $text; ?></h1>
    <div class="space20"></div>
  <?php endif; ?>
<?php endif; ?>
