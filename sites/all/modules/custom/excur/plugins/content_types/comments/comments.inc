<?php
/**
 * @file
 * Ctools content type new_message.
 */

/**
 * Implements hook_ctools_content_types().
 */
function excur_comments_ctools_content_types() {
  return array(
    'single' => TRUE,
    'title' => t('Comments'),
    'all contexts' => TRUE,
    'category' => t('Excur'),
    'hook theme' => 'excur_comments_content_type_theme',
  );
}

/**
 * Implements hook_content_type_render().
 */
function excur_comments_content_type_render($subtype, $conf, $panel_args, $context) {
  $block = new stdClass();
  $block->content = theme('excur_comments');

  return $block;
}

/**
* Implements hook_content_type_theme().
 */
function excur_comments_content_type_theme(&$theme, $plugin) {
  $theme['excur_comments'] = array(
    'path' => $plugin['path'],
    'template' => 'excur-comments',
  );
}

/**
 * Process variables for excur-comments.tpl.php.
 */
function template_preprocess_excur_comments(&$vars) {
  $node  = menu_get_object();
  $node_view = node_view($node);
  $vars['comments'] = render($node_view['comments']);
}