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
  'title' => t('Top, center, left sidebar'),
  'icon' => 'sidebar_left.png',
  'theme' => 'sidebar-left',
  'regions' => array(
    'top' => t('Top'),    
    'content_left' => t('Content: left'),
    'content_center' => t('Content: center'),
  ),
);
