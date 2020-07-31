<?php

/**
 * Implements hook_theme_suggestions_page_alter().
 * https://www.drupal.org/node/2521876#comment-10684366
 */
function bootstrap_italia_suggestions_page_alter(array &$suggestions, array $variables)
{
  // Add content type suggestions.
  if (($node = \Drupal::request()->attributes->get('node')) && (strpos($_SERVER['REQUEST_URI'], "revisions") == false)) {
    array_splice($suggestions, 1, 0, 'page__node__' . $node->getType());
    $variables['content_type_name'] = $node->getType();
  }
}

/**
 * Implements hook_theme_suggestions_HOOK_alter().
 * @todo da sistemare, bug drupal? bug mio?
 * FILE NAME SUGGESTIONS:
 * x menu--slim.html.twig <=================
 * menu--header-slim.html.twig
 * menu--header-slim--slim.html.twig
 * x menu--slim.html.twig <=================
 * menu.html.twig
 */
function bootstrap_italia_theme_suggestions_menu_alter(array &$suggestions, array $variables)
{
  $menu_name = isset($variables['menu_name']) ? $variables['menu_name'] : 'generic';

  if (isset($variables['attributes']['block'])) {
    $block = \Drupal\block\Entity\Block::load($variables['attributes']['block']);
    $region = $block->getRegion();
    $suggestions[] = 'menu__' . $region;
    $suggestions[] = 'menu__' . $region . '__' . $menu_name;
    $suggestions[] = 'menu__' . $menu_name . '__' . $region;
  }
}

/**
 * Implements hook_theme_suggestions_block_alter().
 */
function bootstrap_italia_theme_suggestions_block_alter(array &$suggestions, array $variables)
{
  $content = $variables['elements']['content'];
  if (isset($content['#block_content']) and $content['#block_content'] instanceof BlockContentInterface) {
    $bundle = $content['#block_content']->bundle();
    $view_mode = $content['#view_mode'];
    $suggestions[] = 'block__' . $bundle;
    $suggestions[] = 'block__' . $view_mode;
    $suggestions[] = 'block__' . $bundle . $view_mode;
  }
  if (!empty($variables['elements']['#id'])) { 
    // if ($variables['elements']['#id'] == 'navigazioneprincipale') kpr($variables['elements']);
    $block = \Drupal\block\Entity\Block::load($variables['elements']['#id']);
    $region = $block->getRegion();
    // adds suggestion with region and block id
    $suggestions[] = 'block__' . $region . '__' . $variables['elements']['#id'];
    // adds suggestion with region id
    $suggestions[] = 'block__' . $region;
    // adds suggestions with base and derivative plugin id
    $suggestions[] = 'block__' . $region . '__' . $variables['elements']['#base_plugin_id'];
    $suggestions[] = 'block__' . $region . '__' . $variables['elements']['#base_plugin_id'] . '__' . $variables['elements']['#derivative_plugin_id'];
  }
}

/**
 * Implements hook_theme_suggestions_HOOK_alter().
 */
function bootstrap_italia_theme_suggestions_views_view_unformatted_alter(array &$suggestions, array $variables)
{
  if (isset($variables['view'])) {
    $view = $variables['view'];
    $displayObj = $view->getDisplay();
    $view = $variables['view'];
    $displayObj = $view->getDisplay();
    $suggestions[] = 'views_view_unformatted__' . $view->id();
    $suggestions[] = 'views_view_unformatted__' . $view->id() . '__' . $displayObj->display['id'];
  }
}