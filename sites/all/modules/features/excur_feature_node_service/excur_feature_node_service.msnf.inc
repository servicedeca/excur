<?php
/**
 * @file
 * excur_feature_node_service.msnf.inc
 */

/**
 * Implements hook_msnf_step_info().
 */
function excur_feature_node_service_msnf_step_info() {
  $export = array();

  $msnf = new stdClass();
  $msnf->disabled = FALSE; /* Edit this to true to make a default msnf disabled initially */
  $msnf->api_version = 1;
  $msnf->identifier = 'step_1|node|service';
  $msnf->step_name = 'step_1';
  $msnf->entity_type = 'node';
  $msnf->bundle = 'service';
  $msnf->data = array(
    'label' => 'Description',
    'weight' => '24',
    'children' => array(
      0 => 'body',
      1 => 'title_field',
      2 => 'field_city',
      3 => 'field_duration',
      4 => 'field_languages',
      5 => 'field_guide',
      6 => 'field_category',
      7 => 'language',
    ),
    'format_type' => 'default',
    'format_settings' => array(
      'label' => 'Description',
      'instance_settings' => array(
        'skip_non_required' => 1,
        'hide_if_empty' => 0,
        'classes' => '',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h2',
        'buttons' => array(
          'previous' => '',
          'next' => 'Next',
          'skip' => 'Skip',
        ),
      ),
    ),
  );
  $export['step_1|node|service'] = $msnf;

  $msnf = new stdClass();
  $msnf->disabled = FALSE; /* Edit this to true to make a default msnf disabled initially */
  $msnf->api_version = 1;
  $msnf->identifier = 'step_conditions|node|service';
  $msnf->step_name = 'step_conditions';
  $msnf->entity_type = 'node';
  $msnf->bundle = 'service';
  $msnf->data = array(
    'label' => 'Conditions',
    'weight' => '100',
    'children' => array(
      0 => 'field_start_place',
      1 => 'field_excluded',
      2 => 'field_included',
      3 => 'field_reservation',
      4 => 'field_reservation_rules',
      5 => 'field_private_place',
    ),
    'format_type' => 'default',
    'format_settings' => array(
      'label' => 'Conditions',
      'instance_settings' => array(
        'skip_non_required' => 1,
        'hide_if_empty' => 0,
        'classes' => '',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h2',
        'buttons' => array(
          'previous' => 'Back',
          'next' => 'Next',
          'skip' => 'Skip',
        ),
      ),
    ),
  );
  $export['step_conditions|node|service'] = $msnf;

  $msnf = new stdClass();
  $msnf->disabled = FALSE; /* Edit this to true to make a default msnf disabled initially */
  $msnf->api_version = 1;
  $msnf->identifier = 'step_photo|node|service';
  $msnf->step_name = 'step_photo';
  $msnf->entity_type = 'node';
  $msnf->bundle = 'service';
  $msnf->data = array(
    'label' => 'Photos',
    'weight' => '99',
    'children' => array(
      0 => 'field_image',
      1 => 'field_slider_images',
    ),
    'format_type' => 'default',
    'format_settings' => array(
      'label' => 'Photos',
      'instance_settings' => array(
        'skip_non_required' => 1,
        'hide_if_empty' => 0,
        'classes' => '',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h2',
        'buttons' => array(
          'previous' => 'Back',
          'next' => 'Next',
          'skip' => 'Skip',
        ),
      ),
    ),
  );
  $export['step_photo|node|service'] = $msnf;

  $msnf = new stdClass();
  $msnf->disabled = FALSE; /* Edit this to true to make a default msnf disabled initially */
  $msnf->api_version = 1;
  $msnf->identifier = 'step_prices|node|service';
  $msnf->step_name = 'step_prices';
  $msnf->entity_type = 'node';
  $msnf->bundle = 'service';
  $msnf->data = array(
    'label' => 'Prices',
    'weight' => '103',
    'children' => array(
      0 => 'field_currency',
      1 => 'field_offer',
      2 => 'field_start_time',
      3 => 'field_private_time',
    ),
    'format_type' => 'default',
    'format_settings' => array(
      'label' => 'Prices',
      'instance_settings' => array(
        'skip_non_required' => 1,
        'hide_if_empty' => 0,
        'classes' => '',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h2',
        'buttons' => array(
          'previous' => 'Back',
          'next' => 'Save',
          'skip' => 'Skip',
        ),
      ),
    ),
  );
  $export['step_prices|node|service'] = $msnf;

  return $export;
}
