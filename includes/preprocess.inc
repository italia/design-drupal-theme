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

/**
 * Implements hook_preprocess_file_link().
 */
function bootstrap_italia_preprocess_file_link(&$variables): void {
  /** @var Drupal\file\Entity\File $variables['file'] */
  $variables['file_link_mime_type'] = $variables['file']->getMimeType();
  $variables['file_link_default_icon'] = theme_get_setting('file_link_default_icon') ?: 'it-clip';
  $variables['file_link_icon_autodetect'] = theme_get_setting('file_link_icon_autodetect') ?: FALSE;
  $variables['file_link_show_size'] = theme_get_setting('file_link_show_size') ?: TRUE;
}
