<?php

/**
 * @file
 * Preprocess menu.
 */

/**
 * Implements hook_preprocess_menu().
 */
function bootstrap_italia_preprocess_menu(&$variables, $hook) {
  // Main menu.
  $variables['main_menu_link_size'] = (bool) theme_get_setting('main_menu_link_size');
  $variables['main_menu_link_bolder_active'] = (bool) theme_get_setting('main_menu_link_bolder_active');
  $variables['main_menu_dropdown_link_description'] = (bool) theme_get_setting('main_menu_dropdown_link_description');
  $variables['main_menu_megamenu_title_description'] = (bool) theme_get_setting('main_menu_megamenu_title_description');
  $variables['main_menu_megamenu_link_description'] = (bool) theme_get_setting('main_menu_megamenu_link_description');

  // Sidebar menu.
  $variables['sidebar_menu_background'] =
    (string) theme_get_setting('sidebar_menu_background') == 'custom' ?
    FALSE :
    (string) theme_get_setting('sidebar_menu_background');

  if ((string) theme_get_setting('sidebar_menu_link_size') == 'all') {
    $variables['sidebar_menu_link_size'] = TRUE;
    $variables['sidebar_menu_link_size_active'] = FALSE;
  }
  elseif ((string) theme_get_setting('sidebar_menu_link_size') == 'active') {
    $variables['sidebar_menu_link_size'] = FALSE;
    $variables['sidebar_menu_link_size_active'] = TRUE;
  }
  else {
    $variables['sidebar_menu_link_size'] = FALSE;
    $variables['sidebar_menu_link_size_active'] = FALSE;
  }

  if ((string) theme_get_setting('sidebar_menu_link_weight') == 'all') {
    $variables['sidebar_menu_link_weight'] = TRUE;
    $variables['sidebar_menu_link_weight_active'] = FALSE;
  }
  elseif ((string) theme_get_setting('sidebar_menu_link_weight') == 'active') {
    $variables['sidebar_menu_link_weight'] = FALSE;
    $variables['sidebar_menu_link_weight_active'] = TRUE;
  }
  else {
    $variables['sidebar_menu_link_weight'] = FALSE;
    $variables['sidebar_menu_link_weight_active'] = FALSE;
  }

  $variables['sidebar_menu_link_description'] = (bool) theme_get_setting('sidebar_menu_link_description');
  $variables['sidebar_menu_icon_type'] = (string) theme_get_setting('sidebar_menu_icon_type');
  $variables['sidebar_menu_icon_position'] = (string) theme_get_setting('sidebar_menu_icon_position');
  $variables['sidebar_menu_icon_color'] = (string) theme_get_setting('sidebar_menu_icon_color');

}
