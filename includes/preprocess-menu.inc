<?php

/**
 * @file
 * Hook THEME_preprocess_menu_*.
 */

use Drupal\user\Entity\User;

/**
 * Implements hook_preprocess_menu().
 */
function bootstrap_italia_preprocess_menu(&$variables) {
  // User menu.
  if ($variables['menu_name'] == 'account') {
    // Login button settings for logged user.
    $variables['slim_header_action_type'] = theme_get_setting('slim_header_action_type');
    $variables['slim_header_action_icon'] = (bool) theme_get_setting('slim_header_action_icon');
    $variables['slim_header_action_dark'] = (bool) theme_get_setting('slim_header_action_dark');

    if (theme_get_setting('slim_header_action_username')) {
      $current_user = \Drupal::currentUser();
      $uid = $current_user->id();
      $account = User::load($uid);
      $variables['slim_header_action_username'] = $account->getDisplayName();
    }
  }
  // Menu in main navbar.
  if (isset($variables['attributes']['data-block']['region']) &&
    $variables['attributes']['data-block']['region'] == 'header_nav'
  ) {
    $variables['navigation_header_show_link_description'] = (bool) theme_get_setting('navigation_header_show_link_description');
    $variables['navigation_header_active_items_large'] = (bool) theme_get_setting('navigation_header_active_items_large');
    $variables['navigation_header_active_items_bold'] = (bool) theme_get_setting('navigation_header_active_items_bold');
    $variables['navigation_header_verbose_classes'] = (bool) theme_get_setting('navigation_header_verbose_classes');
    $variables['navigation_header_megamenu_columns_lg'] = theme_get_setting('navigation_header_megamenu_columns_lg');
    $variables['navigation_header_megamenu_columns_xl'] = theme_get_setting('navigation_header_megamenu_columns_xl');
    $variables['navigation_header_main_menu_name'] = theme_get_setting('navigation_header_main_menu_name');
  }

}
