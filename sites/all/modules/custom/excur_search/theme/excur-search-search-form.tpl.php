<div class="search-box">
  <a href="#" class="search-icon">
    <i class="fa fa-search"></i>
  </a>
  <?php print render($form['search']); ?>
  <div class="element-hidden">
    <?php print drupal_render_children($form); ?>
  </div>
</div>
