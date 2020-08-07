<?php

/**
 * Implements hook_preprocess_pager()
 */
function bootstrap_italia_preprocess_pager(&$variables)
{
  // @see globals.api.php
  global $pager_total;
  $element = $variables['pager']['#element'];
  // Get the max page number for the current pager.
  $variables['total_pages'] = $pager_total[$element];
}
