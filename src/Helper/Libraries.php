<?php

namespace Drupal\bootstrap_italia\Helper;

/**
 * Libraries class for bootstrap_italia theme.
 *
 * Why isn't it a service? https://www.drupal.org/project/drupal/issues/2002606.
 */
class Libraries {

  /**
   * Distribution folder name.
   *
   * @var string
   */
  private static string $distributionFolder = 'dist';

  /**
   * Returns available theme libraries.
   *
   * @return array<int|string, mixed>
   *   Array with theme libraries options.
   */
  public static function getLibraries(): array {
    $theme = Helper::getTheme();
    $assets_css_path = $theme->getPath() . '/' . self::$distributionFolder . '/css';
    $assets_js_path = $theme->getPath() . '/' . self::$distributionFolder . '/js';

    $static_option = [
      'vanilla' => t('Vanilla libraries'),
      'cdn' => t('CDN libraries'),
      '' => t('Use @theme.libraries.yml', ['@theme' => $theme->getName()]),
    ];

    // Check if directories css and js exists.
    if (!is_dir($assets_css_path) || !is_dir($assets_js_path)) {
      return $static_option;
    }

    // Config extensions parameters.
    $extensions = ['css', 'js'];
    $extensions = array_map('preg_quote', $extensions);
    $extensions = implode('|', $extensions);

    // Search css e js file in theme/dist.
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
   * @return array<int|string|empty>
   *   Libraries array.
   */
  public static function setLibraries(): array {
    // Get libraries_type from Drupal config.
    /** @var string $libraries_type */
    $libraries_type = Helper::getSettings()->get('libraries_type');

    if (!empty($libraries_type) && $libraries_type == 'vanilla') {
      $libraries['libraries-ui'] = self::getLibrariesVanilla();
    }
    elseif (!empty($libraries_type) && $libraries_type == 'cdn') {
      $libraries['libraries-ui'] = self::getLibrariesCdn();
    }
    elseif (!empty($libraries_type) && $libraries_type != '') {
      $libraries['libraries-ui'] = [
        'css' => [
          'theme' => [
            self::$distributionFolder . '/css/' . $libraries_type . '.css' => ['minified' => TRUE],
          ],
        ],
        'js' => [
          self::$distributionFolder . '/js/' . $libraries_type . '.js' => ['minified' => TRUE],
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
   * @return array<string, mixed>
   *   Array with vanilla libraries
   */
  public static function getLibrariesVanilla(): array {
    $js = Helper::getSettings()->get('libraries_vanilla_bundle')
      ? self::$distributionFolder . '/js/bootstrap-italia.bundle.min.js'
      : self::$distributionFolder . '/js/bootstrap-italia.min.js';

    $css = self::$distributionFolder . '/css/bootstrap-italia.min.css';

    return [
      'css' => [
        'theme' => [
          $css => ['minified' => TRUE],
        ],
      ],
      'js' => [
        $js => ['minified' => TRUE],
      ],
      'dependencies' => [
        'core/drupal',
      ],
    ];
  }

  /**
   * Returns CDN libraries.
   *
   * @return array<string, mixed>
   *   Array with CDN libraries
   */
  public static function getLibrariesCdn(): array {
    $css = Helper::getSettings()->get('libraries_cdn_css');
    $js = Helper::getSettings()->get('libraries_cdn_js');
    $min = Helper::getSettings()->get('libraries_cdn_minified');
    return [
      'css' => [
        'theme' => [
          $css => [
            'type' => 'external',
            'minified' => $min,
          ],
        ],
      ],
      'js' => [
        $js => [
          'type' => 'external',
          'minified' => $min,
        ],
      ],
      'dependencies' => [
        'core/drupal',
      ],
    ];
  }

}
