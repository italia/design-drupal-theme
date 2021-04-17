<?php
/**
 * @file
 * Theme and preprocess functions for forms.
 */

use Drupal\Core\Form\FormStateInterface;

/**
 * Implements hook_form_FORM_ID_alter().
 */
function bootstrap_italia_form_search_block_form_alter(&$form, FormStateInterface $form_state, $form_id) {
  // Update the placeholder and size of field.
  $form['keys']['#title'] = '';
  $form['keys']['#size'] = 20;
  $form['keys']['#placeholder'] = t('Search');
}

/**
 * Implements hook_preprocess_form_element().
 */
function bootstrap_italia_preprocess_form_element(&$variables) {
  $element = $variables['element'];

  // Add required class for checkbox and radio labels.
  if (in_array($element['#type'], ['checkbox', 'radio'])) {
    $variables['label']['#attributes']['class'][] = 'form-check-label';
  }
}

/**
 * Implements hook_preprocess_input().
 */
function bootstrap_italia_preprocess_input(&$variables) {
  $element = $variables['element'];

  // Add the element type to the theme.
  $variables['type'] = $element['#type'];
}
