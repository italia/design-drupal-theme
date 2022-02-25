<?php

/**
 * @file
 * Theme settings.
 */

use Drupal\Core\Form\FormStateInterface;
use Drupal\bootstrap_italia\Helper;

/**
 * Implements hook_form_system_theme_settings_alter().
 */
function bootstrap_italia_form_system_theme_settings_alter(array &$form, FormStateInterface $form_state, $form_id = NULL) {

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
    '#description' => t("Impostazioni personalizzabili per l'intestazione del sito.") . ' <a href="https://italia.github.io/bootstrap-italia/docs/menu-di-navigazione/header/" target="_blank">Docs://Header</a>',
    '#open' => TRUE,
    '#group' => 'bootstrap',
    '#weight' => 0,
  ];

  // Layout and theme variants.
  $form['header_settings']['layout_and_variants'] = [
    '#type' => 'details',
    '#title' => t('Layout e varianti colore'),
    '#description' => t('Impostazioni per il layout e le varianti colore.'),
    '#open' => TRUE,
    '#group' => 'header_settings',
  ];
  // Slim header light.
  $form['header_settings']['layout_and_variants']['slim_header_light'] = [
    '#type' => 'checkbox',
    '#title' => t('Attiva la variante chiara dello slim header'),
    '#default_value' => theme_get_setting('slim_header_light'),
  ];
  // Header center light.
  $form['header_settings']['layout_and_variants']['header_center_light'] = [
    '#type' => 'checkbox',
    '#title' => t("Attiva la variante chiara dell'header centrale."),
    '#default_value' => theme_get_setting('header_center_light'),
  ];
  // Header center small.
  $form['header_settings']['layout_and_variants']['header_center_small'] = [
    '#type' => 'checkbox',
    '#title' => t("Attiva la variante small dell'header centrale"),
    '#default_value' => theme_get_setting('header_center_small'),
  ];
  // Header sticky.
  $form['header_settings']['layout_and_variants']['header_sticky'] = [
    '#type' => 'checkbox',
    '#title' => t('Attiva la possibiltà che la testata rimanga parzialmente visibile anche allo scorrere della pagina'),
    '#default_value' => theme_get_setting('header_sticky'),
  ];

  // Ente di appartenenza.
  $form['header_settings']['ente_appartenenza'] = [
    '#type' => 'details',
    '#title' => t('Ente di appartenenza'),
    '#description' => t("Impostazioni personalizzabili l'ente di appartenenza."),
    '#open' => TRUE,
    '#group' => 'header_settings',
  ];
  $form['header_settings']['ente_appartenenza']['ente_appartenenza_nome'] = [
    '#type' => 'textfield',
    '#title' => t('Nome Ente di Appartenenza'),
    '#description' => t("Qui puoi personalizzare il nome dell'Ente di Appartenenza."),
    '#default_value' => theme_get_setting('ente_appartenenza_nome'),
  ];
  $form['header_settings']['ente_appartenenza']['ente_appartenenza_url'] = [
    '#type' => 'url',
    '#title' => t('URL Ente di Appartenenza'),
    '#description' => t("Inserisci l'URL dell'Ente di Appartenenza. Es: https://www.example.com"),
    '#default_value' => theme_get_setting('ente_appartenenza_url'),
  ];

  // Right Action.
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

  // Social network.
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
      '#title' => t('URL profilo @social', ['@social' => $social]),
      '#description' => t("Inserisci l'URL del profilo @social. Es: https://www.example.com", ['@social' => $social]),
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

  // Main menu settings.
  $form['navigation_settings']['main_menu'] = [
    '#type' => 'details',
    '#title' => t('Menu principale'),
    '#description' => t('Impostazioni personalizzabili per il menu principale'),
    '#open' => TRUE,
    '#group' => 'navigation_settings',
  ];
  $form['navigation_settings']['main_menu']['main_menu_breakpoint_expand'] = [
    '#type' => 'select',
    '#title' => t('Visualizza il menu dal breakpoint'),
    '#description' => t("Seleziona il breakpoint (dimensione schermo) dal quale desideri visualizzare l'intero menu."),
    '#default_value' => theme_get_setting('main_menu_breakpoint_expand'),
    '#options' => Helper::getBreakpoints(TRUE),
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

  // Sidebar menu settings.
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
    '#description' => t("Scegli le varianti colore. Se scegli il tema dark, imposta uno dei colori chiari all'icona delle voci espandibili."),
    '#options' => [
      'white' => 'White',
      'light' => 'Light',
      'dark' => 'Dark',
      'custom' => 'Nessuno (potrai personalizzarlo attraverso i CSS)',
    ],
  ];
  $form['navigation_settings']['sidebar_menu']['sidebar_menu_link_size'] = [
    '#type' => 'select',
    '#title' => t('Dimensione voci'),
    '#default_value' => theme_get_setting('sidebar_menu_link_size'),
    '#description' => t("Questa impostazione gestisce la dimensione e l'altezza del contenitore della voce di menu."),
    '#options' => [
      'default' => 'Dimensione predefinita',
      'all' => 'Variante large per tutte le voci',
      'active' => 'Variante large solo per le voci attive',
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
      'active' => 'Grassetto solo per le voci attive',
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
      'it-chevron-right' => 'Parentesi angolare verso destra',
    ],
  ];
  $form['navigation_settings']['sidebar_menu']['sidebar_menu_icon_position'] = [
    '#type' => 'select',
    '#title' => t('Posizione icona delle voci espandibili'),
    '#default_value' => theme_get_setting('sidebar_menu_icon_position'),
    '#description' => t("Scegli la posizione dell'icona utilizzata per espandere i livelli annidati."),
    '#options' => [
      'left' => 'Sinistra',
      'right' => 'Destra',
    ],
  ];
  $form['navigation_settings']['sidebar_menu']['sidebar_menu_icon_color'] = [
    '#type' => 'select',
    '#title' => t('Colore icona delle voci espandibili'),
    '#default_value' => theme_get_setting('sidebar_menu_icon_color'),
    '#description' => t("Scegli il colore dell'icona utilizzata per espandere i livelli annidati."),
    '#options' => Helper::getColorsName(TRUE),
  ];

  // Back to top settings.
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
    '#title' => t("Usa l'ombreggiatura del pulsante."),
    '#default_value' => theme_get_setting('back_to_top_shadow'),
  ];

  /* Content settings ------------------------------------------------ */
  $form['content_settings'] = [
    '#type' => 'details',
    '#title' => t('Contenuto'),
    '#description' => t('Impostazioni personalizzabili per gli elementi nel contenuto della pagina.'),
    '#open' => FALSE,
    '#group' => 'bootstrap',
    '#weight' => 10,
  ];

  // Images settings.
  $form['content_settings']['images'] = [
    '#type' => 'details',
    '#title' => t('Immagini'),
    '#description' => t('Impostazioni personalizzabili per tutte le immagini.'),
    '#open' => TRUE,
    '#group' => 'content_settings',
  ];
  $form['content_settings']['images']['image_fluid'] = [
    '#type' => 'checkbox',
    '#title' => t('Seleziona per abilitare il ridimensionamento automatico delle immagini.'),
    '#default_value' => theme_get_setting('image_fluid'),
  ];
  $form['content_settings']['images']['image_rounded'] = [
    '#type' => 'checkbox',
    '#title' => t('Seleziona per arrotondare il bordo delle immagini.'),
    '#default_value' => theme_get_setting('image_rounded'),
  ];

  // Table settings.
  $form['content_settings']['table'] = [
    '#type' => 'details',
    '#title' => t('Tabelle'),
    '#description' => t('Impostazioni personalizzabili per le tabelle.'),
    '#open' => TRUE,
    '#group' => 'content_settings',
  ];
  $form['content_settings']['table']['table_bg'] = [
    '#type' => 'checkbox',
    '#title' => t('Seleziona per abilitare lo sfondo scuro nelle tabelle'),
    '#default_value' => theme_get_setting('table_bg'),
  ];
  $form['content_settings']['table']['table_thead'] = [
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
  $form['content_settings']['table']['table_striped'] = [
    '#type' => 'checkbox',
    '#title' => t('Seleziona per abilitare lo zebrato ad ogni riga della tabella'),
    '#default_value' => theme_get_setting('table_striped'),
  ];
  $form['content_settings']['table']['table_bordered'] = [
    '#type' => 'checkbox',
    '#title' => t('Seleziona per avere i bordi a tutti i lati della tabella e su tutte le celle'),
    '#default_value' => theme_get_setting('table_bordered'),
  ];
  $form['content_settings']['table']['table_hover'] = [
    '#type' => 'checkbox',
    '#title' => t('Seleziona per abilitare lo stato hover sulle righe della tabella'),
    '#default_value' => theme_get_setting('table_hover'),
  ];
  $form['content_settings']['table']['table_sm'] = [
    '#type' => 'checkbox',
    '#title' => t('Seleziona per rendere le tabelle più compatte dimezzando il cell padding'),
    '#default_value' => theme_get_setting('table_sm'),
  ];

  // Modal settings.
  $form['content_settings']['modal'] = [
    '#type' => 'details',
    '#title' => t('Search Modal'),
    '#description' => t('Seleziona la grandezza del modal di ricerca.'),
    '#open' => TRUE,
    '#group' => 'content_settings',
  ];
  $form['content_settings']['modal']['modal_size'] = [
    '#type' => 'select',
    '#title' => t('Dimensione Modal'),
    '#description' => t('Seleziona la dimensione per il modal (xl corrisponde a fullscreen).'),
    '#default_value' => theme_get_setting('modal_size'),
    '#options' => [
      'xs' => 'xs',
      'sm' => 'sm',
      'md' => 'md',
      'lg' => 'lg',
      'xl' => 'xl',
    ],
  ];

  /* Component settings ------------------------------------------------ */
  $form['component_settings'] = [
    '#type' => 'details',
    '#title' => t('Componenti'),
    '#description' => t('Impostazioni personalizzabili per i componenti.'),
    '#open' => FALSE,
    '#group' => 'bootstrap',
    '#weight' => 14,
  ];

  // Avatar settings.
  $form['component_settings']['avatar'] = [
    '#type' => 'details',
    '#title' => t('Avatar'),
    '#description' => t('Impostazioni personalizzabili per avatar utente.'),
    '#open' => TRUE,
    '#group' => 'component_settings',
  ];
  $form['component_settings']['avatar']['avatar_size'] = [
    '#type' => 'select',
    '#title' => t('Dimensione Avatar'),
    '#description' => t("Seleziona la dimensione per l'avatar (es: xs)."),
    '#default_value' => theme_get_setting('avatar_size'),
    '#options' => [
      'xs' => 'xs',
      'sm' => 'sm',
      'md' => 'md',
      'lg' => 'lg',
      'xl' => 'xl',
    ],
  ];

  // Card settings.
  $form['component_settings']['card'] = [
    '#type' => 'details',
    '#title' => t('Card'),
    '#description' => t('Impostazioni personalizzabili per il componente card.'),
    '#open' => TRUE,
    '#group' => 'component_settings',
  ];
  $form['component_settings']['card']['card_description'] = [
    '#type' => 'markup',
    '#markup' => t('<p>Se desideri informazioni sul componente <em>Card</em> e la sua terminologia puoi consultare due risorse: <a href="https://italia.github.io/bootstrap-italia/docs/componenti/card/" target="_blank">1) Componente Card su bootstrap Italia</a>; <a href="/patterns#card" target="_blank">2) libreria dei pattern presente in questa installazione.</a></p>'),
  ];

  $form['component_settings']['card']['pattern_card_simple'] = [
    '#type' => 'details',
    '#title' => t('Card semplice'),
    '#open' => FALSE,
    '#group' => 'card',
  ];
  $form['component_settings']['card']['pattern_card_simple']['pattern_card_simple_shadow'] = [
    '#type' => 'checkbox',
    '#title' => t('Attiva ombreggiatura'),
    '#default_value' => theme_get_setting('pattern_card_simple_shadow'),
  ];
  $form['component_settings']['card']['pattern_card_simple']['pattern_card_simple_border_bottom'] = [
    '#type' => 'checkbox',
    '#title' => t('Visualizza il bordo inferiore'),
    '#default_value' => theme_get_setting('pattern_card_simple_border_bottom'),
  ];
  $form['component_settings']['card']['pattern_card_simple']['pattern_card_simple_border_rounded'] = [
    '#type' => 'checkbox',
    '#title' => t('Arrotonda gli angoli'),
    '#default_value' => theme_get_setting('pattern_card_simple_border_rounded'),
  ];

  $form['component_settings']['card']['pattern_card_simple_article'] = [
    '#type' => 'details',
    '#title' => t('Card articolo semplice'),
    '#open' => FALSE,
    '#group' => 'card',
  ];
  $form['component_settings']['card']['pattern_card_simple_article']['pattern_card_simple_article_shadow'] = [
    '#type' => 'checkbox',
    '#title' => t('Attiva ombreggiatura'),
    '#default_value' => theme_get_setting('pattern_card_simple_article_shadow'),
  ];
  $form['component_settings']['card']['pattern_card_simple_article']['pattern_card_simple_article_border_bottom'] = [
    '#type' => 'checkbox',
    '#title' => t('Visualizza il bordo inferiore'),
    '#default_value' => theme_get_setting('pattern_card_simple_article_border_bottom'),
  ];
  $form['component_settings']['card']['pattern_card_simple_article']['pattern_card_simple_article_border_rounded'] = [
    '#type' => 'checkbox',
    '#title' => t('Arrotonda gli angoli'),
    '#default_value' => theme_get_setting('pattern_card_simple_article_border_rounded'),
  ];

  $form['component_settings']['card']['pattern_card_big1'] = [
    '#type' => 'details',
    '#title' => t('Card grande con icona'),
    '#open' => FALSE,
    '#group' => 'card',
  ];
  $form['component_settings']['card']['pattern_card_big1']['pattern_card_big1_shadow'] = [
    '#type' => 'checkbox',
    '#title' => t('Attiva ombreggiatura'),
    '#default_value' => theme_get_setting('pattern_card_big1_shadow'),
  ];
  $form['component_settings']['card']['pattern_card_big1']['pattern_card_big1_border_bottom'] = [
    '#type' => 'checkbox',
    '#title' => t('Visualizza il bordo inferiore'),
    '#default_value' => theme_get_setting('pattern_card_big1_border_bottom'),
  ];
  $form['component_settings']['card']['pattern_card_big1']['pattern_card_big1_border_rounded'] = [
    '#type' => 'checkbox',
    '#title' => t('Arrotonda gli angoli'),
    '#default_value' => theme_get_setting('pattern_card_big1_border_rounded'),
  ];

  $form['component_settings']['card']['pattern_card_big2'] = [
    '#type' => 'details',
    '#title' => t('Card grande con icona e tag o categoria'),
    '#open' => FALSE,
    '#group' => 'card',
  ];
  $form['component_settings']['card']['pattern_card_big2']['pattern_card_big2_shadow'] = [
    '#type' => 'checkbox',
    '#title' => t('Attiva ombreggiatura'),
    '#default_value' => theme_get_setting('pattern_card_big2_shadow'),
  ];
  $form['component_settings']['card']['pattern_card_big2']['pattern_card_big2_border_bottom'] = [
    '#type' => 'checkbox',
    '#title' => t('Visualizza il bordo inferiore'),
    '#default_value' => theme_get_setting('pattern_card_big2_border_bottom'),
  ];
  $form['component_settings']['card']['pattern_card_big2']['pattern_card_big2_border_rounded'] = [
    '#type' => 'checkbox',
    '#title' => t('Arrotonda gli angoli'),
    '#default_value' => theme_get_setting('pattern_card_big2_border_rounded'),
  ];

  $form['component_settings']['card']['pattern_card_big3'] = [
    '#type' => 'details',
    '#title' => t('Card grande con tag, data e call to action'),
    '#open' => FALSE,
    '#group' => 'card',
  ];
  $form['component_settings']['card']['pattern_card_big3']['pattern_card_big3_shadow'] = [
    '#type' => 'checkbox',
    '#title' => t('Attiva ombreggiatura'),
    '#default_value' => theme_get_setting('pattern_card_big3_shadow'),
  ];
  $form['component_settings']['card']['pattern_card_big3']['pattern_card_big3_border_bottom'] = [
    '#type' => 'checkbox',
    '#title' => t('Visualizza il bordo inferiore'),
    '#default_value' => theme_get_setting('pattern_card_big3_border_bottom'),
  ];
  $form['component_settings']['card']['pattern_card_big3']['pattern_card_big3_border_rounded'] = [
    '#type' => 'checkbox',
    '#title' => t('Arrotonda gli angoli'),
    '#default_value' => theme_get_setting('pattern_card_big3_border_rounded'),
  ];

  $form['component_settings']['card']['pattern_card_with_img'] = [
    '#type' => 'details',
    '#title' => t('Card con immagine'),
    '#open' => FALSE,
    '#group' => 'card',
  ];
  $form['component_settings']['card']['pattern_card_with_img']['pattern_card_with_img_shadow'] = [
    '#type' => 'checkbox',
    '#title' => t('Attiva ombreggiatura'),
    '#default_value' => theme_get_setting('pattern_card_with_img_shadow'),
  ];
  $form['component_settings']['card']['pattern_card_with_img']['pattern_card_with_img_border_bottom'] = [
    '#type' => 'checkbox',
    '#title' => t('Visualizza il bordo inferiore'),
    '#default_value' => theme_get_setting('pattern_card_with_img_border_bottom'),
  ];
  $form['component_settings']['card']['pattern_card_with_img']['pattern_card_with_img_border_rounded'] = [
    '#type' => 'checkbox',
    '#title' => t('Arrotonda gli angoli'),
    '#default_value' => theme_get_setting('pattern_card_with_img_border_rounded'),
  ];

  $form['component_settings']['card']['pattern_card_special'] = [
    '#type' => 'details',
    '#title' => t('Card special'),
    '#description' => t('Per una buona resa grafica non attivare queste impostazione se non strettamente necessarie.'),
    '#open' => FALSE,
    '#group' => 'card',
  ];
  $form['component_settings']['card']['pattern_card_special']['pattern_card_special_shadow'] = [
    '#type' => 'checkbox',
    '#title' => t('Attiva ombreggiatura'),
    '#default_value' => theme_get_setting('pattern_card_special_shadow'),
  ];
  $form['component_settings']['card']['pattern_card_special']['pattern_card_special_border_bottom'] = [
    '#type' => 'checkbox',
    '#title' => t('Visualizza il bordo inferiore'),
    '#default_value' => theme_get_setting('pattern_card_special_border_bottom'),
  ];
  $form['component_settings']['card']['pattern_card_special']['pattern_card_special_border_rounded'] = [
    '#type' => 'checkbox',
    '#title' => t('Arrotonda gli angoli'),
    '#default_value' => theme_get_setting('pattern_card_special_border_rounded'),
  ];

  $form['component_settings']['card']['pattern_card_teaser'] = [
    '#type' => 'details',
    '#title' => t('Card teaser'),
    '#description' => t("Consulta la documentazione, per questo tipo di card va aggiunto il wrapper in base all'uso."),
    '#open' => FALSE,
    '#group' => 'card',
  ];
  $form['component_settings']['card']['pattern_card_teaser']['pattern_card_teaser_shadow'] = [
    '#type' => 'checkbox',
    '#title' => t('Attiva ombreggiatura'),
    '#default_value' => theme_get_setting('pattern_card_teaser_shadow'),
  ];
  $form['component_settings']['card']['pattern_card_teaser']['pattern_card_teaser_border_bottom'] = [
    '#type' => 'checkbox',
    '#title' => t('Visualizza il bordo inferiore'),
    '#default_value' => theme_get_setting('pattern_card_teaser_border_bottom'),
  ];
  $form['component_settings']['card']['pattern_card_teaser']['pattern_card_teaser_border_rounded'] = [
    '#type' => 'checkbox',
    '#title' => t('Arrotonda gli angoli'),
    '#default_value' => theme_get_setting('pattern_card_teaser_border_rounded'),
  ];

  /* Container settings ------------------------------------------------ */
  $form['container_settings'] = [
    '#type' => 'details',
    '#title' => t('Tipo di Container'),
    '#description' => t("Scegli il tipo di container da applicare alle diverse sezioni della pagina.") . ' <a href="https://getbootstrap.com/docs/4.5/layout/overview/#containers" target="_blank">Docs://Container</a>',
    '#open' => FALSE,
    '#group' => 'bootstrap',
    '#weight' => 18,
  ];
  $form['container_settings']['slim_header_container_type'] = [
    '#type' => 'select',
    '#title' => t("Container dell'intestazione"),
    '#description' => t('Seleziona il tipo di container.'),
    '#default_value' => theme_get_setting('slim_header_container_type'),
    '#options' => Helper::getBootstrapContainerType(TRUE),
  ];
  $form['container_settings']['header_container_type'] = [
    '#type' => 'select',
    '#title' => t("Container della testata"),
    '#description' => t('Seleziona il tipo di container.'),
    '#default_value' => theme_get_setting('header_container_type'),
    '#options' => Helper::getBootstrapContainerType(TRUE),
  ];
  $form['container_settings']['navigation_container_type'] = [
    '#type' => 'select',
    '#title' => t("Container del menu di navigazione"),
    '#description' => t('Seleziona il tipo di container.'),
    '#default_value' => theme_get_setting('navigation_container_type'),
    '#options' => Helper::getBootstrapContainerType(TRUE),
  ];
  $form['container_settings']['content_container_type'] = [
    '#type' => 'select',
    '#title' => t("Container del contenuto"),
    '#description' => t('Seleziona il tipo di container.'),
    '#default_value' => theme_get_setting('content_container_type'),
    '#options' => Helper::getBootstrapContainerType(TRUE),
  ];
  $form['container_settings']['home_content_container_type'] = [
    '#type' => 'select',
    '#title' => t("Container del contenuto in home"),
    '#description' => t('Seleziona il tipo di container.'),
    '#default_value' => theme_get_setting('home_content_container_type'),
    '#options' => Helper::getBootstrapContainerType(TRUE),
  ];
  $form['container_settings']['footer_container_type'] = [
    '#type' => 'select',
    '#title' => t("Container del footer"),
    '#description' => t('Seleziona il tipo di container.'),
    '#default_value' => theme_get_setting('footer_container_type'),
    '#options' => Helper::getBootstrapContainerType(TRUE),
  ];

  /* Libraries Settings ------------------------------------------------ */
  $form['libraries_settings'] = [
    '#type' => 'details',
    '#title' => t('Varianti del tema'),
    '#description' => t("Queste impostazioni ti permettono di scegliere quale variante del tema usare."),
    '#open' => FALSE,
    '#group' => 'bootstrap',
    '#weight' => 20,
  ];
  $form['libraries_settings']['theme_variant'] = [
    '#type' => 'select',
    '#title' => t("Scegli la variante del tema"),
    '#description' => t('Ogni volta che cambi questa impostazione devi cancellare la cache per visualizzare i cambiamenti.'),
    '#default_value' => theme_get_setting('theme_variant'),
    '#options' => Helper::getThemeVariants(),
  ];
  $form['libraries_settings']['theme_variant_docs'] = [
    '#type' => 'markup',
    '#markup' => t('
      <style>
        code {background-color: #eeeeee;color: #333333;padding: 0 2px;}
        pre {background-color: #333333;color: #ffffff;padding: 10px;}
      </style>
      <h6>Impostazione consigliata</h6>
      <p>Scegli <code>*.libraries.yml (raccomandato)</code>
         se intendi compilare una sola variante del tema.
         Questa è la scelta migliore se non stai usando il multisite.
      </p>
      <h6>Multisite</h6>
      <p>Se hai un\'installazione multisite e non vuoi duplicare gli assets
         in ogni sub-theme (magari solo per cambiare il colore),
         usa come canovaccio i seguenti passi:</p>
      <ol>
        <li>Duplica il contenuto di <code>/src/scss/theme.scss</code> in <code>/src/scss/theme-red.scss</code></li>
        <li>
          Edita il file che hai appena duplicato aggiungendo dopo la prima riga
          <code>@import "variables/palette-red";</code> (riusi tutto variando solo il colore),
          dovresti avere la seguente situazione
<pre>
 1 @import "variables";
 2 @import "variables/palette-red";
 3 @import "node_modules/bootstrap-italia/src/scss/bootstrap-italia.scss";
</pre>
        </li>
        <li>Edita <code>webpack.common.js</code> e aggiungi una riga nella sezione entry
<pre>
 10 entry: {
 11  "bootstrap-italia": [paths.src + \'/js/index.js\', paths.src + \'/scss/theme.scss\'],
 12  "bootstrap-italia-red": [paths.src + \'/js/index.js\', paths.src + \'/scss/theme-red.scss\']
 13 },
</pre>
        Hai riutilizzato integralmente <code>index.js</code> con la variante <code>theme-red.scss</code>
        </li>
        <li>Compila gli assets con <code>npm</code> e poi <code>drush cr</code></li>
        <li>Se non hai un sub-sub-theme, in <code>var/starter_kits/multisite_example</code> ne trovi uno.
            I file che fanno funzionare tutto sono: <code>multisite_example.info.yml</code> e
            <code>multisite_example.theme</code>.<br />
            È fondamentale costruire un collegamento simbolico con gli asset del tema genitore:
<pre>
$ cd path/to/nome_del_sub_sub_theme
$ ln -s ../italiagov/assets assets
</pre>
        </li>
        <li>Nelle impostazioni del sub-sub-theme, la select delle varianti avrà tra
            le opzioni il nome macchina che hai scelto al punto 3.
            Se hai seguito questo esempio, dovresti visualizzare: <code>bootstrap-italia-red</code>
        </li>
      </ol>
      <h6>Release Vanilla</h6>
      <p>Per usare la release vanilla (è quella rilasciata sul repo github),
          scarica la release corretta da <a href="https://github.com/italia/bootstrap-italia/releases">GitHub</a>
          e decomprimi il file .zip dentro <code>/themes/custom/sub-theme/assets/</code>.
          Successivamente, modifica il file <code>sub-theme.libraries.yml</code> in modo da caricare i file corretti,
          oppure scegli la variante dalla select sopra.</p>
      <p>Se non hai molta esperienza ti sconsiglio questa modalità in quanto:
          1) devi scaricare la versione supportata da questo tema (non è detto che sia sempre l\'ultima);
          2) devi applicare un po\' di fix css e js per far funzionare il tutto correttamente.
      </p>
     '),
  ];

  $form['#validate'][] = 'bootstrap_italia_form_system_theme_settings_validate';
}

/**
 * Implements hook_form_system_theme_settings_validate().
 */
function bootstrap_italia_form_system_theme_settings_validate(array &$form, FormStateInterface $form_state) {
  if (function_exists('file_save_upload')) {
    // Handle file uploads.
    $image_factory = \Drupal::service('image.factory');
    $supported_extensions = $image_factory->getSupportedExtensions();
    $supported_extensions[] = 'svg';
    $validators = ['file_validate_extensions' => [implode(' ', $supported_extensions)]];

    // Check for a new uploaded logo.
    $file = file_save_upload('logo_upload', $validators, FALSE, 0);
    if (isset($file)) {
      // File upload was attempted.
      if ($file) {
        // Put the temporary file in form_values so we can save it on submit.
        $form_state->setValue('logo_upload', $file);
      }
      else {
        // File upload failed.
        $form_state->setErrorByName('logo_upload', t('The logo could not be uploaded.'));
      }
    }
  }
}
