<?php

/**
 * Implements hook_preprocess().
 */
function bootstrap_italia_preprocess_pattern_card(&$variables, $hook)
{
  $variables['pattern_card_simple_shadow'] = true;
  $variables['pattern_card_simple_article_shadow'] = true;
  $variables['pattern_card_big1_shadow'] = true;
  $variables['pattern_card_big2_shadow'] = true;
  $variables['pattern_card_big3_shadow'] = true;
  $variables['pattern_card_with_img_shadow'] = true;
  $variables['pattern_card_special_shadow'] = false;
  $variables['pattern_card_teaser_shadow'] = true;

  $variables['pattern_card_simple_border_bottom'] = true;
  $variables['pattern_card_simple_article_border_bottom'] = true;
  $variables['pattern_card_big1_border_bottom'] = true;
  $variables['pattern_card_big2_border_bottom'] = true;
  $variables['pattern_card_big3_border_bottom'] = true;
  $variables['pattern_card_with_img_border_bottom'] = true;
  $variables['pattern_card_special_border_bottom'] = false;
  $variables['pattern_card_teaser_border_bottom'] = true;

  $variables['pattern_card_simple_border_rounded'] = true;
  $variables['pattern_card_simple_article_border_rounded'] = true;
  $variables['pattern_card_big1_border_rounded'] = true;
  $variables['pattern_card_big2_border_rounded'] = true;
  $variables['pattern_card_big3_border_rounded'] = true;
  $variables['pattern_card_with_img_border_rounded'] = true;
  $variables['pattern_card_special_border_rounded'] = false;
  $variables['pattern_card_teaser_border_rounded'] = true;

  if ( isset($variables['card_date']) && $variables['variant'] == 'with_img' ){
    $current_path = \Drupal::service('path.current')->getPath();
    $date_time = $current_path == '/patterns' ?
      $variables['card_date'] :
      $variables['card_date']['node_post_date']['0']['0']['#markup'];

    $date_time_elements = explode(' - ', $date_time);
    $date = explode('/', $date_time_elements[0]);

    $variables['card_date'] = [
      'year' => isset($date[2]) ? $date[2] : false,
      'month' => isset($date[1]) ? $date[1] : false,
      'day' => isset($date[0]) ? $date[0] : false,
      'time' => isset($date_time_elements[1]) ? $date_time_elements[1] : false
    ];
  }
}
