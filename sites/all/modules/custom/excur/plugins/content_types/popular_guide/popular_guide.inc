<?php
/**
 * @file
 * Ctools content type new_message.
 */

/**
 * Implements hook_ctools_content_types().
 */
function excur_popular_guide_ctools_content_types() {
  return array(
    'single' => TRUE,
    'title' => t('Popular guides'),
    'all contexts' => TRUE,
    'category' => t('Excur'),
    'hook theme' => 'excur_popular_guide_content_type_theme',
  );
}

/**
 * Implements hook_content_type_render().
 */
function excur_popular_guide_content_type_render($subtype, $conf, $panel_args, $context) {
  $block = new stdClass();
  $block->content = theme('excur_popular_guide');

  return $block;
}

/**
 * Implements hook_content_type_theme().
 */
function excur_popular_guide_content_type_theme(&$theme, $plugin) {
  $theme['excur_popular_guide'] = array(
    'path' => $plugin['path'],
    'template' => 'excur-popular-guide',
  );
}

/**
 * Process variables for excur-popular-guide.tpl.php.
 */
function template_preprocess_excur_popular_guide(&$vars) {
  $term = menu_get_object('taxonomy_term', 2);
  $uids = array();

  if ($term->vocabulary_machine_name == 'city') {
    $uids = excur_popular_giudes_in_city($term->tid);
  }
  elseif ($term->vocabulary_machine_name == 'country') {
    $uids = excur_popular_giudes_in_country($term->tid);
  }

  if ($uids) {
    foreach (user_load_multiple($uids) as $account) {
      $city = taxonomy_term_load($account->field_city[LANGUAGE_NONE][0]['target_id']);
      $city = isset($city->name) ? l($city->name, "taxonomy/term/$city->tid") : NULL;

      $image = theme('image_style', array(
        'style_name' => '70x70',
        'path' => $account->field_image[LANGUAGE_NONE][0]['uri'],
        'alt' => $account->field_name[LANGUAGE_NONE][0]['safe_value'],
        'title' => $account->field_name[LANGUAGE_NONE][0]['safe_value'],
      ));
      $vars['guides'][] = array(
        'title' => l($account->field_name[LANGUAGE_NONE][0]['value'], "user/$account->uid"),
        'city' => $city,
        'image' => l($image, "user/$account->uid", array('html' => TRUE)),
      );
    }
  }
}
