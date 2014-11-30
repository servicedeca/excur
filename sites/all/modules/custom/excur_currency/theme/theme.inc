<?php

/**
 * @file.
 */

/**
 * Preprocess for excur-travel-planner.tpl.php.
 */
function excur_currency_preprocess_excur_currency_switcher(&$vars) {
  $def_currency = excur_offer_user_currency();

  $vars['def_currency'] = excur_currency_get_icon($def_currency);

  $currencies = array(
    EXCUR_CURRENCY_EURO => t('Euro'),
    EXCUR_CURRENCY_US_DOLLAR => t('U.S. Dollar'),
    EXCUR_CURRENCY_RUS_ROUBLE => t('Russian Rouble'),
    EXCUR_CURRENCY_CAN_DOLLAR => t('Canadian Dollar'),
    EXCUR_CURRENCY_CZECH_KORUNA => t('Czech Koruna'),
    EXCUR_CURRENCY_JAPAN_YEN => t('Japanese Yen'),
    EXCUR_CURRENCY_CHINESE_YUAN => t('Chinese Yuan'),
    EXCUR_CURRENCY_GB_POUND => t('Pound sterling'),
    EXCUR_CURRENCY_SWISS_FRANC => t('Swiss Franc'),
  );

  foreach ($currencies as $key => $curr) {
    $vars['currencies'][$key]['class'] = $key == $def_currency
      ? 'active'
      : '';
    $vars['currencies'][$key]['currency'] = $key;
    $vars['currencies'][$key]['title'] = $curr;
    $vars['currencies'][$key]['icon'] = excur_currency_get_icon($key);
  }
}
