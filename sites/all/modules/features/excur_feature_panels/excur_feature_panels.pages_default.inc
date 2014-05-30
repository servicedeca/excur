<?php
/**
 * @file
 * excur_feature_panels.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_handlers().
 */
function excur_feature_panels_default_page_manager_handlers() {
  $export = array();

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view_panel_context';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Услуга',
    'no_blocks' => 1,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'service' => 'service',
            ),
          ),
          'context' => 'argument_entity_id:node_1',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'sidebar_right';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'top' => NULL,
      'content_right' => NULL,
      'content_center' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = 'd285f9e4-5e44-4da3-a80a-e2d0352d5b26';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-d618ec66-a8bc-42c1-a7f8-5aaab645a48c';
    $pane->panel = 'content_center';
    $pane->type = 'entity_view';
    $pane->subtype = 'node';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'view_mode' => 'full',
      'context' => 'argument_entity_id:node_1',
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'd618ec66-a8bc-42c1-a7f8-5aaab645a48c';
    $display->content['new-d618ec66-a8bc-42c1-a7f8-5aaab645a48c'] = $pane;
    $display->panels['content_center'][0] = 'new-d618ec66-a8bc-42c1-a7f8-5aaab645a48c';
    $pane = new stdClass();
    $pane->pid = 'new-477bb8f4-5f55-411e-8fe7-e53436500f52';
    $pane->panel = 'content_center';
    $pane->type = 'service_offer';
    $pane->subtype = 'service_offer';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '477bb8f4-5f55-411e-8fe7-e53436500f52';
    $display->content['new-477bb8f4-5f55-411e-8fe7-e53436500f52'] = $pane;
    $display->panels['content_center'][1] = 'new-477bb8f4-5f55-411e-8fe7-e53436500f52';
    $pane = new stdClass();
    $pane->pid = 'new-432b6aa1-e3c6-4be4-9fb4-797a7144c1b7';
    $pane->panel = 'content_right';
    $pane->type = 'service_info';
    $pane->subtype = 'service_info';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '432b6aa1-e3c6-4be4-9fb4-797a7144c1b7';
    $display->content['new-432b6aa1-e3c6-4be4-9fb4-797a7144c1b7'] = $pane;
    $display->panels['content_right'][0] = 'new-432b6aa1-e3c6-4be4-9fb4-797a7144c1b7';
    $pane = new stdClass();
    $pane->pid = 'new-4ec7b092-ce47-4751-b822-83c3b0498919';
    $pane->panel = 'content_right';
    $pane->type = 'guide_block';
    $pane->subtype = 'guide_block';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '4ec7b092-ce47-4751-b822-83c3b0498919';
    $display->content['new-4ec7b092-ce47-4751-b822-83c3b0498919'] = $pane;
    $display->panels['content_right'][1] = 'new-4ec7b092-ce47-4751-b822-83c3b0498919';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-d618ec66-a8bc-42c1-a7f8-5aaab645a48c';
  $handler->conf['display'] = $display;
  $export['node_view_panel_context'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view_panel_context_2';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 1;
  $handler->conf = array(
    'title' => 'Страница',
    'no_blocks' => 1,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'page' => 'page',
            ),
          ),
          'context' => 'argument_entity_id:node_1',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'sidebar_right';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'top' => NULL,
      'content_right' => NULL,
      'content_center' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '825133d7-68b3-4d3b-89cb-71ef2dd177ae';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-51270e6e-dcb3-4728-86fc-051584f5cb89';
    $pane->panel = 'content_center';
    $pane->type = 'entity_view';
    $pane->subtype = 'node';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'view_mode' => 'full',
      'context' => 'argument_entity_id:node_1',
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '51270e6e-dcb3-4728-86fc-051584f5cb89';
    $display->content['new-51270e6e-dcb3-4728-86fc-051584f5cb89'] = $pane;
    $display->panels['content_center'][0] = 'new-51270e6e-dcb3-4728-86fc-051584f5cb89';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-51270e6e-dcb3-4728-86fc-051584f5cb89';
  $handler->conf['display'] = $display;
  $export['node_view_panel_context_2'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'term_view_panel_context';
  $handler->task = 'term_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Континент',
    'no_blocks' => 1,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'term_vocabulary',
          'settings' => array(
            'machine_name' => array(
              'continent' => 'continent',
            ),
          ),
          'context' => 'argument_term_1',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'onecol';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'middle' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '5d557346-b103-4c72-bcbb-a050b6492679';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-365be476-c11e-4e3e-b1b4-c0e264dd9781';
    $pane->panel = 'middle';
    $pane->type = 'term_name';
    $pane->subtype = 'term_name';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '365be476-c11e-4e3e-b1b4-c0e264dd9781';
    $display->content['new-365be476-c11e-4e3e-b1b4-c0e264dd9781'] = $pane;
    $display->panels['middle'][0] = 'new-365be476-c11e-4e3e-b1b4-c0e264dd9781';
    $pane = new stdClass();
    $pane->pid = 'new-a479e2e6-08c4-41f1-8b1d-8afb026198a7';
    $pane->panel = 'middle';
    $pane->type = 'image_slider';
    $pane->subtype = 'image_slider';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'a479e2e6-08c4-41f1-8b1d-8afb026198a7';
    $display->content['new-a479e2e6-08c4-41f1-8b1d-8afb026198a7'] = $pane;
    $display->panels['middle'][1] = 'new-a479e2e6-08c4-41f1-8b1d-8afb026198a7';
    $pane = new stdClass();
    $pane->pid = 'new-88ab184f-430b-4a1a-831d-3cb1cb38aa93';
    $pane->panel = 'middle';
    $pane->type = 'entity_field';
    $pane->subtype = 'taxonomy_term:description_field';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'hidden',
      'formatter' => 'text_default',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(),
      'context' => 'argument_term_1',
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '88ab184f-430b-4a1a-831d-3cb1cb38aa93';
    $display->content['new-88ab184f-430b-4a1a-831d-3cb1cb38aa93'] = $pane;
    $display->panels['middle'][2] = 'new-88ab184f-430b-4a1a-831d-3cb1cb38aa93';
    $pane = new stdClass();
    $pane->pid = 'new-198d7e46-50a3-4bda-9ec0-5ea6c1491af6';
    $pane->panel = 'middle';
    $pane->type = 'country';
    $pane->subtype = 'country';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = '198d7e46-50a3-4bda-9ec0-5ea6c1491af6';
    $display->content['new-198d7e46-50a3-4bda-9ec0-5ea6c1491af6'] = $pane;
    $display->panels['middle'][3] = 'new-198d7e46-50a3-4bda-9ec0-5ea6c1491af6';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['term_view_panel_context'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'term_view_panel_context_2';
  $handler->task = 'term_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 1;
  $handler->conf = array(
    'title' => 'Страна',
    'no_blocks' => 1,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'access' => array(
      'logic' => 'and',
      'plugins' => array(
        0 => array(
          'name' => 'term_vocabulary',
          'settings' => array(
            'machine_name' => array(
              'country' => 'country',
            ),
          ),
          'context' => 'argument_term_1',
          'not' => FALSE,
        ),
      ),
    ),
  );
  $display = new panels_display();
  $display->layout = 'sidebar_left';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'middle' => NULL,
      'left' => NULL,
      'right' => NULL,
      'top' => NULL,
      'content_left' => NULL,
      'content_center' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '17f1d86e-b015-4473-86b2-587440cbb2e7';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-d2310765-d718-44cb-9d7f-4af482b60976';
    $pane->panel = 'content_center';
    $pane->type = 'entity_field';
    $pane->subtype = 'taxonomy_term:description_field';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'hidden',
      'formatter' => 'text_default',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(),
      'context' => 'argument_term_1',
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'd2310765-d718-44cb-9d7f-4af482b60976';
    $display->content['new-d2310765-d718-44cb-9d7f-4af482b60976'] = $pane;
    $display->panels['content_center'][0] = 'new-d2310765-d718-44cb-9d7f-4af482b60976';
    $pane = new stdClass();
    $pane->pid = 'new-bd51ccdd-a106-417a-9826-7ac53c289e82';
    $pane->panel = 'content_center';
    $pane->type = 'city';
    $pane->subtype = 'city';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'bd51ccdd-a106-417a-9826-7ac53c289e82';
    $display->content['new-bd51ccdd-a106-417a-9826-7ac53c289e82'] = $pane;
    $display->panels['content_center'][1] = 'new-bd51ccdd-a106-417a-9826-7ac53c289e82';
    $pane = new stdClass();
    $pane->pid = 'new-dc69c51d-5877-4c3c-98ac-e0f190cd3639';
    $pane->panel = 'content_center';
    $pane->type = 'popular_city';
    $pane->subtype = 'popular_city';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = 'dc69c51d-5877-4c3c-98ac-e0f190cd3639';
    $display->content['new-dc69c51d-5877-4c3c-98ac-e0f190cd3639'] = $pane;
    $display->panels['content_center'][2] = 'new-dc69c51d-5877-4c3c-98ac-e0f190cd3639';
    $pane = new stdClass();
    $pane->pid = 'new-e9b35a02-2cfd-45b9-a234-0a6520159d01';
    $pane->panel = 'content_left';
    $pane->type = 'popular_guide';
    $pane->subtype = 'popular_guide';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'e9b35a02-2cfd-45b9-a234-0a6520159d01';
    $display->content['new-e9b35a02-2cfd-45b9-a234-0a6520159d01'] = $pane;
    $display->panels['content_left'][0] = 'new-e9b35a02-2cfd-45b9-a234-0a6520159d01';
    $pane = new stdClass();
    $pane->pid = 'new-09b18ed3-5c9d-40a7-bdfd-69749692eaa4';
    $pane->panel = 'top';
    $pane->type = 'term_name';
    $pane->subtype = 'term_name';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '09b18ed3-5c9d-40a7-bdfd-69749692eaa4';
    $display->content['new-09b18ed3-5c9d-40a7-bdfd-69749692eaa4'] = $pane;
    $display->panels['top'][0] = 'new-09b18ed3-5c9d-40a7-bdfd-69749692eaa4';
    $pane = new stdClass();
    $pane->pid = 'new-f355c286-77b8-48aa-933b-0ff178bad3f5';
    $pane->panel = 'top';
    $pane->type = 'image_slider';
    $pane->subtype = 'image_slider';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'f355c286-77b8-48aa-933b-0ff178bad3f5';
    $display->content['new-f355c286-77b8-48aa-933b-0ff178bad3f5'] = $pane;
    $display->panels['top'][1] = 'new-f355c286-77b8-48aa-933b-0ff178bad3f5';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['term_view_panel_context_2'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'term_view_panel_context_3';
  $handler->task = 'term_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 2;
  $handler->conf = array(
    'title' => 'Город',
    'no_blocks' => 1,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'term_vocabulary',
          'settings' => array(
            'machine_name' => array(
              'city' => 'city',
            ),
          ),
          'context' => 'argument_term_1',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'sidebar_left';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'top' => NULL,
      'content_left' => NULL,
      'content_center' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '2db4eb66-0061-45f8-b03f-05fc2769de66';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-9b65d86e-353c-4770-92fe-6838e4b3240f';
    $pane->panel = 'content_center';
    $pane->type = 'entity_field';
    $pane->subtype = 'taxonomy_term:description_field';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'hidden',
      'formatter' => 'text_default',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(),
      'context' => 'argument_term_1',
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '9b65d86e-353c-4770-92fe-6838e4b3240f';
    $display->content['new-9b65d86e-353c-4770-92fe-6838e4b3240f'] = $pane;
    $display->panels['content_center'][0] = 'new-9b65d86e-353c-4770-92fe-6838e4b3240f';
    $pane = new stdClass();
    $pane->pid = 'new-a17c2523-ae7e-40f0-9563-87c239075e7c';
    $pane->panel = 'content_center';
    $pane->type = 'views_panes';
    $pane->subtype = 'content-city_service';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'context' => array(
        0 => 'argument_term_1',
      ),
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'a17c2523-ae7e-40f0-9563-87c239075e7c';
    $display->content['new-a17c2523-ae7e-40f0-9563-87c239075e7c'] = $pane;
    $display->panels['content_center'][1] = 'new-a17c2523-ae7e-40f0-9563-87c239075e7c';
    $pane = new stdClass();
    $pane->pid = 'new-ee90fe0e-824d-4aa6-b53b-8fbff695f54b';
    $pane->panel = 'content_left';
    $pane->type = 'popular_guide';
    $pane->subtype = 'popular_guide';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'ee90fe0e-824d-4aa6-b53b-8fbff695f54b';
    $display->content['new-ee90fe0e-824d-4aa6-b53b-8fbff695f54b'] = $pane;
    $display->panels['content_left'][0] = 'new-ee90fe0e-824d-4aa6-b53b-8fbff695f54b';
    $pane = new stdClass();
    $pane->pid = 'new-4c7fe817-2906-4713-90ca-4622c9ec825b';
    $pane->panel = 'top';
    $pane->type = 'term_name';
    $pane->subtype = 'term_name';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '4c7fe817-2906-4713-90ca-4622c9ec825b';
    $display->content['new-4c7fe817-2906-4713-90ca-4622c9ec825b'] = $pane;
    $display->panels['top'][0] = 'new-4c7fe817-2906-4713-90ca-4622c9ec825b';
    $pane = new stdClass();
    $pane->pid = 'new-39e67174-c10d-49b1-b715-43af5c5fe351';
    $pane->panel = 'top';
    $pane->type = 'image_slider';
    $pane->subtype = 'image_slider';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '39e67174-c10d-49b1-b715-43af5c5fe351';
    $display->content['new-39e67174-c10d-49b1-b715-43af5c5fe351'] = $pane;
    $display->panels['top'][1] = 'new-39e67174-c10d-49b1-b715-43af5c5fe351';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-4c7fe817-2906-4713-90ca-4622c9ec825b';
  $handler->conf['display'] = $display;
  $export['term_view_panel_context_3'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'user_view_panel_context';
  $handler->task = 'user_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Гид',
    'no_blocks' => 1,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'role',
          'settings' => array(
            'rids' => array(
              0 => 4,
            ),
          ),
          'context' => 'argument_entity_id:user_1',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'sidebar_left';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'top' => NULL,
      'content_left' => NULL,
      'content_center' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '9be0b58c-d1c5-4ef4-b1e5-1935add10df9';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-0bf105cd-faa9-4edf-b6f6-c713f730c850';
    $pane->panel = 'content_center';
    $pane->type = 'entity_field';
    $pane->subtype = 'user:field_description';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'hidden',
      'formatter' => 'text_default',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(),
      'context' => 'argument_entity_id:user_1',
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'well',
    );
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '0bf105cd-faa9-4edf-b6f6-c713f730c850';
    $display->content['new-0bf105cd-faa9-4edf-b6f6-c713f730c850'] = $pane;
    $display->panels['content_center'][0] = 'new-0bf105cd-faa9-4edf-b6f6-c713f730c850';
    $pane = new stdClass();
    $pane->pid = 'new-f31a7900-9159-4737-a070-5c3fbb31f9c0';
    $pane->panel = 'content_center';
    $pane->type = 'views_panes';
    $pane->subtype = 'content-guide_service';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'f31a7900-9159-4737-a070-5c3fbb31f9c0';
    $display->content['new-f31a7900-9159-4737-a070-5c3fbb31f9c0'] = $pane;
    $display->panels['content_center'][1] = 'new-f31a7900-9159-4737-a070-5c3fbb31f9c0';
    $pane = new stdClass();
    $pane->pid = 'new-420e49dd-afda-442e-ab8e-47d3f9b17772';
    $pane->panel = 'content_left';
    $pane->type = 'guide_info';
    $pane->subtype = 'guide_info';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '420e49dd-afda-442e-ab8e-47d3f9b17772';
    $display->content['new-420e49dd-afda-442e-ab8e-47d3f9b17772'] = $pane;
    $display->panels['content_left'][0] = 'new-420e49dd-afda-442e-ab8e-47d3f9b17772';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['user_view_panel_context'] = $handler;

  return $export;
}

/**
 * Implements hook_default_page_manager_pages().
 */
function excur_feature_panels_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'front';
  $page->task = 'page';
  $page->admin_title = 'Главная страница';
  $page->admin_description = '';
  $page->path = '<front>';
  $page->access = array();
  $page->menu = array();
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_front_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'front';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Панель',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
  );
  $display = new panels_display();
  $display->layout = 'onecol';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'middle' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '4bc15ebb-e089-4e51-9b89-acb6ba898fac';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-b2141861-201d-49f6-a2ce-59eaa5627b33';
    $pane->panel = 'middle';
    $pane->type = 'main_form';
    $pane->subtype = 'main_form';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'b2141861-201d-49f6-a2ce-59eaa5627b33';
    $display->content['new-b2141861-201d-49f6-a2ce-59eaa5627b33'] = $pane;
    $display->panels['middle'][0] = 'new-b2141861-201d-49f6-a2ce-59eaa5627b33';
    $pane = new stdClass();
    $pane->pid = 'new-1a46c8a7-9a9b-436d-b299-5dcf8a6eec3a';
    $pane->panel = 'middle';
    $pane->type = 'image_slider';
    $pane->subtype = 'image_slider';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '1a46c8a7-9a9b-436d-b299-5dcf8a6eec3a';
    $display->content['new-1a46c8a7-9a9b-436d-b299-5dcf8a6eec3a'] = $pane;
    $display->panels['middle'][1] = 'new-1a46c8a7-9a9b-436d-b299-5dcf8a6eec3a';
    $pane = new stdClass();
    $pane->pid = 'new-dc8a42f1-2ecc-4da0-88b9-2422faa7f3d3';
    $pane->panel = 'middle';
    $pane->type = 'text_blocks';
    $pane->subtype = 'text_blocks';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = 'dc8a42f1-2ecc-4da0-88b9-2422faa7f3d3';
    $display->content['new-dc8a42f1-2ecc-4da0-88b9-2422faa7f3d3'] = $pane;
    $display->panels['middle'][2] = 'new-dc8a42f1-2ecc-4da0-88b9-2422faa7f3d3';
    $pane = new stdClass();
    $pane->pid = 'new-f775392b-6fd5-4c6e-8aec-7e7d95be50e2';
    $pane->panel = 'middle';
    $pane->type = 'continents';
    $pane->subtype = 'continents';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = 'f775392b-6fd5-4c6e-8aec-7e7d95be50e2';
    $display->content['new-f775392b-6fd5-4c6e-8aec-7e7d95be50e2'] = $pane;
    $display->panels['middle'][3] = 'new-f775392b-6fd5-4c6e-8aec-7e7d95be50e2';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['front'] = $page;

  return $pages;

}