<?php
/**
 * @file
 * excur_feature_node_slider.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function excur_feature_node_slider_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create main_page_slider content'.
  $permissions['create main_page_slider content'] = array(
    'name' => 'create main_page_slider content',
    'roles' => array(
      'Администратор' => 'Администратор',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any main_page_slider content'.
  $permissions['delete any main_page_slider content'] = array(
    'name' => 'delete any main_page_slider content',
    'roles' => array(
      'Администратор' => 'Администратор',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own main_page_slider content'.
  $permissions['delete own main_page_slider content'] = array(
    'name' => 'delete own main_page_slider content',
    'roles' => array(
      'Администратор' => 'Администратор',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any main_page_slider content'.
  $permissions['edit any main_page_slider content'] = array(
    'name' => 'edit any main_page_slider content',
    'roles' => array(
      'Администратор' => 'Администратор',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own main_page_slider content'.
  $permissions['edit own main_page_slider content'] = array(
    'name' => 'edit own main_page_slider content',
    'roles' => array(
      'Администратор' => 'Администратор',
    ),
    'module' => 'node',
  );

  return $permissions;
}
