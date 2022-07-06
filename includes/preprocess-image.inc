<?php

/**
 * @file
 * Preprocess image.
 */

/**
 * Implements hook_preprocess_image().
 */
function bootstrap_italia_preprocess_image(&$variables) {
  $variables['image_fluid'] = (bool) theme_get_setting('image_fluid');
  $variables['image_rounded'] = (bool) theme_get_setting('image_rounded');
  $variables['image_border'] = theme_get_setting('image_border');
}
