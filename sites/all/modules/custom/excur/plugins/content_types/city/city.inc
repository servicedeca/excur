<?php
/**
 * @file
 * Ctools content type new_message.
 */

/**
 * Implements hook_ctools_content_types().
 */
function excur_city_ctools_content_types() {
  return array(
    'single' => TRUE,
    'title' => t('Cities'),
    'all contexts' => TRUE,
    'category' => t('Excur'),
    'hook theme' => 'excur_city_content_type_theme',
  );
}

/**
 * Implements hook_content_type_render().
 */
function excur_city_content_type_render($subtype, $conf, $panel_args, $context) {
  $term = menu_get_object('taxonomy_term', 2);
  $block = new stdClass();
  $block->content = '<h2>' . t('Cities') . '</h2>';

  $view = views_get_view('term');
  $view->set_display('city');
  $view->preview = TRUE;
  $view->display_handler->options['filters']['field_country_target_id']['value']['value'] = $term->tid;
  $view->pre_execute(array());
  $block->content .= $view->display_handler->preview();
  $view->post_execute();

  return $block;
}
