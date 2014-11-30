<button data-label-placement data-toggle="dropdown" class="btn btn-default dropdown-toggle mybutt padd">
  <i class="data-label">
    <?php print $def_currency; ?>
  </i>
</button>
<ul class="dropdown-menu drop-lang" id="currency-switcher">
  <?php foreach ($currencies as $curr): ?>
    <li>
      <label data-currency="<?php print $curr['currency']; ?>" class="<?php print $curr['class']; ?>">
        <i class="data-label">
          <?php print $curr['icon']; ?>
        </i>
        <?php print $curr['title']; ?>
      </label>
    </li>
  <?php endforeach; ?>
</ul>
