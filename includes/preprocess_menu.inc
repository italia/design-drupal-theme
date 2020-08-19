<?php

/**
* Implements hook_preprocess_menu().
*/

// use Drupal\node\Entity\Node;

function bootstrap_italia_preprocess_menu(&$variables, $hook)
{
  // Main menu
  $variables['main_menu_link_size'] = (bool) theme_get_setting('main_menu_link_size');
  $variables['main_menu_link_bolder_active'] = (bool) theme_get_setting('main_menu_link_bolder_active');
  $variables['main_menu_dropdown_link_description'] = (bool) theme_get_setting('main_menu_dropdown_link_description');
  $variables['main_menu_megamenu_title_description'] = (bool) theme_get_setting('main_menu_megamenu_title_description');
  $variables['main_menu_megamenu_link_description'] = (bool) theme_get_setting('main_menu_megamenu_link_description');

  // Sidebar menu
  $variables['sidebar_menu_background'] =
    (string) theme_get_setting('sidebar_menu_background') == 'custom' ?
    false :
    (string) theme_get_setting('sidebar_menu_background');

  if ( (string) theme_get_setting('sidebar_menu_link_size') == 'all' ) {
    $variables['sidebar_menu_link_size'] = true;
    $variables['sidebar_menu_link_size_active'] = false;
  }
  elseif ( (string) theme_get_setting('sidebar_menu_link_size') == 'active' ) {
    $variables['sidebar_menu_link_size'] = false;
    $variables['sidebar_menu_link_size_active'] = true;
  }
  else {
    $variables['sidebar_menu_link_size'] = false;
    $variables['sidebar_menu_link_size_active'] = false;
  }

  if ( (string) theme_get_setting('sidebar_menu_link_weight') == 'all' ) {
    $variables['sidebar_menu_link_weight'] = true;
    $variables['sidebar_menu_link_weight_active'] = false;
  }
  elseif ( (string) theme_get_setting('sidebar_menu_link_weight') == 'active' ) {
    $variables['sidebar_menu_link_weight'] = false;
    $variables['sidebar_menu_link_weight_active'] = true;
  }
  else {
    $variables['sidebar_menu_link_weight'] = false;
    $variables['sidebar_menu_link_weight_active'] = false;
  }

  $variables['sidebar_menu_link_description'] = (bool) theme_get_setting('sidebar_menu_link_description');
  $variables['sidebar_menu_icon_type'] = (string) theme_get_setting('sidebar_menu_icon_type');
  $variables['sidebar_menu_icon_position'] = (string) theme_get_setting('sidebar_menu_icon_position');
  $variables['sidebar_menu_icon_color'] = (string) theme_get_setting('sidebar_menu_icon_color');

}
