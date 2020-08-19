<?php

namespace Drupal\bootstrap_italia;

class Helper {

  public static function getSocialItems(): array
  {
    return [
      'Behance',
      'Facebook',
      'Flickr',
      'Github',
      'Instagram',
      'Linkedin',
      'Medium',
      'Twitter',
      // 'Telegram', //manca icona
      'WhatsApp',
      'YouTube',
      // 'RSS', //manca icona
    ];
  }

  public static function getColorsName($withKeys=false): array
  {
    if ($withKeys) {
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

    return  [ 'primary ', 'secondary', 'success', 'info', 'warning', 'danger', 'light', 'white', 'dark' ];
  }
}
