<?php
/**
 * @file
 * Ctools content type new_message.
 */

/**
 * Implements hook_ctools_content_types().
 */
function excur_country_city_top_ctools_content_types() {
  return array(
    'single' => TRUE,
    'title' => t('Country/city top'),
    'all contexts' => TRUE,
    'category' => t('Excur'),
    'hook theme' => 'excur_country_city_top_content_type_theme',
  );
}

/**
 * Implements hook_content_type_render().
 */
function excur_country_city_top_content_type_render($subtype, $conf, $panel_args, $context) {
  $block = new stdClass();
  $block->content = theme('excur_country_city_top');

  return $block;
}

/**
 * Implements hook_content_type_theme().
 */
function excur_country_city_top_content_type_theme(&$theme, $plugin) {
  $theme['excur_country_city_top'] = array(
    'path' => $plugin['path'],
    'template' => 'excur-country-city-top',
  );
}

/**
 * Process variables for excur-image-slider.tpl.php.
 */
function template_preprocess_excur_country_city_top(&$vars) {
  global $language;
  $current_term = menu_get_object('taxonomy_term', 2);
  $node = menu_get_object();

  if ($current_term) {
    if ($current_term->vocabulary_machine_name == 'country') {
      $cid = 'excur_country_city_top-country:' . $current_term->tid . '-language:' . $language->language;
      if ($cache = cache_get($cid)) {
        $data = $cache->data;
        $vars += $data;
      }
      else {
        // Get continents.
        $current_continent = taxonomy_term_load($current_term->field_continent[LANGUAGE_NONE][0]['target_id']);
        $data['continent'] = $current_continent->name;
        $vocabulary = taxonomy_vocabulary_machine_name_load('continent');
        foreach (taxonomy_get_tree($vocabulary->vid) as $continent) {
          $data['continents'][] = l($continent->name, "taxonomy/term/$continent->tid", array(
            'attributes' => array(
              'title' => check_plain($continent->name),
            ),
          ));
        }

        // Get countries.
        $data['country'] = $current_term->name;
        $query = new EntityFieldQuery();
        $results = $query->entityCondition('entity_type', 'taxonomy_term')
          ->entityCondition('bundle', 'country')
          ->fieldCondition('field_continent', 'target_id', $current_continent->tid)
          ->execute();
        if (isset($results['taxonomy_term'])) {
          foreach ($results['taxonomy_term'] as $result) {
            $country = taxonomy_term_load($result->tid);
            $data['countries'][] = l($country->name, "taxonomy/term/$country->tid", array(
              'attributes' => array(
                'title' => check_plain($country->name),
              ),
            ));
          }
        }

        // Get cities.
        $data['city'] = t('Select a city');
        $query = new EntityFieldQuery();
        $results = $query->entityCondition('entity_type', 'taxonomy_term')
          ->entityCondition('bundle', 'city')
          ->fieldCondition('field_country', 'target_id', $current_term->tid)
          ->execute();
        if (isset($results['taxonomy_term'])) {
          foreach ($results['taxonomy_term'] as $result) {
            $city = taxonomy_term_load($result->tid);
            $data['cities'][] = l($city->name, "taxonomy/term/$city->tid", array(
              'attributes' => array(
                'title' => check_plain($city->name),
              ),
            ));
          }
        }

        cache_set($cid, $data);
        $vars += $data;
      }
    }
    elseif ($current_term->vocabulary_machine_name == 'city') {
      $cid = 'excur_country_city_top-city:' . $current_term->tid . '-language:' . $language->language;
      if ($cache = cache_get($cid)) {
        $data = $cache->data;
        $vars += $data;
      }
      else {
        $current_country = taxonomy_term_load($current_term->field_country[LANGUAGE_NONE][0]['target_id']);
        $current_continent = taxonomy_term_load($current_country->field_continent[LANGUAGE_NONE][0]['target_id']);

        // Get cities.
        $data['city'] = $current_term->name;
        $query = new EntityFieldQuery();
        $results = $query->entityCondition('entity_type', 'taxonomy_term')
          ->entityCondition('bundle', 'city')
          ->fieldCondition('field_country', 'target_id', $current_country->tid)
          ->execute();
        if (isset($results['taxonomy_term'])) {
          foreach ($results['taxonomy_term'] as $result) {
            $city = taxonomy_term_load($result->tid);
            $data['cities'][] = l($city->name, "taxonomy/term/$city->tid", array(
              'attributes' => array(
                'title' => check_plain($city->name),
              ),
            ));
          }
        }

        // Get countries.
        $data['country'] = $current_country->name;
        $query = new EntityFieldQuery();
        $results = $query->entityCondition('entity_type', 'taxonomy_term')
          ->entityCondition('bundle', 'country')
          ->fieldCondition('field_continent', 'target_id', $current_continent->tid)
          ->execute();
        if (isset($results['taxonomy_term'])) {
          foreach ($results['taxonomy_term'] as $result) {
            $country = taxonomy_term_load($result->tid);
            $data['countries'][] = l($country->name, "taxonomy/term/$country->tid", array(
              'attributes' => array(
                'title' => check_plain($country->name),
              ),
            ));
          }
        }

        // Get continents.
        $data['continent'] = $current_continent->name;
        $vocabulary = taxonomy_vocabulary_machine_name_load('continent');
        foreach (taxonomy_get_tree($vocabulary->vid) as $continent) {
          $data['continents'][] = l($continent->name, "taxonomy/term/$continent->tid", array(
            'attributes' => array(
              'title' => check_plain($continent->name),
            ),
          ));
        }

        cache_set($cid, $data);
        $vars += $data;
      }
    }
  }
  elseif ($node) {
    $current_city = taxonomy_term_load($node->field_city[LANGUAGE_NONE][0]['target_id']);

    $cid = 'excur_country_city_top-city:' . $current_city->tid . '-language:' . $language->language;
    if ($cache = cache_get($cid)) {
      $data = $cache->data;
      $vars += $data;
    }
    else {
      $current_country = taxonomy_term_load($current_city->field_country[LANGUAGE_NONE][0]['target_id']);
      $current_continent = taxonomy_term_load($current_country->field_continent[LANGUAGE_NONE][0]['target_id']);

      // Get cities.
      $data['city'] = $current_city->name;
      $query = new EntityFieldQuery();
      $results = $query->entityCondition('entity_type', 'taxonomy_term')
        ->entityCondition('bundle', 'city')
        ->fieldCondition('field_country', 'target_id', $current_country->tid)
        ->execute();
      if (isset($results['taxonomy_term'])) {
        foreach ($results['taxonomy_term'] as $result) {
          $city = taxonomy_term_load($result->tid);
          $data['cities'][] = l($city->name, "taxonomy/term/$city->tid", array(
            'attributes' => array(
              'title' => check_plain($city->name),
            ),
          ));
        }
      }

      // Get countries.
      $data['country'] = $current_country->name;
      $query = new EntityFieldQuery();
      $results = $query->entityCondition('entity_type', 'taxonomy_term')
        ->entityCondition('bundle', 'country')
        ->fieldCondition('field_continent', 'target_id', $current_continent->tid)
        ->execute();
      if (isset($results['taxonomy_term'])) {
        foreach ($results['taxonomy_term'] as $result) {
          $country = taxonomy_term_load($result->tid);
          $data['countries'][] = l($country->name, "taxonomy/term/$country->tid", array(
            'attributes' => array(
              'title' => check_plain($country->name),
            ),
          ));
        }
      }

      // Get continents.
      $data['continent'] = $current_continent->name;
      $vocabulary = taxonomy_vocabulary_machine_name_load('continent');
      foreach (taxonomy_get_tree($vocabulary->vid) as $continent) {
        $data['continents'][] = l($continent->name, "taxonomy/term/$continent->tid", array(
          'attributes' => array(
            'title' => check_plain($continent->name),
          ),
        ));
      }

      cache_set($cid, $data);
      $vars += $data;
    }
  }
}
