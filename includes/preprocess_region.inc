<?php

/**
 * Implements hook_preprocess_region().
 * @param $variables
 * @param $hook
 */
function bootstrap_italia_preprocess_region(&$variables, $hook){

  // header-nav
  $variables['main_menu_breakpoint_expand'] = (string) theme_get_setting('main_menu_breakpoint_expand');
}
