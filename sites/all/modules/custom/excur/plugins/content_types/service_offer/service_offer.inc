<?php
/**
 * @file
 * Ctools content type new_message.
 */

/**
 * Implements hook_ctools_content_types().
 */
function excur_service_offer_ctools_content_types() {
  return array(
    'single' => TRUE,
    'title' => t('Service offer'),
    'all contexts' => TRUE,
    'category' => t('Excur'),
    'hook theme' => 'excur_service_offer_content_type_theme',
  );
}

/**
 * Implements hook_content_type_render().
 */
function excur_service_offer_content_type_render($subtype, $conf, $panel_args, $context) {
  $block = new stdClass();
  $block->content = theme('excur_service_offer');

  return $block;
}

/**
 * Implements hook_content_type_theme().
 */
function excur_service_offer_content_type_theme(&$theme, $plugin) {
  $theme['excur_service_offer'] = array(
    'path' => $plugin['path'],
    'template' => 'excur-service-offer',
  );
}

/**
 * Process variables for excur-image-slider.tpl.php.
 */
function template_preprocess_excur_service_offer(&$vars) {
  global $language;
  $node = menu_get_object();

  $wrapper = entity_metadata_wrapper('node', $node);
  $wrapper->language($language->language);

  $currency = $wrapper->field_currency->value();
  $current_currency = excur_offer_user_currency();

  foreach ($wrapper->field_offer->value() as $offer) {
    $offer_tickets = array();

    if (!empty($offer->field_offer_title[$language->language])) {
      $offer_title = $offer->field_offer_title[$language->language][0]['safe_value'];
    }
    else {
      $offer_title = reset($offer->field_offer_title);
      $offer_title = $offer_title[0]['safe_value'];
    }

    if (!empty($offer->field_offer_duration[$language->language])) {
      $offer_duration = $offer->field_offer_duration[$language->language][0]['safe_value'];
    }
    else {
      $offer_duration = reset($offer->field_offer_duration);
      $offer_duration = $offer_duration[0]['safe_value'];
    }

    foreach ($offer->field_offer_ticket[LANGUAGE_NONE] as $offer_ticket_id) {
      $offer_ticket = field_collection_item_load($offer_ticket_id['value']);

      if (!empty($offer_ticket->field_offer_ticket_title[$language->language])) {
        $offer_ticket_title = $offer_ticket->field_offer_ticket_title[$language->language][0]['safe_value'];
      }
      else {
        $offer_ticket_title = reset($offer_ticket->field_offer_ticket_title);
        $offer_ticket_title = $offer_ticket_title[0]['safe_value'];
      }

      $offer_ticket_price = $offer_ticket->field_offer_ticket_price[LANGUAGE_NONE][0]['value'];
      if ($currency != $current_currency) {
        $offer_ticket_price = excur_currency_convert($offer_ticket_price, $currency, $current_currency);
      }

      $offer_tickets[(string) $offer_ticket->field_offer_ticket_price[LANGUAGE_NONE][0]['value']] = array(
        'title' => $offer_ticket_title,
        'price' => $offer_ticket_price,
      );
    }

    $offer_info = array(
      'currency' => excur_currency_get_icon($current_currency),
      'nid' => $node->nid,
      'title' => $offer_title,
      'duration' => $offer_duration,
      'tickets' => $offer_tickets,
      'type' => !empty($offer->field_type_offer)
          ? $offer->field_type_offer[LANGUAGE_NONE][0]['value']
          : EXCUR_OFFER_PRICE_PER_GROUP,
      'id' => $offer->item_id,
    );
    $vars['offers'][] = drupal_get_form('excur_offer_offer_form_' . $offer->item_id, $offer_info);
  }
}
