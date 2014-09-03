<?php if (!empty($guides)): ?>
  <div class="row">
    <div class="span3">
      <h2><?php print t('Popular guides'); ?></h2>
    </div>
  </div>
  <?php foreach ($guides as $id => $guide): ?>
    <div class="row popular-guide">
      <div class="span1 img-border">
        <?php print $guide['image']; ?>
      </div>
      <div class="span2">
        <div class="title">
          <h3><?php print $guide['title']; ?></h3>
        </div>
        <div class="city">
          <?php print $guide['city']; ?>
        </div>
      </div>
    </div>
    <div class="space20"></div>
  <?php endforeach; ?>
<?php endif; ?>
