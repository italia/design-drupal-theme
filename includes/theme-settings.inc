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
      '#description' => t('Inserisci l\'URL del profilo '. $social .'. Inserisci indirizzo completo come: https://www.example.com.'),
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

  // Main menu settings
  $form['navigation_settings']['main_menu'] = [
    '#type' => 'details',
    '#title' => t('Menu principale'),
    '#description' => t('Impostazioni personalizzabili per il menu principale'),
    '#open' => TRUE,
    '#group' => 'navigation_settings',
  ];
  $form['navigation_settings']['main_menu']['main_menu_breackpoint_expand'] = [
    '#type' => 'select',
    '#title' => t('Visualizza il menu dal breackpoint'),
    '#description' => t('Seleziona il breackpoint (dimensione schermo) dal quale desideri visualizzare l\'intero menu'),
    '#default_value' => theme_get_setting('main_menu_breackpoint_expand'),
    '#options' => Helper::getBreackpoints(true),
  ];
  $form['navigation_settings']['main_menu']['main_menu_link_size'] = [
    '#type' => 'checkbox',
    '#title' => t('Usa la variante large delle voci di menu'),
    '#default_value' => theme_get_setting('main_menu_link_size'),
  ];
  $form['navigation_settings']['main_menu']['main_menu_link_bolder_active'] = [
    '#type' => 'checkbox',
    '#title' => t('Aumenta il peso del carattere per i link attivi'),
    '#default_value' => theme_get_setting('main_menu_link_bolder_active'),
  ];
  $form['navigation_settings']['main_menu']['main_menu_dropdown_link_description'] = [
    '#type' => 'checkbox',
    '#title' => t('Visualizza la descrizione sotto link dei dropdown'),
    '#default_value' => theme_get_setting('main_menu_dropdown_link_description'),
  ];
  $form['navigation_settings']['main_menu']['main_menu_megamenu_title_description'] = [
    '#type' => 'checkbox',
    '#title' => t('Visualizza la descrizione sotto i titoli dei megamenu'),
    '#default_value' => theme_get_setting('main_menu_megamenu_title_description'),
  ];
  $form['navigation_settings']['main_menu']['main_menu_megamenu_link_description'] = [
    '#type' => 'checkbox',
    '#title' => t('Visualizza la descrizione sotto i link dei megamenu'),
    '#default_value' => theme_get_setting('main_menu_megamenu_link_description'),
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

  // Sidebar menu settings
  $form['navigation_settings']['sidebar_menu'] = [
    '#type' => 'details',
    '#title' => t('Sidebar Menu'),
    '#description' => t('Impostazioni personalizzabili per i menu nelle sidebar'),
    '#open' => TRUE,
    '#group' => 'navigation_settings',
  ];
  $form['navigation_settings']['sidebar_menu']['sidebar_menu_background'] = [
    '#type' => 'select',
    '#title' => t('Varianti colore'),
    '#default_value' => theme_get_setting('sidebar_menu_background'),
    '#description' => t('Scegli le varianti colore. Se scegli il tema dark, imposta uno dei colori chiari all\'icona delle voci espandibili.'),
    '#options' => [
      'white' => 'White',
      'light' => 'Light',
      'dark' => 'Dark',
      'custom' => 'Nessuno (potrai personalizzarlo attraverso i CSS)'
    ],
  ];
  $form['navigation_settings']['sidebar_menu']['sidebar_menu_link_size'] = [
    '#type' => 'select',
    '#title' => t('Dimensione voci'),
    '#default_value' => theme_get_setting('sidebar_menu_link_size'),
    '#description' => t('Questa impostazione gestisce la dimensione e l\'altezza del contenitore della voce di menu'),
    '#options' => [
      'default' => 'Dimensione predefinita',
      'all' => 'Variante large per tutte le voci',
      'active' => 'Variante large solo per le voci attive'
    ],
  ];
  $form['navigation_settings']['sidebar_menu']['sidebar_menu_link_weight'] = [
    '#type' => 'select',
    '#title' => t('Peso del carattere'),
    '#default_value' => theme_get_setting('sidebar_menu_link_weight'),
    '#description' => t('Questa impostazione gestisce il peso del carattere della voce di menu'),
    '#options' => [
      'default' => 'Dimensione predefinita',
      'all' => 'Grassetto per tutte le voci',
      'active' => 'Grassetto solo per le voci attive'
    ],
  ];
  $form['navigation_settings']['sidebar_menu']['sidebar_menu_link_description'] = [
    '#type' => 'checkbox',
    '#title' => t('Visualizza la descrizione sotto tutte le voci di menu'),
    '#default_value' => theme_get_setting('sidebar_menu_link_description'),
  ];
  $form['navigation_settings']['sidebar_menu']['sidebar_menu_icon_type'] = [
    '#type' => 'select',
    '#title' => t('Icona delle voci espandibili'),
    '#default_value' => theme_get_setting('sidebar_menu_icon_position'),
    '#description' => t('Scegli quale icona utilizzare per espandere i livelli annidati'),
    '#options' => [
      'it-expand' => 'Parentesi angolare verso il basso',
      'it-chevron-right' => 'Parentesi angolare verso destra'
    ],
  ];
  $form['navigation_settings']['sidebar_menu']['sidebar_menu_icon_position'] = [
    '#type' => 'select',
    '#title' => t('Posizione icona delle voci espandibili'),
    '#default_value' => theme_get_setting('sidebar_menu_icon_position'),
    '#description' => t('Scegli la posizione dell\'icona utilizzata per espandere i livelli annidati'),
    '#options' => [
      'left' => 'Sinistra',
      'right' => 'Destra'
    ],
  ];
  $form['navigation_settings']['sidebar_menu']['sidebar_menu_icon_color'] = [
    '#type' => 'select',
    '#title' => t('Colore icona delle voci espandibili'),
    '#default_value' => theme_get_setting('sidebar_menu_icon_color'),
    '#description' => t('Scegli il colore dell\'icona utilizzata per espandere i livelli annidati'),
    '#options' => Helper::getColorsName(true),
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
