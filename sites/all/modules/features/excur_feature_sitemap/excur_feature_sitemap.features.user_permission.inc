<?php
/**
 * @file
 * excur_feature_sitemap.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function excur_feature_sitemap_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'administer xmlsitemap'.
  $permissions['administer xmlsitemap'] = array(
    'name' => 'administer xmlsitemap',
    'roles' => array(
      'Администратор' => 'Администратор',
    ),
    'module' => 'xmlsitemap',
  );

  return $permissions;
}
