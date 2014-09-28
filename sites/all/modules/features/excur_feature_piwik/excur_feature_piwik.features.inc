<?php
/**
 * @file
 * excur_feature_piwik.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function excur_feature_piwik_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}
