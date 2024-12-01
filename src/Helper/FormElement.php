<?php

namespace Drupal\bootstrap_italia\Helper;

/**
 * Helper Form class for bootstrap_italia theme.
 *
 * Why isn't it a service? https://www.drupal.org/project/drupal/issues/2002606.
 */
class FormElement {

  /**
   * Set form element.
   *
   * @param array<string, mixed> &$variables
   *   Referenced $variables array.
   */
  public static function set(array &$variables): void {
    if (isset($variables['type'])) {
      $variables['type'] = self::getType($variables);

      switch ($variables['type']) {
        case 'text':
        case 'textfield':
        case 'entity_autocomplete':
        case 'email':
        case 'search':
        case 'password':
        case 'file':
        case 'color':
        case 'url':
        case 'month':
        case 'week':
        case 'webform_email_multiple':
          self::setText($variables);
          break;

        case 'number':
          self::setNumber($variables);
          break;

        case 'number_composite':
          self::setNumberComposite($variables);
          break;

        case 'tel':
          self::setTel($variables);
          break;

        case 'textarea':
          self::setTextarea($variables);
          break;

        case 'date':
        case 'datetime':
        case 'datelist':
        case 'datetime_local':
        case 'time':
        case 'webform_time':
          self::setDateTime($variables);
          break;

        case 'checkbox':
        case 'radio':
          self::setBoolean($variables);
          break;

        case 'select':
          self::setSelect($variables);
          break;

        case 'select_composite':
          self::setSelectComposite($variables);
          break;
      }
    }
  }

  /**
   * Check if label is active.
   *
   * @param array<string, mixed> &$variables
   *   Referenced $variables array.
   */
  public static function setActiveLabel(array &$variables): void {
    if (
      isset($variables['element']['#attributes']['value']) &&
      (
        !empty($variables['element']['#attributes']['value']) ||
        !empty($variables['element']['#attributes']['placeholder'])
      ) &&
      !isset($variables['label']['#attributes']['class']['active'])
    ) {
      $variables['label']['#attributes']['class'][] = 'active';
    }
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
    $type = $variables['type'];

    if ($type == 'textfield' &&
      isset($variables['element']['#title_display']) &&
      $variables['element']['#title_display'] == 'invisible' &&
      isset($variables['label_display']) &&
      $variables['label_display'] == 'invisible'
    ) {
      $type = 'textfield_composite';
    }

    if ($type == 'number' &&
      isset($variables['element']['#title_display']) &&
      $variables['element']['#title_display'] == 'invisible' &&
      isset($variables['label_display']) &&
      $variables['label_display'] == 'invisible'
    ) {
      $type = 'number_composite';
    }

    if ($type == 'url' &&
      isset($variables['element']['#title_display']) &&
      $variables['element']['#title_display'] == 'invisible' &&
      isset($variables['label_display']) &&
      $variables['label_display'] == 'invisible'
    ) {
      $type = 'url_composite';
    }

    if ($type === 'select' &&
      isset($variables['element']['#attributes']) &&
      isset($variables['element']['#attributes']['multiple']) &&
      $variables['element']['#attributes']['multiple'] == 'multiple'
    ) {
      $type = 'select_multiple';
    }

    if ($type === 'select' &&
      isset($variables['element']['#attributes']) &&
      isset($variables['element']['#attributes']['class']) &&
      in_array('webform-select2', $variables['element']['#attributes']['class'], TRUE)
    ) {
      $type = 'select2';
    }

    if ($type == 'select' &&
      isset($variables['element']['#title_display']) &&
      $variables['element']['#title_display'] == 'invisible' &&
      isset($variables['label_display']) &&
      $variables['label_display'] == 'invisible'
    ) {
      $type = 'select_composite';
    }

    if ($type === 'radio' &&
      isset($variables['element']['#attributes']) &&
      isset($variables['element']['#attributes']['class']) &&
      in_array('visually-hidden', $variables['element']['#attributes']['class'], TRUE)
    ) {
      $type = 'radio_composite';
    }

    if ($type === 'checkbox' &&
      isset($variables['element']['#attributes']) &&
      isset($variables['element']['#attributes']['class'])
    ) {
      if (in_array('tableselect', $variables['element']['#attributes']['class'], TRUE)) {
        $type = 'checkbox_tableselect';
      }
      if (in_array('webform-tableselect-sort', $variables['element']['#attributes']['class'], TRUE)) {
        $type = 'checkbox_tableselect_sort';
      }
    }

    if ($type === 'entity_autocomplete' &&
      isset($variables['element']['#title_display']) &&
      $variables['element']['#title_display'] == 'invisible' &&
      isset($variables['label_display']) &&
      $variables['label_display'] == 'invisible'
    ) {
      $type = 'entity_autocomplete_composite';
    }

    return $type;
  }

  /**
   * Number element settings.
   *
   * @param array<string, mixed> $variables
   *   Variables array.
   */
  private static function setNumber(array &$variables): void {
    $variables['label']['#attributes']['class'][] = 'input-number-label';
    $variables['label']['#attributes']['class'][] = 'active';
    $variables['attributes']['class'][] = 'form-group';
  }

  /**
   * Number composite element settings.
   *
   * @param array<string, mixed> $variables
   *   Variables array.
   */
  private static function setNumberComposite(array &$variables): void {
    $variables['label']['#attributes']['class'][] = 'input-number-label';
    $variables['label']['#attributes']['class'][] = 'active';
  }

  /**
   * Telephone element settings.
   *
   * @param array<string, mixed> $variables
   *   Variables array.
   */
  private static function setTel(array &$variables): void {
    if (isset($variables['element']['#international']) &&
      $variables['element']['#international']
    ) {
      $variables['label']['#attributes']['class'][] = 'active';
    }
    $variables['attributes']['class'][] = 'form-group';
  }

  /**
   * Textarea element settings.
   *
   * @param array<string, mixed> $variables
   *   Variables array.
   */
  private static function setTextarea(array &$variables): void {
    $variables['label']['#attributes']['class'][] = 'active';
    $variables['attributes']['class'][] = 'form-group';
  }

  /**
   * Date time element settings.
   *
   * @param array<string, mixed> $variables
   *   Variables array.
   */
  private static function setDateTime(array &$variables): void {
    $variables['label']['#attributes']['class'][] = 'active';
    $variables['attributes']['class'][] = 'form-group';
  }

  /**
   * Text element settings.
   *
   * @param array<string, mixed> $variables
   *   Variables array.
   */
  private static function setText(array &$variables): void {
    $variables['attributes']['class'][] = 'form-group';
  }

  /**
   * Boolean element settings.
   *
   * @param array<string, mixed> $variables
   *   Variables array.
   */
  private static function setBoolean(array &$variables): void {
    $variables['attributes']['class'][] = 'form-check';
  }

  /**
   * Select element settings.
   *
   * @param array<string, mixed> $variables
   *   Variables array.
   */
  private static function setSelect(array &$variables): void {
    $variables['attributes']['class'][] = 'select-wrapper';
  }

  /**
   * Select composite element settings.
   *
   * @param array<string, mixed> $variables
   *   Variables array.
   */
  private static function setSelectComposite(array &$variables): void {
    $variables['attributes']['class'][] = 'select-wrapper';
  }

}
