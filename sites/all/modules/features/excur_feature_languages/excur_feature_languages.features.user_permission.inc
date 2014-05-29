<?php
/**
 * @file
 * excur_feature_languages.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function excur_feature_languages_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'administer entity translation'.
  $permissions['administer entity translation'] = array(
    'name' => 'administer entity translation',
    'roles' => array(
      'Администратор' => 'Администратор',
    ),
    'module' => 'entity_translation',
  );

  // Exported permission: 'administer languages'.
  $permissions['administer languages'] = array(
    'name' => 'administer languages',
    'roles' => array(
      'Администратор' => 'Администратор',
    ),
    'module' => 'locale',
  );

  // Exported permission: 'toggle field translatability'.
  $permissions['toggle field translatability'] = array(
    'name' => 'toggle field translatability',
    'roles' => array(
      'Администратор' => 'Администратор',
    ),
    'module' => 'entity_translation',
  );

  // Exported permission: 'translate admin strings'.
  $permissions['translate admin strings'] = array(
    'name' => 'translate admin strings',
    'roles' => array(
      'Администратор' => 'Администратор',
    ),
    'module' => 'i18n_string',
  );

  // Exported permission: 'translate any entity'.
  $permissions['translate any entity'] = array(
    'name' => 'translate any entity',
    'roles' => array(
      'Администратор' => 'Администратор',
    ),
    'module' => 'entity_translation',
  );

  // Exported permission: 'translate field_collection_item entities'.
  $permissions['translate field_collection_item entities'] = array(
    'name' => 'translate field_collection_item entities',
    'roles' => array(),
    'module' => 'entity_translation',
  );

  // Exported permission: 'translate interface'.
  $permissions['translate interface'] = array(
    'name' => 'translate interface',
    'roles' => array(
      'Администратор' => 'Администратор',
    ),
    'module' => 'locale',
  );

  // Exported permission: 'translate node entities'.
  $permissions['translate node entities'] = array(
    'name' => 'translate node entities',
    'roles' => array(
      'Администратор' => 'Администратор',
    ),
    'module' => 'entity_translation',
  );

  // Exported permission: 'translate taxonomy_term entities'.
  $permissions['translate taxonomy_term entities'] = array(
    'name' => 'translate taxonomy_term entities',
    'roles' => array(),
    'module' => 'entity_translation',
  );

  // Exported permission: 'translate user-defined strings'.
  $permissions['translate user-defined strings'] = array(
    'name' => 'translate user-defined strings',
    'roles' => array(
      'Администратор' => 'Администратор',
    ),
    'module' => 'i18n_string',
  );

  return $permissions;
}
