<?php
/**
 * @file
 * Ctools content type new_message.
 */

/**
 * Implements hook_ctools_content_types().
 */
function excur_message_guide_ctools_content_types() {
  return array(
    'single' => TRUE,
    'title' => t('Message to guide'),
    'all contexts' => TRUE,
    'category' => t('Excur'),
    'hook theme' => 'excur_message_guide_content_type_theme',
  );
}

/**
 * Implements hook_content_type_render().
 */
function excur_message_guide_content_type_render($subtype, $conf, $panel_args, $context) {
  $block = new stdClass();
  $block->content = user_is_logged_in() ? theme('excur_message_guide') : '';

  return $block;
}

/**
 * Implements hook_content_type_theme().
 */
function excur_message_guide_content_type_theme(&$theme, $plugin) {
  $theme['excur_message_guide'] = array(
    'path' => $plugin['path'],
    'template' => 'excur-message-guide',
  );
}

/**
 * Process variables for excur-popular-guide.tpl.php.
 */
function template_preprocess_excur_message_guide(&$vars) {
  module_load_include('inc', 'privatemsg', 'privatemsg.pages');
  $node = menu_get_object();
  $guide = user_load($node->field_guide[LANGUAGE_NONE][0]['target_id']);

  $vars['form'] = drupal_get_form(
    'privatemsg_new',
    array($guide),
    t('Question on the proposal "!title"', array('!title' => $node->title))
  );
  $vars['form']['recipient']['#attributes']['disabled'] = TRUE;
  $vars['form']['recipient']['#prefix'] = '<div class="element-hidden">';
  $vars['form']['recipient']['#suffix'] = '</div>';
  $vars['form']['actions']['submit']['#attributes']['class'][] = 'btn';
  unset($vars['form']['actions']['cancel']);
}
