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

  $vars['guide_image'] = excur_guide_logo($guide, '240x240', array('class' => array('excur-contacts-gid-photo')));

  if (user_is_logged_in()) {
    $vars['ask_guide'] = '<a href="#" class="question-button" id="excur-contacts-guide-button">' . t('Write to the guide') . '</a>';
  }
}
