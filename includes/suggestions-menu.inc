<?php

/**
 * @file
 * Hook THEME_suggestions_HOOK_*.
 */


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
