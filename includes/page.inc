<?php

/**
 * @file
 * Hook THEME_page_*
 */

/**
 * Implements page_attachments_alter()
 */
function bootstrap_italia_page_attachments_alter(&$page) {
  $viewport = array(
    '#type' => 'html_tag',
    '#tag' => 'meta',
    '#attributes' => array(
      'name' => 'viewport',
      'content' => 'width=device-width, initial-scale=1, shrink-to-fit=no',
    ),
  );
  $page['#attached']['html_head'][] = [$viewport, 'viewport'];
}

/**
 * Implements hook_preprocess_page().
 */
function bootstrap_italia_preprocess_page(&$variables) {
  // Slim header settings.
  $variables['slim_header_light'] = theme_get_setting('slim_header_light');
  $variables['slim_header_container_type'] = theme_get_setting('slim_header_container_type');
  $variables['government_entity_name'] = theme_get_setting('government_entity_name');
  $variables['government_entity_url'] = theme_get_setting('government_entity_url');
}
