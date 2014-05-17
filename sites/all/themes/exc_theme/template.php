<?php
/**
 * @file
 */

/**
 * Process variables for page.tpl.php.
 */
function exc_theme_preprocess_page(&$vars, $hook) {
  // Get site logo.
  $vars['logo'] = theme('image', array(
    'path' => theme_get_setting('logo_path'),
    'alt' => t(variable_get('site_name')),
    'title' => t(variable_get('site_name')),
  ));

  // Get search form.
  $vars['search_form'] = drupal_get_form('excur_search_search_form');

  // Add language switcher block.
  $language_switcher = module_invoke('locale', 'block_view', 'language');
  $vars['language_switcher'] = $language_switcher['content'];

  // Get footer menu.
  $footer_menu = i18n_menu_translated_tree('menu-footer-menu');
  foreach ($footer_menu as &$item) {
    if (empty($item['#href'])) {
      continue;
    }

    $item['#attributes']['class'][] = 'span3';
  }
  $vars['footer_menu'] = $footer_menu;

  // Add currency change form.
   $vars['currency_switcher'] = drupal_get_form('excur_currency_choice_form');

  // Get main menu.
  foreach (i18n_menu_translated_tree('main-menu') as $item) {
    if (!isset($item['#href'])) {
      continue;
    }

    $vars['main_menu'][] = array(
      'title' => $item['#title'],
      'url' => url($item['#href'], array('absolute' => TRUE)),
      'class' => current_path() == $item['#href'] ? array('active') : array(),
    );
  }

  // Render breadcrumb.
  $vars['breadcrumb'] = theme('breadcrumb', array('breadcrumb' => excur_get_breadcrumb()));
}

/**
 * Main views view preprocess.
 */
function exc_theme_preprocess_views_view(&$vars) {
  if (!empty($vars['theme_hook_suggestion'])) {
    $function = 'exc_theme_preprocess_' . $vars['theme_hook_suggestion'];
    if (function_exists($function)) {
      $function($vars);
    }
  }
}

/**
 * Main views view field preprocess.
 */
function exc_theme_preprocess_views_view_field(&$vars) {
  if (!empty($vars['theme_hook_suggestion'])) {
    $function = 'exc_theme_preprocess_' . $vars['theme_hook_suggestion'];
    if (function_exists($function)) {
      $function($vars);
    }
  }
}

/**
 * Process variables for views-view-field--term--city--name-field.tpl.php.
 */
function exc_theme_preprocess_views_view_field__term__city__name_field(&$vars) {
  $vars['output'] .= ' (' . excur_count_service_by_city($vars['row']->tid) . ')';
}

/**
 * Preprocess variables for node.
 */
function exc_theme_preprocess_node(&$vars, $hook) {
  $node = $vars['node'];
  $view_mode = $vars['view_mode'];

  $vars['theme_hook_suggestions'][] = 'node__' . $node->type . '_' . str_replace('-', '_', $view_mode);
  $preprocesses[] = 'exc_theme_preprocess_node__' . $node->type . '_' . str_replace('-', '_', $view_mode);

  foreach ($preprocesses as $preprocess) {
    if (function_exists($preprocess)) {
      $preprocess($vars, $hook);
    }
  }
}

/**
 * Process variables for node--service-teaser.tpl.php.
 */
function exc_theme_preprocess_node__service_teaser(&$vars) {
  $a = 1;
}
