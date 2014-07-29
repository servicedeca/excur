<?php if (!empty($cities)): ?>
  <div class="space30"></div>
  <div class="row">
    <div class="span9">
      <h2><?php print t('Popular cities'); ?></h2>
    </div>
  </div>
  <div class="row">
    <?php foreach($cities as $id => $city): ?>
      <div class="span4 popular-city">
        <?php print $city['image']; ?>
        <h3><?php print $city['title']; ?></h3>
        <ul>
          <li>
            <span class="service"><?php print $city['service']; ?></span>
            <?php print t('offers'); ?>
          </li>
          <li>
            <span class="guide"><?php print $city['guide']; ?></span>
            <?php print t('guides'); ?>
          </li>
        </ul>
      </div>
      <?php if (($id + 1) % 2 == 0): ?>
        <div class="space20"></div>
      <?php endif; ?>
    <?php endforeach; ?>
  </div>
<?php endif; ?>
