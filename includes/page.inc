<?php

/**
 * @file
 * Hook THEME_page_*.
 */

use Drupal\bootstrap_italia\Helper\Helper;

/**
 * Implements page_attachments_alter()
 */
function bootstrap_italia_page_attachments_alter(&$page) {
  $viewport = array(
    '#type' => 'html_tag',
    '#tag' => 'meta',
    '#attributes' => array(
      'name' => 'viewport',
      'content' => 'width=device-width, initial-scale=1, shrink-to-fit=no',
    ),
  );
  $page['#attached']['html_head'][] = [$viewport, 'viewport'];
}

/**
 * Implements hook_preprocess_page().
 */
function bootstrap_italia_preprocess_page(&$variables) {
  // Slim header settings.
  $variables['slim_header_container_type'] = theme_get_setting('slim_header_container_type');
  $variables['slim_header_light'] = (bool) theme_get_setting('slim_header_light');
  $variables['government_entity_name'] = theme_get_setting('government_entity_name');
  $variables['government_entity_url'] = theme_get_setting('government_entity_url');
  // Login button settings for anonymous user.
  $variables['slim_header_action_type'] = theme_get_setting('slim_header_action_type');
  $variables['slim_header_action_url'] = theme_get_setting('slim_header_action_url');
  $variables['slim_header_action_icon'] = (bool) theme_get_setting('slim_header_action_icon');

  // Center Header Settings.
  $variables['center_header_container_type'] = theme_get_setting('center_header_container_type');
  $variables['center_header_light'] = (bool) theme_get_setting('center_header_light');
  $variables['center_header_small'] = (bool) theme_get_setting('center_header_small');
  // Social.
  $variables['social_new_window'] = (bool) theme_get_setting('social_new_window');
  foreach (Helper::getSocialItems() as $social) {
    $low_social = strtolower($social);
    if (theme_get_setting($low_social)) {
      $variables['socials'][$low_social]['label'] = $social;
      $variables['socials'][$low_social]['url'] = theme_get_setting($low_social);
    }
  }

  // Navigation Settings.
  $variables['navigation_header_container_type'] = theme_get_setting('navigation_header_container_type');
  $variables['navigation_header_light_desktop'] = (bool) theme_get_setting('navigation_header_light_desktop');
  $variables['navigation_header_dark_mobile'] = (bool) theme_get_setting('navigation_header_dark_mobile');
  $variables['navigation_header_sticky'] = (bool) theme_get_setting('navigation_header_sticky');

  // If the navbar uses the "light" variant, the "center header" light is set.
  // Otherwise, 'it-burger' will have the same background color
  // and will not be visible.
  // https://github.com/italia/bootstrap-italia-next/issues/35
/*  if ($variables['navigation_header_light_desktop']) {
    $variables['center_header_light'] = TRUE;
  }*/
}
