<?php if($show_tabs): ?>
  <ul id="guide-services-orders" class="nav nav-tabs" role="tablist">
    <li class="active"><a href="#guide-services"><?php print t('My services'); ?></a></li>
    <li><a href="#guide-orders"><?php print t('My orders'); ?></a></li>
  </ul>
  <div id="guide-services-ordersContent" class="tab-content">
    <div id="guide-services" class="tab-pane fade active in">
      <?php print $services; ?>
    </div>
    <div id="guide-orders" class="tab-pane fade">
      <?php print $orders; ?>
    </div>
  </div>
<?php else: ?>
  <?php print $services; ?>
<?php endif; ?>
