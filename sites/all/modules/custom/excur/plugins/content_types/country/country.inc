<?php
/**
 * @file
 * Ctools content type new_message.
 */

/**
 * Implements hook_ctools_content_types().
 */
function excur_country_ctools_content_types() {
  return array(
    'single' => TRUE,
    'title' => t('Countries'),
    'all contexts' => TRUE,
    'category' => t('Excur'),
    'hook theme' => 'excur_country_content_type_theme',
  );
}

/**
 * Implements hook_content_type_render().
 */
function excur_country_content_type_render($subtype, $conf, $panel_args, $context) {
  $term = menu_get_object('taxonomy_term', 2);
  $block = new stdClass();
  $block->content = '<h2>' . t('Countries') . '</h2>';

  $view = views_get_view('term');
  $view->set_display('country');
  $view->preview = TRUE;
  $view->display_handler->options['filters']['field_continent_target_id']['value']['value'] = $term->tid;
  $view->pre_execute(array());
  $block->content  .= $view->display_handler->preview();
  $view->post_execute();

  return $block;
}
