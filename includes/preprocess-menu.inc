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
}
