<?php
/**
 * @file
 * excur_feature_ckeditor.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function excur_feature_ckeditor_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'administer ckeditor'.
  $permissions['administer ckeditor'] = array(
    'name' => 'administer ckeditor',
    'roles' => array(
      'Администратор' => 'Администратор',
    ),
    'module' => 'ckeditor',
  );

  // Exported permission: 'customize ckeditor'.
  $permissions['customize ckeditor'] = array(
    'name' => 'customize ckeditor',
    'roles' => array(
      'Администратор' => 'Администратор',
    ),
    'module' => 'ckeditor',
  );

  return $permissions;
}
