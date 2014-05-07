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

  if (drupal_is_front_page()) {
    $images = excur_main_slider_images();
  }
  elseif ($term = menu_get_object('taxonomy_term', 2)) {
    $images = $term->field_slider_images[LANGUAGE_NONE];
  }

  foreach ($images as $image) {
    $vars['images'][] = theme('image', array(
      'path' => $image['uri'],
      'alt' => $image['alt'],
      'title' => $image['title'],
    ));
  }

  drupal_add_js(FRONT_THEME_PATH . '/js/skdslider.min.js');
  drupal_add_css(FRONT_THEME_PATH . '/css/skdslider.css');
}
