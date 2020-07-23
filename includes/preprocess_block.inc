<?php

/**
 * Implements hook_preprocess_HOOK() for block.html.twig.
 */
function bootstrap_italia_preprocess_block(&$variables)
{
  // Add the block ID as custom attribute to block content, this will be used
  // for menu template suggestions.
  if (isset($variables['elements']['#id'])) {
    $variables['content']['#attributes']['block'] = $variables['elements']['#id'];
  }
  $variables['base_path'] = base_path();
}
