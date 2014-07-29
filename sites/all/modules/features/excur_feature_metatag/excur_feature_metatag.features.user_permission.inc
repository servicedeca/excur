<?php
/**
 * @file
 * excur_feature_metatag.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function excur_feature_metatag_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'administer meta tags'.
  $permissions['administer meta tags'] = array(
    'name' => 'administer meta tags',
    'roles' => array(
      'Администратор' => 'Администратор',
    ),
    'module' => 'metatag',
  );

  // Exported permission: 'edit meta tags'.
  $permissions['edit meta tags'] = array(
    'name' => 'edit meta tags',
    'roles' => array(
      'Администратор' => 'Администратор',
    ),
    'module' => 'metatag',
  );

  return $permissions;
}
