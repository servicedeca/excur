<?php
/**
 * @file
 * excur_feature_humanstxt.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function excur_feature_humanstxt_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'administer humans.txt'.
  $permissions['administer humans.txt'] = array(
    'name' => 'administer humans.txt',
    'roles' => array(
      'Администратор' => 'Администратор',
    ),
    'module' => 'humanstxt',
  );

  return $permissions;
}
