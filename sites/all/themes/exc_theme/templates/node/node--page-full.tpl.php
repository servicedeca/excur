<?php

/**
 * @file
 */
?>
<div class="row">
  <div class="span12">
    <h1><?php print $title; ?></h1>
  </div>
  <div class="span3">
    <ul class="nav nav-tabs nav-stacked">
      <?php foreach($menu as $item): ?>
        <li>
          <?php print $item ?>
        </li>
      <?php endforeach; ?>
    </ul>
  </div>
  <div class="span9">
    <?php print render($content); ?>
  </div>
</div>
