<?php if (!empty($cities)): ?>
  <section class="pop-city">
    <h3 class="pop-title title-country">
      <?php print t('Popular cities'); ?>
    </h3>
    <?php foreach($cities as $id => $city): ?>
      <a href="<?php print $city['url']; ?>">
        <div class="col-xs-5 pop-city-item border-top">
          <div class="col-xs-5 pop-city-item-img">
            <?php print $city['image']; ?>
          </div>
          <div class="col-xs-7">
            <p class="pop-city-name">
              <?php print $city['title']; ?>
            </p>
            <p class="pop-city-info">
              <span class="numb">
                <?php print $city['service']; ?>
              </span>
              &nbsp;&nbsp;&nbsp;<?php print t('Offers'); ?>
            </p>
            <p class="pop-city-info">
              <span class="numb">
                <?php print $city['guide']; ?>
              </span>
              &nbsp;&nbsp;&nbsp;<?php print t('Guides'); ?>
            </p>
          </div>
        </div>
      </a>
    <?php endforeach; ?>
  </section>
<?php endif; ?>
