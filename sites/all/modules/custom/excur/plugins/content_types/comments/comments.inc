<?php
/**
 * @file
 * Ctools content type new_message.
 */

/**
 * Implements hook_ctools_content_types().
 */
function excur_comments_ctools_content_types() {
  return array(
    'single' => TRUE,
    'title' => t('Comments'),
    'all contexts' => TRUE,
    'category' => t('Excur'),
  );
}

/**
 * Implements hook_content_type_render().
 */
function excur_comments_content_type_render($subtype, $conf, $panel_args, $context) {
  $block = new stdClass();
  $block->content = excur_comments();

  return $block;
}
