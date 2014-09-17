<div class="tabbable">
  <ul class="nav nav-tabs">
    <li class="active"><a href="#pane1" data-toggle="tab"><?php print t('General'); ?></a></li>
    <li><a href="#pane2" data-toggle="tab"><?php print t('Change Password');?></a></li>
    <li><a href="#pane3" data-toggle="tab"><?php print t('Message settings')?></a></li>
    <li><a href="#pane4" data-toggle="tab"></a></li>
  </ul>
  <div class="tab-content">
    <div id="pane1" class="tab-pane active">
      <?php hide($form['account']['pass']); ?>
      <?php hide($form['account']['current_pass'])?>
      <?php hide($form['locale']); ?>
      <?php hide($form['timezone']); ?>
      <?php hide($form['privatemsg']);?>
      <?php hide($form['actions']);?>
      <div class="span3">
        <?php print render($form['field_image']);?>
      </div>
      <div class="span5">
        <?php hide($form['guide']);?>
        <?php hide($form['field_image']);?>
        <?php print render($form['account']['name']);?>
        <?php print render($form['account']['mail']);?>
        <?php print render($form['field_name']);?>
        <?php print render($form['field_city']);?>
        <?php print render($form['field_language']);?>
        <?php print render($form['field_languages']);?>
        <?php print render($form['field_description']);?>
        <?php print render($form['field_birthday']);?>
        <?php print render($form['field_phone']);?>
        <?php print drupal_render_children($form);?>
      </div>
      <div class="span8">
        <?php print render($form['guide']);?>
      </div>
    </div>
    <div id="pane2" class="tab-pane">
      <?php print render($form['account']['current_pass'])?>
      <?php print render($form['account']['pass'])?>
    </div>
    <div id="pane3" class="tab-pane">
      <?php print render($form['privatemsg']);?>
    </div>
    <div id="pane4" class="tab-pane">

    </div>
    <div class="span8">
      <?php print render($form['actions']['submit']);?>
      <?php print render($form['actions']['cancel']);?>
     </div>
  </div>
</div>
