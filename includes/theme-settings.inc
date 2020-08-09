<?php

use Drupal\Core\Form\FormStateInterface;
use Drupal\bootstrap_italia\Helper;
/**
 * @param $form
 * @param \Drupal\Core\Form\FormStateInterface $formState
 * @param null $form_id
 */
function bootstrap_italia_form_system_theme_settings_alter(&$form, FormStateInterface $form_state, $form_id = NULL) {

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

  /* Header settings ------------------------------------------------ */
  $form['header_settings'] = [
    '#type' => 'details',
    '#title' => t('Header'),
    '#description' => t('Impostazioni personalizzabili per l\'intestazione del sito. <a href="https://italia.github.io/bootstrap-italia/docs/menu-di-navigazione/header/" target="_blank">Docs://Header</a>'),
    '#open' => TRUE,
    '#group' => 'bootstrap',
    '#weight' => 0,
  ];

  // Layout and theme variants
  $form['header_settings']['layout_and_variants'] = [
    '#type' => 'details',
    '#title' => t('Layout e varianti colore'),
    '#description' => t('Impostazioni per il layout e le varianti colore.'),
    '#open' => TRUE,
    '#group' => 'header_settings',
  ];
  // Slim header light
  $form['header_settings']['layout_and_variants']['slim_header_light'] = [
    '#type' => 'checkbox',
    '#title' => t('Attiva la variante chiara dello slim header'),
    '#default_value' => theme_get_setting('slim_header_light'),
  ];
  // Header center light
  $form['header_settings']['layout_and_variants']['header_center_light'] = [
    '#type' => 'checkbox',
    '#title' => t('Attiva la variante chiara dell\'header centrale'),
    '#default_value' => theme_get_setting('header_center_light'),
  ];
  // Header center small
  $form['header_settings']['layout_and_variants']['header_center_small'] = [
    '#type' => 'checkbox',
    '#title' => t('Attiva la variante small dell\'header centrale'),
    '#default_value' => theme_get_setting('header_center_small'),
  ];
  // Header sticky
  $form['header_settings']['layout_and_variants']['header_sticky'] = [
    '#type' => 'checkbox',
    '#title' => t('Attiva la possibiltà che la testata rimanga parzialmente visibile anche allo scorrere della pagina'),
    '#default_value' => theme_get_setting('header_sticky'),
  ];

  // Ente di appartenenza
  $form['header_settings']['ente_appartenenza'] = [
    '#type' => 'details',
    '#title' => t('Ente di appartenenza'),
    '#description' => t('Impostazioni personalizzabili l\'ente di appartenenza.'),
    '#open' => TRUE,
    '#group' => 'header_settings',
  ];
  $form['header_settings']['ente_appartenenza']['ente_appartenenza_nome'] = [
    '#type' => 'textfield',
    '#title' => t('Nome Ente di Appartenenza'),
    '#description' => t('Qui puoi personalizzare il nome dell\'Ente di Appartenenza.'),
    '#default_value' => theme_get_setting('ente_appartenenza_nome'),
  ];
  $form['header_settings']['ente_appartenenza']['ente_appartenenza_url'] = [
    '#type' => 'url',
    '#title' => t('URL Ente di Appartenenza'),
    '#description' => t('Inserisci l\'URL per l\'Ente di Appartenenza. Inserisci indirizzo completo come: https://www.example.com.'),
    '#default_value' => theme_get_setting('ente_appartenenza_url'),
  ];

  // Right Action
  $form['header_settings']['right_action_settings'] = [
    '#type' => 'details',
    '#title' => t('Tipo di pulsante login'),
    '#description' => t('Selezione fra normale e full responsive.'),
    '#open' => TRUE,
    '#group' => 'header_settings',
  ];
  $form['header_settings']['right_action_settings']['right_action_size'] = [
    '#type' => 'select',
    '#title' => t('Dimensione pulsante login'),
    '#description' => t('Seleziona la dimensione per pulsante login.'),
    '#default_value' => theme_get_setting('right_action_size'),
    '#options' => [
      'normal' => 'Normale',
      'full' => 'Full responsive',
    ],
  ];

  // Social network
  $form['header_settings']['social_settings'] = [
    '#type' => 'details',
    '#title' => t('Social network'),
    '#description' => t('Impostazioni personalizzabili per i social network.'),
    '#open' => FALSE,
    '#group' => 'header_settings',
  ];

  foreach (Helper::getSocialItems() as $social) {
    $low_social = strtolower($social);
    $form['header_settings']['social_settings'][$low_social] = [
      '#type' => 'url',
      '#title' => t('URL profilo '. $social),
      '#description' => t('Inserisci l\'URL del profilo '. $social .'. Inserisci indirizzo completo come: http://www.example.com.'),
      '#default_value' => theme_get_setting($low_social),
    ];
  }

  /* Tab Navigation settings ------------------------------------------------ */
  $form['navigation_settings'] = [
    '#type' => 'details',
    '#title' => t('Navigation'),
    '#description' => t('Impostazioni personalizzabili per i componenti di navigazione.'),
    '#open' => FALSE,
    '#group' => 'bootstrap',
    '#weight' => 6,
  ];

  // Breadcrumbs settings.
  $form['navigation_settings']['breadcrumbs_settings'] = [
    '#type' => 'details',
    '#title' => t('Breadcrumbs'),
    '#description' => t('Impostazioni personalizzabili per le briciole di pane.'),
    '#open' => TRUE,
    '#group' => 'navigation_settings',
  ];
  $form['navigation_settings']['breadcrumbs_settings']['breadcrumb_dark_background'] = [
    '#type' => 'checkbox',
    '#title' => t('Sfondo scuro'),
    '#description' => t('Attiva un background scuro.'),
    '#default_value' => theme_get_setting('breadcrumb_dark_background'),
  ];
  $form['navigation_settings']['breadcrumbs_settings']['breadcrumb_image'] = [
    '#type' => 'checkbox',
    '#title' => t('Icona'),
    '#description' => t('Attiva icona prima delle voci.'),
    '#default_value' => theme_get_setting('breadcrumb_image'),
  ];
  $form['navigation_settings']['breadcrumbs_settings']['breadcrumb_separator'] = [
    '#type' => 'select',
    '#title' => t('Separatore'),
    '#description' => t('Inserisci il separatore fra le voci (es: >).'),
    '#default_value' => theme_get_setting('breadcrumb_separator'),
    '#options' => [
      '>' => '>',
      '/' => '/',
    ],
  ];

  // Back to top settings
  $form['navigation_settings']['back_to_top'] = [
    '#type' => 'details',
    '#title' => t('Back to top'),
    '#description' => t('Impostazioni personalizzabili per il pulsante Back to top.'),
    '#open' => FALSE,
    '#group' => 'navigation_settings',
  ];
  $form['navigation_settings']['back_to_top']['back_to_top_enable'] = [
    '#type' => 'checkbox',
    '#title' => t('Attiva il pulsante back to top'),
    '#default_value' => theme_get_setting('back_to_top_enable'),
  ];
  $form['navigation_settings']['back_to_top']['back_to_top_small'] = [
    '#type' => 'checkbox',
    '#title' => t('Usa la variante piccola'),
    '#default_value' => theme_get_setting('back_to_top_small'),
  ];
  $form['navigation_settings']['back_to_top']['back_to_top_dark'] = [
    '#type' => 'checkbox',
    '#title' => t('Usa la variante per sfondo scuro'),
    '#default_value' => theme_get_setting('back_to_top_dark'),
  ];
  $form['navigation_settings']['back_to_top']['back_to_top_shadow'] = [
    '#type' => 'checkbox',
    '#title' => t('Usa l\'ombreggiatura del pulsante'),
    '#default_value' => theme_get_setting('back_to_top_shadow'),
  ];

  // Avatar settings.
  $form['avatar_settings'] = [
    '#type' => 'details',
    '#title' => t('Avatar'),
    '#description' => t('Impostazioni personalizzabili per avatar utente.'),
    '#open' => FALSE,
    '#group' => 'bootstrap',
    '#weight' => 10,
  ];
  $form['avatar_settings']['avatar_size'] = [
    '#type' => 'select',
    '#title' => t('Dimensione Avatar'),
    '#description' => t('Seleziona la dimensione per l\'avatar (es: xs).'),
    '#default_value' => theme_get_setting('avatar_size'),
    '#options' => [
      'xs' => 'xs',
      'sm' => 'sm',
      'md' => 'md',
      'lg' => 'lg',
      'xl' => 'xl',
    ],
  ];

  /* Table settings ------------------------------------------------ */
  $form['table_settings'] = [
    '#type' => 'details',
    '#title' => t('Tabelle'),
    '#description' => t('Impostazioni personalizzabili per le tabelle.'),
    '#open' => FALSE,
    '#group' => 'bootstrap',
    '#weight' => 11,
  ];
  $form['table_settings']['table_bg'] = [
    '#type' => 'checkbox',
    '#title' => t('Seleziona per abilitare lo sfondo scuro nelle tabelle'),
    '#default_value' => theme_get_setting('table_bg'),
  ];
  $form['table_settings']['table_thead'] = [
    '#type' => 'select',
    '#title' => t('Sfondo Intestazione tabelle'),
    '#description' => t('Scegli il colore di sfondo per le intestazioni delle tabelle'),
    '#default_value' => theme_get_setting('table_thead'),
    '#options' => [
      'nessuno' => 'nessuno',
      'chiaro' => 'chiaro',
      'scuro' => 'scuro',
    ],
  ];
  $form['table_settings']['table_striped'] = [
    '#type' => 'checkbox',
    '#title' => t('Seleziona per abilitare lo zebrato ad ogni riga della tabella'),
    '#default_value' => theme_get_setting('table_striped'),
  ];
  $form['table_settings']['table_bordered'] = [
    '#type' => 'checkbox',
    '#title' => t('Seleziona per avere i bordi a tutti i lati della tabella e su tutte le celle'),
    '#default_value' => theme_get_setting('table_bordered'),
  ];
  $form['table_settings']['table_hover'] = [
    '#type' => 'checkbox',
    '#title' => t('Seleziona per abilitare lo stato hover sulle righe della tabella'),
    '#default_value' => theme_get_setting('table_hover'),
  ];
  $form['table_settings']['table_sm'] = [
    '#type' => 'checkbox',
    '#title' => t('Seleziona per rendere le tabelle più compatte dimezzando il cell padding'),
    '#default_value' => theme_get_setting('table_sm'),
  ];


}
