<?php

/**
 * @file
 * Hook THEME_suggestions_*.
 */

use Drupal\bootstrap_italia\Helper\Suggestions;
use Drupal\Component\Plugin\Exception\InvalidPluginDefinitionException;
use Drupal\Component\Plugin\Exception\PluginNotFoundException;
use Drupal\node\Entity\Node;
use Drupal\taxonomy\Entity\Term;

/**
 * Implements hook_theme_suggestions_page_alter().
 *
 * Ref: https://www.drupal.org/project/coding_standards/issues/3056368
 *
 * @phpstan-ignore missingType.iterableValue, missingType.iterableValue
 */
function bootstrap_italia_theme_suggestions_page_alter(array &$suggestions, array &$variables): void {
  Suggestions::page($suggestions, $variables);
}

/**
 * Implements hook_theme_suggestions_HOOK_alter() for block templates.
 *
 * Ref: https://www.drupal.org/project/coding_standards/issues/3056368
 *
 * @phpstan-ignore missingType.iterableValue, missingType.iterableValue
 */
function bootstrap_italia_theme_suggestions_page_title_alter(array &$suggestions, array $variables): void {
  $route_name = str_replace('.', '_', Drupal::routeMatch()->getRouteName());
  $suggestions[] = $variables['theme_hook_original'] . '__' . $route_name;
}

/**
 * Implements hook_theme_suggestions_node_alter().
 *
 * Ref: https://www.drupal.org/project/coding_standards/issues/3056368
 *
 * @phpstan-ignore missingType.iterableValue, missingType.iterableValue
 */
function bootstrap_italia_theme_suggestions_node_alter(array &$suggestions, array $variables): void {

  if (isset($variables['elements']['#view_mode'])) {
    $suggestions[] = $variables['theme_hook_original']
      . '__view_mode__' . $variables['elements']['#view_mode'];

    if (isset($variables['elements']['#node']) &&
      ($variables['elements']['#node'] instanceof Node)
    ) {
      $suggestions[] = $variables['theme_hook_original']
        . '__type_' . $variables['elements']['#node']->getType()
        . '__view_mode_' . $variables['elements']['#view_mode'];
    }
  }
}

/**
 * Implements hook_theme_suggestions_taxonomy_term_alter().
 *
 * Ref: https://www.drupal.org/project/coding_standards/issues/3056368
 *
 * @phpstan-ignore missingType.iterableValue, missingType.iterableValue
 */
function bootstrap_italia_theme_suggestions_taxonomy_term_alter(array &$suggestions, array $variables): void {

  if (isset($variables['elements']['#view_mode'])) {
    $suggestions[] = $variables['theme_hook_original']
      . '__view_mode__' . $variables['elements']['#view_mode'];

    if (isset($variables['elements']['#taxonomy_term']) &&
      ($variables['elements']['#taxonomy_term'] instanceof Term)
    ) {
      $suggestions[] = $variables['theme_hook_original']
        . '__type_' . $variables['elements']['#taxonomy_term']->bundle()
        . '__view_mode_' . $variables['elements']['#view_mode'];
    }
  }
}

/**
 * Implements hook_theme_suggestions_field_alter().
 *
 * Ref: https://www.drupal.org/project/coding_standards/issues/3056368
 *
 * @phpstan-ignore missingType.iterableValue, missingType.iterableValue
 */
function bootstrap_italia_theme_suggestions_field_alter(array &$suggestions, array &$variables): void {

  if (isset($variables['element']['#view_mode'])) {
    $suggestions[] = $variables['theme_hook_original']
      . '__view_mode_' . $variables['element']['#view_mode'];

    if (isset($variables['element']['#bundle'])) {
      $suggestions[] = $variables['theme_hook_original']
        . '__view_mode_' . $variables['element']['#view_mode']
        . '__bundle_' . $variables['element']['#bundle'];

      if (isset($variables['element']['#field_type'])) {
        $suggestions[] = $variables['theme_hook_original']
          . '__view_mode_' . $variables['element']['#view_mode']
          . '__bundle_' . $variables['element']['#bundle']
          . '__type_' . $variables['element']['#field_type'];

        if (isset($variables['element']['#field_name'])) {
          $suggestions[] = $variables['theme_hook_original']
            . '__view_mode_' . $variables['element']['#view_mode']
            . '__type_' . $variables['element']['#field_type']
            . '__name_' . $variables['element']['#field_name'];

          $suggestions[] = $variables['theme_hook_original']
            . '__view_mode_' . $variables['element']['#view_mode']
            . '__bundle_' . $variables['element']['#bundle']
            . '__type_' . $variables['element']['#field_type']
            . '__name_' . $variables['element']['#field_name'];
        }
      }
    }
  }
}

/**
 * Implements hook_theme_suggestions_block_alter().
 *
 * Ref: https://www.drupal.org/project/coding_standards/issues/3056368
 *
 * @phpstan-ignore missingType.iterableValue, missingType.iterableValue
 */
function bootstrap_italia_theme_suggestions_block_alter(array &$suggestions, array $variables): void {
  try {
    Suggestions::block($suggestions, $variables);
  }
  catch (InvalidPluginDefinitionException | PluginNotFoundException $e) {
  }
}

/**
 * Implements hook_theme_suggestions_HOOK_alter().
 *
 * Ref: https://www.drupal.org/project/coding_standards/issues/3056368
 *
 * @phpstan-ignore missingType.iterableValue, missingType.iterableValue
 */
function bootstrap_italia_theme_suggestions_menu_alter(array &$suggestions, array $variables): void {
  Suggestions::menu($suggestions, $variables);
}

/**
 * Implements hook_theme_suggestions_HOOK_alter().
 *
 * Ref: https://www.drupal.org/project/coding_standards/issues/3056368
 *
 * @phpstan-ignore missingType.iterableValue, missingType.iterableValue
 */
function bootstrap_italia_theme_suggestions_views_view_alter(array &$suggestions, array $variables): void {
  if (isset($variables['view'])) {
    $view = $variables['view'];
    $displayObj = $view->getDisplay();
    $suggestions[] = 'views_view__' . $view->id() . '__' . $displayObj->display['id'];
  }
}

/**
 * Implements hook_theme_suggestions_HOOK_alter().
 *
 * Ref: https://www.drupal.org/project/coding_standards/issues/3056368
 *
 * @phpstan-ignore missingType.iterableValue, missingType.iterableValue
 */
function bootstrap_italia_theme_suggestions_views_view_unformatted_alter(array &$suggestions, array $variables): void {
  if (isset($variables['view'])) {
    $view = $variables['view'];
    $displayObj = $view->getDisplay();
    $variant = (isset($view->rowPlugin->options['pattern_variant'])) ? '__' . $view->rowPlugin->options['pattern_variant'] : '';
    $suggestions[] = 'views_view_unformatted__' . $view->id() . $variant;
    $suggestions[] = 'views_view_unformatted__' . $view->id() . '__' . $displayObj->display['id'] . $variant;
  }
}

/**
 * Implements hook_theme_suggestions_HOOK_alter().
 *
 * Ref: https://www.drupal.org/project/coding_standards/issues/3056368
 *
 * @phpstan-ignore missingType.iterableValue, missingType.iterableValue
 */
function bootstrap_italia_theme_suggestions_form_alter(array &$suggestions, array &$variables): void {

  // Add a suggestion based on the form id name.
  if (isset($variables['element']['#form_id'])) {
    $suggestions[] = $variables['theme_hook_original'] . '__' . $variables['element']['#form_id'];
  }

  // Check to see if the form is layout builder form.
  if (isset($variables['element']['#layout_builder_element_keys'])) {
    $suggestions[] = $variables['theme_hook_original'] . '__' . 'layout__builder';
  }
}

/**
 * Implements hook_theme_suggestions_HOOK_alter().
 *
 * Ref: https://www.drupal.org/project/coding_standards/issues/3056368
 *
 * @phpstan-ignore missingType.iterableValue, missingType.iterableValue
 */
function bootstrap_italia_theme_suggestions_form_element_alter(array &$suggestions, array &$variables): void {
  Suggestions::form($suggestions, $variables);
}

/**
 * Implements hook_theme_suggestions_HOOK_alter().
 *
 * Ref: https://www.drupal.org/project/coding_standards/issues/3056368
 *
 * @phpstan-ignore missingType.iterableValue, missingType.iterableValue
 */
function bootstrap_italia_theme_suggestions_input_alter(array &$suggestions, array &$variables, string $hook): void {
  Suggestions::form($suggestions, $variables, $hook);
}

/**
 * Implements hook_theme_suggestions_HOOK_alter().
 *
 * Ref: https://www.drupal.org/project/coding_standards/issues/3056368
 *
 * @phpstan-ignore missingType.iterableValue, missingType.iterableValue
 */
function bootstrap_italia_theme_suggestions_select_alter(array &$suggestions, array &$variables, string $hook): void {
  Suggestions::form($suggestions, $variables, $hook);
}

/**
 * Implements hook_theme_suggestions_HOOK_alter().
 *
 * Ref: https://www.drupal.org/project/coding_standards/issues/3056368
 *
 * @phpstan-ignore missingType.iterableValue, missingType.iterableValue
 */
function bootstrap_italia_theme_suggestions_container_alter(array &$suggestions, array &$variables): void {
  Suggestions::form($suggestions, $variables);
}

/**
 * Implements hook_theme_suggestions_HOOK_alter().
 *
 * Ref: https://www.drupal.org/project/coding_standards/issues/3056368
 *
 * @phpstan-ignore missingType.iterableValue, missingType.iterableValue
 */
function bootstrap_italia_theme_suggestions_user_alter(array &$suggestions, array $variables): void {

  // Define the view mode.
  $mode = $variables['elements']['#view_mode'];

  // Create a theme hook suggestion which has the view mode name in it.
  $suggestions[] = 'user__' . $mode;

  // Get current user.
  $current_user = $variables['elements']['#user'];

  // Get current user's roles.
  $roles = $current_user->getRoles();

  // Add suggestion per role.
  foreach ($roles as $role) {
    $suggestions[] = 'user__' . $mode . '__' . $role;
  }
}

/**
 * Implements hook_theme_suggestions_HOOK_alter().
 *
 * Ref: https://www.drupal.org/project/coding_standards/issues/3056368
 *
 * @phpstan-ignore missingType.iterableValue, missingType.iterableValue
 */
function bootstrap_italia_theme_suggestions_image_formatter_alter(array &$suggestions, array $variables): void {
  Suggestions::imageFormatter($suggestions, $variables);
}

/**
 * Implements hook_theme_suggestions_HOOK_alter().
 *
 * Ref: https://www.drupal.org/project/coding_standards/issues/3056368
 *
 * @phpstan-ignore missingType.iterableValue, missingType.iterableValue
 */
function bootstrap_italia_theme_suggestions_responsive_image_formatter_alter(array &$suggestions, array $variables): void {
  Suggestions::imageFormatter($suggestions, $variables);
}

/**
 * Implements hook_theme_suggestions_HOOK_alter().
 *
 * Ref: https://www.drupal.org/project/coding_standards/issues/3056368
 *
 * @phpstan-ignore missingType.iterableValue, missingType.iterableValue
 */
function bootstrap_italia_theme_suggestions_image_style_alter(array &$suggestions, array $variables): void {
  Suggestions::imageStyle($suggestions, $variables);
}

/**
 * Implements hook_theme_suggestions_HOOK_alter().
 *
 * Ref: https://www.drupal.org/project/coding_standards/issues/3056368
 *
 * @phpstan-ignore missingType.iterableValue, missingType.iterableValue
 */
function bootstrap_italia_theme_suggestions_image_alter(array &$suggestions, array $variables): void {
  Suggestions::imageStyle($suggestions, $variables);
}

/**
 * Implements hook_theme_suggestions_HOOK_alter().
 *
 * Ref: https://www.drupal.org/project/coding_standards/issues/3056368
 *
 * @phpstan-ignore missingType.iterableValue, missingType.iterableValue
 */
function bootstrap_italia_theme_suggestions_responsive_image_alter(array &$suggestions, array $variables): void {
  Suggestions::imageStyle($suggestions, $variables);
}

/**
 * Implements hook_link_alter().
 *
 * Ref: https://www.drupal.org/project/coding_standards/issues/3056368
 *
 * @phpstan-ignore missingType.iterableValue, missingType.iterableValue
 */
function bootstrap_italia_theme_suggestions_details_alter(array &$suggestions, array $variables): void {
  if (!empty($variables['element']['#webform_element'])) {
    $suggestions[] = $variables['theme_hook_original'] . '__webform';
  }
}
