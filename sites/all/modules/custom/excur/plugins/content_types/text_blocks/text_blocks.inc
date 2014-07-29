<?php
/**
 * @file
 * Ctools content type new_message.
 */

/**
 * Implements hook_ctools_content_types().
 */
function excur_text_blocks_ctools_content_types() {
  return array(
    'single' => TRUE,
    'title' => t('Text blocks'),
    'all contexts' => TRUE,
    'category' => t('Excur'),
    'hook theme' => 'excur_text_blocks_content_type_theme',
  );
}

/**
 * Implements hook_content_type_render().
 */
function excur_text_blocks_content_type_render($subtype, $conf, $panel_args, $context) {
  $block = new stdClass();
  $block->content = theme('excur_text_blocks');

  return $block;
}

/**
 * Implements hook_content_type_theme().
 */
function excur_text_blocks_content_type_theme(&$theme, $plugin) {
  $theme['excur_text_blocks'] = array(
    'path' => $plugin['path'],
    'template' => 'excur-text-blocks',
  );
}

/**
 * Process variables for excur-image-slider.tpl.php.
 */
function template_preprocess_excur_text_blocks(&$vars) {
  global $language;
  foreach (excur_main_text_blocks() as $node) {
    $wrapper = entity_metadata_wrapper('node', $node);
    $wrapper->language($language->language);

    $vars['blocks'][] = $wrapper->body->value->value();
  }
}
