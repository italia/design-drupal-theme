<?php

/**
 * @file
 * Hook THEME_preprocess_links_*.
 */

/**
 * Implements hook_preprocess_links().
 * Retro-compatible with 0.x
 */
function bootstrap_italia_preprocess_links(&$variables) {
  // Add current language to block.
  $variables['current_language'] = \Drupal::languageManager()->getCurrentLanguage()->getId();
}
