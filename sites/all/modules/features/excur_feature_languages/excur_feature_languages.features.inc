<?php
/**
 * @file
 * excur_feature_languages.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function excur_feature_languages_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}
