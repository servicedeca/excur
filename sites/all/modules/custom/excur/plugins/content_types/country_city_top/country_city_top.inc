<?php
/**
 * @file
 * Ctools content type new_message.
 */

/**
 * Implements hook_ctools_content_types().
 */
function excur_country_city_top_ctools_content_types() {
  return array(
    'single' => TRUE,
    'title' => t('Country/city top'),
    'all contexts' => TRUE,
    'category' => t('Excur'),
    'hook theme' => 'excur_country_city_top_content_type_theme',
  );
}

/**
 * Implements hook_content_type_render().
 */
function excur_country_city_top_content_type_render($subtype, $conf, $panel_args, $context) {
  $block = new stdClass();
  $block->content = theme('excur_country_city_top');

  return $block;
}

/**
 * Implements hook_content_type_theme().
 */
function excur_country_city_top_content_type_theme(&$theme, $plugin) {
  $theme['excur_country_city_top'] = array(
    'path' => $plugin['path'],
    'template' => 'excur-country-city-top',
  );
}

/**
 * Process variables for excur-image-slider.tpl.php.
 */
function template_preprocess_excur_country_city_top(&$vars) {
  $title = t('More about the project');
  $vars['link'] = l($title, 'http://stekos.ru', array(
    'attributes' => array(
      'target' => '_blank',
      'class' => array('stekos-project'),
      'title' => $title,
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
