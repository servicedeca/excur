<?php if (!empty($blocks)): ?>
  <section id="about" data-speed="2" data-type="background" class="hidden-sm hidden-xs" style="background-position: 50% -689px;">
    <h2 class="about-title">
      <?php print t('Benefits'); ?>
    </h2>
    <div class="container">
      <?php foreach ($blocks as $text): ?>
        <div class="col-xs-6 wp5 delay-05s animated fadeInUp">
          <div class="row padiconleft">
            <div class="col-xs-10 col-xs-offset-1 bord1 textmid">
              <?php print $text; ?>
            </div>
          </div>
        </div>
      <?php endforeach; ?>
    </div>
  </section>
<?php endif; ?>
