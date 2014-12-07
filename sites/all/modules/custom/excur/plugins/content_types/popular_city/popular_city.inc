<?php
/**
 * @file
 * Ctools content type new_message.
 */

/**
 * Implements hook_ctools_content_types().
 */
function excur_popular_city_ctools_content_types() {
  return array(
    'single' => TRUE,
    'title' => t('Popular cities'),
    'all contexts' => TRUE,
    'category' => t('Excur'),
    'hook theme' => 'excur_popular_city_content_type_theme',
  );
}

/**
 * Implements hook_content_type_render().
 */
function excur_popular_city_content_type_render($subtype, $conf, $panel_args, $context) {
  $block = new stdClass();
  $block->content = theme('excur_popular_city');

  return $block;
}

/**
 * Implements hook_content_type_theme().
 */
function excur_popular_city_content_type_theme(&$theme, $plugin) {
  $theme['excur_popular_city'] = array(
    'path' => $plugin['path'],
    'template' => 'excur-popular-city',
  );
}

/**
 * Process variables for excur-popular-city.tpl.php.
 */
function template_preprocess_excur_popular_city(&$vars) {
  $term = menu_get_object('taxonomy_term', 2);

  if ($cities = excur_popular_cities($term->tid)) {
    foreach (taxonomy_term_load_multiple($cities) as $term) {
      $image = theme('image_style', array(
        'style_name' => '150x102',
        'path' => $term->field_image[LANGUAGE_NONE][0]['uri'],
        'alt' => $term->name,
        'attributes' => array(
          'class' => array('pop-city-image'),
        ),
      ));
      $vars['cities'][] = array(
        'title' => check_plain($term->name),
        'service' => excur_count_service_by_city($term->tid),
        'guide' => excur_count_guide_by_city($term->tid),
        'image' => $image,
        'url' => url("taxonomy/term/$term->tid"),
      );
    }
  }
}
