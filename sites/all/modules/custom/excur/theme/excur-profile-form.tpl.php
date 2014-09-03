<div class="tabbable">
  <ul class="nav nav-tabs">
    <li class="active"><a href="#pane1" data-toggle="tab"><?php print t('General'); ?></a></li>
    <li><a href="#pane2" data-toggle="tab"><?php print t('Change Password');?></a></li>
    <li><a href="#pane3" data-toggle="tab"></a></li>
    <li><a href="#pane4" data-toggle="tab"></a></li>
  </ul>
  <div class="tab-content">
    <div id="pane1" class="tab-pane active">
      <?php hide($form['account']['pass']); ?>
      <?php hide($form['account']['current_pass'])?>
      <?php print drupal_render_children($form); ?>
    </div>
    <div id="pane2" class="tab-pane">
      <?php print render($form['account']['current_pass'])?>
      <?php print render($form['account']['pass'])?>
      <?php print render($form['actions']['submit'])?>
    </div>
    <div id="pane3" class="tab-pane">

    </div>
    <div id="pane4" class="tab-pane">

    </div>
  </div>
</div>
