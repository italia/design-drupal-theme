<?php

/**
 * @file
 * Hook THEME_preprocess_block_*.
 */

/**
 * Implements hook_preprocess_block() for block templates.
 */
function bootstrap_italia_preprocess_block(&$variables) {
  // All blocks.
  if (isset($variables['elements']['#id'])) {
    /** @var \Drupal\block\BlockInterface $block */
    $block = \Drupal::entityTypeManager()
      ->getStorage('block')
      ->load($variables['elements']['#id']);
    $region = $block->getRegion();

    // Add region and id to data-block.
    // Pass block region value to content so this can be used in
    // MYTHEME_theme_suggestions_menu_alter.
    if (!empty($region)) {
      $variables['content']['#attributes']['data-block']['region'] = $region;
    }
    if (!empty($region) and $region == 'header_slim_menu') {
      $variables['configuration']['government_entity_name'] = theme_get_setting('government_entity_name');
    }

    // Add id to data-block for retro-compatibility.
    $variables['content']['#attributes']['data-block']['id'] = $variables['elements']['#id'];
  }

  // Block 'system_brandig_block'.
  if ($variables['base_plugin_id'] == 'system_branding_block') {
    $variables['svg_logo_id'] = theme_get_setting('svg_logo_id');
    $variables['svg_logo_box'] = theme_get_setting('svg_logo_box');
    $variables['svg_logo_box_sticky'] = theme_get_setting('svg_logo_box_sticky');
    $variables['image_logo_fluid'] = (bool) theme_get_setting('image_logo_fluid');
  }
}
