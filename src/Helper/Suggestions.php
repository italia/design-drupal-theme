<?php

namespace Drupal\bootstrap_italia\Helper;

use Drupal\block_content\BlockContentInterface;

/**
 * Helper Suggestions class for bootstrap_italia theme.
 *
 * Why isn't it a service? https://www.drupal.org/project/drupal/issues/2002606.
 */
class Suggestions {

  /**
   * Set form suggestions.
   *
   * @param array &$suggestions
   *   Referenced $suggestions.
   * @param array $variables
   *   Referenced $variables.
   * @param string|null $hook
   *   Specific hook.
   */
  public static function form(array &$suggestions, array $variables, string $hook = NULL) {
    // Add a suggestion based on the element type.
    if (isset($variables['element']['#type'])) {
      $suggestions[] = $variables['theme_hook_original'] . '__type__' . $variables['element']['#type'];
    }
    if (isset($variables['element']['#type']) && !is_null($hook)) {
      $suggestions[] = $hook . '__type__' . $variables['element']['#type'];
    }
    if (isset($variables['element']['#id'])) {
      $suggestions[] = $variables['theme_hook_original'] . '__id__' . $variables['element']['#id'];
    }
    if (isset($variables['element']['#id']) && !is_null($hook)) {
      $suggestions[] = $hook . '__id__' . $variables['element']['#id'];
    }
    if (isset($variables['element']['#name'])) {
      $suggestions[] = $variables['theme_hook_original'] . '__name__' . $variables['element']['#name'];
    }
    if (isset($variables['element']['#name']) && !is_null($hook)) {
      $suggestions[] = $hook . '__name__' . $variables['element']['#name'];
    }
  }

  /**
   * Set blocks suggestions.
   *
   * @param array &$suggestions
   *   Referenced $suggestions.
   * @param array $variables
   *   Referenced $variables.
   *
   * @throws \Drupal\Component\Plugin\Exception\InvalidPluginDefinitionException
   * @throws \Drupal\Component\Plugin\Exception\PluginNotFoundException
   */
  public static function block(array &$suggestions, array $variables) {
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

  /**
   * Set menu suggestions.
   *
   * @param array &$suggestions
   *   Referenced $suggestions.
   * @param array $variables
   *   Referenced $variables.
   */
  public static function menu(array &$suggestions, array $variables) {
    // See bootstrap_italia_preprocess_block().
    if (isset($variables['attributes']['data-block']['region'])) {
      $region = $variables['attributes']['data-block']['region'];
      $suggestions[] = $variables['theme_hook_original'] . '__' . $region;
      $suggestions[] = 'menu__' . $region;
    }
  }

}
