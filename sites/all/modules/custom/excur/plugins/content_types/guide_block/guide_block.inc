<?php
/**
 * @file
 * Ctools content type new_message.
 */

/**
 * Implements hook_ctools_content_types().
 */
function excur_guide_block_ctools_content_types() {
  return array(
    'single' => TRUE,
    'title' => t('Guide block'),
    'all contexts' => TRUE,
    'category' => t('Excur'),
    'hook theme' => 'excur_guide_block_content_type_theme',
  );
}

/**
 * Implements hook_content_type_render().
 */
function excur_guide_block_content_type_render($subtype, $conf, $panel_args, $context) {
  $block = new stdClass();
  $block->content = theme('excur_guide_block');

  return $block;
}

/**
 * Implements hook_content_type_theme().
 */
function excur_guide_block_content_type_theme(&$theme, $plugin) {
  $theme['excur_guide_block'] = array(
    'path' => $plugin['path'],
    'template' => 'excur-guide-block',
  );
}

/**
 * Process variables for excur-image-slider.tpl.php.
 */
function template_preprocess_excur_guide_block(&$vars) {
  $node = menu_get_object();
  $guide = user_load($node->field_guide[LANGUAGE_NONE][0]['target_id']);

  if (!empty($guide->field_certified[LANGUAGE_NONE]) && $guide->field_certified[LANGUAGE_NONE][0]['value']) {
    $vars['certified'] = t('Certified guide');
  }

  if (!empty($guide->field_image[LANGUAGE_NONE])) {
    $path = $guide->field_image[LANGUAGE_NONE][0]['uri'];
    $theming = 'image_style';
  }
  else {
    $path = EXCUR_FRONT_THEME_PATH . '/images/user-default.png';
    $theming = 'remote_image_style';
  }
  $image = theme($theming, array(
    'style_name' => '238x238',
    'path' => $path,
    'alt' => $guide->field_name[LANGUAGE_NONE][0]['safe_value'],
    'title' => $guide->field_name[LANGUAGE_NONE][0]['safe_value'],
  ));
  $vars['guide_image'] = l($image, "user/$guide->uid", array('html' => TRUE));
  $vars['guide'] = l($guide->field_name[LANGUAGE_NONE][0]['value'], "user/$guide->uid");

  // Get guide rating.
  $rating = fivestar_get_votes('user', $guide->uid);
  if (empty($rating['average'])) {
    $rating = t('Guide has no rating.');
  }
  else {
    $rating = round($rating['average']['value'] / 10, 2);
    $rating = t('Rating: !value/10', array('!value' => $rating));
  }
  $vars['rating'] = $rating;
}
