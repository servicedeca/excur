<?php
/**
 * @file
 * excur_feature_metatag.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function excur_feature_metatag_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'metatag_schema_installed';
  $strongarm->value = TRUE;
  $export['metatag_schema_installed'] = $strongarm;

  return $export;
}
