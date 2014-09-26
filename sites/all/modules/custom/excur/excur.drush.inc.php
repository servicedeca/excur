<?php

/**
* Implements hook_drush_command().
*/
function excur_drush_command() {
  $items = array();
  $items['add-term'] = array(
    'description' => 'Add term',
    'drupal dependencies' => array('example_drush'),
    'arguments' => array(
      'file' => 'File to import',
    ),
    'aliases' => array('at'),
    'callback' => 'excur_add_term',
  );
  return $items;
}

function excur_add_term($file) {
  if($file){
    $term = fopen($file, 'r');
    while (!feof ($term)) {
      $terms[] = fgets($term, 4096);
    }
    fclose ($term);
  }
}
