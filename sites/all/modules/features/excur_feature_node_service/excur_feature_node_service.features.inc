<?php
/**
 * @file
 * excur_feature_node_service.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function excur_feature_node_service_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "msnf" && $api == "msnf") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function excur_feature_node_service_node_info() {
  $items = array(
    'service' => array(
      'name' => t('Услуга'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Заголовок'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
