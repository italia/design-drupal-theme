<?php

use Drupal\bootstrap_italia\Helper;

/**
 * Implements hook_preprocess_page()
 */
function bootstrap_italia_preprocess_views_view_table(&$variables) {
  $variables['table_bg'] = theme_get_setting('table_bg');
  $variables['table_thead'] = theme_get_setting('table_thead');
  $variables['table_striped'] = theme_get_setting('table_striped');
  $variables['table_bordered'] = theme_get_setting('table_bordered');
  $variables['table_hover'] = theme_get_setting('table_hover');
  $variables['table_sm'] = theme_get_setting('table_sm');

}
