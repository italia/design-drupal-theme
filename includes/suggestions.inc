<?php

/**
 * @file
 * Hook THEME_suggestions_*.
 */

use Drupal\bootstrap_italia\Helper\Suggestions;
use Drupal\Component\Plugin\Exception\InvalidPluginDefinitionException;
use Drupal\Component\Plugin\Exception\PluginNotFoundException;

/**
 * Implements hook_theme_suggestions_block_alter().
 */
function bootstrap_italia_theme_suggestions_block_alter(array &$suggestions, array $variables) {
  try {
    Suggestions::block($suggestions, $variables);
  }
  catch (InvalidPluginDefinitionException | PluginNotFoundException $e) {
  }
}

/**
 * Implements hook_theme_suggestions_HOOK_alter().
 */
function bootstrap_italia_theme_suggestions_menu_alter(array &$suggestions, array $variables) {
  Suggestions::menu($suggestions, $variables);
}

/**
 * Implements hook_theme_suggestions_HOOK_alter().
 */
function bootstrap_italia_theme_suggestions_form_alter(array &$suggestions, array &$variables) {

  // Add a suggestion based on the form id name.
  if (isset($variables['element']['#form_id'])) {
    $suggestions[] = $variables['theme_hook_original'] . '__' . $variables['element']['#form_id'];
  }

  // Check to see if the form is layout builder form.
  if (isset($element['#layout_builder_element_keys'])) {
    $suggestions[] = $variables['theme_hook_original'] . '__' . 'layout__builder';
  }
}

/**
 * Implements hook_theme_suggestions_HOOK_alter().
 */
function bootstrap_italia_theme_suggestions_form_element_alter(array &$suggestions, array &$variables) {
  Suggestions::form($suggestions, $variables);
}

/**
 * Implements hook_theme_suggestions_HOOK_alter().
 */
function bootstrap_italia_theme_suggestions_input_alter(array &$suggestions, array &$variables, string $hook) {
  Suggestions::form($suggestions, $variables, $hook);
}

/**
 * Implements hook_theme_suggestions_HOOK_alter().
 */
function bootstrap_italia_theme_suggestions_select_alter(array &$suggestions, array &$variables, string $hook) {
  Suggestions::form($suggestions, $variables, $hook);
}

/**
 * Implements hook_theme_suggestions_HOOK_alter().
 */
function bootstrap_italia_theme_suggestions_container_alter(array &$suggestions, array &$variables) {
  Suggestions::form($suggestions, $variables);
}
