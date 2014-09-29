<?php

/**
* Implements hook_drush_command().
*/
function excur_drush_command() {
  $items['add-term'] = array(
    'description' => 'Add term',
    'aliases' => array('at'),
    'arguments' => array(
      'file' => 'file',
      'id' => 'id',
      'dictionary' => 'dictionary',
    ),
    'callback' => 'excur_drush_add_term',
  );

  return $items;
}
function excur_drush_add_term($file, $id, $dictionary) {
  $vocabulary = taxonomy_vocabulary_machine_name_load($dictionary);
  if($file){
    $new_term = fopen($file, 'r');
    while (!feof ($new_term)) {
      $terms[] = fgets($new_term, 4096);
    }
    fclose ($new_term);

    foreach($terms as $new_term){
      $term = array(
        'vid' => $vocabulary->vid,
        'name' => $new_term,
      );
      $term = (object) $term;
      $term->field_continent['und'][0]['target_id'] = $id;
      taxonomy_term_save($term);
    }
  }
}
