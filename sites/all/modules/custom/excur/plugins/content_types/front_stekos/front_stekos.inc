<?php
/**
 * @file
 * Ctools content type new_message.
 */

/**
 * Implements hook_ctools_content_types().
 */
function excur_front_stekos_ctools_content_types() {
  return array(
    'single' => TRUE,
    'title' => t('Stekos info'),
    'all contexts' => TRUE,
    'category' => t('Excur'),
    'hook theme' => 'excur_front_stekos_content_type_theme',
  );
}

/**
 * Implements hook_content_type_render().
 */
function excur_front_stekos_content_type_render($subtype, $conf, $panel_args, $context) {
  $block = new stdClass();
  $block->content = theme('excur_front_stekos');

  return $block;
}

/**
 * Implements hook_content_type_theme().
 */
function excur_front_stekos_content_type_theme(&$theme, $plugin) {
  $theme['excur_front_stekos'] = array(
    'path' => $plugin['path'],
    'template' => 'excur-front-stekos',
  );
}

/**
 * Process variables for excur-image-slider.tpl.php.
 */
function template_preprocess_excur_front_stekos(&$vars) {
  $title = t('More about the project');
  $vars['link'] = l($title, 'http://stekos.ru', array(
    'attributes' => array(
      'target' => '_blank',
      'class' => array('stekos-project'),
      'title' => $title,
    ),
  ));

  $vars['icon_st'] = theme('image', array(
    'path' => EXCUR_FRONT_THEME_PATH . '/images/st.png',
    'title' => 'Stekos',
    'alt' => 'Stekos',
    'attributes' => array(
      'class' => array('stekos-st'),
    ),
  ));

  $title = t('Get your travel');
  $vars['icon_gyt'] = theme('image', array(
    'path' => EXCUR_FRONT_THEME_PATH . '/images/gyt.png',
    'title' => $title,
    'alt' => $title,
    'attributes' => array(
      'class' => array('stekos-gyt'),
    ),
  ));

  $vars['icon_stekoss'] = theme('image', array(
    'path' => EXCUR_FRONT_THEME_PATH . '/images/stekoss.png',
    'title' => 'Stekos',
    'alt' => 'Stekos',
    'attributes' => array(
      'class' => array('stekoss'),
    ),
  ));
}
