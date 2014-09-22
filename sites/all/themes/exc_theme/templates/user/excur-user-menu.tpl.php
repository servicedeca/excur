<ul class="nav nav-tabs nav-stacked">
  <?php foreach($menu as $item): ?>
    <li>
      <?php print $item ?>
    </li>
  <?php endforeach; ?>
</ul>
<?php if(!empty($guide)):?>
  <div class="side-block">
    <?php print render($guide); ?>
  </div>
<?php endif ?>
<?php if(!empty($partner)):?>
  <div class="side-block">
    <?php print render($partner); ?>
  </div>
<?php endif ?>