<?php


/**
 * Implements hook_ctools_content_types().
 */
function excur_guide_other_ctools_content_types() {
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
function excur_guide_other_content_type_render($subtype, $conf, $panel_args, $context) {
  $block = new stdClass();
  $node = menu_get_object();

  $block->content = '<div class="col-xs-12 other-excur-guide">';
  $block->content .= '<h3 class="other-offer-title">' . t('Other offers guide') . '</h3>';
  $block->content .= views_embed_view('content', 'guide_other', $node->field_guide[LANGUAGE_NONE][0]['target_id']);
  $block->content .= '</div>';

  return $block;
}
