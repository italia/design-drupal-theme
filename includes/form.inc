<?php

/**
 * @file
 * Theme and preprocess functions for forms.
 */

use Drupal\bootstrap_italia\Helper\FormElement;
use Drupal\bootstrap_italia\Helper\FormInput;
use Drupal\Core\Form\FormStateInterface;
use Drupal\Core\Template\Attribute;

/**
 * Implements hook_form_alter() for adding classes and placeholder text to the search forms.
 *
 * Ref: https://www.drupal.org/project/coding_standards/issues/3056368
 *
 * @phpstan-ignore missingType.iterableValue
 */
function bootstrap_italia_form_alter(array &$form, FormStateInterface $form_state, string $form_id): void {
  if (isset($form['actions']['submit']) && (count($form['actions'])) <= 2) {
    $form['actions']['submit']['#attributes']['class'][] = 'btn';
    $form['actions']['submit']['#attributes']['class'][] = 'btn-primary';
  }

  switch ($form_id) {
    case 'search_block_form':
      // Add placeholder text to keys input.
      $form['keys']['#attributes']['placeholder'] = t('Search by keyword or phrase.');

      // Add classes to the search form submit input.
      $form['actions']['submit']['#attributes']['class'][] = 'btn';
      $form['actions']['submit']['#attributes']['class'][] = 'btn-primary';
      break;

    case 'search_form':
      $form['basic']['keys']['#attributes']['placeholder'] = t('Search by keyword or phrase.');
      $form['basic']['submit']['#attributes']['class'][] = 'btn';
      $form['basic']['submit']['#attributes']['class'][] = 'btn-primary';
      $form['advanced']['submit']['#attributes']['class'][] = 'btn';
      $form['advanced']['submit']['#attributes']['class'][] = 'btn-primary';
      break;
  }

  if (isset($form['#attributes']['class'])) {
    $form['#attributes']['class'][] = 'needs-validation';
  }
}

/**
 * Implements hook_form_FORM_ID_alter().
 *
 * Ref: https://www.drupal.org/project/coding_standards/issues/3056368
 *
 * @phpstan-ignore missingType.iterableValue
 */
function bootstrap_italia_form_search_block_form_alter(array &$form): void {
  $form['keys']['#placeholder'] = t('Search by keyword or phrase.');
}

/**
 * Implements hook_preprocess_form_element().
 *
 * Ref: https://www.drupal.org/project/coding_standards/issues/3056368
 *
 * @phpstan-ignore missingType.iterableValue
 */
function bootstrap_italia_preprocess_form_element(array &$variables): void {
  FormElement::set($variables);
  FormElement::setActiveLabel($variables);
}

/**
 * Implements hook_preprocess_input().
 *
 * Ref: https://www.drupal.org/project/coding_standards/issues/3056368
 *
 * @phpstan-ignore missingType.iterableValue
 */
function bootstrap_italia_preprocess_input(array &$variables): void {

  FormInput::set($variables);

  if (!empty($variables['element']['#autocomplete_route_name'])) {
    $variables['autocomplete_message'] = t('Loading…');
  }
}

/**
 * Implements hook_preprocess_select().
 *
 * Ref: https://www.drupal.org/project/coding_standards/issues/3056368
 *
 * @phpstan-ignore missingType.iterableValue
 */
function bootstrap_italia_preprocess_select(array &$variables): void {
  if (isset($variables['attributes']['multiple']) &&
    $variables['attributes']['multiple'] == 'multiple'
  ) {
    $variables['attributes']['class'][] = 'border';
  }
}

/**
 * Implements hook_preprocess_container().
 *
 * Ref: https://www.drupal.org/project/coding_standards/issues/3056368
 *
 * @phpstan-ignore missingType.iterableValue
 */
function bootstrap_italia_preprocess_container(array &$variables): void {
  if (isset($variables['element']['#attributes']) &&
    $variables['element']['#attributes'] instanceof Attribute &&
    $variables['element']['#attributes']->hasClass('webform-element-description')
  ) {
    $variables['element']['#attributes']->addClass('form-text');
  }

  // Detects form actions.
  if (
    (
      isset($variables['attributes']['class']) &&
      isset($variables['element']['#type']) &&
      $variables['element']['#type'] == 'actions'
    ) ||
    (
      isset($variables['attributes']['class']) &&
      is_array($variables['attributes']['class']) &&
      in_array('form-actions', $variables['attributes']['class'], TRUE)
    )
  ) {
    if (theme_get_setting('forms_action_spacing')) {
      $variables['attributes']['class'][] = 'mt-5';
      $variables['attributes']['class'][] = 'mb-3';
    }
    $variables['attributes']['class'][] = 'text-align-' . theme_get_setting('forms_action_alignment');
  }
}

/**
 * Implements hook_template_preprocess_form_element_label().
 *
 * Ref: https://www.drupal.org/project/coding_standards/issues/3056368
 *
 * @phpstan-ignore missingType.iterableValue
 */
function bootstrap_italia_preprocess_form_element_label(array &$variables): void {
  if (isset($variables['required']) && $variables['required']) {
    $variables['forms_field_label_required_mark'] = (bool) theme_get_setting('forms_field_label_required_mark');
  }
}
