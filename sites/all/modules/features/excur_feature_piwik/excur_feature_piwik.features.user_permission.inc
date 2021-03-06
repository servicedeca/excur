<?php
/**
 * @file
 * excur_feature_piwik.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function excur_feature_piwik_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'administer piwik'.
  $permissions['administer piwik'] = array(
    'name' => 'administer piwik',
    'roles' => array(
      'Администратор' => 'Администратор',
    ),
    'module' => 'piwik',
  );

  // Exported permission: 'opt-in or out of tracking'.
  $permissions['opt-in or out of tracking'] = array(
    'name' => 'opt-in or out of tracking',
    'roles' => array(
      'Администратор' => 'Администратор',
    ),
    'module' => 'piwik',
  );

  // Exported permission: 'use PHP for tracking visibility'.
  $permissions['use PHP for tracking visibility'] = array(
    'name' => 'use PHP for tracking visibility',
    'roles' => array(
      'Администратор' => 'Администратор',
    ),
    'module' => 'piwik',
  );

  return $permissions;
}
