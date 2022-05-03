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
        '' => t('Extra small (auto, nessuno o <576px)'),
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

  /**
   * Returns available themes variants.
   *
   * @return array
   *   Array with theme variants options.
   */
  public static function getThemeVariants(): array {
    $theme = \Drupal::service('theme.manager')->getActiveTheme();
    $assets_css_path = $theme->getPath() . '/assets/css';
    $assets_js_path = $theme->getPath() . '/assets/js';

    $default_option = [
      '' => t('Use @theme.libraries.yml (recommended)', ['@theme' => $theme->getName()]),
    ];

    // Check if directories css and js exists.
    if (!is_dir($assets_css_path) || !is_dir($assets_js_path)) {
      return $default_option;
    }

    // Config extensions parameters.
    $extensions = ['css', 'js'];
    $extensions = array_map('preg_quote', $extensions);
    $extensions = implode('|', $extensions);

    // Search css e js file in theme/assets.
    $css = \Drupal::service('file_system')->scanDirectory($assets_css_path, "/{$extensions}$/");
    $js = \Drupal::service('file_system')->scanDirectory($assets_js_path, "/{$extensions}$/");

    // Make a variants return array.
    $variants = [];
    $variants += $default_option;

    // Loop for css file.
    foreach ($css as $fileC) {
      foreach ($js as $fileJ) {
        // If name css and js match.
        if ($fileC->name == $fileJ->name) {
          // Add variant.
          $variants[$fileC->name] = $fileC->name . '.[css/js]';
        }
      }
    }
    return $variants;
  }

  /**
   * Set themes variants.
   *
   * @return array
   *   Libraries array.
   */
  public static function setThemeVariants(): array {
    // Get default theme.
    $theme = \Drupal::service('theme.manager')->getActiveTheme()->getName();
    // Get config default theme.
    $config = \Drupal::config($theme . '.settings');
    // Get theme_variant default theme.
    $theme_variant = $config->getOriginal('theme_variant');

    $libraries = [];
    if (!empty($theme_variant) && $theme_variant != '') {
      $libraries['global'] = [
        'css' => [
          'theme' => [
            'assets/css/' . $theme_variant . '.css' => [],
          ],
        ],
        'js' => [
          'assets/js/' . $theme_variant . '.js' => [],
        ],
        'dependencies' => [
          'core/drupal',
        ],
      ];
    }
    return $libraries;
  }

}
