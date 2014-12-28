<?php
/**
 * @file
 * Ctools content type Node title.
 */

/**
 * Implements hook_ctools_content_types().
 */
function excur_node_title_ctools_content_types() {
  return array(
    'single' => TRUE,
    'title' => t('Title of node with in H1'),
    'all contexts' => TRUE,
    'category' => t('Excur'),
  );
}

/**
 * Implements hook_content_type_render().
 */
function excur_node_title_content_type_render($subtype, $conf, $panel_args, $context) {
  $block = new stdClass();
  $block->content = '';

  $node = array_pop($context);
  if (!empty($node->data) && !empty($node->data->nid)) {
    $node = $node->data;
    $block->content = '<h1 class="excur-title">' . $node->title . '</h1>';
  }

  return $block;
}
