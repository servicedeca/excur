<?php
/**
 * @file
 * Ctools content type new_message.
 */

/**
 * Implements hook_ctools_content_types().
 */
function excur_search_main_form_ctools_content_types() {
  return array(
    'single' => TRUE,
    'title' => t('Search form'),
    'all contexts' => TRUE,
    'category' => t('Excur'),
    'hook theme' => 'excur_search_main_form_content_type_theme',
  );
}

/**
 * Implements hook_content_type_render().
 */
function excur_search_main_form_content_type_render($subtype, $conf, $panel_args, $context) {
  $block = new stdClass();
  $block->content = theme('excur_search_main_form');

  return $block;
}

/**
 * Implements hook_content_type_theme().
 */
function excur_search_main_form_content_type_theme(&$theme, $plugin) {
  $theme['excur_search_main_form'] = array(
    'path' => $plugin['path'],
    'template' => 'excur-search-main-form',
  );
}

/**
 * Process variables for excur-search-main-form.tpl.php.
 */
function template_preprocess_excur_search_main_form(&$vars) {
  $from = drupal_get_form('excur_search_search_form');
  $from['#theme'] = 'excur_search_slider_form';
  $vars['form'] = $from;

  $title = variable_get('site_name');
  $vars['logo'] = theme('image', array(
    'path' => EXCUR_FRONT_THEME_PATH . '/images/logo.png',
    'alt' => $title,
    'title' => $title,
    'attributes' => array(
      'class' => array('logo'),
    )
  ));
}
