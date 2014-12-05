<?php
/**
 * @file
 * excur_feature_taxonomy.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function excur_feature_taxonomy_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_taxonomy_term__city';
  $strongarm->value = array(
    'view_modes' => array(),
    'extra_fields' => array(
      'form' => array(
        'name' => array(
          'weight' => '0',
        ),
        'description' => array(
          'weight' => '1',
        ),
        'metatags' => array(
          'weight' => '6',
        ),
        'path' => array(
          'weight' => '5',
        ),
      ),
      'display' => array(),
    ),
  );
  $export['field_bundle_settings_taxonomy_term__city'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_taxonomy_term__continent';
  $strongarm->value = array(
    'view_modes' => array(),
    'extra_fields' => array(
      'form' => array(
        'metatags' => array(
          'weight' => '8',
        ),
        'path' => array(
          'weight' => '7',
        ),
        'rabbit_hole' => array(
          'weight' => '4',
        ),
        'xmlsitemap' => array(
          'weight' => '6',
        ),
        'language' => array(
          'weight' => '5',
        ),
      ),
      'display' => array(),
    ),
  );
  $export['field_bundle_settings_taxonomy_term__continent'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_taxonomy_term__country';
  $strongarm->value = array(
    'view_modes' => array(),
    'extra_fields' => array(
      'form' => array(
        'metatags' => array(
          'weight' => '9',
        ),
        'path' => array(
          'weight' => '7',
        ),
        'rabbit_hole' => array(
          'weight' => '0',
        ),
        'xmlsitemap' => array(
          'weight' => '10',
        ),
        'language' => array(
          'weight' => '8',
        ),
      ),
      'display' => array(),
    ),
  );
  $export['field_bundle_settings_taxonomy_term__country'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_taxonomy_term__languages';
  $strongarm->value = array(
    'view_modes' => array(),
    'extra_fields' => array(
      'form' => array(
        'metatags' => array(
          'weight' => '5',
        ),
        'path' => array(
          'weight' => '4',
        ),
        'description' => array(
          'weight' => '2',
        ),
        'language' => array(
          'weight' => '3',
        ),
      ),
      'display' => array(),
    ),
  );
  $export['field_bundle_settings_taxonomy_term__languages'] = $strongarm;

  return $export;
}
