<?php
/**
 * @file
 * Ctools content type new_message.
 */

/**
 * Implements hook_ctools_content_types().
 */
function excur_guide_services_ctools_content_types() {
  return array(
    'single' => TRUE,
    'title' => t('Guide services'),
    'all contexts' => TRUE,
    'category' => t('Excur'),
    'hook theme' => 'excur_guide_services_content_type_theme',
  );
}

/**
 * Implements hook_content_type_render().
 */
function excur_guide_services_content_type_render($subtype, $conf, $panel_args, $context) {
  $block = new stdClass();
  $block->content = theme('excur_guide_services');

  return $block;
}

/**
 * Implements hook_content_type_theme().
 */
function excur_guide_services_content_type_theme(&$theme, $plugin) {
  $theme['excur_guide_services'] = array(
    'path' => $plugin['path'],
    'template' => 'excur-guide-services',
  );
}

/**
 * Process variables for excur-image-slider.tpl.php.
 */
function template_preprocess_excur_guide_services(&$vars) {
  global $user;
  $account = menu_get_object('user');

  $vars['services'] = views_embed_view('content', 'guide_service');

  if ($user->uid == 1 || $user->uid == $account->uid) {
    $vars['orders'] = views_embed_view('offers', 'guide_offers', $account->uid);
    $show_tabs = TRUE;
  }
  $vars['show_tabs'] = isset($show_tabs) ? $show_tabs : FALSE;
}
