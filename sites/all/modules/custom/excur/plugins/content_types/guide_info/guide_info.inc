<?php
/**
 * @file
 * Ctools content type new_message.
 */

/**
 * Implements hook_ctools_content_types().
 */
function excur_guide_info_ctools_content_types() {
  return array(
    'single' => TRUE,
    'title' => t('Guide information'),
    'all contexts' => TRUE,
    'category' => t('Excur'),
    'hook theme' => 'excur_guide_info_content_type_theme',
  );
}

/**
 * Implements hook_content_type_render().
 */
function excur_guide_info_content_type_render($subtype, $conf, $panel_args, $context) {
  $block = new stdClass();
  $block->content = theme('excur_guide_info');

  return $block;
}

/**
 * Implements hook_content_type_theme().
 */
function excur_guide_info_content_type_theme(&$theme, $plugin) {
  $theme['excur_guide_info'] = array(
    'path' => $plugin['path'],
    'template' => 'excur-guide-info',
  );
}

/**
 * Process variables for excur-image-slider.tpl.php.
 */
function template_preprocess_excur_guide_info(&$vars) {
//  $a =  drupal_get_title();

  $account = menu_get_object('user');
  $city = $account->field_city[LANGUAGE_NONE][0]['entity'];

  $vars['guide_image'] = theme('image_style', array(
    'style_name' => '238x238',
    'path' => $account->field_image[LANGUAGE_NONE][0]['uri'],
    'alt' => $account->field_name[LANGUAGE_NONE][0]['safe_value'],
    'title' => $account->field_name[LANGUAGE_NONE][0]['safe_value'],
  ));
  $vars['guide'] = $account->field_name[LANGUAGE_NONE][0]['safe_value'];

  $vars['language'] = $account->field_language[LANGUAGE_NONE][0]['taxonomy_term']->field_lang_code[LANGUAGE_NONE][0]['value'];
  $vars['city'] = l($city->name, "taxonomy/term/$city->tid");

  if (!empty($account->field_languages[LANGUAGE_NONE])) {
    foreach ($account->field_languages[LANGUAGE_NONE] as $lang) {
      $vars['languages'][] = $lang['taxonomy_term']->field_lang_code[LANGUAGE_NONE][0]['value'];
    }
  }
}
