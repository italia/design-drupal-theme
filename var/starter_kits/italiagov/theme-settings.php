<?php

use Drupal\Core\Form\FormStateInterface;
/**
 * @param $form
 * @param \Drupal\Core\Form\FormStateInterface $formState
 * @param null $form_id
 */
function italiagov_form_system_theme_settings_alter(&$form, FormStateInterface &$formState, $form_id = NULL) {
  // General "alters" use a form id. Settings should not be set here. The only
  // thing useful about this is if you need to alter the form for the running
  // theme and *not* the theme setting.
  // @see http://drupal.org/node/943212
  if (isset($form_id)) {
    return;
  }

  // Vertical tabs.
  $form['bootstrap'] = [
    '#type' => 'vertical_tabs',
    '#prefix' => '<h2><small>' . t('Bootstrap Italia settings') . '</small></h2>',
    '#weight' => -10,
  ];

  // Header settings.
  $form['header_settings'] = [
    '#type' => 'details',
    '#title' => t('Header'),
    '#description' => t('Impostazioni personalizzabili per l\'intestazione del sito.'),
    '#open' => TRUE,
    '#group' => 'bootstrap',
  ];
  $form['header_settings']['nome_ente_appartenenza'] = [
    '#type' => 'textfield',
    '#title' => t('Nome Ente di Appartenenza'),
    '#description' => t('Qui puoi personalizzare il nome dell\'Ente di Appartenenza.'),
    '#default_value' => theme_get_setting('nome_ente_appartenenza'),
  ];
  $form['header_settings']['url_ente_appartenenza'] = [
    '#type' => 'url',
    '#title' => t('URL Ente di Appartenenza'),
    '#description' => t('Inserisci l\'URL per l\'Ente di Appartenenza. Inserisci indirizzo completo come: http://www.example.com.'),
    '#default_value' => theme_get_setting('url_ente_appartenenza'),
  ];
  // Breadcrumbs settings.
  $form['breadcrumbs_settings'] = [
    '#type' => 'details',
    '#title' => t('Breadcrumbs'),
    '#description' => t('Impostazioni personalizzabili per le briciole di pane.'),
    '#open' => TRUE,
    '#group' => 'bootstrap',
  ];
  $form['breadcrumbs_settings']['darkbkg'] = [
    '#type' => 'checkbox',
    '#title' => t('Sfondo scuro'),
    '#description' => t('Attiva un background scuro.'),
    '#default_value' => theme_get_setting('darkbkg'),
  ];
  $form['breadcrumbs_settings']['image'] = [
    '#type' => 'checkbox',
    '#title' => t('Icona'),
    '#description' => t('Attiva icona prima delle voci.'),
    '#default_value' => theme_get_setting('image'),
  ];
  $form['breadcrumbs_settings']['separator'] = [
    '#type' => 'select',
    '#title' => t('Separatore'),
    '#description' => t('Inserisci il separatore fra le voci (es: >).'),
    '#default_value' => theme_get_setting('separator'),
    '#options' => [
      '>' => '>',
      '/' => '/',
    ],
  ];
}
