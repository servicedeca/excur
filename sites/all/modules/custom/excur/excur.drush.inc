<?php

/**
* Implements hook_drush_command().
*/
function excur_drush_command(){
  $items['add-term'] = array(
    'description' => 'Add term',
    'aliases' => array('at'),
    'arguments' => array(
      'file_name' => 'file_name',
      'tid' => 'tid',
      'vid' => 'vid',
    ),
    'callback' => 'excur_drush_add_term',
  );

  return $items;
}

/**
 * Callback for 'add-term'drush command.
 */
function excur_drush_add_term($file_name, $tid, $vid) {
  if (file_exists($file_name)) {
    $names = array();

    $file = fopen($file_name, 'r');
    while (!feof($file)) {
      $names[] = fgets($file, 4096);
    }
    fclose($file);

    foreach ($names as $name) {
      $term = entity_create('taxonomy_term', array(
        'vid' => $vid,
        'name' => $name,
      ));
      $term->field_continent[LANGUAGE_NONE][0]['target_id'] = $tid;
      taxonomy_term_save($term);
    }
  }
}
