<?php
/**
 * @file
 * excur_feature_node_text_block.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function excur_feature_node_text_block_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create text_block content'.
  $permissions['create text_block content'] = array(
    'name' => 'create text_block content',
    'roles' => array(
      'Администратор' => 'Администратор',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any text_block content'.
  $permissions['delete any text_block content'] = array(
    'name' => 'delete any text_block content',
    'roles' => array(
      'Администратор' => 'Администратор',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own text_block content'.
  $permissions['delete own text_block content'] = array(
    'name' => 'delete own text_block content',
    'roles' => array(
      'Администратор' => 'Администратор',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any text_block content'.
  $permissions['edit any text_block content'] = array(
    'name' => 'edit any text_block content',
    'roles' => array(
      'Администратор' => 'Администратор',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own text_block content'.
  $permissions['edit own text_block content'] = array(
    'name' => 'edit own text_block content',
    'roles' => array(
      'Администратор' => 'Администратор',
    ),
    'module' => 'node',
  );

  return $permissions;
}
