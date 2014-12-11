<?php if (!empty($categories)): ?>
  <h3 class="pop-title title-city">
    <?php print t('Excursions in') . ' ' . $city; ?>
  </h3>

  <section class="excur-list-category">
    <?php foreach ($categories as $category): ?>
      <div class="col-xs-2 category-item">
        <a id="category-<?php print $category['id']; ?>" href="#">
          <div class="col-xs-12 category-item-icon">
            <?php print $category['icon']; ?>
          </div>
          <div class="col-xs-12 category-item-name">
            <div class=" category-item-border">
              <?php print $category['name']; ?>
            </div>
          </div>
        </a>
      </div>
    <?php endforeach; ?>
    <a id="category-0" href="#">
      <div class="col-xs-12 categiry-item-all">
        <?php print t('Show all excursions'); ?>
      </div>
    </a>
  </section>
<?php endif; ?>
