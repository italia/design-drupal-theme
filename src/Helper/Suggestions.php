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
   * @param list<string> &$suggestions
   *   Referenced $suggestions.
   * @param array<string, mixed> $variables
   *   Referenced $variables.
   * @param string|null $hook
   *   Specific hook.
   */
  public static function form(array &$suggestions, array $variables, ?string $hook = NULL): void {
    /** @var string $hook_original */
    $hook_original = $variables['theme_hook_original'];

    /** @var array<string, mixed> $element */
    $element = $variables['element'];

    if (!empty($element)) {

      // Add a suggestion based on the element type.
      if (isset($element['#type']) && is_string($element['#type'])) {
        $element_type = $element['#type'];

        $suggestions[] = $hook_original . '__type__' . $element_type;

        if (!is_null($hook)) {
          $suggestions[] = $hook . '__type__' . $element_type;
        }
      }

      // Add a suggestion based on the element id.
      if (isset($element['#id']) && is_string($element['#id'])) {
        $element_id = self::sanitize($element['#id']);

        $suggestions[] = $hook_original . '__id__' . $element_id;

        if (!is_null($hook)) {
          $suggestions[] = $hook . '__id__' . $element_id;
        }
      }

      // Add a suggestion based on the element name.
      if (isset($element['#name']) && is_string($element['#name'])) {
        $element_name = self::sanitize($element['#name']);

        $suggestions[] = $hook_original . '__name__' . $element_name;

        if (!is_null($hook)) {
          $suggestions[] = $hook . '__name__' . $element_name;
        }
      }
    }

  }

  /**
   * Set blocks suggestions.
   *
   * @param list<string> &$suggestions
   *   Referenced $suggestions.
   * @param array<string, mixed> $variables
   *   Referenced $variables.
   *
   * @throws \Drupal\Component\Plugin\Exception\InvalidPluginDefinitionException
   * @throws \Drupal\Component\Plugin\Exception\PluginNotFoundException
   */
  public static function block(array &$suggestions, array $variables): void {
    /** @var string $hook_original */
    $hook_original = $variables['theme_hook_original'];

    /** @var array<string, mixed> $elements */
    $elements = $variables['elements'];

    /** @var array<string, mixed> $content */
    $content = $elements['content'];

    // Bundle and view mode suggestions.
    if (isset($content['#block_content']) and $content['#block_content'] instanceof BlockContentInterface) {
      $bundle = $content['#block_content']->bundle();
      if (!empty($bundle)) {
        $suggestions[] = 'block__' . $bundle;
      }

      /** @var string $view_mode */
      $view_mode = $content['#view_mode'];
      if (!empty($view_mode)) {
        $suggestions[] = 'block__' . $view_mode;
      }

      if (!empty($bundle) && !empty($view_mode)) {
        $suggestions[] = 'block__' . $bundle . $view_mode;
      }
    }

    if (!empty($elements['#id'])) {
      /** @var string|int $elements_id_original */
      $elements_id_original = $elements['#id'];

      /** @var \Drupal\block\BlockInterface|null $block */
      $block = \Drupal::entityTypeManager()
        ->getStorage('block')
        ->load($elements_id_original);

      /** @var array<string, mixed> $block_configuration */
      $block_configuration = $elements['#configuration'] ?? [];

      $region_name_from_block = '';

      if ($block !== NULL) {
        $region_name_from_block = self::sanitize($block->getRegion());
      }

      if (!empty($region_name_from_block)) {
        $region = $region_name_from_block;
      }
      elseif (
        isset($block_configuration['region'])
        && is_string($block_configuration['region'])
      ) {
        $region = self::sanitize($block_configuration['region']);
      }
      else {
        $region = '';
      }

      $base_plugin_id = isset($elements['#base_plugin_id'])
        && is_string($elements['#base_plugin_id'])
          ? self::sanitize($elements['#base_plugin_id'])
          : '';

      $derivate_plugin_id = isset($elements['#derivative_plugin_id'])
        && is_string($elements['#derivative_plugin_id'])
          ? self::sanitize($elements['#derivative_plugin_id'])
          : '';

      $route_name_raw = \Drupal::routeMatch()->getRouteName();
      $route_name = is_string($route_name_raw)
        ? self::sanitize($route_name_raw)
        : '';

      // Adds suggestions with region id.
      if (!empty($region)) {
        $suggestions[] = 'block__' . $region;
        $suggestions[] = 'block__' . $region . '__' . $elements_id_original;

        if (!empty($base_plugin_id)) {
          $suggestions[] = 'block__' . $region . '__' . $base_plugin_id;

          if (!empty($derivate_plugin_id)) {
            $suggestions[] = 'block__'
              . $region
              . '__'
              . $base_plugin_id
              . '__'
              . $derivate_plugin_id;
          }
        }
      }

      if (!empty($base_plugin_id) && !empty($route_name)) {
        $suggestions[] = $hook_original
          . '__'
          . $base_plugin_id
          . '__'
          . $route_name;
      }
    }
  }

  /**
   * Set menu suggestions.
   *
   * @param list<string> &$suggestions
   *   Referenced $suggestions.
   * @param array<string, mixed> $variables
   *   Referenced $variables.
   */
  public static function menu(array &$suggestions, array $variables): void {
    // See bootstrap_italia_preprocess_block().
    /** @var array<string, mixed> $attributes */
    $attributes = $variables['attributes'];

    /** @var array<string, mixed> $data_block */
    $data_block = $attributes['data-block'] ?? [];

    if (isset($data_block['region'])) {
      /** @var string $region */
      $region = $data_block['region'];

      /** @var string $hook_original */
      $hook_original = $variables['theme_hook_original'];

      if (!empty($region) && !empty($hook_original)) {
        $suggestions[] = $hook_original . '__' . $region;
      }

      if (!empty($region)) {
        $suggestions[] = 'menu__' . $region;
      }
    }
  }

  /**
   * Set page suggestions.
   *
   * @param list<string> &$suggestions
   *   Referenced $suggestions.
   * @param array<string, mixed> &$variables
   *   Referenced $variables.
   */
  public static function page(array &$suggestions, array &$variables): void {
    /** @var string $uri */
    $uri = $_SERVER['REQUEST_URI'] ?? '';
    $is_revision = str_contains($uri, 'revisions');

    // Add content type suggestions.
    $node = \Drupal::request()->attributes->get('node');
    if ($node instanceof NodeInterface && !$is_revision) {
      array_splice($suggestions, 1, 0, 'page__node__' . $node->getType());
      $variables['content_type_name'] = $node->getType();
    }

    // Add taxonomy suggestions.
    $term = \Drupal::request()->attributes->get('taxonomy_term');
    if ($term instanceof Term && !$is_revision) {
      if ((int) $term->get('parent')->target_id === 0) {
        $suggestions[] = 'page__taxonomy__term__firstlevel';
      }
      else {
        $suggestions[] = 'page__taxonomy__term__secondlevel';
      }

      $term_name = Html::getUniqueId(strtolower($term->getName()));
      $suggestions[] = 'page__taxonomy__term__' . self::sanitize($term_name);
      $suggestions[] = 'page__taxonomy__term__' . self::sanitize($term->bundle());
    }
  }

  /**
   * Set image_formatter suggestions.
   *
   * @param list<string> &$suggestions
   *   Referenced $suggestions.
   * @param array<string, mixed> $variables
   *   Referenced $variables.
   */
  public static function imageFormatter(array &$suggestions, array $variables): void {
    /** @var \Drupal\Core\Field\FieldItemInterface $item */
    $item = $variables['item'];

    $entity = $item->getEntity();
    $entity_type_id = $entity->getEntityTypeId();
    $bundle = $entity->bundle();

    /** @var string $hook_original */
    $hook_original = $variables['theme_hook_original'];

    $suggestions[] = $hook_original . '__' . $entity_type_id;

    $suggestions[] = $hook_original . '__' . $bundle;

    $suggestions[] = $hook_original . '__' . $entity_type_id . '__' . $bundle;

    if ($item->getParent()) {
      $field_name = $item->getParent()->getName();

      $suggestions[] = $hook_original . '__' . $field_name;

      $suggestions[] = $hook_original . '__' . $entity_type_id . '__' . $field_name;

      $suggestions[] = $hook_original . '__' . $bundle . '__' . $field_name;

      $suggestions[] =
        $hook_original
        . '__' . $entity_type_id
        . '__' . $bundle
        . '__' . $field_name;
    }
  }

  /**
   * Set image_style suggestions.
   *
   * @param list<string> &$suggestions
   *   Referenced $suggestions.
   * @param array<string, mixed> $variables
   *   Referenced $variables.
   */
  public static function imageStyle(array &$suggestions, array $variables): void {
    if (
      isset($variables['style_name'], $variables['theme_hook_original'])
      && is_string($variables['theme_hook_original'])
      && is_string($variables['style_name'])
    ) {
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
    $s = strtolower($s);
    $s = str_replace('.', '_', $s);
    return str_replace('-', '_', $s);
  }

}
