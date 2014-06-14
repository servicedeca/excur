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
 * Process variables for excur-guide-info.tpl.php.
 */
function template_preprocess_excur_guide_info(&$vars) {
  $account = menu_get_object('user');
  if (!empty($account->field_city[LANGUAGE_NONE])) {
    $city = $account->field_city[LANGUAGE_NONE][0]['entity'];
    $vars['city'] = l($city->name, "taxonomy/term/$city->tid");
  }

  if (!empty($account->field_certified[LANGUAGE_NONE]) && $account->field_certified[LANGUAGE_NONE][0]['value']) {
    $vars['certified'] = t('Certified guide');
  }

  if (!empty($account->field_image[LANGUAGE_NONE])) {
    $path = $account->field_image[LANGUAGE_NONE][0]['uri'];
    $theming = 'image_style';
  }
  else {
    $path = EXCUR_FRONT_THEME_PATH . '/images/user-default.png';
    $theming = 'remote_image_style';
  }
  $vars['guide_image'] = theme($theming, array(
    'style_name' => '238x238',
    'path' => $path,
    'alt' => $account->field_name[LANGUAGE_NONE][0]['safe_value'],
    'title' => $account->field_name[LANGUAGE_NONE][0]['safe_value'],
  ));
  $vars['guide'] = $account->field_name[LANGUAGE_NONE][0]['safe_value'];

  $vars['language'] = $account->field_language[LANGUAGE_NONE][0]['taxonomy_term']->field_lang_code[LANGUAGE_NONE][0]['value'];

  if (!empty($account->field_languages[LANGUAGE_NONE])) {
    foreach ($account->field_languages[LANGUAGE_NONE] as $lang) {
      $vars['languages'][] = $lang['taxonomy_term']->field_lang_code[LANGUAGE_NONE][0]['value'];
    }
  }
}
