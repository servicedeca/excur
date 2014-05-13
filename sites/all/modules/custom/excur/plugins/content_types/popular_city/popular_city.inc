<?php
/**
 * @file
 * Ctools content type new_message.
 */

/**
 * Implements hook_ctools_content_types().
 */
function excur_popular_city_ctools_content_types() {
  return array(
    'single' => TRUE,
    'title' => t('Popular cities'),
    'all contexts' => TRUE,
    'category' => t('Excur'),
    'hook theme' => 'excur_popular_city_content_type_theme',
  );
}

/**
 * Implements hook_content_type_render().
 */
function excur_popular_city_content_type_render($subtype, $conf, $panel_args, $context) {
  $term = menu_get_object('taxonomy_term', 2);
  $block = new stdClass();

  if ($cities = excur_popular_cities($term->tid)) {
    $block->content = '<div class="space30"></div><h2>' . t('Popular cities') . '</h2>';
  }

  return $block;
}
