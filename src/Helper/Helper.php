<?php

namespace Drupal\bootstrap_italia\Helper;

use Drupal\Core\Config\Config;

/**
 * Helper class for bootstrap_italia theme.
 * Why isn't it a service? https://www.drupal.org/project/drupal/issues/2002606
 */
class Helper {

  /**
   * Get active theme.
   *
   * @return mixed
   */
  public static function getTheme() {
    return \Drupal::service('theme.manager')->getActiveTheme();
  }

  /**
   * Get config from Drupal Service.
   *
   * @return \Drupal\Core\Config\Config
   *   Current default theme config.
   */
  public static function getSettings(): Config {
    // Get default theme.
    $themeName = self::getTheme()->getName();
    // Get config default theme.
    return \Drupal::service('config.factory')->getEditable($themeName . '.settings');
  }

  /**
   * Return social name.
   */
  public static function getSocialItems(): array {
    return [
      'Behance',
      'Facebook',
      'Flickr',
      'Github',
      'Instagram',
      'Linkedin',
      'Medium',
      'RSS',
      'Twitter',
      'Telegram',
      'WhatsApp',
      'YouTube',
    ];
  }

  /**
   * Return colors name.
   * https://getbootstrap.com/docs/5.1/utilities/colors/#variables
   */
  public static function getColorsName($withLabel = FALSE): array {
    if ($withLabel) {
      return [
        'primary' => 'Primary ',
        'secondary' => 'Secondary',
        'success' => 'Success',
        'danger' => 'Danger',
        'warning' => 'Warning',
        'info' => 'Info',
        'light' => 'Light',
        'dark' => 'Dark',
        'body' => 'Body',
        'muted' => 'Muted',
        'black' => 'Black',
        'white' => 'White',
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
      'primary ',
      'secondary',
      'success',
      'danger',
      'warning',
      'info',
      'light',
      'dark',
      'body',
      'muted',
      'black',
      'white',
      'blue',
      'indigo',
      'purple',
      'pink',
      'red',
      'orange',
      'yellow',
      'green',
      'teal',
      'cyan',
      'gray-100',
      'gray-200',
      'gray-300',
      'gray-400',
      'gray-500',
      'gray-600',
      'gray-700',
      'gray-800',
      'gray-900',
    ];
  }

  /**
   * Https://italia.github.io/bootstrap-italia/docs/organizzare-gli-spazi/griglie/#le-opzioni.
   */
  public static function getBreakpoints($withLabel = FALSE): array {
    if ($withLabel) {
      return [
        '' => t('Extra small (<576px)'),
        'sm' => t('Small (>= 576px)'),
        'md' => t('Medium (>= 768px)'),
        'lg' => t('Large (>= 992px)'),
        'xl' => t('Extra Large (>= 1200px)'),
        'xxl' => t('Extra Large (>= 1400px)'),
      ];
    }

    return ['', 'sm', 'md', 'lg', 'xl','xxl'];
  }

  /**
   * Return bootstrap container type.
   */
  public static function getBootstrapContainerType($withLabel = FALSE): array {
    if ($withLabel) {
      return [
        'container' => t('Container fixed'),
        'container-fluid' => t('Container fluid'),
        'container-sm' => t('Container sm'),
        'container-md' => t('Container md'),
        'container-lg' => t('Container lg'),
        'container-xl' => t('Container xl'),
        'container-xxl' => t('Container xxl'),
      ];
    }
    return [
      'container',
      'container-fluid',
      'container-sm',
      'container-md',
      'container-lg',
      'container-xl',
      'container-xxl',
    ];
  }
}
