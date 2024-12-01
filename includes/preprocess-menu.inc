<?php

/**
 * @file
 * Hook THEME_preprocess_menu_*.
 */

use Drupal\user\Entity\User;

/**
 * Implements hook_preprocess_menu().
 *
 * Ref: https://www.drupal.org/project/coding_standards/issues/3056368
 *
 * @phpstan-ignore missingType.iterableValue
 */
function bootstrap_italia_preprocess_menu(array &$variables): void {
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

      // Fix cache.
      $variables['#cache']['contexts'][] = 'user';
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
    $variables['navigation_header_sticky_menu_name'] = theme_get_setting('navigation_header_sticky_menu_name');
    $variables['pa_website_validator_type'] = theme_get_setting('pa_website_validator_type');
  }

  // Menu in sidebar first.
  if (isset($variables['attributes']['data-block']['region']) &&
    $variables['attributes']['data-block']['region'] == 'sidebar_first'
  ) {
    $variables['sidebar_first_menu_show_link_description'] = (bool) theme_get_setting('sidebar_first_menu_show_link_description');
    $variables['sidebar_first_menu_first_level_large'] = (bool) theme_get_setting('sidebar_first_menu_first_level_large');
    $variables['sidebar_first_menu_first_level_bold'] = (bool) theme_get_setting('sidebar_first_menu_first_level_bold');
    $variables['sidebar_first_menu_icon_color'] =
      theme_get_setting('sidebar_first_menu_dark') ? 'white' : 'primary';
  }
  // Menu in sidebar second.
  if (isset($variables['attributes']['data-block']['region']) &&
    $variables['attributes']['data-block']['region'] == 'sidebar_second'
  ) {
    $variables['sidebar_second_menu_show_link_description'] = (bool) theme_get_setting('sidebar_second_menu_show_link_description');
    $variables['sidebar_second_menu_first_level_large'] = (bool) theme_get_setting('sidebar_second_menu_first_level_large');
    $variables['sidebar_second_menu_first_level_bold'] = (bool) theme_get_setting('sidebar_second_menu_first_level_bold');
    $variables['sidebar_second_menu_icon_color'] =
      theme_get_setting('sidebar_second_menu_dark') ? 'white' : 'primary';
  }

}

/**
 * Implements hook_preprocess_menu().
 *
 * Ref: https://www.drupal.org/project/coding_standards/issues/3056368
 *
 * @phpstan-ignore missingType.iterableValue
 */
function bootstrap_italia_preprocess_menu_local_tasks(array &$variables): void {
  $variables['editor_nav_tabs_scrollable'] = (bool) theme_get_setting('editor_nav_tabs_scrollable');
}
