<?php

/**
 * Implements hook_preprocess_HOOK() for breadcrumb.html.twig.
 */
function bootstrap_italia_preprocess_breadcrumb(&$variables)
{
  $variables['darkbkg'] = (bool) theme_get_setting('darkbkg');
  $variables['image'] = (bool) theme_get_setting('image');
  $variables['separator'] = theme_get_setting('separator');
}
