<?php
/**
 * @file
 * Ctools content type new_message.
 */

/**
 * Implements hook_ctools_content_types().
 */
function excur_user_info_ctools_content_types() {
  return array(
    'single' => TRUE,
    'title' => t('User information'),
    'all contexts' => TRUE,
    'category' => t('Excur'),
    'hook theme' => 'excur_user_info_content_type_theme',
  );
}

/**
 * Implements hook_content_type_render().
 */
function excur_user_info_content_type_render($subtype, $conf, $panel_args, $context) {
  $block = new stdClass();
  $block->content = theme('excur_user_info');

  return $block;
}

/**
 * Implements hook_content_type_theme().
 */
function excur_user_info_content_type_theme(&$theme, $plugin) {
  $theme['excur_user_info'] = array(
    'path' => $plugin['path'],
    'template' => 'excur-user-info',
  );
}

/**
 * Process variables for excur-user-info.tpl.php.
 */
function template_preprocess_excur_user_info(&$vars) {
  $account = menu_get_object('user');

  if (!empty($account->field_image[LANGUAGE_NONE])) {
    $path = $account->field_image[LANGUAGE_NONE][0]['uri'];
    $theming = 'image_style';
  }
  else {
    $path = EXCUR_FRONT_THEME_PATH . '/images/user-default.png';
    $theming = 'remote_image_style';
  }
  $vars['user_image'] = theme($theming, array(
    'style_name' => '238x238',
    'path' => $path,
    'alt' => $account->field_name[LANGUAGE_NONE][0]['safe_value'],
    'title' => $account->field_name[LANGUAGE_NONE][0]['safe_value'],
  ));
  $vars['user'] = $account->field_name[LANGUAGE_NONE][0]['safe_value'];
}
