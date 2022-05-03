<?php

/**
 * @file
 * Theme settings.
 */

use Drupal\Core\Form\FormStateInterface;
use Drupal\bootstrap_italia\Helper;

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

  // Vertical tabs.
  $form['bootstrap'] = [
    '#type' => 'vertical_tabs',
    '#prefix' => '<h2><small>' . t('Bootstrap Italia settings') . '</small></h2>',
    '#weight' => -10,
  ];

  /* Libraries Settings ------------------------------------------------ */
  $form['libraries_settings'] = [
    '#type' => 'details',
    '#title' => t('Theme libraries'),
    '#description' => t("Library to use."),
    '#open' => FALSE,
    '#group' => 'bootstrap',
    '#weight' => 20,
  ];
  $form['libraries_settings']['theme_variant'] = [
    '#type' => 'select',
    '#title' => t("Choose the theme library"),
    '#description' => t('Whenever you change this setting you have to clear the cache to see the changes.'),
    '#default_value' => theme_get_setting('theme_variant'),
    '#options' => Helper::getThemeVariants(),
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
