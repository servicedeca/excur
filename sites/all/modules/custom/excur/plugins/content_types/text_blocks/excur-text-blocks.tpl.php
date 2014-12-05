<section id="home" data-speed="4" data-type="background" class="hidden-sm hidden-xs z-index" style="background-position: 50% -375.75px;">
  <div class="container">
  </div>
</section>
<?php if (!empty($blocks)): ?>
  <section id="about" data-speed="2" data-type="background" class="hidden-sm hidden-xs" style="background-position: 50% -689px;">
    <h2 class="about-title">
      <?php print t('Benefits'); ?>
    </h2>
    <div class="container">
      <?php foreach ($blocks as $block): ?>
        <div class="col-xs-6 wp5 delay-05s animated fadeInUp">
          <div class="row padiconleft">
            <div class="col-xs-4 col-xs-offset-4 icon-item">
              <?php print $block['icon']; ?>
            </div>
            <div class="col-xs-10 col-xs-offset-1 bord1 textmid">
              <?php print $block['text']; ?>
            </div>
          </div>
        </div>
      <?php endforeach; ?>
    </div>
  </section>
<?php endif; ?>
