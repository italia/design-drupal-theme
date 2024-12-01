<?php

/**
 * @file
 * Preprocess image.
 */

/**
 * Implements hook_preprocess_image().
 *
 * Ref: https://www.drupal.org/project/coding_standards/issues/3056368
 *
 * @phpstan-ignore missingType.iterableValue
 */
function bootstrap_italia_preprocess_image(array &$variables): void {
  $variables['image_fluid'] = (bool) theme_get_setting('image_fluid');
  $variables['image_rounded'] = (bool) theme_get_setting('image_rounded');
  $variables['image_border'] = theme_get_setting('image_border');
}
