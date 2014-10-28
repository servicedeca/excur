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
