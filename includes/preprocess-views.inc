<?php

/**
 * @file
 * Table settings.
 */

use Drupal\bootstrap_italia\Helper\Table;

/**
 * Implements hook_preprocess_views_view_table().
 */
function bootstrap_italia_preprocess_views_view_table(array &$variables): void {
  Table::set($variables);
}

/**
 * Implements hook_preprocess_views_ui_views_listing_table().
 */
function bootstrap_italia_preprocess_views_ui_views_listing_table(array &$variables): void {
  Table::set($variables);
}

/**
 * Implements hook_preprocess_views_mini_pager().
 */
function bootstrap_italia_preprocess_views_mini_pager(array &$variables): void {
  $variables['pager_alignment'] = theme_get_setting('pager_alignment');
  $variables['pager_text_controls'] = (bool) theme_get_setting('pager_text_controls');
}
