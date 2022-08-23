<?php

namespace Drupal\bootstrap_italia\Helper;

/**
 * Helper class for colors.
 *
 * Docs: https://italia.github.io/bootstrap-italia/docs/utilities/colori/
 *
 * Why isn't it a service? https://www.drupal.org/project/drupal/issues/2002606.
 */
class Color {

  /**
   * Return all colors name.
   *
   * Https://getbootstrap.com/docs/5.1/utilities/colors/#variables.
   */
  public static function getAll($withLabel = FALSE): array {
    return self::getTheme($withLabel) +
      self::getPantone($withLabel) +
      self::getGrays($withLabel) +
      self::getUtilities($withLabel) +
      self::getMode($withLabel) +
      self::getMonochromatic($withLabel);
  }

  /**
   * Return Theme colors name.
   *
   * Https://getbootstrap.com/docs/5.1/utilities/colors/#variables.
   */
  public static function getTheme($withLabel = FALSE): array {
    if ($withLabel) {
      return [
        'primary' => 'Primary',
        'secondary' => 'Secondary',
        'success' => 'Success',
        'info' => 'Info',
        'warning' => 'Warning',
        'danger' => 'Danger',
      ];
    }

    return [
      'primary', 'secondary', 'success',
      'info', 'warning', 'danger',
    ];
  }

  /**
   * Return extra colors name.
   *
   * Https://getbootstrap.com/docs/5.1/utilities/colors/#variables.
   */
  public static function getPantone($withLabel = FALSE): array {
    if ($withLabel) {
      return [
        'blue' => 'Blue',
        'indigo' => 'Indigo',
        'purple' => 'Purple',
        'pink' => 'Pink',
        'red' => 'Red',
        'orange' => 'Orange',
        'yellow' => 'Yellow',
        'green' => 'Green',
        'teal' => 'Teal',
        'cyan' => 'Cyan',
      ];
    }

    return [
      'blue', 'indigo', 'purple', 'pink', 'red',
      'orange', 'yellow', 'green', 'teal', 'cyan',
    ];
  }

  /**
   * Return gray colors name.
   *
   * Https://getbootstrap.com/docs/5.1/utilities/colors/#variables.
   */
  public static function getGrays($withLabel = FALSE): array {
    if ($withLabel) {
      return [
        'gray-100' => 'Gray 100',
        'gray-200' => 'Gray 200',
        'gray-300' => 'Gray 300',
        'gray-400' => 'Gray 400',
        'gray-500' => 'Gray 500',
        'gray-600' => 'Gray 600',
        'gray-700' => 'Gray 700',
        'gray-800' => 'Gray 800',
        'gray-900' => 'Gray 900',
      ];
    }

    return [
      'gray-100', 'gray-200', 'gray-300', 'gray-400', 'gray-500',
      'gray-600', 'gray-700', 'gray-800', 'gray-900',
    ];
  }

  /**
   * Return Utilities colors name.
   *
   * Https://getbootstrap.com/docs/5.1/utilities/colors/#variables.
   */
  public static function getUtilities($withLabel = FALSE): array {
    if ($withLabel) {
      return ['body' => 'Body', 'muted' => 'Muted'];
    }

    return ['body', 'muted'];
  }

  /**
   * Return Mode colors name.
   *
   * Https://getbootstrap.com/docs/5.1/utilities/colors/#variables.
   */
  public static function getMode($withLabel = FALSE): array {
    if ($withLabel) {
      return ['light' => 'Light', 'dark' => 'Dark'];
    }

    return ['light', 'dark'];
  }

  /**
   * Return Utilities colors name.
   *
   * Https://getbootstrap.com/docs/5.1/utilities/colors/#variables.
   */
  public static function getMonochromatic($withLabel = FALSE): array {
    if ($withLabel) {
      return ['black' => 'Black', 'white' => 'White'];
    }

    return ['black', 'white'];
  }

}
