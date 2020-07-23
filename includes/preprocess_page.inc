<?php

/**
 * Implements hook_preprocess_page()
 */
function bootstrap_italia_preprocess_page(&$variables)
{
  $variables['nome_ente_appartenenza'] = theme_get_setting('nome_ente_appartenenza');
  $variables['url_ente_appartenenza'] = theme_get_setting('url_ente_appartenenza');
}
