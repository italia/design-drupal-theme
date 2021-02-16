<?php

/**
 * @file
 * Preprocess html.
 */

/**
 * Implements template_preprocess_html()
 */
function bootstrap_italia_preprocess_html(&$variables) {
  // Search modal.
  $variables['modal_size'] = theme_get_setting('modal_size');
}
