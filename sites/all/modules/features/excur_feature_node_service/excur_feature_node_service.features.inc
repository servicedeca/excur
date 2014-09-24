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
 * Implements hook_flag_default_flags().
 */
function excur_feature_node_service_flag_default_flags() {
  $flags = array();
  // Exported flag: "Планировщик путешествий".
  $flags['travel_planner'] = array(
    'entity_type' => 'node',
    'title' => 'Планировщик путешествий',
    'global' => 0,
    'types' => array(
      0 => 'service',
    ),
    'flag_short' => 'Добавить в планировщик путешествий',
    'flag_long' => 'Добавить в планировщик путешествий',
    'flag_message' => 'Экскурсия добавлена в планировщик путешествий',
    'unflag_short' => 'Убрать из планировщика путешествий',
    'unflag_long' => 'Убрать из планировщика путешествий',
    'unflag_message' => 'Экскурсия удалена из планировщика путешествий',
    'unflag_denied_text' => '',
    'link_type' => 'toggle',
    'weight' => 0,
    'show_in_links' => array(
      'full' => 0,
      'teaser' => 0,
      'rss' => 0,
      'diff_standard' => 0,
      'other' => 0,
      'token' => 0,
    ),
    'show_as_field' => 0,
    'show_on_form' => 0,
    'access_author' => '',
    'show_contextual_link' => 0,
    'i18n' => 0,
    'api_version' => 3,
    'module' => 'excur_feature_node_service',
    'locked' => array(
      0 => 'name',
    ),
  );
  return $flags;

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
