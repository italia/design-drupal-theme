<?php

/**
 * @file
 * Table settings.
 */

/**
 * Implements hook_preprocess_table().
 */
function bootstrap_italia_preprocess_table(&$variables) {
  $variables['table_striped'] = theme_get_setting('table_striped');
  $variables['table_striped_columns'] = theme_get_setting('table_striped_columns');
  $variables['table_bg'] = theme_get_setting('table_bg');
  $variables['table_hover'] = theme_get_setting('table_hover');
  $variables['table_bordered'] = theme_get_setting('table_bordered');
  $variables['table_border_color'] = theme_get_setting('table_border_color');
  $variables['table_borderless'] = theme_get_setting('table_borderless');
  $variables['table_sm'] = theme_get_setting('table_sm');
  $variables['table_align_middle'] = theme_get_setting('table_align_middle');
  $variables['table_thead_variant'] = theme_get_setting('table_thead_variant');
  $variables['table_caption_top'] = theme_get_setting('table_caption_top');
  $variables['table_responsive'] = theme_get_setting('table_responsive');

  if (isset($variables['table_hovered']) && $variables['table_hovered']) {
    $variables['table_striped'] = FALSE;
  }

  if (isset($variables['table_borderless']) && $variables['table_borderless']) {
    $variables['table_bordered'] = FALSE;
  }
}
