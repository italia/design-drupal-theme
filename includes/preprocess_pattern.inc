<?php

/**
 * @file
 * Preprocess pattern.
 */

use Drupal\Component\Datetime\DateTimePlus;

/**
 * Implements hook_preprocess().
 */
function bootstrap_italia_preprocess_pattern_card(&$variables, $hook) {
  $variables['pattern_card_simple_shadow'] = (bool) theme_get_setting('pattern_card_simple_shadow');
  $variables['pattern_card_simple_border_bottom'] = (bool) theme_get_setting('pattern_card_simple_border_bottom');
  $variables['pattern_card_simple_border_rounded'] = (bool) theme_get_setting('pattern_card_simple_border_rounded');

  $variables['pattern_card_simple_article_shadow'] = (bool) theme_get_setting('pattern_card_simple_article_shadow');
  $variables['pattern_card_simple_article_border_bottom'] = (bool) theme_get_setting('pattern_card_simple_article_border_bottom');
  $variables['pattern_card_simple_article_border_rounded'] = (bool) theme_get_setting('pattern_card_simple_article_border_rounded');

  $variables['pattern_card_big1_shadow'] = (bool) theme_get_setting('pattern_card_big1_shadow');
  $variables['pattern_card_big1_border_bottom'] = (bool) theme_get_setting('pattern_card_big1_border_bottom');
  $variables['pattern_card_big1_border_rounded'] = (bool) theme_get_setting('pattern_card_big1_border_rounded');

  $variables['pattern_card_big2_shadow'] = (bool) theme_get_setting('pattern_card_big2_shadow');
  $variables['pattern_card_big2_border_bottom'] = (bool) theme_get_setting('pattern_card_big2_border_bottom');
  $variables['pattern_card_big2_border_rounded'] = (bool) theme_get_setting('pattern_card_big2_border_rounded');

  $variables['pattern_card_big3_shadow'] = (bool) theme_get_setting('pattern_card_big3_shadow');
  $variables['pattern_card_big3_border_bottom'] = (bool) theme_get_setting('pattern_card_big3_border_bottom');
  $variables['pattern_card_big3_border_rounded'] = (bool) theme_get_setting('pattern_card_big3_border_rounded');

  $variables['pattern_card_with_img_shadow'] = (bool) theme_get_setting('pattern_card_with_img_shadow');
  $variables['pattern_card_with_img_border_bottom'] = (bool) theme_get_setting('pattern_card_with_img_border_bottom');
  $variables['pattern_card_with_img_border_rounded'] = (bool) theme_get_setting('pattern_card_with_img_border_rounded');

  $variables['pattern_card_special_shadow'] = (bool) theme_get_setting('pattern_card_special_shadow');
  $variables['pattern_card_special_border_bottom'] = (bool) theme_get_setting('pattern_card_special_border_bottom');
  $variables['pattern_card_special_border_rounded'] = (bool) theme_get_setting('pattern_card_special_border_rounded');

  $variables['pattern_card_teaser_shadow'] = (bool) theme_get_setting('pattern_card_teaser_shadow');
  $variables['pattern_card_teaser_border_bottom'] = (bool) theme_get_setting('pattern_card_teaser_border_bottom');
  $variables['pattern_card_teaser_border_rounded'] = (bool) theme_get_setting('pattern_card_teaser_border_rounded');

  if (isset($variables['card_date']) && $variables['variant'] == 'with_img') {
    $current_path = \Drupal::service('path.current')->getPath();
    if ($current_path != '/patterns') {
      $date_field = $variables['card_date'];
      // controlliamo campi non standard come date recur
      $date_field_type = key($date_field);
      switch ($date_field_type) {
        case 'node_post_date':
        case 'node_changed_date':
          $date_time = $variables['card_date'][$date_field_type]['0']['0']['#markup'];
          $date_time_elements = explode(' - ', $date_time);
          $date = explode('/', $date_time_elements[0]);
          break;

        case 'field_date_recur':
          $date = DateTimePlus::createFromTimestamp((int)$variables['card_date']['field_date_recur'][0]['#value']);
          $date_time = $date->format('d/M/Y');
          $date = explode('/', $date_time);
          break;
      }
      $variables['card_date'] = [
        'year' => $date[2] ?? FALSE,
        'month' => $date[1] ?? FALSE,
        'day' => $date[0] ?? FALSE,
        'time' => $date_time_elements[1] ?? FALSE,
      ];
    }
  }
}
