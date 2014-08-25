<?php
/**
 * @file
 * Ctools content type new_message.
 */

/**
 * Implements hook_ctools_content_types().
 */
function excur_service_info_ctools_content_types() {
  return array(
    'single' => TRUE,
    'title' => t('Service information'),
    'all contexts' => TRUE,
    'category' => t('Excur'),
    'hook theme' => 'excur_service_info_content_type_theme',
  );
}

/**
 * Implements hook_content_type_render().
 */
function excur_service_info_content_type_render($subtype, $conf, $panel_args, $context) {
  $block = new stdClass();
  $block->content = theme('excur_service_info');

  return $block;
}

/**
 * Implements hook_content_type_theme().
 */
function excur_service_info_content_type_theme(&$theme, $plugin) {
  $theme['excur_service_info'] = array(
    'path' => $plugin['path'],
    'template' => 'excur-service-info',
  );
}

/**
 * Process variables for excur-image-slider.tpl.php.
 */
function template_preprocess_excur_service_info(&$vars) {
  global $language;

  $node = menu_get_object();
  $wrapper = entity_metadata_wrapper('node', $node);
  $wrapper->language($language->language);
  $city = taxonomy_term_load($node->field_city[LANGUAGE_NONE][0]['target_id']);
  $country = taxonomy_term_load($city->field_country[LANGUAGE_NONE][0]['target_id']);

  $vars['placement'] = l($city->name, "taxonomy/term/$city->tid");
  $vars['placement'] .= ', ' . l($country->name, "taxonomy/term/$country->tid");

  $vars['duration'] = $wrapper->field_duration->value();

  foreach ($wrapper->field_languages->value() as $lang) {
    $vars['languages'][] = $lang->field_lang_code[LANGUAGE_NONE][0]['value'];
  }

  $price = excur_currency_lowest_price($node);
  $currency = $wrapper->field_currency->value();
  $current_currency = !empty($_COOKIE['excur_currency']) && $_COOKIE['excur_currency'] != $currency
    ? $_COOKIE['excur_currency']
    : $currency;

  $price = excur_currency_convert($price, $currency, $current_currency);

  $vars['price'] = $price;
  $vars['currency'] = excur_currency_get_icon($currency);
}
