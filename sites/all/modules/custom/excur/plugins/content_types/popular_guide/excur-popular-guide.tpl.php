<?php if (!empty($guides)): ?>
  <section class="pop-gid">
    <h3 class="pop-title title-country">
      <?php print t('Popular guides'); ?>
    </h3>
    <div class="pop-gid-content">
      <div class="col-xs-1">
      </div>
      <?php foreach ($guides as $id => $guide): ?>
        <div class="col-xs-2">
          <?php print $guide['image']; ?>
          <div class="pop-gid-name">
            <?php print $guide['title']; ?>
          </div>
          <div class="pop-gid-city">
            <?php print $guide['city']; ?>
          </div>
          <div class="pop-gid-star">
            <?php print $icon_star; ?>
            <?php print $guide['rating']; ?>
          </div>
        </div>
      <?php endforeach; ?>
    </div>
  </section>
<?php endif; ?>
