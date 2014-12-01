<div class="option-group">
  <div class="input focused">
    <?php print render($form['search']); ?>
  </div>
  <div class="buttons">
    <?php print render($form['submit']); ?>
  </div>
</div>
<div class="element-hidden">
  <?php print drupal_render_children($form); ?>
</div>
