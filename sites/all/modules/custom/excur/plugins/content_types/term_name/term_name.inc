<?php
/**
 * @file
 * Ctools content type new_message.
 */

/**
 * Implements hook_ctools_content_types().
 */
function excur_term_name_ctools_content_types() {
  return array(
    'single' => TRUE,
    'title' => t('Name of term'),
    'all contexts' => TRUE,
    'category' => t('Excur'),
    'hook theme' => 'excur_term_name_content_type_theme',
  );
}

/**
 * Implements hook_content_type_render().
 */
function excur_term_name_content_type_render($subtype, $conf, $panel_args, $context) {
  $term = menu_get_object('taxonomy_term', 2);
  $block = new stdClass();

  $block->content = '<div class="row"><div class="span12"><div class="title-wrapper"><h1>';
  $block->content .= $term->name;
  $block->content .= '</h1></div></div></div>';

  return $block;
}
