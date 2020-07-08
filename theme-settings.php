<?php

/**
 * @param $form
 * @param \Drupal\Core\Form\FormStateInterface $formState
 * @param null $form_id
 */
function bootstrap_italia_form_system_theme_settings_alter(&$form, \Drupal\Core\Form\FormStateInterface &$formState, $form_id = NULL) {
  if (isset($form_id)) {
    return;
  }

  // Header settings.
  $form['header_settings'] = [
    '#type' => 'details',
    '#title' => t('Header'),
    '#description' => t('Impostazioni personalizzabili per l\'intestazione del sito.'),
    '#open' => TRUE,
  ];
  $form['header_settings']['nome_ente_appartenenza'] = [
    '#type' => 'textfield',
    '#title' => t('Nome Ente di Appartenenza'),
    '#description' => t('Qui puoi personalizzare il nome dell\'Ente di Appartenenza.'),
    '#default_value' => theme_get_setting('header_settings.nome_ente_appartenenza'),
  ];
  $form['header_settings']['url_ente_appartenenza'] = [
    '#type' => 'url',
    '#title' => t('URL Ente di Appartenenza'),
    '#description' => t('Inserisci l\'URL per l\'Ente di Appartenenza. Inserisci indirizzo completo come: http://www.example.com.'),
    '#default_value' => theme_get_setting('header_settings.url_ente_appartenenza'),
  ];
}
