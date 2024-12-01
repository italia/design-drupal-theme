<?php

/**
 * @file
 * Hook THEME_page_*.
 */

use Drupal\bootstrap_italia\Helper\Helper;

/**
 * Implements page_attachments_alter().
 *
 * Ref: https://www.drupal.org/project/coding_standards/issues/3056368
 *
 * @phpstan-ignore missingType.iterableValue
 */
function bootstrap_italia_page_attachments_alter(array &$page): void {
  $viewport = [
    '#type' => 'html_tag',
    '#tag' => 'meta',
    '#attributes' => [
      'name' => 'viewport',
      'content' => 'width=device-width, initial-scale=1, shrink-to-fit=no',
    ],
  ];
  $page['#attached']['html_head'][] = [$viewport, 'viewport'];
}

/**
 * Implements hook_preprocess_page().
 *
 * Ref: https://www.drupal.org/project/coding_standards/issues/3056368
 *
 * @phpstan-ignore missingType.iterableValue
 */
function bootstrap_italia_preprocess_page_title(array &$variables): void {
  if (theme_get_setting('page_title_semibold')) {
    if (!isset($variables['title_attributes']['class'])) {
      $variables['title_attributes']['class'] = [];
    }
    $variables['title_attributes']['class'][] = 'fw-semibold';
  }
}

/**
 * Implements hook_preprocess_page().
 *
 * Ref: https://www.drupal.org/project/coding_standards/issues/3056368
 *
 * @phpstan-ignore missingType.iterableValue
 */
function bootstrap_italia_preprocess_page(array &$variables): void {
  $variables['pa_website_validator_type'] = theme_get_setting('pa_website_validator_type');

  // Site name.
  $variables['site_name'] = \Drupal::config('system.site')->get('name');

  // Header.
  $variables['header_shadow'] = theme_get_setting('header_shadow');

  // Slim header settings.
  $variables['slim_header_container_type'] = theme_get_setting('slim_header_container_type');
  $variables['slim_header_light'] = (bool) theme_get_setting('slim_header_light');
  $variables['government_entity_name'] = theme_get_setting('government_entity_name');
  $variables['government_entity_url'] = theme_get_setting('government_entity_url');

  // Login button settings for anonymous user.
  $variables['slim_header_action_active_login'] = (bool) theme_get_setting('slim_header_action_active_login');
  $variables['slim_header_action_type'] = theme_get_setting('slim_header_action_type');
  $variables['slim_header_action_url'] = theme_get_setting('slim_header_action_url');
  $variables['slim_header_action_icon'] = (bool) theme_get_setting('slim_header_action_icon');

  // Center Header Settings.
  $variables['center_header_container_type'] = theme_get_setting('center_header_container_type');
  $variables['center_header_light'] = (bool) theme_get_setting('center_header_light');
  $variables['center_header_small'] = (bool) theme_get_setting('center_header_small');
  // Social.
  $variables['social_new_window'] = (bool) theme_get_setting('social_new_window');
  $variables['socials'] = Helper::getActiveSocials();
  // Search.
  $variables['search_type'] = theme_get_setting('search_type');
  $variables['search_page_url'] = theme_get_setting('search_page_url');
  $variables['search_modal_size'] = theme_get_setting('search_modal_size');

  // Navigation Settings.
  $variables['navigation_header_container_type'] = theme_get_setting('navigation_header_container_type');
  $variables['navigation_header_light_desktop'] = (bool) theme_get_setting('navigation_header_light_desktop');
  $variables['navigation_header_dark_mobile'] = (bool) theme_get_setting('navigation_header_dark_mobile');
  $variables['navigation_header_sticky'] = (bool) theme_get_setting('navigation_header_sticky');

  // Content Settings.
  $variables['content_container_type'] = theme_get_setting('content_container_type');
  $variables['content_padding_bottom'] = theme_get_setting('content_padding_bottom');
  $variables['content_margin_bottom'] = theme_get_setting('content_margin_bottom');

  // Footer settings.
  $variables['footer_container_type'] = theme_get_setting('footer_container_type');

  // Home settings.
  $variables['show_main_content_in_front'] = (bool) theme_get_setting('show_main_content_in_front');
}

/**
 * Implements hook_preprocess_html().
 *
 * Ref: https://www.drupal.org/project/coding_standards/issues/3056368
 *
 * @phpstan-ignore missingType.iterableValue
 */
function bootstrap_italia_preprocess_html(array &$variables): void {
  // Back to top.
  $variables['back_to_top_enable'] = (bool) theme_get_setting('back_to_top_enable');
  $variables['back_to_top_small'] = (bool) theme_get_setting('back_to_top_small');
  $variables['back_to_top_dark'] = (bool) theme_get_setting('back_to_top_dark');
  $variables['back_to_top_shadow'] = (bool) theme_get_setting('back_to_top_shadow');

  // Add page type.
  if (isset($variables['page']['#type'])) {
    $variables['page_type'] = $variables['page']['#type'];
  }

  // Font from cdn.
  $variables['libraries_fonts_load_from_css'] = (bool) theme_get_setting('libraries_fonts_load_from_css');
  $variables['libraries_cdn_fonts'] = theme_get_setting('libraries_cdn_fonts');
}
