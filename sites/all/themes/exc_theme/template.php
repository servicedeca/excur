<?php
/**
 * @file
 */

function exc_theme_theme() {
  $items['remote_image_style'] = array(
    'variables' => array(
      'style_name' => NULL,
      'path' => NULL,
      'width' => NULL,
      'height' => NULL,
      'alt' => '',
      'title' => NULL,
      'attributes' => array(),
    ),
  );

  return $items;
}

/**
 * Process variables for page.tpl.php.
 */
function exc_theme_preprocess_page(&$vars, $hook) {
  // Get site logo.
  $vars['logo'] = theme('image', array(
    'path' => theme_get_setting('logo_path'),
    'alt' => t(variable_get('site_name')),
    'title' => t(variable_get('site_name')),
    'attributes' => array(
      'class' => array('minilogo'),
    ),
  ));

  // Get search form.
  $search_form = drupal_get_form('excur_search_search_form');
  $search_form['#attributes']['class'][] = 'head-search-form';
  $search_form['search']['#attributes']['class'][] = 'form-control';
  $search_form['search']['#attributes']['class'][] = 'search-form';
  $search_form['#theme'] = 'excur_search_header_form';
  $vars['search_form'] = $search_form;

  // Add language switcher block.
  $vars['language_switcher'] = theme('excur_language_switcher');

  // Add currency change form.
  $vars['currency_switcher'] = theme('excur_currency_switcher');

  if (user_is_anonymous()) {
    $vars['login_form'] = drupal_get_form('user_login');
    $vars['register_form'] = drupal_get_form('user_register_form');
  }

  if ($contact_phone = variable_get('excur_contact_phone')) {
    $vars['contact_phone'] = $contact_phone;
  }

  // Get footer menu.
  $i = 0;
  foreach (i18n_menu_translated_tree('menu-footer-menu') as $item) {
    if (empty($item['#href'])) {
      continue;
    }

    foreach ($item['#below'] as $link) {
      if (!$link['#title']) {
        continue;
      }
      $vars['footer_menu'][$i][] = l($link['#title'], $link['#href']);
    }
    $vars['footer_menu_title'][$i] = $item['#title'];
    $i += 2;
  }

  $options = array(
    'html' => TRUE,
    'external' => TRUE,
    'attributes' => array(
      'class' => array(
        'btn-social',
        'btn-outline',
      ),
    ),
  );

  $vars['footer_menu_title'][1] = t('Join us');
  $vars['footer_menu'][1] = array(
    l('<i class="fa fa-fw fa-facebook"></i>', 'http://facebook.com', $options),
    l('<i class="fa fa-fw fa-google-plus"></i>', 'http://google-plus.com', $options),
    l('<i class="fa fa-fw fa-vk"></i>', 'http://vk.com', $options),
    l('<i class="fa fa-fw fa-twitter"></i>', 'http://twitter.com', $options),
    l('<i class="fa fa-fw fa-linkedin"></i>', 'http://linkedin.com', $options),
  );
  ksort($vars['footer_menu']);
}

/**
 * Main views view preprocess.
 */
function exc_theme_preprocess_views_view(&$vars) {
  if (!empty($vars['theme_hook_suggestion'])) {
    $function = 'exc_theme_preprocess_' . $vars['theme_hook_suggestion'];
    if (function_exists($function)) {
      $function($vars);
    }
  }
}

/**
 * Main views view field preprocess.
 */
function exc_theme_preprocess_views_view_field(&$vars) {
  if (!empty($vars['theme_hook_suggestion'])) {
    $function = 'exc_theme_preprocess_' . $vars['theme_hook_suggestion'];
    if (function_exists($function)) {
      $function($vars);
    }
  }
}

/**
 * Main views view table preprocess.
 */
function exc_theme_preprocess_views_view_table(&$vars) {
  if (!empty($vars['theme_hook_suggestion'])) {
    $function = 'exc_theme_preprocess_' . $vars['theme_hook_suggestion'];
    if (function_exists($function)) {
      $function($vars);
    }
  }
}

/**
 * Process variables for views-view-fields.tpl.php.
 */
function exc_theme_preprocess_views_view_fields(&$vars) {
  if (isset($vars['theme_hook_suggestion'])) {
    $function = 'exc_theme_preprocess_' . $vars['theme_hook_suggestion'];
    if (function_exists($function)) {
      $function($vars);
    }
  }
}

/**
 * Process variables for views-view-fields.tpl.php.
 */
function exc_theme_preprocess_views_view_unformatted(&$vars) {
  if (isset($vars['theme_hook_suggestion'])) {
    $function = 'exc_theme_preprocess_' . $vars['theme_hook_suggestion'];
    if (function_exists($function)) {
      $function($vars);
    }
  }
}

/**
 * Process variables for views-view-field--term--city--name-field.tpl.php.
 */
function exc_theme_preprocess_views_view_field__term__city__name_field(&$vars) {
  $vars['output'] .= ' (' . excur_count_service_by_city($vars['row']->tid) . ')';
}

/**
 * Process variables for views-view-field--term--city--name-field.tpl.php.
 */
function exc_theme_preprocess_views_view_unformatted__term__continent(&$vars) {
  global $language;

  $vars['lang'] = $language->prefix;
  foreach ($vars['view']->result as $id => $result) {
    $term = taxonomy_term_load($result->tid);
    $wrapper = entity_metadata_wrapper('taxonomy_term', $term);
    foreach ($wrapper->field_slider_images->value() as $image) {
      $vars['image'][$id][] = theme('image_style', array(
        'style_name' => '309x183',
        'path' => $image['uri'],
        'alt' => $term->name,
        'title' => $term->name,
        'attributes' => array(
          'class' => array(
            'img-responsive',
            'image-cont',
          ),
        ),
      ));
    }
    $vars['tid'][$id] = $term->tid;
    $vars['title'][$id] = $term->name;
  }
}

/**
 * Process variables for views-view-field--term--city--name-field.tpl.php.
 */
function exc_theme_preprocess_views_view_unformatted__term__country(&$vars) {
  foreach ($vars['view']->result as $id => $result) {
    $term = taxonomy_term_load($result->tid);
    $vars['row_' . $id % 4][$id]['icon'] = '<i class="flag flag-' . $term->field_country_code[LANGUAGE_NONE][0]['value'] . '"></i>';
    $vars['row_' . $id % 4][$id]['title'] = l($term->name, "taxonomy/term/$term->tid", array(
      'attributes' => array(
        'title' => $term->name,
      ),
    ));
  }
}

/**
 * Process variables for views-view-field--term--city--name-field.tpl.php.
 */
function exc_theme_preprocess_views_view_unformatted__content__popular_service(&$vars) {
  $term = menu_get_object('taxonomy_term', 2);
  $vars['country'] = $term->name;
}

/**
 * Preprocess variables for taxonomy_term.
 */
function exc_theme_preprocess_taxonomy_term(&$vars, $hook) {
  $term = $vars['term'];
  $view_mode = $vars['view_mode'];

  $vars['theme_hook_suggestions'][] = 'taxonomy_term__' . $term->vocabulary_machine_name . '_' . str_replace('-', '_', $view_mode);
  $preprocesses[] = 'exc_theme_preprocess_taxonomy_term__' . $term->vocabulary_machine_name . '_' . str_replace('-', '_', $view_mode);

  foreach ($preprocesses as $preprocess) {
    if (function_exists($preprocess)) {
      $preprocess($vars, $hook);
    }
  }
}

/**
 * Process variables for taxonomy-term--continent_full.tpl.php.
 */
function exc_theme_preprocess_taxonomy_term__continent_full(&$vars) {
  global $language;

  $term = $vars['term'];
  $wrapper = entity_metadata_wrapper('taxonomy_term', $term);
  $wrapper->language($language->language);

  $desc = $wrapper->description_field->value();
  $vars['description'] = $desc['safe_value'];

  drupal_add_js(array('continentCode' => $term->field_continent_code[LANGUAGE_NONE][0]['value']), 'setting');

  $view = views_get_view('term');
  $view->set_display('country');
  $view->preview = TRUE;
  $view->display_handler->options['filters']['field_continent_target_id']['value']['value'] = $term->tid;
  $view->pre_execute(array());
  $vars['countries'] = $view->display_handler->preview();
  $view->post_execute();
}

/**
 * Process variables for taxonomy-term--country_full.tpl.php.
 */
function exc_theme_preprocess_taxonomy_term__country_full(&$vars) {
  global $language;

  $term = $vars['term'];
  $wrapper = entity_metadata_wrapper('taxonomy_term', $term);
  $wrapper->language($language->language);

  $vars['image'] = theme('image_style', array(
    'style_name' => '100x67',
    'path' => $term->field_image[LANGUAGE_NONE][0]['uri'],
    'title' => $term->name,
    'alt' => $term->name,
    'attributes' => array(
      'class' => array('country-usefull-flag'),
    )
  ));

  $desc = $wrapper->description_field->value();
  $vars['description'] = $desc['safe_value'];

  $continent = $wrapper->field_continent->value();
  drupal_add_js(array('continentCode' => $continent->field_continent_code[LANGUAGE_NONE][0]['value']), 'setting');
}


/**
 * Process variables for taxonomy-term--city_full.tpl.php.
 */
function exc_theme_preprocess_taxonomy_term__city_full(&$vars) {
  global $language;

  $term = $vars['term'];
  $wrapper = entity_metadata_wrapper('taxonomy_term', $term);
  $wrapper->language($language->language);

  $vars['image'] = theme('image_style', array(
    'style_name' => '240x150',
    'path' => $term->field_slider_images[LANGUAGE_NONE][0]['uri'],
    'title' => $term->name,
    'alt' => $term->name,
    'attributes' => array(
      'class' => array('country-usefull-coat'),
    )
  ));

  $desc = $wrapper->description_field->value();
  $vars['description'] = $desc['safe_value'];

  $country = $wrapper->field_country->value();
  $continent = taxonomy_term_load($country->field_continent[LANGUAGE_NONE][0]['target_id']);
  drupal_add_js(array('continentCode' => $continent->field_continent_code[LANGUAGE_NONE][0]['value']), 'setting');
}

/**
 * Preprocess variables for node.
 */
function exc_theme_preprocess_node(&$vars, $hook) {
  $node = $vars['node'];
  $view_mode = $vars['view_mode'];

  $vars['theme_hook_suggestions'][] = 'node__' . $node->type . '_' . str_replace('-', '_', $view_mode);
  $preprocesses[] = 'exc_theme_preprocess_node__' . $node->type . '_' . str_replace('-', '_', $view_mode);

  foreach ($preprocesses as $preprocess) {
    if (function_exists($preprocess)) {
      $preprocess($vars, $hook);
    }
  }
}

/**
 * Process variables for node--service-other.tpl.php.
 */
function exc_theme_preprocess_node__service_other(&$vars) {
  global $language;
  global $user;

  $node = $vars['node'];
  $wrapper = entity_metadata_wrapper('node', $node);
  $wrapper->language($language->language);
  $price = excur_currency_lowest_price($node);
  if (!empty($_COOKIE['excur_currency']) && $_COOKIE['excur_currency'] != EXCUR_CURRENCY_DEFAULT) {
    $currency = $_COOKIE['excur_currency'];
    $price = excur_currency_convert($price, EXCUR_CURRENCY_DEFAULT, $currency);
  }
  else {
    $currency = EXCUR_CURRENCY_DEFAULT;
  }

  $vars['price'] = $price;
  $image_path = $node->field_image[LANGUAGE_NONE][0]['uri'];
  $vars['image'] = theme('image_style', array(
    'style_name' => '70x70',
    'path' => $image_path,
    'alt' => $node->title,
    'title' => $node->title,
  ));
  $vars['currency'] = excur_currency_get_icon($currency);
  $vars['title'] = l($node->title, "node/$node->nid");
}

/**
 * Process variables for node--service-other.tpl.php.
 */
function exc_theme_preprocess_node__service_country_teaser(&$vars) {
  global $language;

  $node = $vars['node'];
  $wrapper = entity_metadata_wrapper('node', $node);
  $wrapper->language($language->language);
  $price = excur_currency_lowest_price($node);
  if (!empty($_COOKIE['excur_currency']) && $_COOKIE['excur_currency'] != EXCUR_CURRENCY_DEFAULT) {
    $currency = $_COOKIE['excur_currency'];
    $price = excur_currency_convert($price, EXCUR_CURRENCY_DEFAULT, $currency);
  }
  else {
    $currency = EXCUR_CURRENCY_DEFAULT;
  }

  $vars['price'] = $price;
  $image_path = $node->field_image[LANGUAGE_NONE][0]['uri'];
  $vars['image'] = theme('image_style', array(
    'style_name' => '225x150',
    'path' => $image_path,
    'alt' => $node->title,
    'title' => $node->title,
    'attributes' => array(
      'class' => array('pop-excur-image'),
    )
  ));
  $vars['currency'] = excur_currency_get_icon($currency);
  $vars['title'] = check_plain($node->title);

  foreach ($wrapper->field_languages->value() as $lang) {
    $vars['langs'][] = $lang->field_lang_code[LANGUAGE_NONE][0]['value'];
  }

  $guide = user_load($node->field_guide[LANGUAGE_NONE][0]['target_id']);
  $vars['guide'] = check_plain($guide->field_name[LANGUAGE_NONE][0]['value']);
  $vars['guide_url'] = url("user/$guide->uid");

  $vars['duration'] = $wrapper->field_duration->value();

  $title = t('Excursion rating');
  $vars['icon_star'] = theme('image', array(
    'path' => EXCUR_FRONT_THEME_PATH . '/images/star.png',
    'alt' => $title,
    'title' => $title,
    'attributes' => array(
      'class' => array('iconstar'),
    ),
  ));

  $title = t('The duration of excursion');
  $vars['icon_time'] = theme('image', array(
    'path' => EXCUR_FRONT_THEME_PATH . '/images/time.png',
    'alt' => $title,
    'title' => $title,
    'attributes' => array(
      'class' => array('icont'),
    ),
  ));

  $rating = fivestar_get_votes('node', $node->nid);
  if (empty($rating['average'])) {
    $rating = t(' Offer is unrated.');
  }
  else {
    $rating = round($rating['average']['value'] / 10, 2);
  }
  $vars['rating'] = $rating;

  $vars['read_more'] = l(t('Read more'), "node/$node->nid", array(
    'html' => TRUE,
    'attributes' => array(
      'class' => array(
        'button-go',
        'button-go-pop',
        'excur-list-button',
      ),
    ),
  ));
}

/**
 * Process variables for node--page-full.tpl.php.
 */
function exc_theme_preprocess_node__page_full(&$vars) {
  $menu = menu_tree_all_data('menu-footer-menu');

  foreach($menu as $value){
    foreach($value['below'] as $key => $value2){
      $vars['menu'][] = l($value2['link']['title'], $value2['link']['href']);
    }
  }
}

/**
 * Process variables for node--service-teaser.tpl.php.
 */
function exc_theme_preprocess_node__service_teaser(&$vars) {
  global $language;
  global $user;

  $node = $vars['node'];
  $wrapper = entity_metadata_wrapper('node', $node);
  $wrapper->language($language->language);
  $guide = user_load($node->field_guide[LANGUAGE_NONE][0]['target_id']);

  $guide_image = excur_guide_logo($guide, '70x70');
  $title = excur_guide_is_company($guide)
    ? $guide->field_company_name[LANGUAGE_NONE][0]['value']
    : $guide->field_name[LANGUAGE_NONE][0]['value'];
  $vars['guide'] = array(
    'title' => l($title, "user/$guide->uid"),
    'image' => l($guide_image, "user/$guide->uid", array('html' => TRUE)),
  );

  $vars['read_more'] = l('<i class="fa fa-search"></i>' . t('Read more'), "node/$node->nid", array('html' => TRUE));
  $vars['book'] = l(t('Book'), "node/$node->nid", array('html' => TRUE));

  $currency = $wrapper->field_currency->value();
  $current_currency = excur_offer_user_currency();
  $price = excur_currency_lowest_price($node);
  if ($currency != $current_currency) {
    $price = excur_currency_convert($price, $currency, $current_currency);
  }

  $vars['price'] = $price;
  $vars['currency'] = excur_currency_get_icon($current_currency);

  foreach ($wrapper->field_languages->value() as $lang) {
    $vars['languages'][] = $lang->field_lang_code[LANGUAGE_NONE][0]['value'];
  }

  if ($user->uid == $guide->uid) {
    $vars['edit_link'] = l(t('Edit'), "node/$node->nid/edit", array(
      'query' => array(
        'destination' => current_path(),
      ),
    ));
  }
}

/**
 * Process variables for node--service-full.tpl.php.
 */
function exc_theme_preprocess_node__service_full(&$vars) {
  global $language;

  $node = $vars['node'];
  $wrapper = entity_metadata_wrapper('node', $node);
  $wrapper->language($language->language);

  if (empty($node->field_slider_images)) {
    $node->field_slider_images[LANGUAGE_NONE][0] = $node->field_image[LANGUAGE_NONE][0];
  }
  if (!empty($node->field_slider_images[LANGUAGE_NONE])) {
    foreach ($node->field_slider_images[LANGUAGE_NONE] as $image) {
      $vars['images'][] = theme('image_style', array(
        'style_name' => '870x653',
        'path' => $image['uri'],
        'alt' => t($image['alt']),
        'title' => t($image['title']),
      ));
    }

    drupal_add_js(EXCUR_FRONT_THEME_PATH . '/js/fotorama.min.js');
    drupal_add_css(EXCUR_FRONT_THEME_PATH . '/css/fotorama.css');
  }

  $vars['venue'] = $wrapper->field_start_place->value();
  $vars['meeting_time'] = $wrapper->field_start_time->value();
}

/**
 * Returns HTML for a select form element.
 */
function exc_theme_select($variables) {
  $element = $variables['element'];
  element_set_attributes($element, array('id', 'name', 'size'));
  _form_set_class($element, array('form-select'));

  return '<select' . drupal_attributes($element['#attributes']) . '>' . exc_theme_form_select_options($element) . '</select>';
}

/**
 * Converts a select form element's options array into HTML.
 */
function exc_theme_form_select_options($element, $choices = NULL) {
  if (!isset($choices)) {
    $choices = $element['#options'];
  }

  $value_valid = isset($element['#value']) || array_key_exists('#value', $element);
  $value_is_array = $value_valid && is_array($element['#value']);
  $options = '';
  foreach ($choices as $key => $choice) {
    if (is_array($choice)) {
      $options .= '<optgroup label="' . $key . '">';
      $options .= exc_theme_form_select_options($element, $choice);
      $options .= '</optgroup>';
    }
    elseif (is_object($choice)) {
      $options .= form_select_options($element, $choice->option);
    }
    else {
      $key = (string) $key;
      if ($value_valid && (!$value_is_array && (string) $element['#value'] === $key || ($value_is_array && in_array($key, $element['#value'])))) {
        $selected = ' selected="selected"';
      }
      else {
        $selected = '';
      }

      $data_content = isset($element['#data-content'][$key]) ? str_replace('"', '\'', $element['#data-content'][$key]) : check_plain($choice);
      $options .= '<option value="' . check_plain($key) . '"' . $selected . ' data-content="' . $data_content . '">' . check_plain($choice) . '</option>';
    }
  }
  return $options;
}

/**
 * Custom item list.
 *
 * @param $vars.
 * @return string.
 */
function exc_theme_ul_item_list($vars) {
  $items = $vars['items'];
  $attributes = $vars['attributes'];
  $output = '';

  if (!empty($items)) {
    $output .= "<ul" . drupal_attributes($attributes) . '>';
    $num_items = count($items);
    $i = 0;
    foreach ($items as $item) {
      $attributes = array();
      $i++;
      $data = $item;

      if ($i == 1) {
        $attributes['class'][] = 'first';
      }
      if ($i == $num_items) {
        $attributes['class'][] = 'last';
      }
      $output .= '<li' . drupal_attributes($attributes) . '>' . $data . "</li>\n";
    }
    $output .= "</ul>";
  }

  return $output;
}

/**
 * Returns HTML for an image using a specific image style.
 *
 * Clones theme_image_style() with the additional step of forcing the creation
 * of the derivative to bypass any 404 issues.
 */
function exc_theme_remote_image_style($variables) {
  // Determine the dimensions of the styled image.
  $dimensions = array(
    'width' => $variables['width'],
    'height' => $variables['height'],
  );
  image_style_transform_dimensions($variables['style_name'], $dimensions);

  $variables['width'] = $dimensions['width'];
  $variables['height'] = $dimensions['height'];

  $image_style_dest_path = image_style_path($variables['style_name'], $variables['path']);
  if (!file_exists($image_style_dest_path)) {
    $style = image_style_load($variables['style_name']);
    image_style_create_derivative($style, $variables['path'], $image_style_dest_path);
  }
  $variables['path'] = file_create_url($image_style_dest_path);
  return theme('image', $variables);
}

/**
 * Process variables for views-view-fields--offers--guide-offers.tpl.php
 */
function exc_theme_preprocess_views_view_fields__offers__guide_offers(&$vars) {
  if (!empty($vars['row']->field_field_image)) {
    $path_image = $vars['row']->field_field_image[0]['raw']['uri'];
    $vars['image'] = theme('image_style', array(
      'style_name' => '170x130',
      'path' => $path_image,
      'attributes' => array('class' => array('b-c-image')),
    ));
  }

  $vars['title'] = $vars['fields']['title']->content;
  $vars['guide'] = $vars['fields']['field_name_1']->content;
  $vars['id'] = $vars['fields']['id']->content;
  $vars['date'] = $vars['fields']['date']->content;
  $nid = $vars['row']->node_excur_offer_nid;
  $id = $vars['row']->excur_offer_id;
  $vars['details'] = l(t('details'),'excur/offer/pay/'. $nid, array('query' => array('id' => $id)));

  $value = $vars['row']->excur_offer_status;
  switch ($value) {
    case EXCUR_OFFER_NOT_CONFIRMED:
      $vars['fields']['status']->content = '<div class="content_confirm' . $id . '">';
      $vars['fields']['status']->content .= '<div class = "order-card-status-inner">';
      $vars['fields']['status']->content .= t('Awaiting confirmation');
      $vars['fields']['status']->content .= '</div>';
      $vars['fields']['status']->content .= '<br/>';
      $vars['fields']['status']->content .= l(t('Confirm'), '#', array(
        'external' => TRUE,
        'attributes' => array(
          'class' => array('confirm-order'),
          'data-id' => $id,
        )
      ));
      $vars['fields']['status']->content .= '<br/>';
      $vars['fields']['status']->content .= l(t('Reject'), '#', array(
        'external' => TRUE,
        'attributes' => array(
          'class' => array('confirm-reject'),
          'data-id' => $id,
        )
      ));
      $vars['fields']['status']->content .= '</div>';
      break;
    case EXCUR_OFFER_CONFIRMED:
      $vars['fields']['status']->content = '<div class="content_confirm"' . $id . '"><div class="order-card-status-inner-confirm">' . t('Confirmed') . '</div></div>';
      break;
    case EXCUR_OFFER_REJECTED:
      $vars['fields']['status']->content = '<div id="content_confirm"' . $id . '"><div class="order-card-status-inner-confirm">' . t('Rejected') . '</div></div>';
      break;
  }
}

/**
 * Process variables for views-view-fields--offers--confirmed-guide-offers.tpl.php
 */
function exc_theme_preprocess_views_view_fields__offers__confirmed_guide_offers(&$vars) {
  if (!empty($vars['row']->field_field_image)) {
    $path_image = $vars['row']->field_field_image[0]['raw']['uri'];
    $vars['image'] = theme('image_style', array(
      'style_name' => '170x130',
      'path' => $path_image,
      'attributes' => array('class' => array('b-c-image')),
    ));
  }

  $vars['title'] = $vars['fields']['title']->content;
  $vars['guide'] = $vars['fields']['field_name_1']->content;
  $vars['id'] = $vars['fields']['id']->content;
  $vars['date'] = $vars['fields']['date']->content;
  $nid = $vars['row']->node_excur_offer_nid;
  $id = $vars['row']->excur_offer_id;
  $vars['details'] = l(t('details'),'excur/offer/pay/'. $nid, array('query' => array('id' => $id)));

  $value = $vars['row']->excur_offer_status;
  switch ($value) {
    case EXCUR_OFFER_NOT_CONFIRMED:
      $vars['fields']['status']->content = '<div class="content_confirm' . $id . '">';
      $vars['fields']['status']->content .= '<div class = "order-card-status-inner">';
      $vars['fields']['status']->content .= t('Awaiting confirmation');
      $vars['fields']['status']->content .= '</div>';
      $vars['fields']['status']->content .= '<br/>';
      $vars['fields']['status']->content .= l(t('Confirm'), '#', array(
        'external' => TRUE,
        'attributes' => array(
          'class' => array('confirm-order'),
          'data-id' => $id,
        )
      ));
      $vars['fields']['status']->content .= '<br/>';
      $vars['fields']['status']->content .= l(t('Reject'), '#', array(
        'external' => TRUE,
        'attributes' => array(
          'class' => array('confirm-reject'),
          'data-id' => $id,
        )
      ));
      $vars['fields']['status']->content .= '</div>';
      break;
    case EXCUR_OFFER_CONFIRMED:
      $vars['fields']['status']->content = '<div class="content_confirm"' . $id . '"><div class="order-card-status-inner-confirm">' . t('Confirmed') . '</div></div>';
      break;
    case EXCUR_OFFER_REJECTED:
      $vars['fields']['status']->content = '<div id="content_confirm"' . $id . '"><div class="order-card-status-inner-confirm">' . t('Rejected') . '</div></div>';
      break;
  }
}

/**
 * Process variables for views-view-fields--offers--archive-guide-offers.tpl.php
 */
function exc_theme_preprocess_views_view_fields__offers__archive_guide_offers(&$vars) {
  if (!empty($vars['row']->field_field_image)) {
    $path_image = $vars['row']->field_field_image[0]['raw']['uri'];
    $vars['image'] = theme('image_style', array(
      'style_name' => '170x130',
      'path' => $path_image,
      'attributes' => array('class' => array('b-c-image')),
    ));
  }

  $vars['title'] = $vars['fields']['title']->content;
  $vars['guide'] = $vars['fields']['field_name_1']->content;
  $vars['id'] = $vars['fields']['id']->content;
  $vars['date'] = $vars['fields']['date']->content;
  $nid = $vars['row']->node_excur_offer_nid;
  $id = $vars['row']->excur_offer_id;
  $vars['details'] = l(t('details'),'excur/offer/pay/'. $nid, array('query' => array('id' => $id)));

  $value = $vars['row']->excur_offer_status;
  switch ($value) {
    case EXCUR_OFFER_NOT_CONFIRMED:
      $vars['fields']['status']->content = '<div class="content_confirm' . $id . '">';
      $vars['fields']['status']->content .= '<div class = "order-card-status-inner">';
      $vars['fields']['status']->content .= t('Awaiting confirmation');
      $vars['fields']['status']->content .= '</div>';
      $vars['fields']['status']->content .= '<br/>';
      $vars['fields']['status']->content .= l(t('Confirm'), '#', array(
        'external' => TRUE,
        'attributes' => array(
          'class' => array('confirm-order'),
          'data-id' => $id,
        )
      ));
      $vars['fields']['status']->content .= '<br/>';
      $vars['fields']['status']->content .= l(t('Reject'), '#', array(
        'external' => TRUE,
        'attributes' => array(
          'class' => array('confirm-reject'),
          'data-id' => $id,
        )
      ));
      $vars['fields']['status']->content .= '</div>';
      break;
    case EXCUR_OFFER_CONFIRMED:
      $vars['fields']['status']->content = '<div class="content_confirm"' . $id . '"><div class="order-card-status-inner-confirm">' . t('Confirmed') . '</div></div>';
      break;
    case EXCUR_OFFER_REJECTED:
      $vars['fields']['status']->content = '<div id="content_confirm"' . $id . '"><div class="order-card-status-inner-confirm">' . t('Rejected') . '</div></div>';
      break;
  }
}

/**
 * Process variables for views-view-fields--offers--rejected-guide-offers.tpl.php
 */
function exc_theme_preprocess_views_view_fields__offers__rejected_guide_offers(&$vars) {
  if (!empty($vars['row']->field_field_image)) {
    $path_image = $vars['row']->field_field_image[0]['raw']['uri'];
    $vars['image'] = theme('image_style', array(
      'style_name' => '170x130',
      'path' => $path_image,
      'attributes' => array('class' => array('b-c-image')),
    ));
  }

  $vars['title'] = $vars['fields']['title']->content;
  $vars['guide'] = $vars['fields']['field_name_1']->content;
  $vars['id'] = $vars['fields']['id']->content;
  $vars['date'] = $vars['fields']['date']->content;
  $nid = $vars['row']->node_excur_offer_nid;
  $id = $vars['row']->excur_offer_id;
  $vars['details'] = l(t('details'),'excur/offer/pay/'. $nid, array('query' => array('id' => $id)));

  $value = $vars['row']->excur_offer_status;
  switch ($value) {
    case EXCUR_OFFER_NOT_CONFIRMED:
      $vars['fields']['status']->content = '<div class="content_confirm' . $id . '">';
      $vars['fields']['status']->content .= '<div class = "order-card-status-inner">';
      $vars['fields']['status']->content .= t('Awaiting confirmation');
      $vars['fields']['status']->content .= '</div>';
      $vars['fields']['status']->content .= '<br/>';
      $vars['fields']['status']->content .= l(t('Confirm'), '#', array(
        'external' => TRUE,
        'attributes' => array(
          'class' => array('confirm-order'),
          'data-id' => $id,
        )
      ));
      $vars['fields']['status']->content .= '<br/>';
      $vars['fields']['status']->content .= l(t('Reject'), '#', array(
        'external' => TRUE,
        'attributes' => array(
          'class' => array('confirm-reject'),
          'data-id' => $id,
        )
      ));
      $vars['fields']['status']->content .= '</div>';
      break;
    case EXCUR_OFFER_CONFIRMED:
      $vars['fields']['status']->content = '<div class="content_confirm"' . $id . '"><div class="order-card-status-inner-confirm">' . t('Confirmed') . '</div></div>';
      break;
    case EXCUR_OFFER_REJECTED:
      $vars['fields']['status']->content = '<div id="content_confirm"' . $id . '"><div class="order-card-status-inner-confirm">' . t('Rejected') . '</div></div>';
      break;
  }
}

/**
 * Process variables for views-view-fields--offers--confirmed-user-offers.tpl.php
 */
function exc_theme_preprocess_views_view_fields__offers__confirmed_user_offers(&$vars) {
  $guide = user_load($vars['row']->users_field_data_field_guide_uid);
  $is_company = excur_guide_is_company($guide);

  if (!empty($vars['row']->field_field_image)) {
    $path_image = $vars['row']->field_field_image[0]['raw']['uri'];
    $vars['image'] = theme('image_style', array(
      'style_name' => '170x130',
      'path' => $path_image,
      'attributes' => array('class' => array('b-c-image')),
    ));
  }

  $vars['title'] = $vars['fields']['title']->content;
  $vars['guide'] = $is_company
    ? $guide->field_company_name[LANGUAGE_NONE][0]['value']
    : $guide->field_name[LANGUAGE_NONE][0]['value'];
  $vars['id'] = $vars['fields']['id']->content;
  $vars['data'] = $vars['fields']['date']->content;
  $vars['status'] = $vars['fields']['status']->content;
  $nid = $vars['row']->node_excur_offer_nid;
  $id = $vars['row']->excur_offer_id;
  $vars['guide_image'] = excur_guide_logo($guide, '70x70');
  $vars['details'] = l(t('details'),'excur/offer/pay/'. $nid, array('query' => array('id' => $id)));
}

/**
 * Process variables for views-view-fields--offers--archive-user-offers.tpl.php
 */
function exc_theme_preprocess_views_view_fields__offers__archive_user_offers(&$vars) {
  $guide = user_load($vars['row']->users_field_data_field_guide_uid);
  $is_company = excur_guide_is_company($guide);

  if (!empty($vars['row']->field_field_image)) {
    $path_image = $vars['row']->field_field_image[0]['raw']['uri'];
    $vars['image'] = theme('image_style', array(
      'style_name' => '170x130',
      'path' => $path_image,
      'attributes' => array('class' => array('b-c-image')),
    ));
  }

  $vars['title'] = $vars['fields']['title']->content;
  $vars['guide'] = $is_company
    ? $guide->field_company_name[LANGUAGE_NONE][0]['value']
    : $guide->field_name[LANGUAGE_NONE][0]['value'];
  $vars['id'] = $vars['fields']['id']->content;
  $vars['data'] = $vars['fields']['date']->content;
  $vars['status'] = $vars['fields']['status']->content;
  $nid = $vars['row']->node_excur_offer_nid;
  $id = $vars['row']->excur_offer_id;
  $vars['guide_image'] = excur_guide_logo($guide, '70x70');
  $vars['details'] = l(t('details'),'excur/offer/pay/'. $nid, array('query' => array('id' => $id)));
}

/**
 * Process variables for views-view-fields--offers--user-offers.tpl.php
 */
function exc_theme_preprocess_views_view_fields__offers__user_offers(&$vars) {
  $guide = user_load($vars['row']->users_field_data_field_guide_uid);
  $is_company = excur_guide_is_company($guide);

  if (!empty($vars['row']->field_field_image)) {
    $path_image = $vars['row']->field_field_image[0]['raw']['uri'];
    $vars['image'] = theme('image_style', array(
      'style_name' => '170x130',
      'path' => $path_image,
      'attributes' => array('class' => array('b-c-image')),
    ));
  }

  $vars['title'] = $vars['fields']['title']->content;
  $vars['guide'] = $is_company
    ? $guide->field_company_name[LANGUAGE_NONE][0]['value']
    : $guide->field_name[LANGUAGE_NONE][0]['value'];
  $vars['id'] = $vars['fields']['id']->content;
  $vars['data'] = $vars['fields']['date']->content;
  $vars['status'] = $vars['fields']['status']->content;
  $nid = $vars['row']->node_excur_offer_nid;
  $id = $vars['row']->excur_offer_id;
  $vars['guide_image'] = excur_guide_logo($guide, '70x70');
  $vars['details'] = l(t('details'),'excur/offer/pay/'. $nid, array('query' => array('id' => $id)));
}

/**
 * Process variables for views-view-fields--offers--rejected-user-offers.tpl.php
 */
function exc_theme_preprocess_views_view_fields__offers__rejected_user_offers(&$vars) {
  $guide = user_load($vars['row']->users_field_data_field_guide_uid);
  $is_company = excur_guide_is_company($guide);

  if (!empty($vars['row']->field_field_image)) {
    $path_image = $vars['row']->field_field_image[0]['raw']['uri'];
    $vars['image'] = theme('image_style', array(
      'style_name' => '170x130',
      'path' => $path_image,
      'attributes' => array('class' => array('b-c-image')),
    ));
  }

  $vars['title'] = $vars['fields']['title']->content;
  $vars['guide'] = $is_company
    ? $guide->field_company_name[LANGUAGE_NONE][0]['value']
    : $guide->field_name[LANGUAGE_NONE][0]['value'];
  $vars['id'] = $vars['fields']['id']->content;
  $vars['data'] = $vars['fields']['date']->content;
  $vars['status'] = $vars['fields']['status']->content;
  $nid = $vars['row']->node_excur_offer_nid;
  $id = $vars['row']->excur_offer_id;
  $vars['guide_image'] = excur_guide_logo($guide, '70x70');
  $vars['details'] = l(t('details'),'excur/offer/pay/'. $nid, array('query' => array('id' => $id)));
}

/**
 * Process variables for order-template.tpl.php
 */
function exc_theme_preprocess_order_template(&$vars) {
  $offer = excur_offer_load($_GET['id']);
  $node = $vars['order'];

  if ($node->type == 'service') {
    $guide = user_load($node->field_guide[LANGUAGE_NONE][0]['target_id']);
  }
  else {
    $guide = user_load($node->uid);
  }

  $city = taxonomy_term_load($node->field_city[LANGUAGE_NONE][0]['target_id']);
  $title_offer = $node->title;
  $country = taxonomy_term_load($city->field_country[LANGUAGE_NONE][0]['target_id']);

  if (!empty($node->field_image)) {
    $vars['image'] = theme('image_style', array(
      'style_name' => '470x470',
      'path' => $node->field_image[LANGUAGE_NONE][0]['uri'],
    ));
  }

  $total_price = 0;
  $tickets = unserialize($offer->ticket);
  foreach ($tickets as $ticket) {
    $total_price += $ticket['price'] * $ticket['count'];
  }

  foreach ($tickets as $ticket_title => $value) {
    $vars['tickets'][] = $ticket_title . ' (' . $value['count'] . ')';
  }

  $title = excur_guide_is_company($guide)
    ? $guide->field_company_name[LANGUAGE_NONE][0]['value']
    : $guide->field_name[LANGUAGE_NONE][0]['value'];

  $vars['offer'] = array(
    'title' => $title_offer,
    'guide_name' => l($title, "user/$guide->uid"),
    'country_name' => l($country->name, "taxonomy/term/$country->tid"),
    'city_name' => l($city->name, "taxonomy/term/$city->tid"),
    'id' => $offer->id,
    'price' => $total_price,
    'currency' => excur_currency_get_icon($offer->currency),
    'offer' => $offer->offer,
    'date' => $offer->date,
    'duration' => $offer->duration,
  );

  $vars['guide_image'] = excur_guide_logo($guide, '238x238');

  $vars['form'] = drupal_get_form('excur_offer_order_form', $node);
}

/**
 * Process variables for pay-template.tpl.php
 */
function exc_theme_preprocess_pay_template(&$vars) {
  $offer = excur_offer_load($_GET['id']);
  $node = node_load($offer->nid);
  $city = taxonomy_term_load($node->field_city[LANGUAGE_NONE][0]['target_id']);
  $country = taxonomy_term_load($city->field_country[LANGUAGE_NONE][0]['target_id']);
  $guide = !empty($node->field_guide)
    ? user_load($node->field_guide[LANGUAGE_NONE][0]['target_id'])
    : user_load($node->uid);

  if (!empty($node->field_image)) {
    $vars['image'] = theme('image_style', array(
      'style_name' => '470x470',
      'path' => $node->field_image[LANGUAGE_NONE][0]['uri'],
    ));
  }

  $total_price = 0;
  $tickets = unserialize($offer->ticket);
  foreach ($tickets as $ticket) {
    $total_price += $ticket['price'] * $ticket['count'];
  }

  foreach ($tickets as $ticket_title => $value) {
    $vars['tickets'][] = $ticket_title . ' (' . $value['count'] . ')';
  }

  $title = excur_guide_is_company($guide)
    ? $guide->field_company_name[LANGUAGE_NONE][0]['value']
    : $guide->field_name[LANGUAGE_NONE][0]['value'];


  $vars['offer'] = array(
    'title' => $node->title,
    'date' => $offer->date,
    'ticket' => $offer->ticket,
    'currency' => excur_currency_get_icon($offer->currency),
    'id' => $offer->id,
    'language' => $offer->language,
    'offer' => $offer->offer,
    'city_name' => l($city->name, "taxonomy/term/$city->tid"),
    'country_name' => l($country->name, "taxonomy/term/$country->tid"),
    'guide_name' => l($title, "user/$guide->uid"),
    'price' => $total_price,
    'duration' => $offer->duration,
    'name' => $offer->name,
    'email' => $offer->email,
    'phone' => $offer->phone,
    'tourist_name' => $offer->tourist_name,
    'tourist_email' => $offer->tourist_email,
    'tourist_phone' => $offer->tourist_phone,
    'venue' => $offer->venue,
    'time' => $offer->start_time,
  );

  $vars['guide_image'] = excur_guide_logo($guide, '238x238');
  $vars['form'] = drupal_get_form('excur_offer_pay_form');
}

/**
 * Process variables for excur-user-menu.tpl.php.
 */
function exc_theme_preprocess_excur_user_menu(&$vars) {
  $account = $vars['account'];
  $uid = $account->uid;

  $vars['menu']['news'] = l(t('News and notices'), "user/$uid");
  $vars['menu']['messages'] = l(t('Messages'), "user/$uid/messages");
  $vars['menu']['profile'] = l(t('Profile'), "user/$uid/edit");
  $vars['menu']['bookings'] = l(t('My bookings'), "user/$uid/bookings");

  if (!empty($account->roles[EXCUR_USER_ROLE_GUIDE_ID])) {
    $vars['menu']['offers'] = l(t('My offers'), "user/$uid/offer");
    $vars['menu']['orders'] = l(t('My orders'), "user/$uid/order");
  }
  else {
    $vars['guide'] = l(t('Become a guide'), "user/$uid/edit", array(
      'query' => array('guide' =>'guide'),
      'attributes' => array(
        'class' => array('btn'),
      ),
    ));
  }

  if (empty($account->roles[EXCUR_USER_ROLE_PARTNER_ID])) {
    $vars['partner'] = l(t('Become a partner'), "user/$uid/edit", array(
      'query' => array('partner' =>'partner'),
      'attributes' => array(
        'class' => array('btn btn-primary'),
      ),
    ));
  }

  $vars['menu']['planner'] = l(t('Travel planner'), "user/$uid/travel-planner");
}

/**
 * Process variables for excur-user-massages.tpl.php.
 */
function exc_theme_preprocess_excur_user_messages(&$vars) {
  $account = $vars['user'];

  $vars['user_menu'] = excur_user_menu($account);
  $vars['messages'] = privatemsg_list_page('list', $account->uid);
}

/**
 * Process variables for excur-user-edit.tpl.php.
 */
function exc_theme_preprocess_excur_user_edit(&$vars) {
  $account = $vars['account'];

  $vars['user_menu'] = excur_user_menu($account);
  $vars['form'] = drupal_get_form('user_profile_form', $account);
  if(isset($_GET['guide']) && $_GET['guide'] == 'guide'){
    $vars['form']['guide']['#checked'] = TRUE;
  }
  if(isset($_GET['partner']) && $_GET['partner'] == 'partner'){
    $vars['form']['partner']['#checked'] = TRUE;
  }
}

/**
 * Process variables for excur-user-bookings.tpl.php
 */
function exc_theme_preprocess_excur_user_bookings(&$vars) {
  $account = $vars['account'];

  $vars['user_menu'] = excur_user_menu($account);
  $vars['confirmed'] = views_embed_view('offers', 'confirmed_user_offers');
  $vars['archive'] = views_embed_view('offers', 'archive_user_offers');
  $vars['rejected'] = views_embed_view('offers', 'rejected_user_offers');
  $vars['not_confirmed'] = views_embed_view('offers', 'user_offers');
}

/**
 * Process variables for excur-user-order.tpl.php
 */
function exc_theme_preprocess_excur_user_order(&$vars) {
  $account = $vars['account'];

  $vars['user_menu'] = excur_user_menu($account);
  $vars['not_confirmed'] = views_embed_view('offers', 'guide_offers', $account->uid);
  $vars['confirmed'] = views_embed_view('offers', 'confirmed_guide_offers', $account->uid);
  $vars['archive'] = views_embed_view('offers', 'archive_guide_offers', $account->uid);
  $vars['rejected'] = views_embed_view('offers', 'rejected_guide_offers', $account->uid);
}

/**
 * Process variables for excur-user-offers.tpl.php
 */
function exc_theme_preprocess_excur_user_offers(&$vars) {
  $account = $vars['account'];

  $vars['user_menu'] = excur_user_menu($account);
  $vars['offer'] = views_embed_view('content', 'guide_service', $account->uid);

  if (!empty($account->roles[EXCUR_USER_ROLE_GUIDE_ID])) {
    $vars['add_service'] = l(t('Add excursion'), 'user/'.$account->uid.'/add_service', array(
      'query' => array(
        'guide' => $account->uid,
      )
    ));
  }
}

/**
 * Process variables for views-view-fields--guide-other.tpl.php
 */
function exc_theme_preprocess_views_view_fields__guide_other(&$vars) {
  $nid = $vars['row']->nid;
  $title = $vars['row']->field_title_field[0]['raw']['value'];
  $vars['title'] = l($title, "node/$nid");
  $path_image = $vars['row']->field_field_image[0]['raw']['uri'];
  $vars['image'] = theme('image_style', array(
    'style_name' => '170x130',
    'path' => $path_image,
    'attributes' => array('class' => array('')),
  ));
}

/**
 * Process variables for views-view-fields--companion-service.tpl.php
 */
function exc_theme_preprocess_views_view_fields__companion_service(&$vars) {
  $guide = user_load($vars['row']->uid);
  $node = menu_get_object();
  $vars['image'] = excur_guide_logo($guide, '70x70');
  $vars['name'] = $vars['fields']['name']->content;
  $vars['message'] = l(t('Write a message'),'excur/companion/message/'.$node->nid.'/'.$guide->uid, array());
}

/**
 * Process variables for views-view-fields--companion-city.tpl.php
 */
function exc_theme_preprocess_views_view_fields__companion_city(&$vars) {
  global $language;

  $node = node_load($vars['fields']['nid']->raw);
  $wrapper = entity_metadata_wrapper('node', $node);
  $wrapper->language($language->language);

  $vars['title'] = l($node->title, "node/$node->nid");
  $image_path = $node->field_image[LANGUAGE_NONE][0]['uri'];
  $vars['image'] = theme('image_style', array(
    'style_name' => '170x130',
    'path' => $image_path,
  ));

  foreach ($wrapper->field_languages->value() as $lang) {
    $vars['languages'][] = $lang->field_lang_code[LANGUAGE_NONE][0]['value'];
  }

  $currency = $wrapper->field_currency->value();
  $current_currency = excur_offer_user_currency();
  $price = excur_currency_lowest_price($node);
  if ($currency != $current_currency) {
    $price = excur_currency_convert($price, $currency, $current_currency);
  }

  $vars['price'] = $price;
  $vars['currency'] = excur_currency_get_icon($current_currency);
}

/**
 * Process variables for comment.tpl.php
 */
function exc_theme_preprocess_comment(&$vars) {
  $account = user_load($vars['comment']->uid);
  $node = $vars['node'];

  $vars['comments'] = $vars['comment']->field_comment[LANGUAGE_NONE][0]['safe_value'];
  $vars['name'] = $account->field_name[LANGUAGE_NONE][0]['safe_value'];
  $vars['date'] = gmdate("m-d-Y", $vars['comment']->created);

  if (!empty($account->field_image[LANGUAGE_NONE])) {
    $path = $account->field_image[LANGUAGE_NONE][0]['uri'];
    $theming = 'image_style';
  }
  else {
    $path = EXCUR_FRONT_THEME_PATH . '/images/user-default.png';
    $theming = 'remote_image_style';
  }
  $vars['user_image'] = theme($theming, array(
    'style_name' => '70x70',
    'path' => $path,
    'alt' => $account->field_name[LANGUAGE_NONE][0]['safe_value'],
    'title' => $account->field_name[LANGUAGE_NONE][0]['safe_value'],
  ));

  $guide_rating = fivestar_get_votes('user', $node->field_guide[LANGUAGE_NONE][0]['target_id'], 'vote', $account->uid);
  $service_rating = fivestar_get_votes('node', $node->nid, 'vote', $account->uid);
  $vars['guide_rating'] = !empty($guide_rating['user']) ? $guide_rating['user']['value'] / 20 : NULL;
  $vars['service_rating'] = !empty($service_rating['user']) ? $service_rating['user']['value'] / 20 : NULL;
}

/**
 * Process variables for comment_wrapper.tpl.php
 */
function exc_theme_preprocess_comment_wrapper(&$vars) {
  $node = $vars['content']['#node'];
  $node_view = node_view($node);
  $guide = user_load($node->field_guide[LANGUAGE_NONE][0]['target_id']);
  $guide = user_view($guide);

  if (user_is_logged_in()) {
    $vars['rating_widget'] = render($node_view['field_offer_rating']);
    $vars['rating_widget_guide'] = render($guide['field_rating']);
  }
}

/**
 * Process variables for comment-form.tpl.php
 */
function exc_theme_preprocess_comment_form(&$vars) {
  $vars['form']['actions']['#attributes']['class'] = array();
  $vars['form']['actions']['submit']['#attributes']['class'][] = 'btn';
}
