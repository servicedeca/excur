<?php
/**
 * @file
 * Ctools content type new_message.
 */

/**
 * Implements hook_ctools_content_types().
 */
function excur_main_slider_ctools_content_types() {
  return array(
    'single' => TRUE,
    'title' => t('Main page slider'),
    'all contexts' => TRUE,
    'category' => t('Excur'),
    'hook theme' => 'excur_main_slider_content_type_theme',
  );
}

/**
 * Implements hook_content_type_render().
 */
function excur_main_slider_content_type_render($subtype, $conf, $panel_args, $context) {
  $block = new stdClass();
  $block->content = theme('excur_main_slider');

  return $block;
}

/**
 * Implements hook_content_type_theme().
 */
function excur_main_slider_content_type_theme(&$theme, $plugin) {
  $theme['excur_main_slider'] = array(
    'path' => $plugin['path'],
    'template' => 'excur-main-slider',
  );
}

/**
 * Process variables for excur-main-slider.tpl.php.
 *
 * @see excur-main-slider.tpl.php
 */
function template_preprocess_excur_main_slider(&$vars) {
  drupal_add_js(FRONT_THEME_PATH . '/js/skdslider.min.js');
  drupal_add_css(FRONT_THEME_PATH . '/css/skdslider.css');
}
