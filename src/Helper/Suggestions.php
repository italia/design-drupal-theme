<?php

namespace Drupal\bootstrap_italia\Helper;

/**
 * Helper Suggestions class for bootstrap_italia theme.
 *
 * Why isn't it a service? https://www.drupal.org/project/drupal/issues/2002606.
 */
class Suggestions {

  /**
   * Set form input.
   *
   * @param array &$suggestions
   *   Referenced $suggestions.
   * @param array &$variables
   *   Referenced $variables.
   */
  public static function form(array &$suggestions, array &$variables, string $hook = NULL) {
    // Add a suggestion based on the element type.
    if (isset($variables['element']['#type'])) {
      $suggestions[] = $variables['theme_hook_original'] . '__type__' . $variables['element']['#type'];
    }
    if (isset($variables['element']['#type']) && !is_null($hook)) {
      $suggestions[] = $hook . '__type__' . $variables['element']['#type'];
    }
    if (isset($variables['element']['#id'])) {
      $suggestions[] = $variables['theme_hook_original'] . '__id__' . $variables['element']['#id'];
    }
    if (isset($variables['element']['#id']) && !is_null($hook)) {
      $suggestions[] = $hook . '__id__' . $variables['element']['#id'];
    }
    if (isset($variables['element']['#name'])) {
      $suggestions[] = $variables['theme_hook_original'] . '__name__' . $variables['element']['#name'];
    }
    if (isset($variables['element']['#name']) && !is_null($hook)) {
      $suggestions[] = $hook . '__name__' . $variables['element']['#name'];
    }
  }

}