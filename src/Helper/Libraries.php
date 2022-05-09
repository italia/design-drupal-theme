<?php

namespace Drupal\bootstrap_italia\Helper;

/**
 * Libraries class for bootstrap_italia theme.
 * Why isn't it a service? https://www.drupal.org/project/drupal/issues/2002606
 */
class Libraries {

  /**
   * Returns available theme libraries.
   *
   * @return array
   *   Array with theme libraries options.
   */
  public static function getLibraries(): array {
    $theme = Helper::getTheme();
    $assets_css_path = $theme->getPath() . '/assets/css';
    $assets_js_path = $theme->getPath() . '/assets/js';

    $static_option = [
      '' => t('Use @theme.libraries.yml', ['@theme' => $theme->getName()]),
      'vanilla' => t('Vanilla libraries'),
      'cdn' => t('CDN libraries'),
    ];

    // Check if directories css and js exists.
    if (!is_dir($assets_css_path) || !is_dir($assets_js_path)) {
      return $static_option;
    }

    // Config extensions parameters.
    $extensions = ['css', 'js'];
    $extensions = array_map('preg_quote', $extensions);
    $extensions = implode('|', $extensions);

    // Search css e js file in theme/assets.
    $css = \Drupal::service('file_system')->scanDirectory($assets_css_path, "/{$extensions}$/");
    $js = \Drupal::service('file_system')->scanDirectory($assets_js_path, "/{$extensions}$/");

    // Make a libraries return array.
    $libraries = [];
    $libraries += $static_option;

    // Loop for css files.
    foreach ($css as $fileC) {
      // Loop for js files.
      foreach ($js as $fileJ) {
        // If name css and js match.
        if ($fileC->name == $fileJ->name) {
          // Add variant.
          $libraries[$fileC->name] = 'Webpack: ' . $fileC->name . '.[css/js]';
        }
      }
    }
    return $libraries;
  }

  /**
   * Set themes libraries.
   *
   * @return array
   *   Libraries array.
   */
  public static function setLibraries(): array {
    // Get libraries_type from Drupal config.
    $libraries_type = Helper::getSettings()->get('libraries_type');

    if (!empty($libraries_type) && $libraries_type == 'vanilla') {
      $libraries['libraries-ui'] = self::getLibrariesVanilla();
    }
    elseif (!empty($libraries_type) && $libraries_type == 'cdn') {
      $libraries['libraries-ui'] = self::getLibrariesCDN();
    }
    elseif (!empty($libraries_type) && $libraries_type != '') {
      $libraries['libraries-ui'] = [
        'css' => [
          'theme' => [
            'assets/css/' . $libraries_type . '.css' => [],
          ],
        ],
        'js' => [
          'assets/js/' . $libraries_type . '.js' => [],
        ],
        'dependencies' => [
          'core/drupal',
        ],
      ];
    }
    else {
      $libraries = [];
    }
    return $libraries;
  }

  /**
   * Returns vanilla libraries.
   *
   * @return array
   *   Array with vanilla libraries
   */
  public static function getLibrariesVanilla(): array {
    $js = Helper::getSettings()->get('libraries_bundle')
      ? 'assets/js/bootstrap-italia.bundle.min.js'
      : 'assets/js/bootstrap-italia.min.js';

    return [
      'css' => [
        'theme' => [
          'assets/css/bootstrap-italia.min.css' => ['minified' => TRUE]
        ],
      ],
      'js' => [
        $js => ['minified' => TRUE]
      ],
      'dependencies' => [
        'core/drupal',
      ],
    ];
  }

  /**
   * Returns CDN libraries.
   *
   * @return array
   *   Array with CDN libraries
   */
  public static function getLibrariesCDN(): array {
    $css = Helper::getSettings()->get('libraries_cdn_css');
    $js = Helper::getSettings()->get('libraries_cdn_js');
    $min = Helper::getSettings()->get('libraries_cdn_minified');
    return [
      'css' => [
        'theme' => [
          $css => [
            'type' => 'external',
            'minified' => $min
          ]
        ],
      ],
      'js' => [
        $js => [
          'type' => 'external',
          'minified' => $min
        ]
      ],
      'dependencies' => [
        'core/drupal',
      ],
    ];
  }

}