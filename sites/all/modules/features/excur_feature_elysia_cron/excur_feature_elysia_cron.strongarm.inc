<?php
/**
 * @file
 * excur_feature_elysia_cron.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function excur_feature_elysia_cron_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'cron_key';
  $strongarm->value = 'jN94ZGqHVZPPzlK1wVScoFAE0HQKVlgbgaTC36AaMnw';
  $export['cron_key'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'elysia_cron_version';
  $strongarm->value = 20111020;
  $export['elysia_cron_version'] = $strongarm;

  return $export;
}
