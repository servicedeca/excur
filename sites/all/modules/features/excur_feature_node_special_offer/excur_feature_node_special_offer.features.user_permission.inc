<?php
/**
 * @file
 * excur_feature_node_special_offer.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function excur_feature_node_special_offer_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create special_offer content'.
  $permissions['create special_offer content'] = array(
    'name' => 'create special_offer content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete any special_offer content'.
  $permissions['delete any special_offer content'] = array(
    'name' => 'delete any special_offer content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete own special_offer content'.
  $permissions['delete own special_offer content'] = array(
    'name' => 'delete own special_offer content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit any special_offer content'.
  $permissions['edit any special_offer content'] = array(
    'name' => 'edit any special_offer content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit own special_offer content'.
  $permissions['edit own special_offer content'] = array(
    'name' => 'edit own special_offer content',
    'roles' => array(),
    'module' => 'node',
  );

  return $permissions;
}
