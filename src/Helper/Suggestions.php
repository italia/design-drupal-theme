<?php

namespace Drupal\bootstrap_italia\Helper;

use Drupal\block_content\BlockContentInterface;
use Drupal\Component\Utility\Html;
use Drupal\node\NodeInterface;
use Drupal\taxonomy\Entity\Term;

/**
 * Helper Suggestions class for bootstrap_italia theme.
 *
 * Why isn't it a service? https://www.drupal.org/project/drupal/issues/2002606.
 */
class Suggestions {

  /**
   * Set form suggestions.
   *
   * @param array<string> &$suggestions
   *   Referenced $suggestions.
   * @param array<string, mixed> $variables
   *   Referenced $variables.
   * @param string|null $hook
   *   Specific hook.
   */
  public static function form(array &$suggestions, array $variables, ?string $hook = NULL): void {
    // Add a suggestion based on the element type.
    if (isset($variables['element']['#type'])) {
      $suggestions[] = $variables['theme_hook_original'] . '__type__' . $variables['element']['#type'];
    }
    if (isset($variables['element']['#type']) && !is_null($hook)) {
      $suggestions[] = $hook . '__type__' . $variables['element']['#type'];
    }
    if (isset($variables['element']['#id'])) {
      $suggestions[] = $variables['theme_hook_original'] . '__id__' . self::sanitize($variables['element']['#id']);
    }
    if (isset($variables['element']['#id']) && !is_null($hook)) {
      $suggestions[] = $hook . '__id__' . self::sanitize($variables['element']['#id']);
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
   * @param array<string> &$suggestions
   *   Referenced $suggestions.
   * @param array<string, mixed> $variables
   *   Referenced $variables.
   *
   * @throws \Drupal\Component\Plugin\Exception\InvalidPluginDefinitionException
   * @throws \Drupal\Component\Plugin\Exception\PluginNotFoundException
   */
  public static function block(array &$suggestions, array $variables): void {
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

      if (!empty($block->getRegion())) {
        $region = $block->getRegion();
      }
      else {
        $region = (isset($variables['elements']['#configuration']['region'])) ? $variables['elements']['#configuration']['region'] : '';
      }
      // Adds suggestion with region and block id.
      $suggestions[] = 'block__' . $region . '__' . $variables['elements']['#id'];
      // Adds suggestion with region id.
      $suggestions[] = 'block__' . $region;

      if (isset($variables['elements']['#base_plugin_id'])) {
        // Adds suggestions with base and derivative plugin id.
        $suggestions[] = 'block__' . $region . '__' . $variables['elements']['#base_plugin_id'];

        if ($variables['elements']['#derivative_plugin_id']) {
          $suggestions[] = 'block__' . $region . '__' . $variables['elements']['#base_plugin_id'] . '__' . self::sanitize($variables['elements']['#derivative_plugin_id']);
        }

        $route_name = str_replace('.', '_', \Drupal::routeMatch()->getRouteName());
        $suggestions[] = $variables['theme_hook_original'] . '__' . $variables['elements']['#base_plugin_id'] . '__' . self::sanitize($route_name);

      }
    }
  }

  /**
   * Set menu suggestions.
   *
   * @param array<string> &$suggestions
   *   Referenced $suggestions.
   * @param array<string, mixed> $variables
   *   Referenced $variables.
   */
  public static function menu(array &$suggestions, array $variables): void {
    // See bootstrap_italia_preprocess_block().
    if (isset($variables['attributes']['data-block']['region'])) {
      $region = $variables['attributes']['data-block']['region'];
      $suggestions[] = $variables['theme_hook_original'] . '__' . $region;
      $suggestions[] = 'menu__' . $region;
    }
  }

  /**
   * Set page suggestions.
   *
   * @param array<string> &$suggestions
   *   Referenced $suggestions.
   * @param array<string, mixed> &$variables
   *   Referenced $variables.
   */
  public static function page(array &$suggestions, array &$variables): void {
    // Add content type suggestions.
    if (($node = \Drupal::request()->attributes->get('node')) &&
      !strpos($_SERVER['REQUEST_URI'], "revisions")
    ) {
      if ($node instanceof NodeInterface) {
        array_splice($suggestions, 1, 0, 'page__node__' . $node->getType());
        $variables['content_type_name'] = $node->getType();
      }
    }
    // Add taxonomy suggestions.
    if (($term = \Drupal::request()->attributes->get('taxonomy_term')) &&
      !strpos($_SERVER['REQUEST_URI'], "revisions")
    ) {
      if ($term instanceof Term) {
        if ($term->get('parent')->target_id == 0) {
          $suggestions[] = 'page__taxonomy__term__firstlevel';
        }
        else {
          $suggestions[] = 'page__taxonomy__term__secondlevel';
        }
        $term_name = Html::getUniqueId(strtolower($term->getName()));
        $suggestions[] = 'page__taxonomy__term__' . self::sanitize($term_name);
        $suggestions[] = 'page__taxonomy__term__' . $term->bundle();
      }
    }

  }

  /**
   * Set image_formatter suggestions.
   *
   * @param array<string> &$suggestions
   *   Referenced $suggestions.
   * @param array<string, mixed> $variables
   *   Referenced $variables.
   */
  public static function imageFormatter(array &$suggestions, array $variables): void {
    $entity = $variables['item']->getEntity();
    $field_name = $variables['item']->getParent()->getName();

    $suggestions[] =
      $variables['theme_hook_original'] . '__' . $entity->getEntityTypeId();

    $suggestions[] =
      $variables['theme_hook_original'] . '__' . $entity->bundle();

    $suggestions[] =
      $variables['theme_hook_original'] . '__' . $field_name;

    $suggestions[] = $variables['theme_hook_original']
      . '__' . $entity->getEntityTypeId() . '__' . $entity->bundle();

    $suggestions[] = $variables['theme_hook_original']
      . '__' . $entity->getEntityTypeId() . '__' . $field_name;

    $suggestions[] = $variables['theme_hook_original']
      . '__' . $entity->bundle() . '__' . $field_name;

    $suggestions[] =
      $variables['theme_hook_original']
      . '__' . $entity->getEntityTypeId()
      . '__' . $entity->bundle()
      . '__' . $field_name;
  }

  /**
   * Set image_style suggestions.
   *
   * @param array<string> &$suggestions
   *   Referenced $suggestions.
   * @param array<string, mixed> $variables
   *   Referenced $variables.
   */
  public static function imageStyle(array &$suggestions, array $variables): void {
    if (isset($variables['style_name'])) {
      $suggestions[] = $variables['theme_hook_original'] . '__' . $variables['style_name'];
    }
  }

  /**
   * Sanitize string to use in suggestion.
   *
   * @param string $s
   *   String to sanitize.
   *
   * @return string
   *   Clean string
   */
  public static function sanitize(string $s): string {
    return str_replace('-', '_', $s);
  }

}
