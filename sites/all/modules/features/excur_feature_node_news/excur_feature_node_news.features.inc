<?php
/**
 * @file
 * excur_feature_node_news.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function excur_feature_node_news_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function excur_feature_node_news_node_info() {
  $items = array(
    'news' => array(
      'name' => t('Новость'),
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
