<?php

namespace Drupal\bootstrap_italia\Helper;

/**
 * Helper Form class for bootstrap_italia theme.
 * Why isn't it a service? https://www.drupal.org/project/drupal/issues/2002606
 */
class FormElement {

  /**
   * Set form element.
   *
   * @param $variables
   *   Referenced $variables.
   *
   * @return void
   */
  public static function set(&$variables) {
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
      }
    }
  }

  /**
   * Return variables type.
   *
   * @param $variables
   *   Variables array.
   *
   * @return string
   *   Element type.
   */
  private static function getType($variables): string {
    $type = $variables['type'];

    if ($type == 'textfield' &&
      isset($variables['element']['#title_display']) &&
      $variables['element']['#title_display'] == 'invisible' &&
      isset($variables['label_display']) &&
      $variables['label_display'] == 'invisible'
    ) {
      $type = 'textfield_composite';
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

  private static function setNumber(&$variables) {
    $variables['label']['#attributes']['class'][] = 'input-number-label';
    $variables['label']['#attributes']['class'][] = 'active';
    $variables['attributes']['class'][] = 'form-group';
  }

  private static function setTel(&$variables) {
    if (isset($variables['element']['#international']) &&
      $variables['element']['#international']
    ) {
      $variables['label']['#attributes']['class'][] = 'active';
    }
    $variables['attributes']['class'][] = 'form-group';
  }

  private static function setTextarea(&$variables) {
    $variables['label']['#attributes']['class'][] = 'active';
    $variables['attributes']['class'][] = 'form-group';
  }

  private static function setDateTime(&$variables) {
    $variables['label']['#attributes']['class'][] = 'active';
    $variables['attributes']['class'][] = 'form-group';
  }

  private static function setText(&$variables) {
    $variables['attributes']['class'][] = 'form-group';
  }

  private static function setBoolean(&$variables) {
    $variables['attributes']['class'][] = 'form-check';
  }

  private static function setSelect(&$variables) {
    $variables['attributes']['class'][] = 'select-wrapper';
  }

}
