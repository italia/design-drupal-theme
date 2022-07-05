<?php

/**
 * @file
 * Preprocess pager.
 */

/**
 * Implements hook_preprocess_pager().
 */
function bootstrap_italia_preprocess_pager(&$variables) {
  $pager = \Drupal::service('pager.manager')->getPager();
  $variables['total_pages'] = $pager ? $pager->getTotalPages() : NULL;

  $variables['pager_alignment'] = theme_get_setting('pager_alignment');
  $variables['pager_responsive'] = (bool) theme_get_setting('pager_responsive');
  $variables['pager_jump_to_page'] = (bool) theme_get_setting('pager_jump_to_page');
  $variables['pager_show_first_last_page_link'] = (bool) theme_get_setting('pager_show_first_last_page_link');
  $variables['pager_text_controls'] = (bool) theme_get_setting('pager_text_controls');
  $variables['pager_show_total_pages'] = (bool) theme_get_setting('pager_show_total_pages');
}
