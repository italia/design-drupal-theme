<?php

/**
 * Implements hook_preprocess_pager()
 * @param $variables
 */
function bootstrap_italia_preprocess_pager(&$variables)
{
  $pager = \Drupal::service('pager.manager')->getPager();
  $variables['total_pages'] = $pager ? $pager->getTotalPages() : NULL;
}
