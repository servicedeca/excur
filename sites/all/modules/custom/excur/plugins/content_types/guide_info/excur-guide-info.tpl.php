<div class="side-block guide-block">
  <?php print $guide_image; ?>
  <div class="name">
    <?php print $guide; ?>
  </div>
  <div class="guide-rating">
    <?php print $rating; ?>
  </div>
  <?php if (!empty($city)): ?>
    <p>
      <i class="fa fa-map-marker"></i>
      <?php print $city; ?>
    </p>
  <?php endif; ?>
  <?php if (!empty($certified)): ?>
    <p class="certified">
      <i class="fa fa-thumbs-up"></i>
      <?php print $certified; ?>
    </p>
  <?php endif; ?>
  <p>
    <i class="fa fa-language"></i>
    <?php print t('Native language') . ': '; ?>
    <i class="flag flag-<?php print $language; ?>"></i>
  </p>
  <?php if (!empty($languages)): ?>
    <p>
      <i class="fa fa-language"></i>
      <?php print t('Available languages') . ': '; ?>
      <?php foreach($languages as $lang):  ?>
        <i class="flag flag-<?php print $lang; ?>"></i>
      <?php endforeach; ?>
    </p>
  <?php endif; ?>
</div>
