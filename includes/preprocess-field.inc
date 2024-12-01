<?php

/**
 * @file
 * Hook THEME_preprocess_field_*.
 */

/**
 * Implements hook_preprocess_field().
 *
 * Ref: https://www.drupal.org/project/coding_standards/issues/3056368
 *
 * @phpstan-ignore missingType.iterableValue
 */
function bootstrap_italia_preprocess_field(array &$variables): void {
  $variables['field_label_bold'] = (bool) theme_get_setting('field_label_bold');
  $variables['field_label_separator'] = theme_get_setting('field_label_separator');
  $variables['field_container_vertical_padding'] = theme_get_setting('field_container_vertical_padding');
  $variables['field_container_vertical_margin'] = theme_get_setting('field_container_vertical_margin');

  if (isset($variables['element']['#view_mode'])) {
    $variables['field_view_mode'] = $variables['element']['#view_mode'];
  }

}
