<?php if ($show_header): ?>
<div class="bg_parralax topline" data-type="background" data-speed="10" style="background-position: 50% 0px;">
  <div class="continent-name"></div>
</div>
<?php endif; ?>
<section class="bread-crumbsleft"></section>
<section class="bread-crumbsright"></section>
<section class="bread-crumbs-content">
  <div class="col-xs-4 bread-crumbs-mainland">
    <div id="dd-cont" class="wrapper-dropdown-cont" tabindex="1">
      <div class="bread-crumbs-name">
        <?php print $continent; ?>
      </div>
      <ul class="dropdown">
        <?php foreach ($continents as $continent): ?>
          <li>
            <?php print $continent; ?>
          </li>
        <?php endforeach; ?>
      </ul>
    </div>
    <div class="crumbs-mainland-icon">
    </div>
  </div>
  <div class="col-xs-4 bread-crumbs-country arrow-country">
    <div id="dd-country" class="wrapper-dropdown-country" tabindex="1">
      <div class="bread-crumbs-name-main">
        <?php print $country; ?>
      </div>
      <ul class="dropdown">
        <?php foreach ($countries as $country): ?>
          <li>
            <?php print $country; ?>
          </li>
        <?php endforeach; ?>
      </ul>
    </div>
  </div>
  <div class="col-xs-4 bread-crumbs-city">
    <div id="dd-city" class="wrapper-dropdown-city" tabindex="1">
      <div class="bread-crumbs-name">
        <?php print $city; ?>
      </div>
      <ul class="dropdown">
        <?php foreach ($cities as $city): ?>
          <li>
            <?php print $city; ?>
          </li>
        <?php endforeach; ?>
      </ul>
    </div>
  </div>
</section>
