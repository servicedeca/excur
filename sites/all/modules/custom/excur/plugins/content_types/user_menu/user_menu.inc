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
    'hook theme' => 'excur_user_menu_content_type_theme',
  );
}

/**
 * Implements hook_content_type_render().
 */
function excur_user_menu_content_type_render($subtype, $conf, $panel_args, $context) {
  $block = new stdClass();
  $block->content = theme('excur_user_menu');

  return $block;
}

/**
 * Implements hook_content_type_theme().
 */
function excur_user_menu_content_type_theme(&$theme, $plugin) {
  $theme['excur_user_menu'] = array(
    'path' => $plugin['path'],
    'template' => 'excur-user-menu',
  );
}

/**
 * Process variables for excur-user-info.tpl.php.
 */
function template_preprocess_excur_user_menu(&$vars) {
  global $user;

  $uid = $user->uid;
  $vars['news'] = l(t('news and notices'),'user/'.$uid);
}
