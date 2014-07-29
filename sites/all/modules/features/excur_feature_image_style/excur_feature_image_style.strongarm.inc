<?php
/**
 * @file
 * excur_feature_image_style.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function excur_feature_image_style_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'imageapi_optimize_advpng';
  $strongarm->value = '';
  $export['imageapi_optimize_advpng'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'imageapi_optimize_jfifremove';
  $strongarm->value = '';
  $export['imageapi_optimize_jfifremove'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'imageapi_optimize_jpegtran';
  $strongarm->value = '';
  $export['imageapi_optimize_jpegtran'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'imageapi_optimize_optipng';
  $strongarm->value = '';
  $export['imageapi_optimize_optipng'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'imageapi_optimize_pngcrush';
  $strongarm->value = '';
  $export['imageapi_optimize_pngcrush'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'imageapi_optimize_service';
  $strongarm->value = 'smushit';
  $export['imageapi_optimize_service'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'imageapi_optimize_toolkit';
  $strongarm->value = 'gd';
  $export['imageapi_optimize_toolkit'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'image_jpeg_quality';
  $strongarm->value = '75';
  $export['image_jpeg_quality'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'image_toolkit';
  $strongarm->value = 'imageapi_optimize';
  $export['image_toolkit'] = $strongarm;

  return $export;
}
