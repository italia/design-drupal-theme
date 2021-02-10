<?php

/**
 * Implements template_preprocess_html()
 * @param $variables
 */
function bootstrap_italia_preprocess_html(&$variables)
{
  // search modal
  $variables['modal_size'] = theme_get_setting('modal_size');
}
