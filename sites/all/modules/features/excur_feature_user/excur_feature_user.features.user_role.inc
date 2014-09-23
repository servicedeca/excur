<?php
/**
 * @file
 * excur_feature_user.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function excur_feature_user_user_default_roles() {
  $roles = array();

  // Exported role: Администратор.
  $roles['Администратор'] = array(
    'name' => 'Администратор',
    'weight' => 2,
  );

  // Exported role: Гид.
  $roles['Гид'] = array(
    'name' => 'Гид',
    'weight' => 3,
  );

  // Exported role: Партнер.
  $roles['Партнер'] = array(
    'name' => 'Партнер',
    'weight' => 4,
  );

  return $roles;
}
