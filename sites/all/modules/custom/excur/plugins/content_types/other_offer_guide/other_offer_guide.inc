<?php


/**
 * Implements hook_ctools_content_types().
 */
function excur_other_offer_guide_ctools_content_types() {
  return array(
    'single' => TRUE,
    'title' => t('Other offer guide'),
    'all contexts' => TRUE,
    'category' => t('Excur'),
  );
}

/**
 * Implements hook_content_type_render().
 */
function excur_other_offer_guide_content_type_render($subtype, $conf, $panel_args, $context) {
  $block = new stdClass();
  $block->content = '<h1>' . t('Other offer guide') . '</h1>';
  $block->content .= views_embed_view('offers', 'other_offer_guide');

  return $block;
}