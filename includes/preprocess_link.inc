<?php

/**
 * Implements hook_preprocess_links().
 */
function bootstrap_italia_preprocess_links(&$variables)
{
  // Add current language to block
  $variables['current_language'] = \Drupal::languageManager()->getCurrentLanguage()->getId();
}
