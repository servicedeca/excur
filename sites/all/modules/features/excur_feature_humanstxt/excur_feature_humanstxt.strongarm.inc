<?php
/**
 * @file
 * excur_feature_humanstxt.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function excur_feature_humanstxt_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'humanstxt';
  $strongarm->value = '/* TEAM */
	Lead developer: Dmitry Kiselev
	Contact: kiselev.kala4ek [at] gmail.com
	From: Novosibirsk, Russia

	Web developer: Vladimir Usolcev
	Contact: usolcevv [at] mail.ru
	From: Novosibirsk, Russia

	Front-end developer: Nikita Kisarin
	Contact: kisarinnikita [at] yandex.ru
	From: Novosibirsk, Russia

/* SITE */
	Tools: Drupal 7, Git
	IDE: PhpStorm, Photoshop';
  $export['humanstxt'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'humanstxt_display_link';
  $strongarm->value = 1;
  $export['humanstxt_display_link'] = $strongarm;

  return $export;
}
