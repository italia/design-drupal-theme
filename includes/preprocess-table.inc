<?php

/**
 * @file
 * Table settings.
 */

use Drupal\bootstrap_italia\Helper\Table;

/**
 * Implements hook_preprocess_table().
 */
function bootstrap_italia_preprocess_table(array &$variables): void {
  Table::set($variables);
}
