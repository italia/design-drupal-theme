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
   *
   * @param bool $withLabel
   *   Choose from array with label or not.
   *
   * @return array<int|string>
   *   All colors.
   */
  public static function getAll(bool $withLabel = FALSE): array {
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
   *
   * @param bool $withLabel
   *   Choose from array with label or not.
   *
   * @return array<int|string>
   *   Theme colors.
   */
  public static function getTheme(bool $withLabel = FALSE): array {
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
   *
   * @param bool $withLabel
   *   Choose from array with label or not.
   *
   * @return array<int|string>
   *   Pantone colors.
   */
  public static function getPantone(bool $withLabel = FALSE): array {
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
   *
   * @param bool $withLabel
   *   Choose from array with label or not.
   *
   * @return array<int|string>
   *   Gray colors.
   */
  public static function getGrays(bool $withLabel = FALSE): array {
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
   *
   * @param bool $withLabel
   *   Choose from array with label or not.
   *
   * @return array<int|string>
   *   Utilities colors.
   */
  public static function getUtilities(bool $withLabel = FALSE): array {
    if ($withLabel) {
      return ['body' => 'Body', 'muted' => 'Muted'];
    }

    return ['body', 'muted'];
  }

  /**
   * Return Mode colors name.
   *
   * Https://getbootstrap.com/docs/5.1/utilities/colors/#variables.
   *
   * @param bool $withLabel
   *   Choose from array with label or not.
   *
   * @return array<int|string>
   *   Color mode.
   */
  public static function getMode(bool $withLabel = FALSE): array {
    if ($withLabel) {
      return ['light' => 'Light', 'dark' => 'Dark'];
    }

    return ['light', 'dark'];
  }

  /**
   * Return Utilities colors name.
   *
   * Https://getbootstrap.com/docs/5.1/utilities/colors/#variables.
   *
   * @param bool $withLabel
   *   Choose from array with label or not.
   *
   * @return array<int|string>
   *   Monochromatic colors.
   */
  public static function getMonochromatic(bool $withLabel = FALSE): array {
    if ($withLabel) {
      return ['black' => 'Black', 'white' => 'White'];
    }

    return ['black', 'white'];
  }

}
