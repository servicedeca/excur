<?php
/**
 * @file
 * Ctools content type new_message.
 */

/**
 * Implements hook_ctools_content_types().
 */
function excur_image_slider_ctools_content_types() {
  return array(
    'single' => TRUE,
    'title' => t('Image slider'),
    'all contexts' => TRUE,
    'category' => t('Excur'),
    'hook theme' => 'excur_image_slider_content_type_theme',
  );
}

/**
 * Implements hook_content_type_render().
 */
function excur_image_slider_content_type_render($subtype, $conf, $panel_args, $context) {
  $block = new stdClass();
  $block->content = theme('excur_image_slider');

  return $block;
}

/**
 * Implements hook_content_type_theme().
 */
function excur_image_slider_content_type_theme(&$theme, $plugin) {
  $theme['excur_image_slider'] = array(
    'path' => $plugin['path'],
    'template' => 'excur-image-slider',
  );
}

/**
 * Process variables for excur-image-slider.tpl.php.
 */
function template_preprocess_excur_image_slider(&$vars) {
  $images = array();

  if ($term = menu_get_object('taxonomy_term', 2)) {
    if (!empty($term->field_slider_images)) {
      $images = $term->field_slider_images[LANGUAGE_NONE];
    }
  }

  foreach ($images as $image) {
    $vars['images'][] = theme('image_style', array(
      'style_name' => '1170x555',
      'path' => $image['uri'],
      'alt' => $image['alt'],
      'title' => $image['title'],
    ));
  }

  drupal_add_js(EXCUR_FRONT_THEME_PATH . '/js/jquery.flexslider.js');
  drupal_add_css(EXCUR_FRONT_THEME_PATH . '/css/flexslider.css');
}
