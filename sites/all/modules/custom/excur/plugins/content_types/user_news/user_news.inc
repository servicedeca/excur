<?php
/**
 * @file
 * Ctools content type new_message.
 */

/**
 * Implements hook_ctools_content_types().
 */
function excur_user_news_ctools_content_types() {
  return array(
    'single' => TRUE,
    'title' => t('News and notices'),
    'all contexts' => TRUE,
    'category' => t('Excur'),
    'hook theme' => 'excur_user_news_content_type_theme',
  );
}

/**
 * Implements hook_content_type_render().
 */
function excur_user_news_content_type_render($subtype, $conf, $panel_args, $context) {
  $block = new stdClass();
  $block->content = '<h1>' . t('News and notices') . '</h1>';
  $block->content .= views_embed_view('content', 'news');

  return $block;
}
