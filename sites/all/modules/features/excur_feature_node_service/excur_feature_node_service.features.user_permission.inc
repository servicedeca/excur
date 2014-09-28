<?php
/**
 * @file
 * excur_feature_node_service.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function excur_feature_node_service_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'administer flags'.
  $permissions['administer flags'] = array(
    'name' => 'administer flags',
    'roles' => array(
      'Администратор' => 'Администратор',
    ),
    'module' => 'flag',
  );

  // Exported permission: 'create service content'.
  $permissions['create service content'] = array(
    'name' => 'create service content',
    'roles' => array(
      'Администратор' => 'Администратор',
      'Гид' => 'Гид',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any service content'.
  $permissions['delete any service content'] = array(
    'name' => 'delete any service content',
    'roles' => array(
      'Администратор' => 'Администратор',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own service content'.
  $permissions['delete own service content'] = array(
    'name' => 'delete own service content',
    'roles' => array(
      'Администратор' => 'Администратор',
      'Гид' => 'Гид',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any service content'.
  $permissions['edit any service content'] = array(
    'name' => 'edit any service content',
    'roles' => array(
      'Администратор' => 'Администратор',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own service content'.
  $permissions['edit own service content'] = array(
    'name' => 'edit own service content',
    'roles' => array(
      'Администратор' => 'Администратор',
      'Гид' => 'Гид',
    ),
    'module' => 'node',
  );

  // Exported permission: 'flag travel_planner'.
  $permissions['flag travel_planner'] = array(
    'name' => 'flag travel_planner',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'flag',
  );

  // Exported permission: 'unflag travel_planner'.
  $permissions['unflag travel_planner'] = array(
    'name' => 'unflag travel_planner',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'flag',
  );

  // Exported permission: 'use flag import'.
  $permissions['use flag import'] = array(
    'name' => 'use flag import',
    'roles' => array(
      'Администратор' => 'Администратор',
    ),
    'module' => 'flag',
  );

  return $permissions;
}
