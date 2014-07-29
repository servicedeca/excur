<?php
/**
 * @file
 * landing_user.inc
 * Definition of custom panels layout.
 *
 */

// Plugin definition
$plugin = array(
  'category' => t('Excur'),
  'title' => t('Top, center, right sidebar'),
  'icon' => 'sidebar_right.png',
  'theme' => 'sidebar-right',
  'regions' => array(
    'top' => t('Top'),    
    'content_right' => t('Content: right'),
    'content_center' => t('Content: center'),
  ),
);