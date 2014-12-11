<?php
/**
 * @file
 * Ctools content type new_message.
 */

/**
 * Implements hook_ctools_content_types().
 */
function excur_service_category_ctools_content_types() {
  return array(
    'single' => TRUE,
    'title' => t('Categories of service'),
    'all contexts' => TRUE,
    'category' => t('Excur'),
    'hook theme' => 'excur_service_category_content_type_theme',
  );
}

/**
 * Implements hook_content_type_render().
 */
function excur_service_category_content_type_render($subtype, $conf, $panel_args, $context) {
  $block = new stdClass();
  $block->content = theme('excur_service_category');

  return $block;
}

/**
 * Implements hook_content_type_theme().
 */
function excur_service_category_content_type_theme(&$theme, $plugin) {
  $theme['excur_service_category'] = array(
    'path' => $plugin['path'],
    'template' => 'excur-service-category',
  );
}

/**
 * Process variables for excur-image-slider.tpl.php.
 */
function template_preprocess_excur_service_category(&$vars) {
  $city = menu_get_object('taxonomy_term', 2);
  $vars['city'] = $city->name;

  $vocabulary = taxonomy_vocabulary_machine_name_load('category');
  foreach (taxonomy_get_tree($vocabulary->vid, 0, NULL, TRUE) as $key => $term) {
    $vars['categories'][$key]['name'] = $term->name;
    $vars['categories'][$key]['id'] = $term->tid;
    $vars['categories'][$key]['icon'] = theme('image_style', array(
      'style_name' => '50x50',
      'path' => $term->field_image[LANGUAGE_NONE][0]['uri'],
      'alt' => $term->name,
      'title' => $term->name,
      'attributes' => array(
        'class' => array('categoty-icon'),
      ),
    ));
  }
}
