<?php

use Drupal\bootstrap_italia\Helper;

/**
 * Implements hook_preprocess_pager()
 */
function bootstrap_italia_preprocess_pager(&$variables)
{
  if (isset($variables['items']['last']['href'])) {
    $pieces = explode('=', $variables['items']['last']['href']);
    $variables['total_pages'] = $pieces[1] + 1;
  }
}
