<?php

namespace Drupal\bootstrap_italia\Helper;

/**
 * Helper Form class for bootstrap_italia theme.
 *
 * Why isn't it a service? https://www.drupal.org/project/drupal/issues/2002606.
 */
class FormInput {

  /**
   * Set form input.
   *
   * @param array<string, mixed> &$variables
   *   Referenced $variables.
   */
  public static function set(array &$variables): void {
    if (isset($variables['element']['#type'])) {
      $variables['type'] = self::getType($variables);

      switch ($variables['type']) {
        case 'text':
        case 'email':
        case 'tel':
        case 'search':
        case 'date':
        case 'datetime-local':
        case 'datetime':
        case 'datelist':
        case 'webform_time':
        case 'time':
        case 'color':
        case 'url':
        case 'month':
        case 'week':
          self::setText($variables);
          break;

        case 'textfield':
          self::setTextfield($variables);
          break;

        case 'range':
          self::setRange($variables);
          break;

        case 'file':
          self::setFile($variables);
          break;

        case 'password':
        case 'webform_password':
          self::setPassword($variables);
          break;

        case 'submit':
          self::setSubmit($variables);
          break;
      }
    }

    self::checkErrors($variables);
    self::checkSuccess($variables);
  }

  /**
   * Return variables type.
   *
   * @param array<string, mixed> $variables
   *   Variables array.
   *
   * @return string
   *   Element type.
   */
  private static function getType(array $variables): string {
    $type = $variables['element']['#type'];

    // Search if a webform-password.
    if (isset($variables['attributes']['class']) &&
      in_array('js-webform-input-hide', $variables['attributes']['class'], TRUE)
    ) {
      $type = 'webform_password';
    }

    return $type;
  }

  /**
   * Set text input type.
   *
   * @param array<string, mixed> $variables
   *   Variables array.
   */
  private static function setText(array &$variables): void {
    $variables['attributes']['class'][] = 'form-control';
  }

  /**
   * Set textfield input type.
   *
   * @param array<string, mixed> $variables
   *   Variables array.
   */
  private static function setTextfield(array &$variables): void {
    // Ensure there is no collision with Bootstrap 5 default class names
    // by replacing ".form-text" with ".form-textfield".
    $attributes = &$variables['attributes'];

    if (!empty($attributes['class'])) {
      $classIndex = array_search('form-text', $attributes['class']);
      $attributes['class'][$classIndex] = 'form-textfield';
    }
    $variables['attributes']['class'][] = 'form-control';
  }

  /**
   * Set range input type.
   *
   * @param array<string, mixed> $variables
   *   Variables array.
   */
  private static function setRange(array &$variables): void {
    $variables['attributes']['class'][] = 'form-range';
  }

  /**
   * Set file input type.
   *
   * @param array<string, mixed> $variables
   *   Variables array.
   */
  private static function setFile(array &$variables): void {
    $variables['attributes']['class'][] = 'upload';
  }

  /**
   * Set submit input type.
   *
   * @param array<string, mixed> $variables
   *   Variables array.
   */
  private static function setSubmit(array &$variables): void {
    $variables['attributes']['class'][] = 'btn';

    if (isset($variables['attributes']['data-drupal-selector'])) {

      if ($variables['attributes']['data-drupal-selector'] == 'edit-submit' ||
        $variables['attributes']['data-drupal-selector'] == 'edit-actions-submit' ||
        $variables['attributes']['data-drupal-selector'] == 'edit-submit-watchdog'
      ) {
        $variables['attributes']['class'][] = 'btn-primary';
        $variables['attributes']['class'][] = 'me-3';
      }

      if ($variables['attributes']['data-drupal-selector'] == 'edit-reset') {
        $variables['attributes']['class'][] = 'btn-outline-danger';
        $variables['attributes']['class'][] = 'me-3';
      }

      if ($variables['attributes']['data-drupal-selector'] == 'edit-delete') {
        $variables['attributes']['class'][] = 'btn-danger';
        $variables['attributes']['class'][] = 'me-3';
      }

      if ($variables['attributes']['data-drupal-selector'] == 'edit-apply-above' ||
        $variables['attributes']['data-drupal-selector'] == 'edit-apply-below' ||
        $variables['attributes']['data-drupal-selector'] == 'edit-preview-next' ||
        $variables['attributes']['data-drupal-selector'] == 'edit-preview' ||
        $variables['attributes']['data-drupal-selector'] == 'edit-submit-content' ||
        $variables['attributes']['data-drupal-selector'] == 'edit-overview' ||
        $variables['attributes']['data-drupal-selector'] == 'edit-wizard-next' ||
        $variables['attributes']['data-drupal-selector'] == 'edit-wizard-prev'
      ) {
        $variables['attributes']['class'][] = 'btn-outline-primary';
        $variables['attributes']['class'][] = 'me-3';
      }

      // Detect ajax remove buttons.
      if (str_ends_with($variables['attributes']['data-drupal-selector'], '-remove-button')) {
        $variables['attributes']['class'][] = 'btn-outline-danger';
      }

    }
  }

  /**
   * Set password input type.
   *
   * @param array<string, mixed> $variables
   *   Variables array.
   */
  private static function setPassword(array &$variables): void {
    $variables['attributes']['class'][] = 'form-control ';
    $variables['attributes']['class'][] = 'input-password';

    // Ensure there is no collision with Bootstrap 5 default class names
    // unset ".form-text".
    $attributes = &$variables['attributes'];
    if (!empty($attributes['class'])) {
      $classIndex = array_search('form-text', $attributes['class']);
      unset($attributes['class'][$classIndex]);
    }

    $variables['attributes']['data-bs-input'] = TRUE;
  }

  /**
   * Check validation error on single field.
   *
   * @param array<string, mixed> $variables
   *   Variables array.
   */
  private static function checkErrors(array &$variables): void {
    if (isset($variables['attributes']['class']) &&
      in_array('error', $variables['attributes']['class'], TRUE)
    ) {
      $variables['attributes']['class'][] = 'is-invalid';
    }
    if (isset($variables['attributes']['class']) &&
      in_array('error', $variables['attributes']['class'], TRUE)
    ) {
      $variables['attributes']['class'][] = 'is-invalid';
    }
  }

  /**
   * Check validation success on single field.
   *
   * @param array<string, mixed> $variables
   *   Variables array.
   */
  private static function checkSuccess(array &$variables): void {
    if (isset($variables['attributes']['class'])) {
      if (in_array('success', $variables['attributes']['class'], TRUE) ||
        in_array('valid', $variables['attributes']['class'], TRUE) ||
        in_array('validated', $variables['attributes']['class'], TRUE)
      ) {
        $variables['attributes']['class'][] = 'just-validate-success-field';
      }
    }
  }

}
