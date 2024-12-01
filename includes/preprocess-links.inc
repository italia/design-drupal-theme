<?php

/**
 * @file
 * Hook THEME_preprocess_links_*.
 */

/**
 * Implements hook_preprocess_links().
 *
 * Ref: https://www.drupal.org/project/coding_standards/issues/3056368
 *
 * @phpstan-ignore missingType.iterableValue
 */
function bootstrap_italia_preprocess_links(array &$variables): void {
  // Add current language to block.
  $variables['current_language'] = \Drupal::languageManager()->getCurrentLanguage()->getId();
  $variables['links_type'] = $variables['theme_hook_original'];
}
