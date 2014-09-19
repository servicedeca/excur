<?php


/**
 * Implements hook_ctools_content_types().
 */
function excur_companions_city_ctools_content_types() {
  return array(
    'single' => TRUE,
    'title' => t('seeking a companion'),
    'all contexts' => TRUE,
    'category' => t('Excur'),
  );
}

/**
 * Implements hook_content_type_render().
 */
function excur_companions_city_content_type_render($subtype, $conf, $panel_args, $context) {
  $block = new stdClass();

  $block->content = '<h1>' . t('Looking for travel companions') . '</h1>';
  $block->content .= views_embed_view('user', 'companions_city');

  return $block;
}
