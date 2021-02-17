<?php

namespace Drupal\bootstrap_italia;

/**
 * Helper class for bootstrap_italia theme.
 */
class Helper {

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
   */
  public static function getColorsName($withLabel = FALSE): array {
    if ($withLabel) {
      return [
        'primary' => 'Primary ',
        'secondary' => 'Secondary',
        'success' => 'Success',
        'info' => 'Info',
        'warning' => 'Warning',
        'danger' => 'Danger',
        'light' => 'Light',
        'white' => 'White',
        'dark' => 'Dark',
      ];
    }

    return [
      'primary ',
      'secondary',
      'success',
      'info',
      'warning',
      'danger',
      'light',
      'white',
      'dark',
    ];
  }

  /**
   * Https://italia.github.io/bootstrap-italia/docs/organizzare-gli-spazi/griglie/#le-opzioni.
   */
  public static function getBreakpoints($withLabel = FALSE): array {
    if ($withLabel) {
      return [
        '' => t('Extra small (auto, nessuno o <576px)'),
        'sm' => t('Small (>= 576px)'),
        'md' => t('Medium (>= 768px)'),
        'lg' => t('Large (>= 992px)'),
        'xl' => t('Extra Large (>= 1200px)'),
      ];
    }

    return ['', 'sm', 'md', 'lg', 'xl'];
  }

}
