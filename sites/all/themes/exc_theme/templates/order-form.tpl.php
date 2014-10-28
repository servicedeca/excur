<div class="span3">
  <div class="panel panel-default">
    <div class="panel-heading">
      <h2>
        <?php print t('Your contact details');?>
      </h2>
    </div>
    <div class="panel-body">
      <?php print render($form['name']);?>
      <?php print render($form['email']);?>
      <?php print render($form['phone']);?>
    </div>
  </div>
</div>
<div class="span3">
  <div class="panel panel-default">
    <div class="panel-heading">
      <h2>
        <?php print t('The contact details of the tourist'); ?>
      </h2>
    </div>
    <div class="panel-body">
      <?php print render($form['tourist_name']);?>
      <?php print render($form['tourist_email']);?>
      <?php print render($form['tourist_phone']);?>
    </div>
  </div>
</div>
<div class="span3">
  <div class="panel panel-default">
    <div class="panel-heading">
      <h2>
        <?php print t('Parameters of your order'); ?>
      </h2>
    </div>
    <div class="panel-body">
      <?php print render($form['venue']); ?>
      <?php print render($form['time']); ?>
      <?php print render($form['language']); ?>
    </div>
  </div>
</div>
<div class="element-hidden">
  <?php print drupal_render_children($form); ?>
</div>
