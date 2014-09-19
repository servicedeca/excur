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
    'hook theme' => 'excur_guide_other_content_type_theme',
  );
}

/**
 * Implements hook_content_type_render().
 */
function excur_guide_other_content_type_render($subtype, $conf, $panel_args, $context) {
  $block = new stdClass();
  $node = menu_get_object();
  $uid = $node->field_guide[LANGUAGE_NONE][0]['target_id'];
  $block->content = '<h1>' . t('Other offers guide') . '</h1>';
  $block->content .= views_embed_view('content', 'guide_other', $uid);
  $block->content .= theme('excur_guide_other');
  return $block;
}

/**
 * Implements hook_content_type_theme().
 */
function excur_guide_other_content_type_theme(&$theme, $plugin) {
  $theme['excur_guide_other'] = array(
    'path' => $plugin['path'],
    'template' => 'excur-guide-other',
  );
}

/**
 * Process variables for guide_other.tpl.php.
 */
function template_preprocess_excur_guide_other(&$vars) {

}