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
  global $user;

  // Get site logo.
  $vars['logo'] = theme('image', array(
    'path' => theme_get_setting('logo_path'),
    'alt' => t(variable_get('site_name')),
    'title' => t(variable_get('site_name')),
  ));

  // Get search form.
  $vars['search_form'] = drupal_get_form('excur_search_search_form');

  // Add language switcher block.
  $vars['language_switcher'] = drupal_get_form('excur_language_switcher');

  // Get footer menu.
  $footer_menu = i18n_menu_translated_tree('menu-footer-menu');
  foreach ($footer_menu as &$item) {
    if (empty($item['#href'])) {
      continue;
    }

    $item['#attributes']['class'][] = 'span3';
  }
  $vars['footer_menu'] = $footer_menu;

  // Add currency change form.
   $vars['currency_switcher'] = drupal_get_form('excur_currency_choice_form');

  // Get main menu.
  foreach (i18n_menu_translated_tree('main-menu') as $item) {
    if (!isset($item['#href'])) {
      continue;
    }

    $vars['main_menu'][] = array(
      'title' => $item['#title'],
      'url' => url($item['#href'], array('absolute' => TRUE)),
      'class' => current_path() == $item['#href'] ? array('active') : array(),
    );
  }

  // Get user links.
  if (user_is_logged_in()) {
    $items = array(
      l(t('User profile'), "user/$user->uid"),
      l(t('Logout'), 'user/logout'),
    );
  }
  else {
    $items = array(
      l(t('Login'), 'user/login'),
      l(t('Register'), 'user/register'),
    );
  }
  $vars['user_links'] = exc_theme_ul_item_list(array(
    'items' => $items,
    'attributes' => array(
      'class' => array('nav', 'nav-right'),
    ),
  ));

  // Render breadcrumb.
  if (menu_get_object('user')) {
    $vars['breadcrumb'] = '';
  }
  else {
    $vars['breadcrumb'] = theme('breadcrumb', array('breadcrumb' => excur_get_breadcrumb()));
  }
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
 * Process variables for views-view-field--term--city--name-field.tpl.php.
 */
function exc_theme_preprocess_views_view_field__term__city__name_field(&$vars) {
  $vars['output'] .= ' (' . excur_count_service_by_city($vars['row']->tid) . ')';
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
 * Process variables for node--service-teaser.tpl.php.
 */
function exc_theme_preprocess_node__service_teaser(&$vars) {
  global $language;
  global $user;

  $node = $vars['node'];
  $wrapper = entity_metadata_wrapper('node', $node);
  $wrapper->language($language->language);
  $guide = user_load($node->field_guide[LANGUAGE_NONE][0]['target_id']);

  if (!empty($guide->field_image[LANGUAGE_NONE])) {
    $path = $guide->field_image[LANGUAGE_NONE][0]['uri'];
    $theming = 'image_style';
  }
  else {
    $path = EXCUR_FRONT_THEME_PATH . '/images/user-default.png';
    $theming = 'remote_image_style';
  }
  $guide_image = theme($theming, array(
    'style_name' => '70x70',
    'path' => $path,
    'alt' => $guide->field_name[LANGUAGE_NONE][0]['safe_value'],
    'title' => $guide->field_name[LANGUAGE_NONE][0]['safe_value'],
  ));
  $vars['guide'] = array(
    'title' => l($guide->field_name[LANGUAGE_NONE][0]['value'], "user/$guide->uid"),
    'image' => l($guide_image, "user/$guide->uid", array('html' => TRUE)),
  );

  $vars['read_more'] = l('<i class="fa fa-search"></i>' . t('Read more'), "node/$node->nid", array('html' => TRUE));
  $vars['book'] = l(t('book'), "node/$node->nid", array('html' => TRUE));

  $price = excur_currency_lowest_price($node);
  if (!empty($_COOKIE['excur_currency']) && $_COOKIE['excur_currency'] != EXCUR_CURRENCY_DEFAULT) {
    $currency = $_COOKIE['excur_currency'];
    $price = excur_currency_convert($price, EXCUR_CURRENCY_DEFAULT, $currency);
  }
  else {
    $currency = EXCUR_CURRENCY_DEFAULT;
  }

  $vars['price'] = $price;
  $vars['currency'] = excur_currency_get_icon($currency);

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
function exc_theme_preprocess_views_view_fields__offers__guide_offers(&$vars){
  if (!empty($vars['row']->field_field_image)) {
    $path_image = $vars['row']->field_field_image[0]['raw']['uri'];
    $vars['image'] = theme('image', array(
      'path' => $path_image,
      'width' => '150px',
      'height' => '150px',
    ));
  }

  $vars['title'] = $vars['fields']['title']->content;
  $vars['guide'] = $vars['fields']['field_name_1']->content;
  $vars['id'] = $vars['fields']['id']->content;
  $vars['data'] = $vars['fields']['data']->content;
  $nid = $vars['row']->node_excur_offer_nid;
  $id = $vars['row']->excur_offer_id;
  $vars['details'] = l(t('details'),'excur/offer/pay/'. $nid, array('query' => array('id' => $id)));

  $value = $vars['row']->excur_offer_status;
  switch ($value){
    case EXCUR_OFFER_NOT_CONFIRMED:
      $vars['fields']['status']->content = '<div class="content_confirm' . $id . '">';
      $vars['fields']['status']->content .= t('Awaiting confirmation');
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
      $value['status'] = '<div class="content_confirm"' . $id . '">' . t('Confirmed') . '</div>';
      break;
    case EXCUR_OFFER_REJECTED:
      $value['status'] = '<div id="content_confirm"' . $id . '">' . t('Rejected') . '</div>';
      break;
  }
}

/**
 * Process variables for views-view-fields--offers--user-offers.tpl.php
 */
function exc_theme_preprocess_views_view_fields__offers__user_offers(&$vars) {
  if (!empty($vars['row']->field_field_image)) {
    $path_image = $vars['row']->field_field_image[0]['raw']['uri'];
    $vars['image'] = theme('image', array(
      'path' => $path_image,
      'width' => '150px',
      'height' => '150px',
    ));
  }

  $vars['title'] = $vars['fields']['title']->content;
  $vars['guide'] = $vars['fields']['field_name']->content;
  $vars['id'] = $vars['fields']['id']->content;
  $vars['data'] = $vars['fields']['date']->content;
  $vars['status'] = $vars['fields']['status']->content;
  $nid = $vars['row']->node_excur_offer_nid;
  $id = $vars['row']->excur_offer_id;
  $vars['guide_image'] = $vars['fields']['field_image_1']->content;
  $vars['details'] = l(t('details'),'excur/offer/pay/'. $nid, array('query' => array('id' => $id)));
}

/**
 * Process variables for order-template.tpl.php
 */
function exc_theme_preprocess_order_template(&$vars){
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

  $guide_image_path = $guide->field_image[LANGUAGE_NONE][0]['uri'];
  if(empty($guide_image_path)){
    $guide_image_path ='public/sites/all/themes/exc_theme/images/user-default.png';
  }

  if (!empty($node->field_image)) {
    $vars['image'] = theme('image_style', array(
      'style_name' => '470x470',
      'path' => $node->field_image[LANGUAGE_NONE][0]['uri'],
    ));
  }

  $vars['offer'] = array(
    'title' => $title_offer,
    'guide_name' => l($guide->name, "user/$guide->uid"),
    'country_name' => l($country->name, "taxonomy/term/$country->tid"),
    'city_name' => l($city->name, "taxonomy/term/$city->tid"),
    'id' => $offer->id,
    'ticket_type' => $offer->ticket_type ,
    'price' => $offer->ticket,
    'currency' => excur_currency_get_icon($offer->currency),
    'offer' => $offer->offer,
    'date' => $offer->date,
    'duration' => $offer->duration,
  );

  $vars['guide_image'] = theme('image', array(
    'path' => $guide_image_path,
    'width' => '95%',
    'height' => '95%',
    'attributes' => array('class' => array('imggd')),
  ));

  $vars['form'] = drupal_get_form('excur_offer_order_form', $node);
}

/**
 * Process variables for pay-template.tpl.php
 */
function exc_theme_preprocess_pay_template(&$vars){
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

  $vars['offer'] = array(
    'title' => $node->title,
    'date' => $offer->date,
    'ticket' => $offer->ticket,
    'currency' => $offer->currency,
    'id' => $offer->id,
    'language' => $offer->language,
    'offer' => $offer->offer,
    'city_name' => l($city->name, "taxonomy/term/$city->tid"),
    'country_name' => l($country->name, "taxonomy/term/$country->tid"),
    'guide_name' => l($guide->name, "user/$guide->uid"),
    'ticket_type' => $offer->ticket_type,
    'price' => $offer->ticket,
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

  $vars['guide_image'] = excur_guide_logo($guide, '238x238', array('class' => array('imggd')));
  $vars['form'] = drupal_get_form('excur_offer_pay_form');
}

/**
 * Process variables for excur-user-menu.tpl.php.
 */
function exc_theme_preprocess_excur_user_menu(&$vars) {
  $account = $vars['account'];
  $uid = $account->uid;

  $vars['menu']['news'] = l(t('News and notices'), "user/$uid");
  $vars['menu']['messages'] = l(t('Messages'), 'user/' . $uid . '/messages');
  $vars['menu']['profile'] = l(t('Profile'), 'user/' . $uid . '/edit');
  $vars['menu']['bookings'] = l(t('My bookings'), 'user/' .$uid. '/bookings');
  if (!empty($account->roles[EXCUR_USER_ROLE_GUIDE_ID])) {
    $vars['menu']['offers'] = l(t('My offers'), 'user/' .$uid. '/offer');
    $vars['menu']['orders'] = l(t('My orders '),'user/' .$uid. '/order');
  }
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
}

/**
 * Process variables for excur-user-bookings.tpl.php
 */
function exc_theme_preprocess_excur_user_bookings(&$vars){
  $account = $vars['account'];

  $vars['user_menu'] = excur_user_menu($account);
  $vars['bookings'] = views_embed_view('offers', 'user_offers');
}

/**
 * Process variables for excur-user-order.tpl.php
 */
function exc_theme_preprocess_excur_user_order(&$vars){
  $account = $vars['account'];

  $vars['user_menu'] = excur_user_menu($account);
  $vars['order'] = views_embed_view('offers', 'guide_offers', $account->uid);
}

/**
 * Process variables for excur-user-offers.tpl.php
 */
function exc_theme_preprocess_excur_user_offers(&$vars){
  $account = $vars['account'];

  $vars['user_menu'] = excur_user_menu($account);
  $vars['offer'] = views_embed_view('content', 'guide_service', $account->uid);

  if (!empty($account->roles[EXCUR_USER_ROLE_GUIDE_ID])) {
    $vars['add_service'] = l(t('Add excursion'), 'node/add/service', array(
      'query' => array(
        'guide' => $account->uid,
      )
    ));
  }
}
