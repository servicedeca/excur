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

  if ($uids = excur_popular_giudes_in_country($term->tid)) {
    foreach (user_load_multiple($uids) as $account) {
//      $image = theme('image_style', array(
//        'style_name' => '100x100',
//        'path' => $term->field_image[LANGUAGE_NONE][0]['uri'],
//        'alt' => $term->name,
//      ));
//      $vars['cities'][] = array(
//        'title' => l($term->name, "taxonomy/term/$term->tid"),
//        'service' => excur_count_service_by_city($term->tid),
//        'guide' => excur_count_guide_by_city($term->tid),
//        'image' => l($image, "taxonomy/term/$term->tid", array('html' => TRUE)),
//      );
    }
  }
}
