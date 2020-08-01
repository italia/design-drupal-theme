<?php

use Drupal\bootstrap_italia\Helper;

/**
 * Implements hook_preprocess_page()
 */
function bootstrap_italia_preprocess_page(&$variables)
{
  $variables['ente_appartenenza_nome'] = theme_get_setting('ente_appartenenza_nome');
  $variables['ente_appartenenza_url'] = theme_get_setting('ente_appartenenza_url');
  $variables['avatar_size'] = theme_get_setting('avatar_size');
  // social
  foreach (Helper::getSocialItems() as $social) {
    $low_social = strtolower($social);
    if (theme_get_setting($low_social)){
      $variables['socials'][$low_social]['label'] = $social;
      $variables['socials'][$low_social]['url'] = theme_get_setting($low_social);
    }
  }
  // end social
  $variables['right_action_size'] = theme_get_setting('right_action_size');
  $variables['back_to_top_enable'] = (bool) theme_get_setting('back_to_top_enable');
  $variables['back_to_top_small'] = (bool) theme_get_setting('back_to_top_small');
  $variables['back_to_top_dark'] = (bool) theme_get_setting('back_to_top_dark');
  $variables['back_to_top_shadow'] = (bool) theme_get_setting('back_to_top_shadow');
}
