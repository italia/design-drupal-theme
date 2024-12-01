<?php

/**
 * @file
 * Table settings.
 */

use Drupal\bootstrap_italia\Helper\Table;

/**
 * Implements hook_preprocess_table().
 *
 * Ref: https://www.drupal.org/project/coding_standards/issues/3056368
 *
 * @phpstan-ignore missingType.iterableValue
 */
function bootstrap_italia_preprocess_table(array &$variables): void {
  Table::set($variables);
}
