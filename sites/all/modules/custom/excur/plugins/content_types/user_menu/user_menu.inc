<?php
/**
 * @file
 * Ctools content type new_message.
 */

/**
 * Implements hook_ctools_content_types().
 */
function excur_user_menu_ctools_content_types() {
  return array(
    'single' => TRUE,
    'title' => t('User left menu'),
    'all contexts' => TRUE,
    'category' => t('Excur'),
  );
}

/**
 * Implements hook_content_type_render().
 */
function excur_user_menu_content_type_render($subtype, $conf, $panel_args, $context) {
  $account = reset($context)->data;
  $block = new stdClass();
  $block->content = excur_user_menu($account);

  return $block;
}
