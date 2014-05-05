<?php
/**
 * @file
 * Ctools content type new_message.
 */

/**
 * Implements hook_ctools_content_types().
 */
function excur_continents_ctools_content_types() {
  return array(
    'single' => TRUE,
    'title' => t('Continents'),
    'all contexts' => TRUE,
    'category' => t('Excur'),
    'hook theme' => 'excur_continents_content_type_theme',
  );
}

/**
 * Implements hook_content_type_render().
 */
function excur_continents_content_type_render($subtype, $conf, $panel_args, $context) {
  $block = new stdClass();
  $block->content = '<h2>' . t('Continents') . '</h2>';
  $block->content .= views_embed_view('term', 'continent');

  return $block;
}
