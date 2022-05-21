<?php

use Drupal\block\Entity\Block;

/**
 * Implements hook_preprocess_HOOK().
 *
 * Not retro-compatible with 0.x.
 *
 * Pass block region value to content so this can be used in
 * MYTHEME_theme_suggestions_menu_alter.
 */
function bootstrap_italia_preprocess_block(&$variables) {
  if (isset($variables['elements']['#id'])) {
    $region = Block::load($variables['elements']['#id'])->getRegion();
    if (!empty($region)) {
      $variables['content']['#attributes']['data-block']['region'] = $region;
    }
    if (!empty($region) and $region == 'header_slim_menu') {
      $variables['configuration']['government_entity_name'] = theme_get_setting('government_entity_name');
    }
  }
  $variables['content']['#attributes']['data-block']['id'] = $variables['elements']['#id'];
}

/**
 * Implements hook_theme_suggestions_HOOK_alter().
 */
function bootstrap_italia_theme_suggestions_menu_alter(array &$suggestions, array $variables) {
  if (isset($variables['attributes']['data-block']['region'])) {
    $region = $variables['attributes']['data-block']['region'];
    $suggestions[] = $variables['theme_hook_original'] . '__' . $region;
    $suggestions[] = 'menu__' . $region;
  }
}
