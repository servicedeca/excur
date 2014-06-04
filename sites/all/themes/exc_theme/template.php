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
  $vars['language_switcher'] = drupal_get_form('excur_language_switcher');

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
  if (menu_get_object('user')) {
    $vars['breadcrumb'] = '';
  }
  else {
    $vars['breadcrumb'] = theme('breadcrumb', array('breadcrumb' => excur_get_breadcrumb()));
  }
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
  $node = $vars['node'];
  $guide = user_load($node->field_guide[LANGUAGE_NONE][0]['target_id']);

  $guide_image = theme('image_style', array(
    'style_name' => '70x70',
    'path' => $guide->field_image[LANGUAGE_NONE][0]['uri'],
    'alt' => $guide->field_name[LANGUAGE_NONE][0]['safe_value'],
    'title' => $guide->field_name[LANGUAGE_NONE][0]['safe_value'],
  ));
  $vars['guide'] = array(
    'title' => l($guide->field_name[LANGUAGE_NONE][0]['value'], "user/$guide->uid"),
    'image' => l($guide_image, "user/$guide->uid", array('html' => TRUE)),
  );

  $vars['read_more'] = l('<i class="fa fa-search"></i>' . t('Read more'), "node/$node->nid", array('html' => TRUE));

  $price = excur_currency_lowest_price($node);
  if (!empty($_COOKIE['excur_currency']) && $_COOKIE['excur_currency'] != EXCUR_CURRENCY_DEFAULT) {
    $currency = $_COOKIE['excur_currency'];
    $price = excur_currency_convert($price, EXCUR_CURRENCY_DEFAULT, $currency);
  }
  else {
    $currency = EXCUR_CURRENCY_DEFAULT;
  }

  $vars['price'] = $price;
  $vars['currency'] = excur_currency_get_icon($currency);
}

/**
 * Process variables for node--service-full.tpl.php.
 */
function exc_theme_preprocess_node__service_full(&$vars) {
  global $language;

  $node = $vars['node'];
  $wrapper = entity_metadata_wrapper('node', $node);
  $wrapper->language($language->language);

  if (!empty($node->field_slider_images[LANGUAGE_NONE])) {
    foreach ($node->field_slider_images[LANGUAGE_NONE] as $image) {
      $vars['images'][] = theme('image_style', array(
        'style_name' => '870x653',
        'path' => $image['uri'],
        'alt' => t($image['alt']),
        'title' => t($image['title']),
      ));
    }

    drupal_add_js(EXCUR_FRONT_THEME_PATH . '/js/fotorama.min.js');
    drupal_add_css(EXCUR_FRONT_THEME_PATH . '/css/fotorama.css');
  }

  $vars['venue'] = $wrapper->field_start_place->value();
  $vars['meeting_time'] = $wrapper->field_start_time->value();
}

/**
 * Returns HTML for a select form element.
 */
function exc_theme_select($variables) {
  $element = $variables['element'];
  element_set_attributes($element, array('id', 'name', 'size'));
  _form_set_class($element, array('form-select'));

  return '<select' . drupal_attributes($element['#attributes']) . '>' . exc_theme_form_select_options($element) . '</select>';
}

/**
 * Converts a select form element's options array into HTML.
 */
function exc_theme_form_select_options($element, $choices = NULL) {
  if (!isset($choices)) {
    $choices = $element['#options'];
  }

  $value_valid = isset($element['#value']) || array_key_exists('#value', $element);
  $value_is_array = $value_valid && is_array($element['#value']);
  $options = '';
  foreach ($choices as $key => $choice) {
    if (is_array($choice)) {
      $options .= '<optgroup label="' . $key . '">';
      $options .= exc_theme_form_select_options($element, $choice);
      $options .= '</optgroup>';
    }
    elseif (is_object($choice)) {
      $options .= form_select_options($element, $choice->option);
    }
    else {
      $key = (string) $key;
      if ($value_valid && (!$value_is_array && (string) $element['#value'] === $key || ($value_is_array && in_array($key, $element['#value'])))) {
        $selected = ' selected="selected"';
      }
      else {
        $selected = '';
      }

      $data_content = isset($element['#data-content'][$key]) ? str_replace('"', '\'', $element['#data-content'][$key]) : check_plain($choice);
      $options .= '<option value="' . check_plain($key) . '"' . $selected . ' data-content="' . $data_content . '">' . check_plain($choice) . '</option>';
    }
  }
  return $options;
}
