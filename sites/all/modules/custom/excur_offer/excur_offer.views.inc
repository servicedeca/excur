<?php

/**
 * @file.
 */

function excur_offer_views_data() {
  $data['excur_offer']['table']['group'] = t('Excursionline');

  $data['excur_offer']['table']['base'] = array(
    'field' => 'oid',
    'title' => t('Offers'),
    'help' => t('User offers'),
    'weight' => -10,
  );

  $data['excur_offer']['table']['join'] = array(
    'node' => array(
      'left_field' => 'nid',
      'field' => 'nid',
    ),
    'users' => array(
      'left_field' => 'uid',
      'field' => 'uid',
    ),
  );

  $data['excur_offer']['date'] = array(
    'title' => t('Date'),
    'help' => t('Chosen offer date.'),
    'field' => array(
      'handler' => 'views_handler_field',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );

  $data['excur_offer']['uid'] = array(
    'title' => t('User id'),
    'help' => t('User which make order.'),
    'field' => array(
      'handler' => 'views_handler_field_numeric',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'relationship' => array(
      'base' => 'users',
      'field' => 'uid',
      'handler' => 'views_handler_relationship',
      'label' => t('User'),
    ),
  );

  $data['excur_offer']['nid'] = array(
    'title' => t('Node id'),
    'help' => t('Service which has been ordered.'),
    'field' => array(
      'handler' => 'views_handler_field_numeric',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'relationship' => array(
      'base' => 'node',
      'field' => 'nid',
      'handler' => 'views_handler_relationship',
      'label' => t('Service'),
    ),
  );

  $data['excur_offer']['ticket'] = array(
    'title' => t('Price'),
    'help' => t('Ordered price'),
    'field' => array(
      'handler' => 'views_handler_field_numeric',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );

  $data['excur_offer']['oid'] = array(
    'title' => t('Offer id'),
    'help' => t('Unique offer id'),
    'field' => array(
      'handler' => 'views_handler_field',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );

  return $data;
}
