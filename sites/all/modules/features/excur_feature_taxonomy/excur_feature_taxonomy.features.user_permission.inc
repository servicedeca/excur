<?php
/**
 * @file
 * excur_feature_taxonomy.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function excur_feature_taxonomy_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'administer taxonomy'.
  $permissions['administer taxonomy'] = array(
    'name' => 'administer taxonomy',
    'roles' => array(
      'Администратор' => 'Администратор',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in city'.
  $permissions['delete terms in city'] = array(
    'name' => 'delete terms in city',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in continent'.
  $permissions['delete terms in continent'] = array(
    'name' => 'delete terms in continent',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in country'.
  $permissions['delete terms in country'] = array(
    'name' => 'delete terms in country',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in languages'.
  $permissions['delete terms in languages'] = array(
    'name' => 'delete terms in languages',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in city'.
  $permissions['edit terms in city'] = array(
    'name' => 'edit terms in city',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in continent'.
  $permissions['edit terms in continent'] = array(
    'name' => 'edit terms in continent',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in country'.
  $permissions['edit terms in country'] = array(
    'name' => 'edit terms in country',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in languages'.
  $permissions['edit terms in languages'] = array(
    'name' => 'edit terms in languages',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  return $permissions;
}
