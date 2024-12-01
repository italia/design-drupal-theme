<?php

/**
 * @file
 * Preprocess node.
 */

/**
 * Implements hook_preprocess_HOOK() for node.html.twig.
 *
 * Ref: https://www.drupal.org/project/coding_standards/issues/3056368
 *
 * @phpstan-ignore missingType.iterableValue
 */
function bootstrap_italia_preprocess_node(array &$variables): void {
  // Remove the "Add new comment" link on teasers or when the comment form is
  // displayed on the page.
  if ($variables['teaser'] || !empty($variables['content']['comments']['comment_form'])) {
    unset($variables['content']['links']['comment']['#links']['comment-add']);
  }

  // Apply custom date formatter to "date" field.
  if (!empty($variables['date'])) {
    $variables['date'] = \Drupal::service('date.formatter')->format($variables['node']->getCreatedTime(), 'bootstrap_italia_medium');
  }
}
