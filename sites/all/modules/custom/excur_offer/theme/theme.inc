<?php

/**
 * @file.
 */

/**
 * Preprocess for contact-site-form.tpl.php.
 * @see contact-site-form.tpl.php
 */
function excur_offer_preprocess_offer_mail(&$vars) {
  global $language;

  $offer = $vars['offer'];
  $service = node_load($offer->nid);
  $wrapper = entity_metadata_wrapper('node', $service);
  $wrapper->language($language->language);
  $guide = $wrapper->field_guide->value();
  $city = $wrapper->field_city->value();
  $country = taxonomy_term_load($city->field_country['und'][0]['target_id']);

  $vars['title'] = $service->title;
  $vars['contacts'] = variable_get('site_mail');
  $vars['logo'] = theme('image', array(
    'title' => variable_get('site_name'),
    'alt' => variable_get('site_name'),
    'path' => theme_get_setting('logo'),
  ));
  $vars['price'] = excur_currency_convert($offer->ticket, EXCUR_CURRENCY_DEFAULT, $offer->currency);
  $vars['duration'] = excur_offer_duration_by_price($offer->ticket, $offer->nid);
  $vars['venue'] = $wrapper->field_start_place->value();
  $vars['meeting_time'] = $wrapper->field_start_time->value();
  $vars['guide_name'] = $guide->field_name[LANGUAGE_NONE][0]['safe_value'];
  $vars['guide_contacts'] = $guide->mail;
  if (!empty($guide->field_phone)) {
    $vars['guide_contacts'] .= ' (' . $guide->field_phone[LANGUAGE_NONE][0]['value'] . ')';
  }
  $vars['country'] = $city->name . ', ' . $country->name;
  $vars['languages'] = '';
  foreach ($wrapper->field_languages->value() as $lang) {
    if ($lang == end($wrapper->field_languages->value())) {
      $vars['languages'] .= $lang->name;
    }
    else {
      $vars['languages'] .= "$lang->name, ";
    }
  }
}
