<?php

/**
 * @file
 * Preprocess breadcrumb.
 */

use Drupal\Core\Template\Attribute;

/**
 * Implements hook_preprocess_HOOK() for breadcrumb.html.twig.
 */
function bootstrap_italia_preprocess_breadcrumb(&$variables) {
  $variables['breadcrumb_dark_background'] = (bool) theme_get_setting('breadcrumb_dark_background');
  $variables['breadcrumb_image'] = (bool) theme_get_setting('breadcrumb_image');
  $variables['breadcrumb_separator'] = theme_get_setting('breadcrumb_separator');

  // Add current page to breadcrumb.
  if ($variables['breadcrumb']) {
    $request = \Drupal::request();
    $route_match = \Drupal::routeMatch();
    $page_title = \Drupal::service('title_resolver')->getTitle($request, $route_match->getRouteObject());

    if (!empty($page_title)) {
      $variables['breadcrumb'][] = [
        'text' => $page_title,
        'attributes' => new Attribute(['class' => ['active']]),
      ];
    }
  }
}
