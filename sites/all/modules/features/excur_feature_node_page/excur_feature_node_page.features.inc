<?php
/**
 * @file
 * excur_feature_node_page.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function excur_feature_node_page_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function excur_feature_node_page_node_info() {
  $items = array(
    'page' => array(
      'name' => t('Страница'),
      'base' => 'node_content',
      'description' => t('Страница — это документ, который используется для страниц с редко изменяемой информацией. Например, таких страниц как «О сайте» или «Наш адрес». По умолчанию, документы этого типа не выводятся на первую страницу сайта и их комментирование отключено.'),
      'has_title' => '1',
      'title_label' => t('Заголовок'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
