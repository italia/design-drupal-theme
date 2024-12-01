<?php

/**
 * @file
 * Hook THEME_preprocess.
 */

use Drupal\file\Entity\File;

/**
 * Implements hook_preprocess_HOOK() for all templates.
 *
 * Ref: https://www.drupal.org/project/coding_standards/issues/3056368
 *
 * @phpstan-ignore missingType.iterableValue
 */
function bootstrap_italia_preprocess(array &$variables): void {
  // Icon libraries from cdn.
  $variables['libraries_cdn_icons'] = theme_get_setting('libraries_cdn_icons');
}

/**
 * Implements hook_preprocess_file_link().
 *
 * Ref: https://www.drupal.org/project/coding_standards/issues/3056368
 *
 * @phpstan-ignore missingType.iterableValue
 */
function bootstrap_italia_preprocess_file_link(array &$variables): void {
  /** @var \Drupal\file\Entity\File $file */
  $file = $variables['file'];

  if ($file instanceof File) {
    $variables['file_link_mime_type'] = $file->getMimeType();
  }
  $variables['file_link_default_icon'] = theme_get_setting('file_link_default_icon') ?: 'it-clip';
  $variables['file_link_icon_autodetect'] = theme_get_setting('file_link_icon_autodetect') ?: FALSE;
  $variables['file_link_show_size'] = theme_get_setting('file_link_show_size') ?: TRUE;
}
