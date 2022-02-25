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

  /**
   * Return bootstrap container type
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
      ];
    }
    return ['container', 'container-fluid'];
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
      '' => t('Usa @theme.libraries.yml (raccomandato)', ['@theme' => $theme->getName()])
    ];

    // Check if directories css and js exists.
    if (!is_dir($assets_css_path) || !is_dir($assets_js_path) ) {
      return $default_option;
    }

    // Config extensions parameters
    $extensions = ['css', 'js'];
    $extensions = array_map('preg_quote', $extensions);
    $extensions = implode('|', $extensions);

    // Search css e js file in theme/assets
    $css = \Drupal::service('file_system')->scanDirectory($assets_css_path, "/{$extensions}$/");
    $js = \Drupal::service('file_system')->scanDirectory($assets_js_path, "/{$extensions}$/");

    // Make a variants return array
    $variants = [];
    $variants += $default_option;

    // Loop for css file
    foreach ($css as $fileC) {
      foreach ($js as $fileJ) {
        // If name css and js match
        if ($fileC->name == $fileJ->name) {
          // Add variant
          $variants[$fileC->name] = $fileC->name . '.[css/js]';
        }
      }
    }
    return $variants;
  }

}
