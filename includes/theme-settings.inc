<?php

/**
 * @file
 * Theme settings.
 */

use Drupal\bootstrap_italia\Helper\Helper;
use Drupal\bootstrap_italia\Helper\Libraries;
use Drupal\Core\Form\FormStateInterface;

/**
 * Implements hook_form_system_theme_settings_alter().
 */
function bootstrap_italia_form_system_theme_settings_alter(array &$form, FormStateInterface $form_state, $form_id = NULL) {

  // General "alters" use a form id. Settings should not be set here. The only
  // thing useful about this is if you need to alter the form for the running
  // theme and *not* the theme setting.
  // @see http://drupal.org/node/943212
  if (isset($form_id)) {
    return;
  }

  // Main vertical tabs.
  $form['bootstrap'] = [
    '#type' => 'vertical_tabs',
    '#weight' => -10,
  ];

  // Header slim --------------------------------------------------------------.
  $form['slim_header'] = [
    '#type' => 'details',
    '#title' => t('Slim Header'),
    '#description' => t("Slim header settings"),
    '#open' => TRUE,
    '#group' => 'bootstrap',
    '#weight' => 0,
  ];
  // Slim header appearance.
  $form['slim_header']['slim_header_appearance'] = [
    '#type' => 'details',
    '#title' => t('Appearance'),
    '#open' => TRUE,
    '#group' => 'slim_header',
  ];
  $form['slim_header']['slim_header_appearance']['slim_header_container_type'] = [
    '#type' => 'select',
    '#title' => t("Container"),
    '#description' => t('Choose container type.'),
    '#default_value' => theme_get_setting('slim_header_container_type'),
    '#options' => Helper::getBootstrapContainerType(TRUE),
  ];
  $form['slim_header']['slim_header_appearance']['slim_header_light'] = [
    '#type' => 'checkbox',
    '#title' => t('Enable light variant'),
    '#default_value' => theme_get_setting('slim_header_light'),
  ];
  // Government entity.
  $form['slim_header']['government_entity'] = [
    '#type' => 'details',
    '#title' => t('Government entity'),
    '#description' => t("Settings related to the superior government entity."),
    '#open' => TRUE,
    '#group' => 'slim_header',
  ];
  $form['slim_header']['government_entity']['government_entity_name'] = [
    '#type' => 'textfield',
    '#title' => t('Name'),
    '#description' => t("Government entity name."),
    '#placeholder' => t('Italian government'),
    '#default_value' => theme_get_setting('government_entity_name'),
  ];
  $form['slim_header']['government_entity']['government_entity_url'] = [
    '#type' => 'url',
    '#title' => t('Government entity web site'),
    '#placeholder' => t('https://example.gov.it'),
    '#description' => t("Government entity URL. Example: https://example.gov.it."),
    '#default_value' => theme_get_setting('government_entity_url'),
  ];
  // Slim header Action.
  $form['slim_header']['slim_header_action'] = [
    '#type' => 'details',
    '#title' => t('Login button and user menu'),
    '#open' => TRUE,
    '#group' => 'slim_header',
  ];
  $form['slim_header']['slim_header_action']['slim_header_action_type'] = [
    '#type' => 'select',
    '#title' => t('Login button type'),
    '#description' => t('Choose login button variant.'),
    '#default_value' => theme_get_setting('slim_header_action_type'),
    '#options' => [
      'default' => t('Default'),
      'full' => t('Full responsive'),
    ],
  ];
  $form['slim_header']['slim_header_action']['slim_header_action_url'] = [
    '#type' => 'textfield',
    '#title' => t('Login page URL'),
    '#description' => t("Fill if you use a custom login page."),
    '#placeholder' => t('/user/login'),
    '#default_value' => theme_get_setting('slim_header_action_url'),
  ];
  $form['slim_header']['slim_header_action']['slim_header_action_icon'] = [
    '#type' => 'checkbox',
    '#title' => t('Show icon'),
    '#default_value' => theme_get_setting('slim_header_action_icon'),
  ];
  $form['slim_header']['slim_header_action']['slim_header_action_username'] = [
    '#type' => 'checkbox',
    '#title' => t('Show username'),
    '#default_value' => theme_get_setting('slim_header_action_username'),
  ];
  $form['slim_header']['slim_header_action']['slim_header_action_dark'] = [
    '#type' => 'checkbox',
    '#title' => t('Enable dark mode to user logged menu'),
    '#default_value' => theme_get_setting('slim_header_action_dark'),
  ];

  // Center header ------------------------------------------------------------.
  $form['center_header'] = [
    '#type' => 'details',
    '#title' => t('Center header'),
    '#description' => t("Center header settings"),
    '#open' => TRUE,
    '#group' => 'bootstrap',
    '#weight' => 0,
  ];
  // Center header appearance.
  $form['center_header']['center_header_appearance'] = [
    '#type' => 'details',
    '#title' => t('Appearance'),
    '#open' => TRUE,
    '#group' => 'center_header',
  ];
  $form['center_header']['center_header_appearance']['center_header_container_type'] = [
    '#type' => 'select',
    '#title' => t("Container"),
    '#description' => t('Choose container type.'),
    '#default_value' => theme_get_setting('center_header_container_type'),
    '#options' => Helper::getBootstrapContainerType(TRUE),
  ];
  $form['center_header']['center_header_appearance']['center_header_light'] = [
    '#type' => 'checkbox',
    '#title' => t('Enable light variant'),
    '#default_value' => theme_get_setting('center_header_light'),
  ];
  $form['center_header']['center_header_appearance']['center_header_small'] = [
    '#type' => 'checkbox',
    '#title' => t('Enable small variant'),
    '#default_value' => theme_get_setting('center_header_small'),
  ];
  // Center header branding.
  $form['center_header']['center_header_branding'] = [
    '#type' => 'details',
    '#title' => t('Branding block'),
    '#open' => TRUE,
    '#group' => 'center_header',
  ];
  $form['center_header']['center_header_branding']['svg_logo_id'] = [
    '#type' => 'textfield',
    '#title' => t('Svg logo: group id'),
    '#description' => t("Choose your custom id ('symbol' tag of svg file). Default: 'logo'."),
    '#placeholder' => t('logo'),
    '#default_value' => theme_get_setting('svg_logo_id'),
  ];
  $form['center_header']['center_header_branding']['svg_logo_box'] = [
    '#type' => 'textfield',
    '#title' => t('Svg logo: view box'),
    '#description' => t("Choose your custom viewBox."),
    '#placeholder' => t('0 0 82 82'),
    '#default_value' => theme_get_setting('svg_logo_box'),
  ];
  $form['center_header']['center_header_branding']['svg_logo_box_sticky'] = [
    '#type' => 'textfield',
    '#title' => t('Svg logo: view box when header is sticky'),
    '#description' => t("Choose your custom viewBox."),
    '#placeholder' => t('0 0 82 82'),
    '#default_value' => theme_get_setting('svg_logo_box_sticky'),
  ];
  $form['center_header']['center_header_branding']['image_logo_fluid'] = [
    '#type' => 'checkbox',
    '#title' => t('Enable responsive feature'),
    '#description' => t("If checked and you have loaded a raster image, enable the 'img-fluid' feature."),
    '#default_value' => theme_get_setting('image_logo_fluid'),
  ];

  // Navigation header --------------------------------------------------------.
  $form['navigation_header'] = [
    '#type' => 'details',
    '#title' => t('Main navigation'),
    '#description' => t("Main navigation settings"),
    '#open' => TRUE,
    '#group' => 'bootstrap',
    '#weight' => 0,
  ];
  // Navigation header appearance.
  $form['navigation_header']['navigation_header_appearance'] = [
    '#type' => 'details',
    '#title' => t('Appearance'),
    '#open' => TRUE,
    '#group' => 'navigation_header',
  ];
  $form['navigation_header']['navigation_header_appearance']['navigation_header_container_type'] = [
    '#type' => 'select',
    '#title' => t("Container"),
    '#description' => t('Choose container type.'),
    '#default_value' => theme_get_setting('navigation_header_container_type'),
    '#options' => Helper::getBootstrapContainerType(TRUE),
  ];
  $form['navigation_header']['navigation_header_appearance']['navigation_header_light_desktop'] = [
    '#type' => 'checkbox',
    '#title' => t('Enable light variant to desktop'),
    '#default_value' => theme_get_setting('navigation_header_light_desktop'),
  ];
  $form['navigation_header']['navigation_header_appearance']['navigation_header_dark_mobile'] = [
    '#type' => 'checkbox',
    '#title' => t('Enable dark variant to mobile'),
    '#default_value' => theme_get_setting('navigation_header_dark_mobile'),
  ];
  $form['navigation_header']['navigation_header_appearance']['navigation_header_sticky'] = [
    '#type' => 'checkbox',
    '#title' => t('Enable sticky on top'),
    '#default_value' => theme_get_setting('navigation_header_sticky'),
  ];

  // Libraries Settings -------------------------------------------------------.
  $form['libraries_settings'] = [
    '#type' => 'details',
    '#title' => t('Libraries'),
    '#description' => t("Customize library source. You need to clear the cache if you change these settings."),
    '#open' => FALSE,
    '#group' => 'bootstrap',
    '#weight' => 20,
  ];
  $form['libraries_settings']['libraries_type'] = [
    '#type' => 'select',
    '#title' => t("Choose libraries type"),
    '#default_value' => theme_get_setting('libraries_type'),
    '#options' => Libraries::getLibraries(),
  ];

  // Vanilla Settings
  $form['libraries_settings']['vanilla'] = [
    '#type' => 'details',
    '#title' => t('Vanilla Settings'),
    '#open' => TRUE,
    '#group' => 'libraries_settings',
  ];
  $form['libraries_settings']['vanilla']['libraries_bundle'] = [
    '#type' => 'checkbox',
    '#title' => t("Use the bundle version (only for vanilla option)."),
    '#default_value' => theme_get_setting('libraries_bundle'),
  ];

  // CDN Settings
  $form['libraries_settings']['cdn'] = [
    '#type' => 'details',
    '#title' => t('CDN Settings'),
    '#description' => t("If you use a third-party CDN, check that you are compliant with the GDPR."),
    '#open' => TRUE,
    '#group' => 'libraries_settings',
  ];
  $form['libraries_settings']['cdn']['libraries_cdn_css'] = [
    '#type' => 'url',
    '#title' => t('CSS from CDN'),
    '#description' => t("Put resource URI."),
    '#default_value' => theme_get_setting('libraries_cdn_css'),
  ];
  $form['libraries_settings']['cdn']['libraries_cdn_js'] = [
    '#type' => 'url',
    '#title' => t('JS from CDN'),
    '#description' => t("Put resource URI."),
    '#default_value' => theme_get_setting('libraries_cdn_js'),
  ];
  $form['libraries_settings']['cdn']['libraries_cdn_minified'] = [
    '#type' => 'checkbox',
    '#title' => t('Check if you are using minified libraries.'),
    '#default_value' => theme_get_setting('libraries_cdn_minified'),
  ];


  $form['#validate'][] = 'bootstrap_italia_form_system_theme_settings_validate';
}

/**
 * Implements hook_form_system_theme_settings_validate().
 */
function bootstrap_italia_form_system_theme_settings_validate(array &$form, FormStateInterface $form_state) {
  if (function_exists('file_save_upload')) {
    // Handle file uploads.
    $image_factory = \Drupal::service('image.factory');
    $supported_extensions = $image_factory->getSupportedExtensions();
    $supported_extensions[] = 'svg';
    $validators = ['file_validate_extensions' => [implode(' ', $supported_extensions)]];

    // Check for a new uploaded logo.
    $file = file_save_upload('logo_upload', $validators, FALSE, 0);
    if (isset($file)) {
      // File upload was attempted.
      if ($file) {
        // Put the temporary file in form_values so we can save it on submit.
        $form_state->setValue('logo_upload', $file);
      }
      else {
        // File upload failed.
        $form_state->setErrorByName('logo_upload', t('The logo could not be uploaded.'));
      }
    }
  }
}
