<?php
/**
 * @file
 * excur_feature_views.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function excur_feature_views_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'content';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Контент';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'ещё';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Применить';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Сбросить';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Сортировать по';
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'По возрастанию';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'По убыванию';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Элементов на страницу';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Все -';
  $handler->display->display_options['pager']['options']['expose']['offset_label'] = 'Пропустить';
  $handler->display->display_options['pager']['options']['tags']['first'] = '« первая';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '‹ предыдущая';
  $handler->display->display_options['pager']['options']['tags']['next'] = 'следующая ›';
  $handler->display->display_options['pager']['options']['tags']['last'] = 'последняя »';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Связь: Содержимое: Entity translation: translations */
  $handler->display->display_options['relationships']['entity_translations']['id'] = 'entity_translations';
  $handler->display->display_options['relationships']['entity_translations']['table'] = 'node';
  $handler->display->display_options['relationships']['entity_translations']['field'] = 'entity_translations';
  /* Поле: Содержимое: Заголовок */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Критерий фильтра: Содержимое: Опубликовано */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Критерий фильтра: Содержимое: Тип */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'news' => 'news',
  );
  /* Критерий фильтра: Перевод сущностей: Язык */
  $handler->display->display_options['filters']['language']['id'] = 'language';
  $handler->display->display_options['filters']['language']['table'] = 'entity_translation';
  $handler->display->display_options['filters']['language']['field'] = 'language';
  $handler->display->display_options['filters']['language']['relationship'] = 'entity_translations';
  $handler->display->display_options['filters']['language']['value'] = array(
    '***CURRENT_LANGUAGE***' => '***CURRENT_LANGUAGE***',
  );

  /* Display: Услуги города */
  $handler = $view->new_display('panel_pane', 'Услуги города', 'city_service');
  $handler->display->display_options['defaults']['use_ajax'] = FALSE;
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['defaults']['group_by'] = FALSE;
  $handler->display->display_options['group_by'] = TRUE;
  $handler->display->display_options['defaults']['query'] = FALSE;
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'mini';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Элементов на страницу';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Все -';
  $handler->display->display_options['pager']['options']['expose']['offset_label'] = 'Пропустить';
  $handler->display->display_options['pager']['options']['tags']['first'] = '« первая';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '‹ предыдущая';
  $handler->display->display_options['pager']['options']['tags']['next'] = 'следующая ›';
  $handler->display->display_options['pager']['options']['tags']['last'] = 'последняя »';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'node';
  $handler->display->display_options['row_options']['links'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Связь: Содержимое: Entity translation: translations */
  $handler->display->display_options['relationships']['entity_translations']['id'] = 'entity_translations';
  $handler->display->display_options['relationships']['entity_translations']['table'] = 'node';
  $handler->display->display_options['relationships']['entity_translations']['field'] = 'entity_translations';
  /* Связь: Содержимое: Предложение (field_offer) */
  $handler->display->display_options['relationships']['field_offer_value']['id'] = 'field_offer_value';
  $handler->display->display_options['relationships']['field_offer_value']['table'] = 'field_data_field_offer';
  $handler->display->display_options['relationships']['field_offer_value']['field'] = 'field_offer_value';
  $handler->display->display_options['relationships']['field_offer_value']['label'] = 'Предложение';
  $handler->display->display_options['relationships']['field_offer_value']['required'] = TRUE;
  $handler->display->display_options['relationships']['field_offer_value']['delta'] = '-1';
  /* Связь: Элемент коллекции полей: Билеты (field_offer_ticket) */
  $handler->display->display_options['relationships']['field_offer_ticket_value']['id'] = 'field_offer_ticket_value';
  $handler->display->display_options['relationships']['field_offer_ticket_value']['table'] = 'field_data_field_offer_ticket';
  $handler->display->display_options['relationships']['field_offer_ticket_value']['field'] = 'field_offer_ticket_value';
  $handler->display->display_options['relationships']['field_offer_ticket_value']['relationship'] = 'field_offer_value';
  $handler->display->display_options['relationships']['field_offer_ticket_value']['label'] = 'Билет';
  $handler->display->display_options['relationships']['field_offer_ticket_value']['required'] = TRUE;
  $handler->display->display_options['relationships']['field_offer_ticket_value']['delta'] = '-1';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Поле: Содержимое: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Критерий сортировки: Excursionline: Node id */
  $handler->display->display_options['sorts']['nid']['id'] = 'nid';
  $handler->display->display_options['sorts']['nid']['table'] = 'excur_offer';
  $handler->display->display_options['sorts']['nid']['field'] = 'nid';
  $handler->display->display_options['sorts']['nid']['group_type'] = 'count';
  $handler->display->display_options['sorts']['nid']['order'] = 'DESC';
  $handler->display->display_options['sorts']['nid']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['nid']['expose']['label'] = 'Рейтингу';
  /* Критерий сортировки: Элемент коллекции полей: Цена (field_offer_ticket_price) */
  $handler->display->display_options['sorts']['field_offer_ticket_price_value']['id'] = 'field_offer_ticket_price_value';
  $handler->display->display_options['sorts']['field_offer_ticket_price_value']['table'] = 'field_data_field_offer_ticket_price';
  $handler->display->display_options['sorts']['field_offer_ticket_price_value']['field'] = 'field_offer_ticket_price_value';
  $handler->display->display_options['sorts']['field_offer_ticket_price_value']['relationship'] = 'field_offer_ticket_value';
  $handler->display->display_options['sorts']['field_offer_ticket_price_value']['group_type'] = 'min';
  $handler->display->display_options['sorts']['field_offer_ticket_price_value']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['field_offer_ticket_price_value']['expose']['label'] = 'Цене';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Контекстный фильтр: Поле: Город (field_city) */
  $handler->display->display_options['arguments']['field_city_target_id']['id'] = 'field_city_target_id';
  $handler->display->display_options['arguments']['field_city_target_id']['table'] = 'field_data_field_city';
  $handler->display->display_options['arguments']['field_city_target_id']['field'] = 'field_city_target_id';
  $handler->display->display_options['arguments']['field_city_target_id']['exception']['title'] = 'Все';
  $handler->display->display_options['arguments']['field_city_target_id']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_city_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_city_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_city_target_id']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Критерий фильтра: Содержимое: Опубликовано */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Критерий фильтра: Перевод сущностей: Язык */
  $handler->display->display_options['filters']['language']['id'] = 'language';
  $handler->display->display_options['filters']['language']['table'] = 'entity_translation';
  $handler->display->display_options['filters']['language']['field'] = 'language';
  $handler->display->display_options['filters']['language']['relationship'] = 'entity_translations';
  $handler->display->display_options['filters']['language']['value'] = array(
    '***CURRENT_LANGUAGE***' => '***CURRENT_LANGUAGE***',
  );
  /* Критерий фильтра: Содержимое: Тип */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'service' => 'service',
  );
  /* Критерий фильтра: Содержимое: Имеет термин таксономии */
  $handler->display->display_options['filters']['tid']['id'] = 'tid';
  $handler->display->display_options['filters']['tid']['table'] = 'taxonomy_index';
  $handler->display->display_options['filters']['tid']['field'] = 'tid';
  $handler->display->display_options['filters']['tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['tid']['expose']['operator_id'] = 'tid_op';
  $handler->display->display_options['filters']['tid']['expose']['label'] = 'Категория';
  $handler->display->display_options['filters']['tid']['expose']['operator'] = 'tid_op';
  $handler->display->display_options['filters']['tid']['expose']['identifier'] = 'tid';
  $handler->display->display_options['filters']['tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  $handler->display->display_options['filters']['tid']['type'] = 'select';
  $handler->display->display_options['filters']['tid']['vocabulary'] = 'category';
  /* Критерий фильтра: Поле: Языки (field_languages) */
  $handler->display->display_options['filters']['field_languages_tid']['id'] = 'field_languages_tid';
  $handler->display->display_options['filters']['field_languages_tid']['table'] = 'field_data_field_languages';
  $handler->display->display_options['filters']['field_languages_tid']['field'] = 'field_languages_tid';
  $handler->display->display_options['filters']['field_languages_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_languages_tid']['expose']['operator_id'] = 'field_languages_tid_op';
  $handler->display->display_options['filters']['field_languages_tid']['expose']['label'] = 'Языки';
  $handler->display->display_options['filters']['field_languages_tid']['expose']['operator'] = 'field_languages_tid_op';
  $handler->display->display_options['filters']['field_languages_tid']['expose']['identifier'] = 'field_languages_tid';
  $handler->display->display_options['filters']['field_languages_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_languages_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  $handler->display->display_options['filters']['field_languages_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_languages_tid']['vocabulary'] = 'languages';
  $handler->display->display_options['argument_input'] = array(
    'field_city_target_id' => array(
      'type' => 'context',
      'context' => 'entity:taxonomy_term.tid',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Поле: Город (field_city)',
    ),
  );
  $handler->display->display_options['inherit_panels_path'] = '1';

  /* Display: Услуги гида */
  $handler = $view->new_display('panel_pane', 'Услуги гида', 'guide_service');
  $handler->display->display_options['defaults']['use_ajax'] = FALSE;
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['defaults']['group_by'] = FALSE;
  $handler->display->display_options['group_by'] = TRUE;
  $handler->display->display_options['defaults']['query'] = FALSE;
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'mini';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Элементов на страницу';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Все -';
  $handler->display->display_options['pager']['options']['expose']['offset_label'] = 'Пропустить';
  $handler->display->display_options['pager']['options']['tags']['first'] = '« первая';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '‹ предыдущая';
  $handler->display->display_options['pager']['options']['tags']['next'] = 'следующая ›';
  $handler->display->display_options['pager']['options']['tags']['last'] = 'последняя »';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'node';
  $handler->display->display_options['row_options']['links'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Связь: Содержимое: Entity translation: translations */
  $handler->display->display_options['relationships']['entity_translations']['id'] = 'entity_translations';
  $handler->display->display_options['relationships']['entity_translations']['table'] = 'node';
  $handler->display->display_options['relationships']['entity_translations']['field'] = 'entity_translations';
  /* Связь: Содержимое: Предложение (field_offer) */
  $handler->display->display_options['relationships']['field_offer_value']['id'] = 'field_offer_value';
  $handler->display->display_options['relationships']['field_offer_value']['table'] = 'field_data_field_offer';
  $handler->display->display_options['relationships']['field_offer_value']['field'] = 'field_offer_value';
  $handler->display->display_options['relationships']['field_offer_value']['label'] = 'Предложение';
  $handler->display->display_options['relationships']['field_offer_value']['delta'] = '-1';
  /* Связь: Элемент коллекции полей: Билеты (field_offer_ticket) */
  $handler->display->display_options['relationships']['field_offer_ticket_value']['id'] = 'field_offer_ticket_value';
  $handler->display->display_options['relationships']['field_offer_ticket_value']['table'] = 'field_data_field_offer_ticket';
  $handler->display->display_options['relationships']['field_offer_ticket_value']['field'] = 'field_offer_ticket_value';
  $handler->display->display_options['relationships']['field_offer_ticket_value']['relationship'] = 'field_offer_value';
  $handler->display->display_options['relationships']['field_offer_ticket_value']['label'] = 'Билет';
  $handler->display->display_options['relationships']['field_offer_ticket_value']['delta'] = '-1';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Поле: Содержимое: Заголовок */
  $handler->display->display_options['fields']['title_field']['id'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['table'] = 'field_data_title_field';
  $handler->display->display_options['fields']['title_field']['field'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['label'] = '';
  $handler->display->display_options['fields']['title_field']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title_field']['settings'] = array(
    'title_style' => '_none',
    'title_link' => 'content',
    'title_class' => '',
  );
  $handler->display->display_options['fields']['title_field']['link_to_entity'] = 1;
  /* Поле: Содержимое: Новость */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['type'] = 'text_trimmed';
  $handler->display->display_options['fields']['body']['settings'] = array(
    'trim_length' => '300',
  );
  /* Поле: Поле: Главное изображение */
  $handler->display->display_options['fields']['field_image']['id'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['table'] = 'field_data_field_image';
  $handler->display->display_options['fields']['field_image']['field'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['label'] = '';
  $handler->display->display_options['fields']['field_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image']['settings'] = array(
    'image_style' => '170x130',
    'image_link' => 'content',
  );
  /* Поле: Поле: Главное изображение */
  $handler->display->display_options['fields']['field_image_1']['id'] = 'field_image_1';
  $handler->display->display_options['fields']['field_image_1']['table'] = 'field_data_field_image';
  $handler->display->display_options['fields']['field_image_1']['field'] = 'field_image';
  $handler->display->display_options['fields']['field_image_1']['relationship'] = 'field_guide_target_id';
  $handler->display->display_options['fields']['field_image_1']['label'] = '';
  $handler->display->display_options['fields']['field_image_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image_1']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image_1']['settings'] = array(
    'image_style' => '70x70',
    'image_link' => 'content',
  );
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Критерий сортировки: Excursionline: Node id */
  $handler->display->display_options['sorts']['nid']['id'] = 'nid';
  $handler->display->display_options['sorts']['nid']['table'] = 'excur_offer';
  $handler->display->display_options['sorts']['nid']['field'] = 'nid';
  $handler->display->display_options['sorts']['nid']['group_type'] = 'count';
  $handler->display->display_options['sorts']['nid']['order'] = 'DESC';
  $handler->display->display_options['sorts']['nid']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['nid']['expose']['label'] = 'Рейтингу';
  /* Критерий сортировки: Элемент коллекции полей: Цена (field_offer_ticket_price) */
  $handler->display->display_options['sorts']['field_offer_ticket_price_value']['id'] = 'field_offer_ticket_price_value';
  $handler->display->display_options['sorts']['field_offer_ticket_price_value']['table'] = 'field_data_field_offer_ticket_price';
  $handler->display->display_options['sorts']['field_offer_ticket_price_value']['field'] = 'field_offer_ticket_price_value';
  $handler->display->display_options['sorts']['field_offer_ticket_price_value']['relationship'] = 'field_offer_ticket_value';
  $handler->display->display_options['sorts']['field_offer_ticket_price_value']['group_type'] = 'min';
  $handler->display->display_options['sorts']['field_offer_ticket_price_value']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['field_offer_ticket_price_value']['expose']['label'] = 'Цене';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Контекстный фильтр: Содержимое: Гид (field_guide) */
  $handler->display->display_options['arguments']['field_guide_target_id']['id'] = 'field_guide_target_id';
  $handler->display->display_options['arguments']['field_guide_target_id']['table'] = 'field_data_field_guide';
  $handler->display->display_options['arguments']['field_guide_target_id']['field'] = 'field_guide_target_id';
  $handler->display->display_options['arguments']['field_guide_target_id']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_guide_target_id']['exception']['title'] = 'Все';
  $handler->display->display_options['arguments']['field_guide_target_id']['default_argument_type'] = 'user';
  $handler->display->display_options['arguments']['field_guide_target_id']['default_argument_options']['user'] = FALSE;
  $handler->display->display_options['arguments']['field_guide_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_guide_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_guide_target_id']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Критерий фильтра: Содержимое: Опубликовано */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Критерий фильтра: Перевод сущностей: Язык */
  $handler->display->display_options['filters']['language']['id'] = 'language';
  $handler->display->display_options['filters']['language']['table'] = 'entity_translation';
  $handler->display->display_options['filters']['language']['field'] = 'language';
  $handler->display->display_options['filters']['language']['relationship'] = 'entity_translations';
  $handler->display->display_options['filters']['language']['value'] = array(
    '***CURRENT_LANGUAGE***' => '***CURRENT_LANGUAGE***',
  );
  /* Критерий фильтра: Содержимое: Тип */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'service' => 'service',
  );
  /* Критерий фильтра: Поле: Языки (field_languages) */
  $handler->display->display_options['filters']['field_languages_tid']['id'] = 'field_languages_tid';
  $handler->display->display_options['filters']['field_languages_tid']['table'] = 'field_data_field_languages';
  $handler->display->display_options['filters']['field_languages_tid']['field'] = 'field_languages_tid';
  $handler->display->display_options['filters']['field_languages_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_languages_tid']['expose']['operator_id'] = 'field_languages_tid_op';
  $handler->display->display_options['filters']['field_languages_tid']['expose']['label'] = 'Языки';
  $handler->display->display_options['filters']['field_languages_tid']['expose']['operator'] = 'field_languages_tid_op';
  $handler->display->display_options['filters']['field_languages_tid']['expose']['identifier'] = 'field_languages_tid';
  $handler->display->display_options['filters']['field_languages_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_languages_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  $handler->display->display_options['filters']['field_languages_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_languages_tid']['vocabulary'] = 'languages';
  $handler->display->display_options['argument_input'] = array(
    'field_city_target_id' => array(
      'type' => 'context',
      'context' => 'entity:taxonomy_term.tid',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Поле: Город (field_city)',
    ),
  );
  $handler->display->display_options['inherit_panels_path'] = '1';

  /* Display: Популярные услуги */
  $handler = $view->new_display('panel_pane', 'Популярные услуги', 'popular_service');
  $handler->display->display_options['defaults']['group_by'] = FALSE;
  $handler->display->display_options['group_by'] = TRUE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '6';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'node';
  $handler->display->display_options['row_options']['links'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Связь: Содержимое: Entity translation: translations */
  $handler->display->display_options['relationships']['entity_translations']['id'] = 'entity_translations';
  $handler->display->display_options['relationships']['entity_translations']['table'] = 'node';
  $handler->display->display_options['relationships']['entity_translations']['field'] = 'entity_translations';
  /* Связь: Entity Reference: Связанная Сущность */
  $handler->display->display_options['relationships']['field_city_target_id']['id'] = 'field_city_target_id';
  $handler->display->display_options['relationships']['field_city_target_id']['table'] = 'field_data_field_city';
  $handler->display->display_options['relationships']['field_city_target_id']['field'] = 'field_city_target_id';
  $handler->display->display_options['relationships']['field_city_target_id']['label'] = 'Город';
  $handler->display->display_options['relationships']['field_city_target_id']['required'] = TRUE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Критерий сортировки: Excursionline: Node id */
  $handler->display->display_options['sorts']['nid']['id'] = 'nid';
  $handler->display->display_options['sorts']['nid']['table'] = 'excur_offer';
  $handler->display->display_options['sorts']['nid']['field'] = 'nid';
  $handler->display->display_options['sorts']['nid']['group_type'] = 'count';
  $handler->display->display_options['sorts']['nid']['order'] = 'DESC';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Контекстный фильтр: Поле: Страна (field_country) */
  $handler->display->display_options['arguments']['field_country_target_id']['id'] = 'field_country_target_id';
  $handler->display->display_options['arguments']['field_country_target_id']['table'] = 'field_data_field_country';
  $handler->display->display_options['arguments']['field_country_target_id']['field'] = 'field_country_target_id';
  $handler->display->display_options['arguments']['field_country_target_id']['relationship'] = 'field_city_target_id';
  $handler->display->display_options['arguments']['field_country_target_id']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_country_target_id']['exception']['title'] = 'Все';
  $handler->display->display_options['arguments']['field_country_target_id']['default_argument_type'] = 'taxonomy_tid';
  $handler->display->display_options['arguments']['field_country_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_country_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_country_target_id']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Критерий фильтра: Содержимое: Опубликовано */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Критерий фильтра: Содержимое: Тип */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'service' => 'service',
  );
  /* Критерий фильтра: Перевод сущностей: Язык */
  $handler->display->display_options['filters']['language']['id'] = 'language';
  $handler->display->display_options['filters']['language']['table'] = 'entity_translation';
  $handler->display->display_options['filters']['language']['field'] = 'language';
  $handler->display->display_options['filters']['language']['relationship'] = 'entity_translations';
  $handler->display->display_options['filters']['language']['value'] = array(
    '***CURRENT_LANGUAGE***' => '***CURRENT_LANGUAGE***',
  );

  /* Display: Новости */
  $handler = $view->new_display('panel_pane', 'Новости', 'news');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'mini';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Элементов на страницу';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Все -';
  $handler->display->display_options['pager']['options']['expose']['offset_label'] = 'Пропустить';
  $handler->display->display_options['pager']['options']['tags']['first'] = '« первая';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '‹ предыдущая';
  $handler->display->display_options['pager']['options']['tags']['next'] = 'следующая ›';
  $handler->display->display_options['pager']['options']['tags']['last'] = 'последняя »';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'node';
  $handler->display->display_options['row_options']['links'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Критерий сортировки: Содержимое: Дата публикации */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';

  /* Display: Другие услуги гида */
  $handler = $view->new_display('panel_pane', 'Другие услуги гида', 'guide_other');
  $handler->display->display_options['defaults']['use_ajax'] = FALSE;
  $handler->display->display_options['defaults']['group_by'] = FALSE;
  $handler->display->display_options['defaults']['query'] = FALSE;
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'node';
  $handler->display->display_options['row_options']['view_mode'] = 'other';
  $handler->display->display_options['row_options']['links'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Связь: Содержимое: Entity translation: translations */
  $handler->display->display_options['relationships']['entity_translations']['id'] = 'entity_translations';
  $handler->display->display_options['relationships']['entity_translations']['table'] = 'node';
  $handler->display->display_options['relationships']['entity_translations']['field'] = 'entity_translations';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Критерий сортировки: Глобальный: Случайно */
  $handler->display->display_options['sorts']['random']['id'] = 'random';
  $handler->display->display_options['sorts']['random']['table'] = 'views';
  $handler->display->display_options['sorts']['random']['field'] = 'random';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Контекстный фильтр: Содержимое: Гид (field_guide) */
  $handler->display->display_options['arguments']['field_guide_target_id']['id'] = 'field_guide_target_id';
  $handler->display->display_options['arguments']['field_guide_target_id']['table'] = 'field_data_field_guide';
  $handler->display->display_options['arguments']['field_guide_target_id']['field'] = 'field_guide_target_id';
  $handler->display->display_options['arguments']['field_guide_target_id']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_guide_target_id']['exception']['title'] = 'Все';
  $handler->display->display_options['arguments']['field_guide_target_id']['default_argument_type'] = 'user';
  $handler->display->display_options['arguments']['field_guide_target_id']['default_argument_options']['user'] = FALSE;
  $handler->display->display_options['arguments']['field_guide_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_guide_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_guide_target_id']['summary_options']['items_per_page'] = '25';
  /* Контекстный фильтр: Содержимое: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['exception']['title'] = 'Все';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['nid']['not'] = TRUE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Критерий фильтра: Содержимое: Опубликовано */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Критерий фильтра: Содержимое: Тип */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'service' => 'service',
  );
  /* Критерий фильтра: Перевод сущностей: Язык */
  $handler->display->display_options['filters']['language']['id'] = 'language';
  $handler->display->display_options['filters']['language']['table'] = 'entity_translation';
  $handler->display->display_options['filters']['language']['field'] = 'language';
  $handler->display->display_options['filters']['language']['relationship'] = 'entity_translations';
  $handler->display->display_options['filters']['language']['value'] = array(
    '***CURRENT_LANGUAGE***' => '***CURRENT_LANGUAGE***',
  );
  $handler->display->display_options['argument_input'] = array(
    'field_city_target_id' => array(
      'type' => 'context',
      'context' => 'entity:taxonomy_term.tid',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Поле: Город (field_city)',
    ),
  );
  $handler->display->display_options['inherit_panels_path'] = '1';
  $translatables['content'] = array(
    t('Master'),
    t('ещё'),
    t('Применить'),
    t('Сбросить'),
    t('Сортировать по'),
    t('По возрастанию'),
    t('По убыванию'),
    t('Элементов на страницу'),
    t('- Все -'),
    t('Пропустить'),
    t('« первая'),
    t('‹ предыдущая'),
    t('следующая ›'),
    t('последняя »'),
    t('Переводы'),
    t('Заголовок'),
    t('Услуги города'),
    t('Предложение'),
    t('Билет'),
    t('Рейтингу'),
    t('Цене'),
    t('Все'),
    t('Категория'),
    t('Языки'),
    t('View panes'),
    t('Услуги гида'),
    t('Популярные услуги'),
    t('Город'),
    t('Новости'),
    t('Другие услуги гида'),
  );
  $export['content'] = $view;

  $view = new view();
  $view->name = 'offers';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'excur_offer';
  $view->human_name = 'Offers';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'ещё';
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    3 => '3',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Применить';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Сбросить';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Сортировать по';
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'По возрастанию';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'По убыванию';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '30';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '5';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Элементов на страницу';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Все -';
  $handler->display->display_options['pager']['options']['expose']['offset_label'] = 'Пропустить';
  $handler->display->display_options['pager']['options']['tags']['first'] = '« первая';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '‹ предыдущая';
  $handler->display->display_options['pager']['options']['tags']['next'] = 'следующая ›';
  $handler->display->display_options['pager']['options']['tags']['last'] = 'последняя »';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Связь: Excursionline: Node id */
  $handler->display->display_options['relationships']['nid']['id'] = 'nid';
  $handler->display->display_options['relationships']['nid']['table'] = 'excur_offer';
  $handler->display->display_options['relationships']['nid']['field'] = 'nid';
  $handler->display->display_options['relationships']['nid']['required'] = TRUE;
  /* Связь: Excursionline: User id */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'excur_offer';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  $handler->display->display_options['relationships']['uid']['required'] = TRUE;
  /* Поле: Excursionline: Дата */
  $handler->display->display_options['fields']['date']['id'] = 'date';
  $handler->display->display_options['fields']['date']['table'] = 'excur_offer';
  $handler->display->display_options['fields']['date']['field'] = 'date';
  /* Критерий фильтра: Excursionline: состояние */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'excur_offer';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['operator'] = '!=';
  $handler->display->display_options['filters']['status']['value'] = '0';

  /* Display: Заказы */
  $handler = $view->new_display('page', 'Заказы', 'offers');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Заказы';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title_field' => 'title_field',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'title_field' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Связь: Excursionline: Node id */
  $handler->display->display_options['relationships']['nid']['id'] = 'nid';
  $handler->display->display_options['relationships']['nid']['table'] = 'excur_offer';
  $handler->display->display_options['relationships']['nid']['field'] = 'nid';
  $handler->display->display_options['relationships']['nid']['required'] = TRUE;
  /* Связь: Excursionline: User id */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'excur_offer';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  $handler->display->display_options['relationships']['uid']['required'] = TRUE;
  /* Связь: Entity Reference: Связанная Сущность */
  $handler->display->display_options['relationships']['field_guide_target_id']['id'] = 'field_guide_target_id';
  $handler->display->display_options['relationships']['field_guide_target_id']['table'] = 'field_data_field_guide';
  $handler->display->display_options['relationships']['field_guide_target_id']['field'] = 'field_guide_target_id';
  $handler->display->display_options['relationships']['field_guide_target_id']['relationship'] = 'nid';
  $handler->display->display_options['relationships']['field_guide_target_id']['label'] = 'Гид';
  $handler->display->display_options['relationships']['field_guide_target_id']['required'] = TRUE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Поле: Excursionline: Offer oid */
  $handler->display->display_options['fields']['oid']['id'] = 'oid';
  $handler->display->display_options['fields']['oid']['table'] = 'excur_offer';
  $handler->display->display_options['fields']['oid']['field'] = 'oid';
  $handler->display->display_options['fields']['oid']['label'] = 'ID заказа';
  $handler->display->display_options['fields']['oid']['element_label_colon'] = FALSE;
  /* Поле: Excursionline: Создано */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'excur_offer';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'Дата заказа';
  $handler->display->display_options['fields']['created']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['created']['date_format'] = 'short';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'privatemsg_current_day';
  /* Поле: Содержимое: Заголовок */
  $handler->display->display_options['fields']['title_field']['id'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['table'] = 'field_data_title_field';
  $handler->display->display_options['fields']['title_field']['field'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['relationship'] = 'nid';
  $handler->display->display_options['fields']['title_field']['label'] = 'Услуга';
  $handler->display->display_options['fields']['title_field']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title_field']['type'] = 'title_linked';
  $handler->display->display_options['fields']['title_field']['settings'] = array(
    'title_style' => '_none',
    'title_link' => 'content',
    'title_class' => '',
  );
  $handler->display->display_options['fields']['title_field']['link_to_entity'] = 0;
  /* Поле: Excursionline: Стоимость */
  $handler->display->display_options['fields']['ticket']['id'] = 'ticket';
  $handler->display->display_options['fields']['ticket']['table'] = 'excur_offer';
  $handler->display->display_options['fields']['ticket']['field'] = 'ticket';
  $handler->display->display_options['fields']['ticket']['label'] = '';
  $handler->display->display_options['fields']['ticket']['exclude'] = TRUE;
  $handler->display->display_options['fields']['ticket']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['ticket']['separator'] = ' ';
  /* Поле: Excursionline: Currency */
  $handler->display->display_options['fields']['currency']['id'] = 'currency';
  $handler->display->display_options['fields']['currency']['table'] = 'excur_offer';
  $handler->display->display_options['fields']['currency']['field'] = 'currency';
  $handler->display->display_options['fields']['currency']['label'] = '';
  $handler->display->display_options['fields']['currency']['exclude'] = TRUE;
  $handler->display->display_options['fields']['currency']['element_label_colon'] = FALSE;
  /* Поле: Глобальный: PHP */
  $handler->display->display_options['fields']['php']['id'] = 'php';
  $handler->display->display_options['fields']['php']['table'] = 'views';
  $handler->display->display_options['fields']['php']['field'] = 'php';
  $handler->display->display_options['fields']['php']['label'] = 'Стоимость';
  $handler->display->display_options['fields']['php']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['php']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php']['php_output'] = '<?php print excur_currency_convert($row->ticket, EXCUR_CURRENCY_DEFAULT, $row->currency) . \' \' . excur_currency_get_icon($row->currency); ?>';
  $handler->display->display_options['fields']['php']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php']['php_click_sortable'] = '';
  /* Поле: Пользователь: ФИО */
  $handler->display->display_options['fields']['field_name']['id'] = 'field_name';
  $handler->display->display_options['fields']['field_name']['table'] = 'field_data_field_name';
  $handler->display->display_options['fields']['field_name']['field'] = 'field_name';
  $handler->display->display_options['fields']['field_name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['field_name']['label'] = 'Заказчик';
  $handler->display->display_options['fields']['field_name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_name']['type'] = 'title_linked';
  $handler->display->display_options['fields']['field_name']['settings'] = array(
    'title_style' => '_none',
    'title_link' => 'content',
    'title_class' => '',
  );
  /* Поле: Excursionline: Дата */
  $handler->display->display_options['fields']['date']['id'] = 'date';
  $handler->display->display_options['fields']['date']['table'] = 'excur_offer';
  $handler->display->display_options['fields']['date']['field'] = 'date';
  $handler->display->display_options['fields']['date']['element_label_colon'] = FALSE;
  /* Поле: Поле: Город */
  $handler->display->display_options['fields']['field_city']['id'] = 'field_city';
  $handler->display->display_options['fields']['field_city']['table'] = 'field_data_field_city';
  $handler->display->display_options['fields']['field_city']['field'] = 'field_city';
  $handler->display->display_options['fields']['field_city']['relationship'] = 'nid';
  $handler->display->display_options['fields']['field_city']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_city']['settings'] = array(
    'link' => 1,
  );
  /* Поле: Пользователь: ФИО */
  $handler->display->display_options['fields']['field_name_1']['id'] = 'field_name_1';
  $handler->display->display_options['fields']['field_name_1']['table'] = 'field_data_field_name';
  $handler->display->display_options['fields']['field_name_1']['field'] = 'field_name';
  $handler->display->display_options['fields']['field_name_1']['relationship'] = 'field_guide_target_id';
  $handler->display->display_options['fields']['field_name_1']['label'] = 'Гид';
  $handler->display->display_options['fields']['field_name_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_name_1']['type'] = 'title_linked';
  $handler->display->display_options['fields']['field_name_1']['settings'] = array(
    'title_style' => '_none',
    'title_link' => 'content',
    'title_class' => '',
  );
  /* Поле: Excursionline: Offer id */
  $handler->display->display_options['fields']['id']['id'] = 'id';
  $handler->display->display_options['fields']['id']['table'] = 'excur_offer';
  $handler->display->display_options['fields']['id']['field'] = 'id';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Критерий сортировки: Excursionline: Создано */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'excur_offer';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  $handler->display->display_options['path'] = 'admin/content/offers';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Заказы';
  $handler->display->display_options['menu']['description'] = 'Заказы';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'management';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: Заказы пользователя */
  $handler = $view->new_display('panel_pane', 'Заказы пользователя', 'user_offers');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* Поведение при отсутствии результатов: Глобальный: Текстовое поле */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'Вы не совершали заказов.';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Связь: Excursionline: Node id */
  $handler->display->display_options['relationships']['nid']['id'] = 'nid';
  $handler->display->display_options['relationships']['nid']['table'] = 'excur_offer';
  $handler->display->display_options['relationships']['nid']['field'] = 'nid';
  $handler->display->display_options['relationships']['nid']['required'] = TRUE;
  /* Связь: Excursionline: User id */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'excur_offer';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  $handler->display->display_options['relationships']['uid']['required'] = TRUE;
  /* Связь: Entity Reference: Связанная Сущность */
  $handler->display->display_options['relationships']['field_guide_target_id']['id'] = 'field_guide_target_id';
  $handler->display->display_options['relationships']['field_guide_target_id']['table'] = 'field_data_field_guide';
  $handler->display->display_options['relationships']['field_guide_target_id']['field'] = 'field_guide_target_id';
  $handler->display->display_options['relationships']['field_guide_target_id']['relationship'] = 'nid';
  $handler->display->display_options['relationships']['field_guide_target_id']['label'] = 'Guide';
  $handler->display->display_options['relationships']['field_guide_target_id']['required'] = TRUE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Поле: Excursionline: Offer oid */
  $handler->display->display_options['fields']['oid']['id'] = 'oid';
  $handler->display->display_options['fields']['oid']['table'] = 'excur_offer';
  $handler->display->display_options['fields']['oid']['field'] = 'oid';
  $handler->display->display_options['fields']['oid']['label'] = 'ID заказа';
  $handler->display->display_options['fields']['oid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['oid']['element_label_colon'] = FALSE;
  /* Поле: Excursionline: Создано */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'excur_offer';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'Дата заказа';
  $handler->display->display_options['fields']['created']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['created']['date_format'] = 'short';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'privatemsg_current_day';
  /* Поле: Содержимое: Заголовок */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'nid';
  $handler->display->display_options['fields']['title']['label'] = 'Экскурсия';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Поле: Excursionline: Currency */
  $handler->display->display_options['fields']['currency']['id'] = 'currency';
  $handler->display->display_options['fields']['currency']['table'] = 'excur_offer';
  $handler->display->display_options['fields']['currency']['field'] = 'currency';
  $handler->display->display_options['fields']['currency']['label'] = '';
  $handler->display->display_options['fields']['currency']['exclude'] = TRUE;
  $handler->display->display_options['fields']['currency']['element_label_colon'] = FALSE;
  /* Поле: Excursionline: Стоимость */
  $handler->display->display_options['fields']['ticket']['id'] = 'ticket';
  $handler->display->display_options['fields']['ticket']['table'] = 'excur_offer';
  $handler->display->display_options['fields']['ticket']['field'] = 'ticket';
  $handler->display->display_options['fields']['ticket']['label'] = '';
  $handler->display->display_options['fields']['ticket']['exclude'] = TRUE;
  $handler->display->display_options['fields']['ticket']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['ticket']['separator'] = ' ';
  /* Поле: Глобальный: PHP */
  $handler->display->display_options['fields']['php']['id'] = 'php';
  $handler->display->display_options['fields']['php']['table'] = 'views';
  $handler->display->display_options['fields']['php']['field'] = 'php';
  $handler->display->display_options['fields']['php']['label'] = 'Стоимость';
  $handler->display->display_options['fields']['php']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['php']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php']['php_output'] = '<?php print excur_currency_convert($row->ticket, EXCUR_CURRENCY_DEFAULT, $row->currency) . \' \' . excur_currency_get_icon($row->currency); ?>';
  $handler->display->display_options['fields']['php']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php']['php_click_sortable'] = '';
  /* Поле: Excursionline: Дата */
  $handler->display->display_options['fields']['date']['id'] = 'date';
  $handler->display->display_options['fields']['date']['table'] = 'excur_offer';
  $handler->display->display_options['fields']['date']['field'] = 'date';
  $handler->display->display_options['fields']['date']['label'] = 'Дата встречи';
  /* Поле: Содержимое: Время встречи */
  $handler->display->display_options['fields']['field_start_time']['id'] = 'field_start_time';
  $handler->display->display_options['fields']['field_start_time']['table'] = 'field_data_field_start_time';
  $handler->display->display_options['fields']['field_start_time']['field'] = 'field_start_time';
  $handler->display->display_options['fields']['field_start_time']['relationship'] = 'nid';
  $handler->display->display_options['fields']['field_start_time']['element_label_colon'] = FALSE;
  /* Поле: Содержимое: Место встречи */
  $handler->display->display_options['fields']['field_start_place']['id'] = 'field_start_place';
  $handler->display->display_options['fields']['field_start_place']['table'] = 'field_data_field_start_place';
  $handler->display->display_options['fields']['field_start_place']['field'] = 'field_start_place';
  $handler->display->display_options['fields']['field_start_place']['relationship'] = 'nid';
  $handler->display->display_options['fields']['field_start_place']['element_label_colon'] = FALSE;
  /* Поле: Поле: Город */
  $handler->display->display_options['fields']['field_city']['id'] = 'field_city';
  $handler->display->display_options['fields']['field_city']['table'] = 'field_data_field_city';
  $handler->display->display_options['fields']['field_city']['field'] = 'field_city';
  $handler->display->display_options['fields']['field_city']['relationship'] = 'nid';
  $handler->display->display_options['fields']['field_city']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_city']['settings'] = array(
    'link' => 1,
  );
  /* Поле: Пользователь: ФИО */
  $handler->display->display_options['fields']['field_name']['id'] = 'field_name';
  $handler->display->display_options['fields']['field_name']['table'] = 'field_data_field_name';
  $handler->display->display_options['fields']['field_name']['field'] = 'field_name';
  $handler->display->display_options['fields']['field_name']['relationship'] = 'field_guide_target_id';
  $handler->display->display_options['fields']['field_name']['label'] = 'Гид';
  $handler->display->display_options['fields']['field_name']['type'] = 'title_linked';
  $handler->display->display_options['fields']['field_name']['settings'] = array(
    'title_style' => '_none',
    'title_link' => 'content',
    'title_class' => '',
  );
  /* Поле: Excursionline: состояние */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'excur_offer';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  $handler->display->display_options['fields']['status']['label'] = 'Состояние';
  $handler->display->display_options['fields']['status']['element_label_colon'] = FALSE;
  /* Поле: Excursionline: Offer id */
  $handler->display->display_options['fields']['id']['id'] = 'id';
  $handler->display->display_options['fields']['id']['table'] = 'excur_offer';
  $handler->display->display_options['fields']['id']['field'] = 'id';
  $handler->display->display_options['fields']['id']['label'] = '';
  $handler->display->display_options['fields']['id']['element_label_colon'] = FALSE;
  /* Поле: Поле: Главное изображение */
  $handler->display->display_options['fields']['field_image']['id'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['table'] = 'field_data_field_image';
  $handler->display->display_options['fields']['field_image']['field'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['relationship'] = 'nid';
  $handler->display->display_options['fields']['field_image']['label'] = '';
  $handler->display->display_options['fields']['field_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
  );
  /* Поле: Поле: Главное изображение */
  $handler->display->display_options['fields']['field_image_1']['id'] = 'field_image_1';
  $handler->display->display_options['fields']['field_image_1']['table'] = 'field_data_field_image';
  $handler->display->display_options['fields']['field_image_1']['field'] = 'field_image';
  $handler->display->display_options['fields']['field_image_1']['relationship'] = 'field_guide_target_id';
  $handler->display->display_options['fields']['field_image_1']['label'] = '';
  $handler->display->display_options['fields']['field_image_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image_1']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image_1']['settings'] = array(
    'image_style' => '70x70',
    'image_link' => 'content',
  );
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Критерий сортировки: Excursionline: Создано */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'excur_offer';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Контекстный фильтр: Excursionline: User id */
  $handler->display->display_options['arguments']['uid']['id'] = 'uid';
  $handler->display->display_options['arguments']['uid']['table'] = 'excur_offer';
  $handler->display->display_options['arguments']['uid']['field'] = 'uid';
  $handler->display->display_options['arguments']['uid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['uid']['exception']['title'] = 'Все';
  $handler->display->display_options['arguments']['uid']['default_argument_type'] = 'user';
  $handler->display->display_options['arguments']['uid']['default_argument_options']['user'] = FALSE;
  $handler->display->display_options['arguments']['uid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['uid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['uid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Критерий фильтра: Excursionline: состояние */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'excur_offer';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['operator'] = '!=';
  $handler->display->display_options['filters']['status']['value'] = '0';
  $handler->display->display_options['argument_input'] = array(
    'uid' => array(
      'type' => 'none',
      'context' => 'entity:user.uid',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Excursionline: User id',
    ),
  );

  /* Display: Заказы гида */
  $handler = $view->new_display('panel_pane', 'Заказы гида', 'guide_offers');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '5';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Элементов на страницу';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Все -';
  $handler->display->display_options['pager']['options']['expose']['offset_label'] = 'Пропустить';
  $handler->display->display_options['pager']['options']['tags']['first'] = '« первая';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '‹ предыдущая';
  $handler->display->display_options['pager']['options']['tags']['next'] = 'следующая ›';
  $handler->display->display_options['pager']['options']['tags']['last'] = 'последняя »';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* Поведение при отсутствии результатов: Глобальный: Текстовое поле */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'У вас не совершали заказов.';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Связь: Excursionline: Node id */
  $handler->display->display_options['relationships']['nid']['id'] = 'nid';
  $handler->display->display_options['relationships']['nid']['table'] = 'excur_offer';
  $handler->display->display_options['relationships']['nid']['field'] = 'nid';
  $handler->display->display_options['relationships']['nid']['required'] = TRUE;
  /* Связь: Excursionline: User id */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'excur_offer';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  $handler->display->display_options['relationships']['uid']['required'] = TRUE;
  /* Связь: Entity Reference: Связанная Сущность */
  $handler->display->display_options['relationships']['field_guide_target_id']['id'] = 'field_guide_target_id';
  $handler->display->display_options['relationships']['field_guide_target_id']['table'] = 'field_data_field_guide';
  $handler->display->display_options['relationships']['field_guide_target_id']['field'] = 'field_guide_target_id';
  $handler->display->display_options['relationships']['field_guide_target_id']['relationship'] = 'nid';
  $handler->display->display_options['relationships']['field_guide_target_id']['label'] = 'Guide';
  $handler->display->display_options['relationships']['field_guide_target_id']['required'] = TRUE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Поле: Excursionline: Создано */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'excur_offer';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'Дата заказа';
  $handler->display->display_options['fields']['created']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['created']['date_format'] = 'short';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'privatemsg_current_day';
  /* Поле: Содержимое: Заголовок */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'nid';
  $handler->display->display_options['fields']['title']['label'] = 'Экскурсия';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Поле: Excursionline: Currency */
  $handler->display->display_options['fields']['currency']['id'] = 'currency';
  $handler->display->display_options['fields']['currency']['table'] = 'excur_offer';
  $handler->display->display_options['fields']['currency']['field'] = 'currency';
  $handler->display->display_options['fields']['currency']['label'] = '';
  $handler->display->display_options['fields']['currency']['exclude'] = TRUE;
  $handler->display->display_options['fields']['currency']['element_label_colon'] = FALSE;
  /* Поле: Excursionline: Стоимость */
  $handler->display->display_options['fields']['ticket']['id'] = 'ticket';
  $handler->display->display_options['fields']['ticket']['table'] = 'excur_offer';
  $handler->display->display_options['fields']['ticket']['field'] = 'ticket';
  $handler->display->display_options['fields']['ticket']['label'] = '';
  $handler->display->display_options['fields']['ticket']['exclude'] = TRUE;
  $handler->display->display_options['fields']['ticket']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['ticket']['separator'] = ' ';
  /* Поле: Глобальный: PHP */
  $handler->display->display_options['fields']['php']['id'] = 'php';
  $handler->display->display_options['fields']['php']['table'] = 'views';
  $handler->display->display_options['fields']['php']['field'] = 'php';
  $handler->display->display_options['fields']['php']['label'] = 'Стоимость';
  $handler->display->display_options['fields']['php']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['php']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php']['php_output'] = '<?php print excur_currency_convert($row->ticket, EXCUR_CURRENCY_DEFAULT, $row->currency) . \' \' . excur_currency_get_icon($row->currency); ?>';
  $handler->display->display_options['fields']['php']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php']['php_click_sortable'] = '';
  /* Поле: Excursionline: Дата */
  $handler->display->display_options['fields']['date']['id'] = 'date';
  $handler->display->display_options['fields']['date']['table'] = 'excur_offer';
  $handler->display->display_options['fields']['date']['field'] = 'date';
  $handler->display->display_options['fields']['date']['label'] = 'Дата встречи';
  /* Поле: Содержимое: Время встречи */
  $handler->display->display_options['fields']['field_start_time']['id'] = 'field_start_time';
  $handler->display->display_options['fields']['field_start_time']['table'] = 'field_data_field_start_time';
  $handler->display->display_options['fields']['field_start_time']['field'] = 'field_start_time';
  $handler->display->display_options['fields']['field_start_time']['relationship'] = 'nid';
  $handler->display->display_options['fields']['field_start_time']['element_label_colon'] = FALSE;
  /* Поле: Содержимое: Место встречи */
  $handler->display->display_options['fields']['field_start_place']['id'] = 'field_start_place';
  $handler->display->display_options['fields']['field_start_place']['table'] = 'field_data_field_start_place';
  $handler->display->display_options['fields']['field_start_place']['field'] = 'field_start_place';
  $handler->display->display_options['fields']['field_start_place']['relationship'] = 'nid';
  $handler->display->display_options['fields']['field_start_place']['element_label_colon'] = FALSE;
  /* Поле: Поле: Город */
  $handler->display->display_options['fields']['field_city']['id'] = 'field_city';
  $handler->display->display_options['fields']['field_city']['table'] = 'field_data_field_city';
  $handler->display->display_options['fields']['field_city']['field'] = 'field_city';
  $handler->display->display_options['fields']['field_city']['relationship'] = 'nid';
  $handler->display->display_options['fields']['field_city']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_city']['settings'] = array(
    'link' => 1,
  );
  /* Поле: Пользователь: ФИО */
  $handler->display->display_options['fields']['field_name_1']['id'] = 'field_name_1';
  $handler->display->display_options['fields']['field_name_1']['table'] = 'field_data_field_name';
  $handler->display->display_options['fields']['field_name_1']['field'] = 'field_name';
  $handler->display->display_options['fields']['field_name_1']['relationship'] = 'uid';
  $handler->display->display_options['fields']['field_name_1']['label'] = 'Заказчик';
  $handler->display->display_options['fields']['field_name_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_name_1']['type'] = 'title_linked';
  $handler->display->display_options['fields']['field_name_1']['settings'] = array(
    'title_style' => '_none',
    'title_link' => 'content',
    'title_class' => '',
  );
  /* Поле: Excursionline: состояние */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'excur_offer';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  $handler->display->display_options['fields']['status']['label'] = 'Состояние';
  $handler->display->display_options['fields']['status']['element_label_colon'] = FALSE;
  /* Поле: Excursionline: Offer oid */
  $handler->display->display_options['fields']['oid']['id'] = 'oid';
  $handler->display->display_options['fields']['oid']['table'] = 'excur_offer';
  $handler->display->display_options['fields']['oid']['field'] = 'oid';
  $handler->display->display_options['fields']['oid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['oid']['element_label_colon'] = FALSE;
  /* Поле: Excursionline: Offer id */
  $handler->display->display_options['fields']['id']['id'] = 'id';
  $handler->display->display_options['fields']['id']['table'] = 'excur_offer';
  $handler->display->display_options['fields']['id']['field'] = 'id';
  /* Поле: Содержимое: UID Автора */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'node';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  $handler->display->display_options['fields']['uid']['relationship'] = 'nid';
  /* Поле: Содержимое: Гид */
  $handler->display->display_options['fields']['field_guide']['id'] = 'field_guide';
  $handler->display->display_options['fields']['field_guide']['table'] = 'field_data_field_guide';
  $handler->display->display_options['fields']['field_guide']['field'] = 'field_guide';
  $handler->display->display_options['fields']['field_guide']['relationship'] = 'nid';
  $handler->display->display_options['fields']['field_guide']['settings'] = array(
    'link' => 0,
  );
  /* Поле: Поле: Главное изображение */
  $handler->display->display_options['fields']['field_image']['id'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['table'] = 'field_data_field_image';
  $handler->display->display_options['fields']['field_image']['field'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['relationship'] = 'nid';
  $handler->display->display_options['fields']['field_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
  );
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Критерий сортировки: Excursionline: Создано */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'excur_offer';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Контекстный фильтр: Содержимое: Гид (field_guide) */
  $handler->display->display_options['arguments']['field_guide_target_id']['id'] = 'field_guide_target_id';
  $handler->display->display_options['arguments']['field_guide_target_id']['table'] = 'field_data_field_guide';
  $handler->display->display_options['arguments']['field_guide_target_id']['field'] = 'field_guide_target_id';
  $handler->display->display_options['arguments']['field_guide_target_id']['relationship'] = 'nid';
  $handler->display->display_options['arguments']['field_guide_target_id']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_guide_target_id']['exception']['title'] = 'Все';
  $handler->display->display_options['arguments']['field_guide_target_id']['default_argument_type'] = 'user';
  $handler->display->display_options['arguments']['field_guide_target_id']['default_argument_options']['user'] = FALSE;
  $handler->display->display_options['arguments']['field_guide_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_guide_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_guide_target_id']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Критерий фильтра: Excursionline: состояние */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'excur_offer';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['operator'] = '!=';
  $handler->display->display_options['filters']['status']['value'] = '0';
  $handler->display->display_options['argument_input'] = array(
    'uid' => array(
      'type' => 'none',
      'context' => 'entity:user.uid',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Excursionline: User id',
    ),
  );
  $translatables['offers'] = array(
    t('Master'),
    t('ещё'),
    t('Применить'),
    t('Сбросить'),
    t('Сортировать по'),
    t('По возрастанию'),
    t('По убыванию'),
    t('Элементов на страницу'),
    t('- Все -'),
    t('Пропустить'),
    t('« первая'),
    t('‹ предыдущая'),
    t('следующая ›'),
    t('последняя »'),
    t('Service'),
    t('Пользователь'),
    t('Дата'),
    t('Заказы'),
    t('Гид'),
    t('ID заказа'),
    t('Дата заказа'),
    t('Услуга'),
    t('.'),
    t(' '),
    t('Стоимость'),
    t('Заказчик'),
    t('Город'),
    t('Offer id'),
    t('Заказы пользователя'),
    t('Вы не совершали заказов.'),
    t('Guide'),
    t('Экскурсия'),
    t('Дата встречи'),
    t('Время встречи'),
    t('Место встречи'),
    t('Состояние'),
    t('Все'),
    t('View panes'),
    t('Заказы гида'),
    t('У вас не совершали заказов.'),
    t('Offer oid'),
    t('UID Автора'),
    t('Главное изображение'),
  );
  $export['offers'] = $view;

  $view = new view();
  $view->name = 'term';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'taxonomy_term_data';
  $view->human_name = 'Термины';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'ещё';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Применить';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Сбросить';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Сортировать по';
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'По возрастанию';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'По убыванию';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Элементов на страницу';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Все -';
  $handler->display->display_options['pager']['options']['expose']['offset_label'] = 'Пропустить';
  $handler->display->display_options['pager']['options']['tags']['first'] = '« первая';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '‹ предыдущая';
  $handler->display->display_options['pager']['options']['tags']['next'] = 'следующая ›';
  $handler->display->display_options['pager']['options']['tags']['last'] = 'последняя »';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Связь: Термин таксономии: Entity translation: translations */
  $handler->display->display_options['relationships']['entity_translations']['id'] = 'entity_translations';
  $handler->display->display_options['relationships']['entity_translations']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['relationships']['entity_translations']['field'] = 'entity_translations';
  /* Поле: Термин таксономии: Имя */
  $handler->display->display_options['fields']['name_field']['id'] = 'name_field';
  $handler->display->display_options['fields']['name_field']['table'] = 'field_data_name_field';
  $handler->display->display_options['fields']['name_field']['field'] = 'name_field';
  $handler->display->display_options['fields']['name_field']['label'] = '';
  $handler->display->display_options['fields']['name_field']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['name_field']['link_to_entity'] = 1;
  /* Критерий фильтра: Перевод сущностей: Язык */
  $handler->display->display_options['filters']['language']['id'] = 'language';
  $handler->display->display_options['filters']['language']['table'] = 'entity_translation';
  $handler->display->display_options['filters']['language']['field'] = 'language';
  $handler->display->display_options['filters']['language']['relationship'] = 'entity_translations';
  $handler->display->display_options['filters']['language']['value'] = array(
    '***CURRENT_LANGUAGE***' => '***CURRENT_LANGUAGE***',
  );

  /* Display: Континенты */
  $handler = $view->new_display('panel_pane', 'Континенты', 'continent');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Поле: Термин таксономии: Имя */
  $handler->display->display_options['fields']['name_field']['id'] = 'name_field';
  $handler->display->display_options['fields']['name_field']['table'] = 'field_data_name_field';
  $handler->display->display_options['fields']['name_field']['field'] = 'name_field';
  $handler->display->display_options['fields']['name_field']['label'] = '';
  $handler->display->display_options['fields']['name_field']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['name_field']['link_to_entity'] = 1;
  /* Поле: Поле: Главное изображение */
  $handler->display->display_options['fields']['field_image']['id'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['table'] = 'field_data_field_image';
  $handler->display->display_options['fields']['field_image']['field'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['label'] = '';
  $handler->display->display_options['fields']['field_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image']['settings'] = array(
    'image_style' => '300x170',
    'image_link' => 'content',
  );
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Критерий фильтра: Термин таксономии: Словарь */
  $handler->display->display_options['filters']['vid']['id'] = 'vid';
  $handler->display->display_options['filters']['vid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['filters']['vid']['field'] = 'vid';
  $handler->display->display_options['filters']['vid']['value'] = array(
    2 => '2',
  );
  /* Критерий фильтра: Перевод сущностей: Язык */
  $handler->display->display_options['filters']['language']['id'] = 'language';
  $handler->display->display_options['filters']['language']['table'] = 'entity_translation';
  $handler->display->display_options['filters']['language']['field'] = 'language';
  $handler->display->display_options['filters']['language']['relationship'] = 'entity_translations';
  $handler->display->display_options['filters']['language']['value'] = array(
    '***CURRENT_LANGUAGE***' => '***CURRENT_LANGUAGE***',
  );

  /* Display: Страны */
  $handler = $view->new_display('panel_pane', 'Страны', 'country');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Связь: Термин таксономии: Entity translation: translations */
  $handler->display->display_options['relationships']['entity_translations']['id'] = 'entity_translations';
  $handler->display->display_options['relationships']['entity_translations']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['relationships']['entity_translations']['field'] = 'entity_translations';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Критерий фильтра: Перевод сущностей: Язык */
  $handler->display->display_options['filters']['language']['id'] = 'language';
  $handler->display->display_options['filters']['language']['table'] = 'entity_translation';
  $handler->display->display_options['filters']['language']['field'] = 'language';
  $handler->display->display_options['filters']['language']['relationship'] = 'entity_translations';
  $handler->display->display_options['filters']['language']['value'] = array(
    '***CURRENT_LANGUAGE***' => '***CURRENT_LANGUAGE***',
  );
  /* Критерий фильтра: Термин таксономии: Словарь */
  $handler->display->display_options['filters']['vid']['id'] = 'vid';
  $handler->display->display_options['filters']['vid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['filters']['vid']['field'] = 'vid';
  $handler->display->display_options['filters']['vid']['value'] = array(
    3 => '3',
  );
  /* Критерий фильтра: Термин таксономии: Континент (field_continent) */
  $handler->display->display_options['filters']['field_continent_target_id']['id'] = 'field_continent_target_id';
  $handler->display->display_options['filters']['field_continent_target_id']['table'] = 'field_data_field_continent';
  $handler->display->display_options['filters']['field_continent_target_id']['field'] = 'field_continent_target_id';
  $handler->display->display_options['filters']['field_continent_target_id']['value']['value'] = '0';

  /* Display: Города */
  $handler = $view->new_display('panel_pane', 'Города', 'city');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Критерий фильтра: Перевод сущностей: Язык */
  $handler->display->display_options['filters']['language']['id'] = 'language';
  $handler->display->display_options['filters']['language']['table'] = 'entity_translation';
  $handler->display->display_options['filters']['language']['field'] = 'language';
  $handler->display->display_options['filters']['language']['relationship'] = 'entity_translations';
  $handler->display->display_options['filters']['language']['value'] = array(
    '***CURRENT_LANGUAGE***' => '***CURRENT_LANGUAGE***',
  );
  /* Критерий фильтра: Термин таксономии: Словарь */
  $handler->display->display_options['filters']['vid']['id'] = 'vid';
  $handler->display->display_options['filters']['vid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['filters']['vid']['field'] = 'vid';
  $handler->display->display_options['filters']['vid']['value'] = array(
    4 => '4',
  );
  /* Критерий фильтра: Поле: Страна (field_country) */
  $handler->display->display_options['filters']['field_country_target_id']['id'] = 'field_country_target_id';
  $handler->display->display_options['filters']['field_country_target_id']['table'] = 'field_data_field_country';
  $handler->display->display_options['filters']['field_country_target_id']['field'] = 'field_country_target_id';
  $handler->display->display_options['filters']['field_country_target_id']['value']['value'] = '0';
  $translatables['term'] = array(
    t('Master'),
    t('ещё'),
    t('Применить'),
    t('Сбросить'),
    t('Сортировать по'),
    t('По возрастанию'),
    t('По убыванию'),
    t('Элементов на страницу'),
    t('- Все -'),
    t('Пропустить'),
    t('« первая'),
    t('‹ предыдущая'),
    t('следующая ›'),
    t('последняя »'),
    t('Переводы'),
    t('Континенты'),
    t('View panes'),
    t('Страны'),
    t('Города'),
  );
  $export['term'] = $view;

  $view = new view();
  $view->name = 'user';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'users';
  $view->human_name = 'Пользователи';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'ещё';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'access user profiles';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Применить';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Сбросить';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Сортировать по';
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'По возрастанию';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'По убыванию';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Элементов на страницу';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Все -';
  $handler->display->display_options['pager']['options']['expose']['offset_label'] = 'Пропустить';
  $handler->display->display_options['pager']['options']['tags']['first'] = '« первая';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '‹ предыдущая';
  $handler->display->display_options['pager']['options']['tags']['next'] = 'следующая ›';
  $handler->display->display_options['pager']['options']['tags']['last'] = 'последняя »';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Поле: Пользователь: Имя */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  /* Критерий фильтра: Пользователь: Активно */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'users';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;

  /* Display: Гид услуги */
  $handler = $view->new_display('entityreference', 'Гид услуги', 'service_guide');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'entityreference_style';
  $handler->display->display_options['style_options']['search_fields'] = array(
    'field_name' => 'field_name',
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'entityreference_fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Поле: Пользователь: ФИО */
  $handler->display->display_options['fields']['field_name']['id'] = 'field_name';
  $handler->display->display_options['fields']['field_name']['table'] = 'field_data_field_name';
  $handler->display->display_options['fields']['field_name']['field'] = 'field_name';
  $handler->display->display_options['fields']['field_name']['label'] = '';
  $handler->display->display_options['fields']['field_name']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Критерий фильтра: Пользователь: Активно */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'users';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Критерий фильтра: Пользователь: Роли */
  $handler->display->display_options['filters']['rid']['id'] = 'rid';
  $handler->display->display_options['filters']['rid']['table'] = 'users_roles';
  $handler->display->display_options['filters']['rid']['field'] = 'rid';
  $handler->display->display_options['filters']['rid']['value'] = array(
    4 => '4',
  );

  /* Display: Попутчики в городе */
  $handler = $view->new_display('panel_pane', 'Попутчики в городе', 'companion_city');
  $handler->display->display_options['defaults']['query'] = FALSE;
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Связь: Excursionline: Node id */
  $handler->display->display_options['relationships']['nid']['id'] = 'nid';
  $handler->display->display_options['relationships']['nid']['table'] = 'excur_offer';
  $handler->display->display_options['relationships']['nid']['field'] = 'nid';
  $handler->display->display_options['relationships']['nid']['required'] = TRUE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Контекстный фильтр: Поле: Город (field_city) */
  $handler->display->display_options['arguments']['field_city_target_id']['id'] = 'field_city_target_id';
  $handler->display->display_options['arguments']['field_city_target_id']['table'] = 'field_data_field_city';
  $handler->display->display_options['arguments']['field_city_target_id']['field'] = 'field_city_target_id';
  $handler->display->display_options['arguments']['field_city_target_id']['relationship'] = 'nid';
  $handler->display->display_options['arguments']['field_city_target_id']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_city_target_id']['exception']['title'] = 'Все';
  $handler->display->display_options['arguments']['field_city_target_id']['default_argument_type'] = 'taxonomy_tid';
  $handler->display->display_options['arguments']['field_city_target_id']['default_argument_options']['vocabularies'] = array(
    'city' => 'city',
  );
  $handler->display->display_options['arguments']['field_city_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_city_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_city_target_id']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Критерий фильтра: Пользователь: Активно */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'users';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Критерий фильтра: Excursionline: companion */
  $handler->display->display_options['filters']['companion']['id'] = 'companion';
  $handler->display->display_options['filters']['companion']['table'] = 'excur_offer';
  $handler->display->display_options['filters']['companion']['field'] = 'companion';
  $handler->display->display_options['filters']['companion']['relationship'] = 'uid';
  $handler->display->display_options['filters']['companion']['value'] = '1';

  /* Display: Попутчики в предложении */
  $handler = $view->new_display('panel_pane', 'Попутчики в предложении', 'companion_service');
  $handler->display->display_options['defaults']['query'] = FALSE;
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Связь: Excursionline: Node id */
  $handler->display->display_options['relationships']['nid']['id'] = 'nid';
  $handler->display->display_options['relationships']['nid']['table'] = 'excur_offer';
  $handler->display->display_options['relationships']['nid']['field'] = 'nid';
  $handler->display->display_options['relationships']['nid']['required'] = TRUE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Контекстный фильтр: Содержимое: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['relationship'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['exception']['title'] = 'Все';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Критерий фильтра: Пользователь: Активно */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'users';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Критерий фильтра: Excursionline: companion */
  $handler->display->display_options['filters']['companion']['id'] = 'companion';
  $handler->display->display_options['filters']['companion']['table'] = 'excur_offer';
  $handler->display->display_options['filters']['companion']['field'] = 'companion';
  $handler->display->display_options['filters']['companion']['relationship'] = 'uid';
  $handler->display->display_options['filters']['companion']['value'] = '1';
  $translatables['user'] = array(
    t('Master'),
    t('ещё'),
    t('Применить'),
    t('Сбросить'),
    t('Сортировать по'),
    t('По возрастанию'),
    t('По убыванию'),
    t('Элементов на страницу'),
    t('- Все -'),
    t('Пропустить'),
    t('« первая'),
    t('‹ предыдущая'),
    t('следующая ›'),
    t('последняя »'),
    t('Гид услуги'),
    t('Попутчики в городе'),
    t('Service'),
    t('Все'),
    t('View panes'),
    t('Попутчики в предложении'),
  );
  $export['user'] = $view;

  return $export;
}
