<?php

/**
 * @file
 */
?>
<section id="services">
  <div class="container padbot">
    <h2 class="service-title">
      <?php print t('Destinations'); ?>
    </h2>
    <div class="index-line">
    </div>
    <div class="container">
      <div class="row">
        <?php foreach ($rows as $id => $row): ?>
          <div class="col-sm-4  portfolio-item">
            <a href="<?php print url('taxonomy/term/' . $tid[$id]); ?>">
              <div class="caption text-center">
                <p class="name_cont">
                  <?php print $title[$id]; ?>
                </p>
              </div>
              <div class="hover panel">
                <div class="front">
                  <?php print $image[$id][0]; ?>
                </div>
                <div class="back">
                  <?php print $image[$id][1]; ?>
                </div>
              </div>
            </a>
          </div>
        <?php endforeach; ?>
      </div>
    </div>
  </div>
</section>
