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
  $footer_menu = i18n_menu_translated_tree('menu-footer-menu');
  foreach ($footer_menu as &$first_item) {
    if (empty($first_item['#href'])) {
      continue;
    }

    $first_item['#attributes']['class'][] = 'span3';
  }
  $vars['footer_menu'] = $footer_menu;
}
