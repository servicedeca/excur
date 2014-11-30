<?php print render($form['search']); ?>
<button type="submit" class="search-button"></button>
<div class="element-hidden">
  <?php print drupal_render_children($form); ?>
</div>
