<?php
/**
 * @file
 * excur_feature_node_slider.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function excur_feature_node_slider_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function excur_feature_node_slider_node_info() {
  $items = array(
    'main_page_slider' => array(
      'name' => t('Слайдер главной страницы'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Название'),
      'help' => '',
    ),
  );
  return $items;
}
