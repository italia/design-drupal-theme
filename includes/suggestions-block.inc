<?php

/**
 * @file
 * Hook THEME_suggestions_block_*.
 */

use Drupal\block_content\BlockContentInterface;

/**
 * Implements hook_theme_suggestions_block_alter().
 */
function bootstrap_italia_theme_suggestions_block_alter(array &$suggestions, array $variables) {
  $content = $variables['elements']['content'];
  if (isset($content['#block_content']) and $content['#block_content'] instanceof BlockContentInterface) {
    $bundle = $content['#block_content']->bundle();
    $view_mode = $content['#view_mode'];
    $suggestions[] = 'block__' . $bundle;
    $suggestions[] = 'block__' . $view_mode;
    $suggestions[] = 'block__' . $bundle . $view_mode;
  }
  if (!empty($variables['elements']['#id'])) {
    /** @var \Drupal\block\BlockInterface $block */
    $block = \Drupal::entityTypeManager()
      ->getStorage('block')
      ->load($variables['elements']['#id']);

    if ($block) {
      $region = $block->getRegion();
    }
    else {
      $region = (isset($variables['elements']['#configuration']['region'])) ? $variables['elements']['#configuration']['region'] : '';
    }
    // Adds suggestion with region and block id.
    $suggestions[] = 'block__' . $region . '__' . $variables['elements']['#id'];
    // Adds suggestion with region id.
    $suggestions[] = 'block__' . $region;
    // Adds suggestions with base and derivative plugin id.
    $suggestions[] = 'block__' . $region . '__' . $variables['elements']['#base_plugin_id'];
    $suggestions[] = 'block__' . $region . '__' . $variables['elements']['#base_plugin_id'] . '__' . $variables['elements']['#derivative_plugin_id'];
  }
}
