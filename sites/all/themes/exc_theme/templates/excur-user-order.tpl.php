<div class="row">
  <div class="span3">
    <?php print $user_menu; ?>
  </div>
  <div class="span9">
    <div class="tabbable">
      <ul class="nav nav-tabs">
        <li class="active"><a href="#pane1" data-toggle="tab"><?php print t('Confirmed'); ?></a></li>
        <li><a href="#pane2" data-toggle="tab"><?php print t('Not confirmed');?></a></li>
        <li><a href="#pane3" data-toggle="tab"><?php print t('Rejected');?></a></li>
        <li><a href="#pane4" data-toggle="tab"><?php print t('Archive');?></a></li>
      </ul>
      <div class="tab-content">
        <div id="pane1" class="tab-pane active">
          <?php print render($confirmed); ?>
        </div>
        <div id="pane2" class="tab-pane">
          <?php print render($not_confirmed); ?>
        </div>
        <div id="pane3" class="tab-pane">
          <?php print render($rejected); ?>
        </div>
        <div id="pane4" class="tab-pane">

        </div>
      </div>
    </div>
  </div>
</div>
