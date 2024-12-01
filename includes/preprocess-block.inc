<?php

/**
 * @file
 * Hook THEME_preprocess_block_*.
 */

/**
 * Implements hook_preprocess_block() for block templates.
 *
 * Ref: https://www.drupal.org/project/coding_standards/issues/3056368
 *
 * @phpstan-ignore missingType.iterableValue
 */
function bootstrap_italia_preprocess_block(array &$variables): void {
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

      if ($region == 'header_slim_menu') {
        $variables['configuration']['government_entity_name'] = theme_get_setting('government_entity_name');
      }
      if ($region == 'sidebar_first' and $variables['base_plugin_id'] == 'system_menu_block') {
        $variables['configuration']['sidebar_first_menu_dark'] = theme_get_setting('sidebar_first_menu_dark');
      }
      if ($region == 'sidebar_second' and $variables['base_plugin_id'] == 'system_menu_block') {
        $variables['configuration']['sidebar_second_menu_dark'] = theme_get_setting('sidebar_second_menu_dark');
      }
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

  // Add base_path for retro-compatibility.
  $variables['base_path'] = base_path();
}
