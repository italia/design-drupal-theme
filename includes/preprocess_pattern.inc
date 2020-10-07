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
  $variables['pattern_card_special_shadow'] = true;
  $variables['pattern_card_teaser_shadow'] = true;

  $variables['pattern_card_simple_border_bottom'] = true;
  $variables['pattern_card_simple_article_border_bottom'] = true;
  $variables['pattern_card_big1_border_bottom'] = true;
  $variables['pattern_card_big2_border_bottom'] = true;
  $variables['pattern_card_big3_border_bottom'] = true;
  $variables['pattern_card_with_img_border_bottom'] = true;
  $variables['pattern_card_special_border_bottom'] = true;
  $variables['pattern_card_teaser_border_bottom'] = true;

  $variables['pattern_card_simple_border_rounded'] = true;
  $variables['pattern_card_simple_article_border_rounded'] = true;
  $variables['pattern_card_big1_border_rounded'] = true;
  $variables['pattern_card_big2_border_rounded'] = true;
  $variables['pattern_card_big3_border_rounded'] = true;
  $variables['pattern_card_with_img_border_rounded'] = true;
  $variables['pattern_card_special_border_rounded'] = true;
  $variables['pattern_card_teaser_border_rounded'] = true;
}
