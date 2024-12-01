<?php

namespace Drupal\bootstrap_italia\Helper;

use Drupal\Core\Config\Config;
use Drupal\Core\Theme\ActiveTheme;

/**
 * Helper class for bootstrap_italia theme.
 *
 * Why isn't it a service? https://www.drupal.org/project/drupal/issues/2002606.
 */
class Helper {

  /**
   * Get active theme.
   *
   * @return \Drupal\Core\Theme\ActiveTheme
   *   Object ActiveTheme.
   */
  public static function getTheme(): ActiveTheme {
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
   *
   * @return array<string>
   *   All social.
   */
  public static function getSocialItems(): array {
    return [
      'Android',
      'Apple',
      'Behance',
      'Facebook',
      'Figma',
      'Flickr',
      'Github',
      'Instagram',
      'Linkedin',
      'Medium',
      'Mastodon',
      'Moodle',
      'Pinterest',
      'Quora',
      'Reddit',
      'RSS',
      'Slack',
      'Snapchat',
      'Stackexchange',
      'Stackoverflow',
      'Telegram',
      'Threads',
      'Tiktok',
      'Twitter',
      'Vimeo',
      'WhatsApp',
      'YouTube',
    ];
  }

  /**
   * Return active social.
   *
   * @return array<string, mixed>
   *   Active social with url.
   */
  public static function getActiveSocials(): array {
    $active_socials = [];
    foreach (self::getSocialItems() as $social) {
      $low_social = strtolower($social);
      $social_url = theme_get_setting($low_social);
      if ($social_url) {
        $active_socials[$low_social]['label'] = $social;
        $active_socials[$low_social]['url'] = $social_url;
      }
    }
    return $active_socials;
  }

  /**
   * Https://italia.github.io/bootstrap-italia/docs/organizzare-gli-spazi/griglie/#le-opzioni.
   *
   * @param bool $withLabel
   *   Choose from array with label or not.
   *
   * @return array<int|string>
   *   Returns breakpoints.
   */
  public static function getBreakpoints(bool $withLabel = FALSE): array {
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

    return ['', 'sm', 'md', 'lg', 'xl', 'xxl'];
  }

  /**
   * Return bootstrap container type.
   *
   * @param bool $withLabel
   *   Choose from array with label or not.
   *
   * @return array<int|string>
   *   Returns container type.
   */
  public static function getBootstrapContainerType(bool $withLabel = FALSE): array {
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
