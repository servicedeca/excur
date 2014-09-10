<?php
/**
 * @file
 * excur_feature_node_special_offer.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function excur_feature_node_special_offer_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function excur_feature_node_special_offer_node_info() {
  $items = array(
    'special_offer' => array(
      'name' => t('Специальное предложение'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Название'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
