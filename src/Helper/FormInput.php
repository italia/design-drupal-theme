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
    $element = $variables['element'] ?? NULL;
    if (!is_array($element)) {
      return;
    }

    $type = $element['#type'] ?? NULL;
    if (!is_string($type)) {
      return;
    }

    // Find the type of the element.
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
    $element = $variables['element'] ?? NULL;
    if (!is_array($element)) {
      return '';
    }

    $type = $element['#type'] ?? '';
    if (!is_string($type)) {
      return '';
    }

    $attributes = $variables['attributes'] ?? [];
    if (!is_array($attributes)) {
      $attributes = [];
    }

    $classes = $attributes['class'] ?? [];
    if (!is_array($classes)) {
      $classes = [];
    }
    $classes = array_values(array_filter($classes, 'is_string'));

    if (in_array('js-webform-input-hide', $classes, TRUE)) {
      return 'webform_password';
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
    $attributes = &Helper::attributes($variables);

    /** @var list<string> $classes */
    $classes = $attributes['class'];

    $classes[] = 'form-control';

    $attributes['class'] = $classes;
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
    $attributes = &Helper::attributes($variables);

    /** @var list<string> $classes */
    $classes = $attributes['class'];

    $classIndex = array_search('form-text', $classes, TRUE);
    if ($classIndex !== FALSE) {
      $classes[$classIndex] = 'form-textfield';
    }

    $classes[] = 'form-control';

    $attributes['class'] = $classes;
  }

  /**
   * Set range input type.
   *
   * @param array<string, mixed> $variables
   *   Variables array.
   */
  private static function setRange(array &$variables): void {
    $attributes = &Helper::attributes($variables);

    /** @var list<string> $classes */
    $classes = $attributes['class'];

    $classes[] = 'form-range';

    $attributes['class'] = $classes;
  }

  /**
   * Set file input type.
   *
   * @param array<string, mixed> $variables
   *   Variables array.
   */
  private static function setFile(array &$variables): void {
    $attributes = &Helper::attributes($variables);

    /** @var list<string> $classes */
    $classes = $attributes['class'];

    $classes[] = 'upload';

    $attributes['class'] = $classes;
  }

  /**
   * Set submit input type.
   *
   * @param array<string, mixed> $variables
   *   Variables array.
   */
  private static function setSubmit(array &$variables): void {
    $attributes = &Helper::attributes($variables);

    /** @var list<string> $classes */
    $classes = $attributes['class'];

    $classes[] = 'btn';

    $selector = $attributes['data-drupal-selector'] ?? NULL;
    if (!is_string($selector)) {
      return;
    }

    if (
      $selector === 'edit-submit' ||
      $selector === 'edit-actions-submit' ||
      $selector === 'edit-submit-watchdog'
    ) {
      $classes[] = 'btn-primary';
      $classes[] = 'me-3';
    }

    if ($selector === 'edit-reset') {
      $classes[] = 'btn-outline-danger';
      $classes[] = 'me-3';
    }

    if ($selector === 'edit-delete') {
      $classes[] = 'btn-danger';
      $classes[] = 'me-3';
    }

    if (
      $selector === 'edit-apply-above' ||
      $selector === 'edit-apply-below' ||
      $selector === 'edit-preview-next' ||
      $selector === 'edit-preview' ||
      $selector === 'edit-submit-content' ||
      $selector === 'edit-overview' ||
      $selector === 'edit-wizard-next' ||
      $selector === 'edit-wizard-prev'
    ) {
      $classes[] = 'btn-outline-primary';
      $classes[] = 'me-3';
    }

    if (str_ends_with($selector, '-remove-button')) {
      $classes[] = 'btn-outline-danger';
    }

    $attributes['class'] = $classes;
  }

  /**
   * Set password input type.
   *
   * @param array<string, mixed> $variables
   *   Variables array.
   */
  private static function setPassword(array &$variables): void {
    $attributes = &Helper::attributes($variables);

    /** @var list<string> $classes */
    $classes = $attributes['class'];

    $classes[] = 'form-control';
    $classes[] = 'input-password';

    $classIndex = array_search('form-text', $classes, TRUE);
    if ($classIndex !== FALSE) {
      unset($classes[$classIndex]);
    }

    $attributes['class'] = $classes;
    $attributes['data-bs-input'] = TRUE;
  }

  /**
   * Check validation error on single field.
   *
   * @param array<string, mixed> $variables
   *   Variables array.
   */
  private static function checkErrors(array &$variables): void {
    $attributes = &Helper::attributes($variables);

    /** @var list<string> $classes */
    $classes = $attributes['class'];

    if (in_array('error', $classes, TRUE)) {
      $classes[] = 'is-invalid';
    }

    $attributes['class'] = $classes;
  }

  /**
   * Check validation success on single field.
   *
   * @param array<string, mixed> $variables
   *   Variables array.
   */
  private static function checkSuccess(array &$variables): void {
    $attributes = &Helper::attributes($variables);

    /** @var list<string> $classes */
    $classes = $attributes['class'];

    if (
      in_array('success', $classes, TRUE) ||
      in_array('valid', $classes, TRUE) ||
      in_array('validated', $classes, TRUE)
    ) {
      $classes[] = 'just-validate-success-field';
    }

    $attributes['class'] = $classes;
  }

}
