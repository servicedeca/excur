<?php if (!empty($categories)): ?>
  <div class="side-block">
    <ul class="list-a categories">
      <li id="category-0">
        <?php print t('Show all services'); ?>
      </li>
      <?php foreach ($categories as $category): ?>
        <li id="category-<?php print $category->entity_id; ?>" class="<?php print ($category->parent ? 'subcategory' : ''); ?>">
          <?php print $category->name_field_value; ?>
        </li>
      <?php endforeach; ?>
    </ul>
  </div>
<?php endif; ?>
