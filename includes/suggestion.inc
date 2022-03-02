<?php

/**
 * @file
 * Theme suggestions.
 */

use Drupal\block\Entity\Block;
use Drupal\block_content\BlockContentInterface;
use Drupal\Component\Utility\Html;
use Drupal\node\NodeInterface;
use Drupal\taxonomy\TermInterface;

/**
 * Implements hook_theme_suggestions_page_alter().
 */
function bootstrap_italia_theme_suggestions_page_alter(array &$suggestions, array $variables) {
  // Add content type suggestions.
  if (($node = \Drupal::request()->attributes->get('node')) &&
   (strpos($_SERVER['REQUEST_URI'], "revisions") == FALSE)) {
    if ($node instanceof NodeInterface) {
      array_splice($suggestions, 1, 0, 'page__node__' . $node->getType());
      $variables['content_type_name'] = $node->getType();
    }
  }
  // Add taxonomy suggestions.
  if (($term = \Drupal::request()->attributes->get('taxonomy_term')) &&
   (strpos($_SERVER['REQUEST_URI'], "revisions") == FALSE)) {
    if ($term instanceof TermInterface) {
      if ($term->parent->target_id == 0) {
        $suggestions[] = 'page__taxonomy__term__firstlevel';
      }
      else {
        $suggestions[] = 'page__taxonomy__term__secondlevel';
      }
      $term_name = Html::getUniqueId(strtolower($term->getName()));
      $suggestions[] = 'page__taxonomy__term__' . $term_name;
      $suggestions[] = 'page__taxonomy__term__' . $term->bundle();
    }
  }
}

/**
 * Implements hook_theme_suggestions_HOOK_alter().
 *
 * @todo da sistemare, bug drupal? bug mio?
 * FILE NAME SUGGESTIONS:
 * x menu--slim.html.twig <=================
 * menu--header-slim.html.twig
 * menu--header-slim--slim.html.twig
 * x menu--slim.html.twig <=================
 * menu.html.twig
 */
function bootstrap_italia_theme_suggestions_menu_alter(array &$suggestions, array $variables) {
  $menu_name = isset($variables['menu_name']) ? $variables['menu_name'] : 'generic';

  if (isset($variables['attributes']['data-block'])) {
    $block = Block::load($variables['attributes']['data-block']);
    if ($block && $region = $block->getRegion()) {
      $suggestions[] = 'menu__' . $region;
      $suggestions[] = 'menu__' . $region . '__' . $menu_name;
      $suggestions[] = 'menu__' . $menu_name . '__' . $region;
    }
  }
}

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
    $block = Block::load($variables['elements']['#id']);
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
 * Implements hook_theme_suggestions_HOOK_alter().
 */
function bootstrap_italia_theme_suggestions_views_view_unformatted_alter(array &$suggestions, array $variables) {
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
 */
function bootstrap_italia_theme_suggestions_form_alter(array &$suggestions, array $variables) {
  $element = $variables['element'];

  // Add a suggestion based on the form id name.
  if (isset($element['#form_id'])) {
    $suggestions[] = $variables['theme_hook_original'] . '__' . $element['#form_id'];
  }
}

/**
 * Implements hook_theme_suggestions_HOOK_alter().
 */
function bootstrap_italia_suggestions_form_element_alter(array &$suggestions, array $variables) {
  $element = $variables['element'];

  // Add a suggestion based on the element type.
  if (isset($element['#type'])) {
    $suggestions[] = $variables['theme_hook_original'] . '__' . $element['#type'];
  }
}

/**
 * Implements hook_theme_suggestions_HOOK_alter().
 */
function bootstrap_italia_theme_suggestions_user_alter(array &$suggestions, array $variables) {

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
 */
function bootstrap_italia_theme_suggestions_image_formatter_alter(array &$suggestions, array $variables) {
  $entity = $variables['item']->getEntity();
  $field_name = $variables['item']->getParent()->getName();
  $suggestions[] =
    $variables['theme_hook_original']
    . '__' . $entity->getEntityTypeId()
    . '__' . $entity->bundle()
    . '__' . $field_name;
}
