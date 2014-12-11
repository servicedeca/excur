<?php

/**
 * @file
 */
?>
<div class="container">
  <div class="col-xs-12 cont-list">
    <div class="col-xs-3">
      <ul>
        <?php foreach ($row_0 as $row): ?>
          <li>
            <?php print $row['icon']; ?>
            <?php print $row['title']; ?>
          </li>
        <?php endforeach; ?>
      </ul>
    </div>
    <div class="col-xs-3">
      <ul>
        <?php foreach ($row_1 as $row): ?>
          <li>
            <?php print $row['icon']; ?>
            <?php print $row['title']; ?>
          </li>
        <?php endforeach; ?>
      </ul>
    </div>
    <div class="col-xs-3">
      <ul>
        <?php foreach ($row_2 as $row): ?>
          <li>
            <?php print $row['icon']; ?>
            <?php print $row['title']; ?>
          </li>
        <?php endforeach; ?>
      </ul>
    </div>
    <div class="col-xs-3">
      <ul>
        <?php foreach ($row_3 as $row): ?>
          <li>
            <?php print $row['icon']; ?>
            <?php print $row['title']; ?>
          </li>
        <?php endforeach; ?>
      </ul>
    </div>
  </div>
</div>
