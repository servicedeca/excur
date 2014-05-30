<?php
/**
 * @file
 * excur_feature_node_text_block.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function excur_feature_node_text_block_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function excur_feature_node_text_block_node_info() {
  $items = array(
    'text_block' => array(
      'name' => t('Текстовый блок'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Заголовок'),
      'help' => '',
    ),
  );
  return $items;
}
