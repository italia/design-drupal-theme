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
   * @param array &$variables
   *   Referenced $variables.
   */
  public static function set(array &$variables) {
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
   * @param array &$variables
   *   Variables array.
   *
   * @return string
   *   Element type.
   */
  private static function getType(array &$variables): string {
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
   */
  private static function setText(&$variables) {
    $variables['attributes']['class'][] = 'form-control';
  }

  /**
   * Set textfield input type.
   */
  private static function setTextfield(&$variables) {
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
   */
  private static function setRange(&$variables) {
    $variables['attributes']['class'][] = 'form-range';
  }

  /**
   * Set file input type.
   */
  private static function setFile(&$variables) {
    $variables['attributes']['class'][] = 'upload';
  }

  /**
   * Set submit input type.
   */
  private static function setSubmit(&$variables) {
    $variables['attributes']['class'][] = 'btn';
  }

  /**
   * Set password input type.
   */
  private static function setPassword(&$variables) {
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
   */
  private static function checkErrors(&$variables) {
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
   */
  private static function checkSuccess(&$variables) {
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
