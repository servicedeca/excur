<?php
/**
 * @file
 * excur_feature_image_style.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function excur_feature_image_style_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'administer image styles'.
  $permissions['administer image styles'] = array(
    'name' => 'administer image styles',
    'roles' => array(
      'Администратор' => 'Администратор',
    ),
    'module' => 'image',
  );

  return $permissions;
}
