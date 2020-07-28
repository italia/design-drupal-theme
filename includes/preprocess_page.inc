<?php

/**
 * Implements hook_preprocess_page()
 */
function bootstrap_italia_preprocess_page(&$variables)
{
  $variables['ente_appartenenza_nome'] = theme_get_setting('ente_appartenenza_nome');
  $variables['ente_appartenenza_url'] = theme_get_setting('ente_appartenenza_url');
}
