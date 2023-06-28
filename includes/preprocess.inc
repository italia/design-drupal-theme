<?php

/**
 * @file
 * Hook THEME_preprocess.
 */

/**
 * Implements hook_preprocess_HOOK() for all templates.
 */
function bootstrap_italia_preprocess(&$variables): void {
  // Icon libraries from cdn.
  $variables['libraries_cdn_icons'] = theme_get_setting('libraries_cdn_icons');
}
