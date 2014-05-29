<?php
/**
 * @file
 * excur_feature_taxonomy.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function excur_feature_taxonomy_taxonomy_default_vocabularies() {
  return array(
    'city' => array(
      'name' => 'Города',
      'machine_name' => 'city',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => -8,
    ),
    'continent' => array(
      'name' => 'Континенты',
      'machine_name' => 'continent',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => -10,
    ),
    'country' => array(
      'name' => 'Страны',
      'machine_name' => 'country',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => -9,
    ),
    'languages' => array(
      'name' => 'Языки',
      'machine_name' => 'languages',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
  );
}
