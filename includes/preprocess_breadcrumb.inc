<?php

/**
 * Implements hook_preprocess_HOOK() for breadcrumb.html.twig.
 */
function bootstrap_italia_preprocess_breadcrumb(&$variables)
{
  $variables['breadcrumb_dark_background'] = (bool) theme_get_setting('breadcrumb_dark_background');
  $variables['breadcrumb_image'] = (bool) theme_get_setting('breadcrumb_image');
  $variables['breadcrumb_separator'] = theme_get_setting('breadcrumb_separator');
}
