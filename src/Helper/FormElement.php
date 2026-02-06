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
    $element = $variables['element'] ?? NULL;
    if (!is_array($element)) {
      $element = [];
    }

    $attributes = $element['#attributes'] ?? NULL;
    if (!is_array($attributes)) {
      $attributes = [];
    }

    if (
      isset($attributes['value']) &&
      (
        !empty($attributes['value']) ||
        !empty($attributes['placeholder'])
      ) &&
      !isset($attributes['class']['active'])
    ) {
      Helper::addLabelClass($variables, 'active');
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
    $type = $variables['type'] ?? '';
    if (!is_string($type)) {
      $type = '';
    }

    $element = $variables['element'] ?? [];
    if (!is_array($element)) {
      $element = [];
    }

    $titleDisplay = $element['#title_display'] ?? null;
    if (!is_string($titleDisplay)) {
      $titleDisplay = null;
    }

    $labelDisplay = $variables['label_display'] ?? null;
    if (!is_string($labelDisplay)) {
      $labelDisplay = null;
    }

    $isComposite = ($titleDisplay === 'invisible' && $labelDisplay === 'invisible');

    $attributes = $element['#attributes'] ?? [];
    if (!is_array($attributes)) {
      $attributes = [];
    }

    $attrClass = $attributes['class'] ?? [];
    if (!is_array($attrClass)) {
      $attrClass = [];
    }
    /** @var list<string> $attrClass */
    $attrClass = array_values(array_filter($attrClass, 'is_string'));

    $multiple = $attributes['multiple'] ?? null;
    if (!is_string($multiple)) {
      $multiple = null;
    }

    return match (true) {
      $type === 'select' && $multiple === 'multiple' => 'select_multiple',
      $type === 'select' && in_array('webform-select2', $attrClass, true) => 'select2',

      $type === 'radio' && in_array('visually-hidden', $attrClass, true) => 'radio_composite',

      $type === 'checkbox' && in_array('tableselect', $attrClass, true) => 'checkbox_tableselect',
      $type === 'checkbox' && in_array('webform-tableselect-sort', $attrClass, true) => 'checkbox_tableselect_sort',

      $type === 'textfield' && $isComposite => 'textfield_composite',
      $type === 'number' && $isComposite => 'number_composite',
      $type === 'url' && $isComposite => 'url_composite',
      $type === 'select' && $isComposite => 'select_composite',
      $type === 'entity_autocomplete' && $isComposite => 'entity_autocomplete_composite',

      default => $type,
    };
  }


  /**
   * Number element settings.
   *
   * @param array<string, mixed> $variables
   *   Variables array.
   */
  private static function setNumber(array &$variables): void {
    Helper::addLabelClass($variables, 'input-number-label');
    Helper::addLabelClass($variables, 'active');

    $attributes = &Helper::attributes($variables);

    /** @var list<string> $attributesClasses */
    $attributesClasses = $attributes['class'];

    $attributesClasses[] = 'form-group';

    $attributes['class'] = $attributesClasses;
  }

  /**
   * Number composite element settings.
   *
   * @param array<string, mixed> $variables
   *   Variables array.
   */
  private static function setNumberComposite(array &$variables): void {
    Helper::addLabelClass($variables, 'input-number-label');
    Helper::addLabelClass($variables, 'active');
  }

  /**
   * Telephone element settings.
   *
   * @param array<string, mixed> $variables
   *   Variables array.
   */
  private static function setTel(array &$variables): void {
    $element = $variables['element'] ?? null;
    if (!is_array($element)) {
      $element = [];
    }
    $international = $element['#international'] ?? FALSE;
    if ($international) {
      Helper::addLabelClass($variables, 'active');
    }

    $attributes = &Helper::attributes($variables);

    /** @var list<string> $attributesClasses */
    $attributesClasses = $attributes['class'];

    $attributesClasses[] = 'form-group';

    $attributes['class'] = $attributesClasses;
  }

  /**
   * Textarea element settings.
   *
   * @param array<string, mixed> $variables
   *   Variables array.
   */
  private static function setTextarea(array &$variables): void {
    Helper::addLabelClass($variables, 'active');

    $attributes = &Helper::attributes($variables);

    /** @var list<string> $attributesClasses */
    $attributesClasses = $attributes['class'];

    $attributesClasses[] = 'form-group';

    $attributes['class'] = $attributesClasses;
  }

  /**
   * Date time element settings.
   *
   * @param array<string, mixed> $variables
   *   Variables array.
   */
  private static function setDateTime(array &$variables): void {
    Helper::addLabelClass($variables, 'active');

    $attributes = &Helper::attributes($variables);

    /** @var list<string> $attributesClasses */
    $attributesClasses = $attributes['class'];

    $attributesClasses[] = 'form-group';

    $attributes['class'] = $attributesClasses;
  }

  /**
   * Text element settings.
   *
   * @param array<string, mixed> $variables
   *   Variables array.
   */
  private static function setText(array &$variables): void {
    $attributes = &Helper::attributes($variables);

    /** @var list<string> $classes */
    $classes = $attributes['class'];

    $classes[] = 'form-group';

    $attributes['class'] = $classes;
  }

  /**
   * Boolean element settings.
   *
   * @param array<string, mixed> $variables
   *   Variables array.
   */
  private static function setBoolean(array &$variables): void {
    $attributes = &Helper::attributes($variables);

    /** @var list<string> $classes */
    $classes = $attributes['class'];

    $classes[] = 'form-check';

    $attributes['class'] = $classes;
  }

  /**
   * Select element settings.
   *
   * @param array<string, mixed> $variables
   *   Variables array.
   */
  private static function setSelect(array &$variables): void {
    $attributes = &Helper::attributes($variables);

    /** @var list<string> $classes */
    $classes = $attributes['class'];

    $classes[] = 'select-wrapper';

    $attributes['class'] = $classes;
  }

  /**
   * Select composite element settings.
   *
   * @param array<string, mixed> $variables
   *   Variables array.
   */
  private static function setSelectComposite(array &$variables): void {
    $attributes = &Helper::attributes($variables);

    /** @var list<string> $classes */
    $classes = $attributes['class'];

    $classes[] = 'select-wrapper';

    $attributes['class'] = $classes;
  }

}
