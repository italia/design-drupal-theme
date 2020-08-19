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

}
