<?php

/**
 * @file.
 */

/**
 * Preprocess for excur-profile-form.tpl.php.
 */
function excur_preprocess_excur_profile_form(&$vars) {
  $vars['form']['account']['name']['#title'] = t('Login');
}

/**
 * Preprocess for excur-travel-planner.tpl.php.
 */
function excur_preprocess_excur_travel_planner(&$vars) {
  $account = user_load($vars['user']->uid);
  drupal_add_library('system', 'ui.draggable');

  $flags = flag_get_user_flags('node', NULL, $account->uid);
  $flags = reset($flags);
  foreach ($flags as $flag) {
    $service = entity_load($flag->entity_type, array($flag->entity_id));
    $service = reset($service);
    $vars['services'][] = check_plain($service->title);
  }

  $vars['user_menu'] = excur_user_menu($account);
}

/**
 * Preprocess for excur-language-switcher.tpl.php.
 */
function excur_preprocess_excur_language_switcher(&$vars) {
  global $language;

  $vars['def_language'] = theme('image', array(
    'path' => EXCUR_FRONT_THEME_PATH . '/images/' . $language->prefix . '.png',
    'alt' => $language->native,
    'title' => $language->native,
    'attributes' => array(
      'class' => array('currency-img'),
    ),
  ));

  foreach (language_list() as $lang) {
    if ($lang->enabled) {
      $url = url(current_path(), array('language' => $lang, 'absolute' => TRUE));

      $vars['languages'][$lang->prefix]['class'] = $lang->prefix == $language->prefix
        ? 'active'
        : '';
      $vars['languages'][$lang->prefix]['url'] = $url;
      $vars['languages'][$lang->prefix]['native'] = $lang->native;
      $vars['languages'][$lang->prefix]['icon'] = theme('image', array(
        'path' => EXCUR_FRONT_THEME_PATH . '/images/' . $lang->prefix . '.png',
        'alt' => $lang->native,
        'title' => $lang->native,
        'attributes' => array(
          'class' => array('currency-img'),
        ),
      ));
    }
  }
}
