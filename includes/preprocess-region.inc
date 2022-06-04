<?php

/**
 * @file
 * Preprocess region.
 */

use Drupal\block\Entity\Block;

/**
 * Implements hook_preprocess_region().
 */
function bootstrap_italia_preprocess_region(&$variables) {

  if ($variables['region'] == 'header_nav') {
    // header-nav.
    $variables['navigation_header_breakpoint_expand'] = (string) theme_get_setting('navigation_header_breakpoint_expand');
  }
}
