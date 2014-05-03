<?php
/**
 * @file
 */
?>
<header>
  <?php if ($logo): ?>
    Логотип
  <?php endif; ?>

  <?php if ($main_menu): ?>
    Главное меню
  <?php endif; ?>
</header>

<?php if ($messages): ?>
  <?php print $messages; ?>
<?php endif; ?>

<?php if ($breadcrumb): ?>
  <div id="breadcrumb">
    <?php print $breadcrumb; ?>
  </div>
<?php endif; ?>

<div id="content">
  <?php print render($title_prefix); ?>
  <?php if ($title): ?>
    <h1 class="title" id="page-title">
      <?php print $title; ?>
    </h1>
  <?php endif; ?>
  <?php print render($title_suffix); ?>
  <?php if ($tabs): ?>
    <div class="tabs">
      <?php print render($tabs); ?>
    </div>
  <?php endif; ?>
  <?php if ($action_links): ?>
    <ul class="action-links">
      <?php print render($action_links); ?>
    </ul>
  <?php endif; ?>
  <?php print render($page['content']); ?>
</div>

<footer>
  Футер
</footer>
