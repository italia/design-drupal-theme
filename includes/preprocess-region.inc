<?php

/**
 * @file
 * Preprocess region.
 */

/**
 * Implements hook_preprocess_region().
 *
 * Ref: https://www.drupal.org/project/coding_standards/issues/3056368
 *
 * @phpstan-ignore missingType.iterableValue
 */
function bootstrap_italia_preprocess_region(array &$variables): void {

  if ($variables['region'] == 'header_nav') {
    $variables['navigation_header_breakpoint_expand'] = (string) theme_get_setting('navigation_header_breakpoint_expand');
  }
}
