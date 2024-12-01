<?php

/**
 * @file
 * Theme settings.
 */

use Drupal\bootstrap_italia\Helper\Color;
use Drupal\bootstrap_italia\Helper\Helper;
use Drupal\bootstrap_italia\Helper\Libraries;
use Drupal\bootstrap_italia\Helper\Spacing;
use Drupal\Core\Form\FormStateInterface;

/**
 * Implements hook_form_system_theme_settings_alter().
 *
 * Ref: https://www.drupal.org/project/coding_standards/issues/3056368
 *
 * @phpstan-ignore missingType.iterableValue
 */
function bootstrap_italia_form_system_theme_settings_alter(array &$form, FormStateInterface $form_state, ?string $form_id = NULL): void {

  // General "alters" use a form id. Settings should not be set here. The only
  // thing useful about this is if you need to alter the form for the running
  // theme and *not* the theme setting.
  // @see http://drupal.org/node/943212
  if (isset($form_id)) {
    return;
  }

  // Main vertical tabs.
  $form['bootstrap'] = [
    '#type' => 'vertical_tabs',
    '#weight' => -10,
  ];
  // Header --------------------------------------------------------------.
  $form['header'] = [
    '#type' => 'details',
    '#title' => t('Header'),
    '#description' => t('Header settings'),
    '#open' => FALSE,
    '#group' => 'bootstrap',
    '#weight' => 0,
  ];
  // Header appearance.
  $form['header']['appearance'] = [
    '#type' => 'details',
    '#title' => t('Appearance'),
    '#open' => FALSE,
    '#group' => 'header',
  ];
  $form['header']['appearance']['header_shadow'] = [
    '#type' => 'checkbox',
    '#title' => t('Enable shadow'),
    '#description' => t("Default: unchecked"),
    '#default_value' => theme_get_setting('header_shadow'),
  ];

  // Header slim --------------------------------------------------------------.
  $form['slim_header'] = [
    '#type' => 'details',
    '#title' => t('Slim header'),
    '#description' => t('Slim header settings. <a href="@link" title="@title" target="_blank">@label</a>', [
      '@link' => 'https://italia.github.io/bootstrap-italia/docs/menu-di-navigazione/header/#slim-header',
      '@title' => 'Read the docs',
      '@label' => 'Docs',
    ]),
    '#open' => FALSE,
    '#group' => 'bootstrap',
    '#weight' => 0,
  ];
  // Slim header appearance.
  $form['slim_header']['appearance'] = [
    '#type' => 'details',
    '#title' => t('Appearance'),
    '#open' => FALSE,
    '#group' => 'slim_header',
  ];
  $form['slim_header']['appearance']['slim_header_container_type'] = [
    '#type' => 'select',
    '#title' => t("Container"),
    '#description' => t('Choose container type. Default: container xxl'),
    '#default_value' => theme_get_setting('slim_header_container_type'),
    '#options' => Helper::getBootstrapContainerType(TRUE),
  ];
  $form['slim_header']['appearance']['slim_header_light'] = [
    '#type' => 'checkbox',
    '#title' => t('Enable light variant'),
    '#description' => t("Default: unchecked"),
    '#default_value' => theme_get_setting('slim_header_light'),
  ];
  // Government entity.
  $form['slim_header']['government_entity'] = [
    '#type' => 'details',
    '#title' => t('Government entity'),
    '#description' => t("Settings related to the superior government entity."),
    '#open' => FALSE,
    '#group' => 'slim_header',
  ];
  $form['slim_header']['government_entity']['government_entity_name'] = [
    '#type' => 'textfield',
    '#title' => t('Name'),
    '#description' => t("Government entity name."),
    '#placeholder' => t('Italian government'),
    '#default_value' => theme_get_setting('government_entity_name'),
  ];
  $form['slim_header']['government_entity']['government_entity_url'] = [
    '#type' => 'url',
    '#title' => t('Government entity web site'),
    '#placeholder' => t('https://example.gov.it'),
    '#description' => t("Government entity URL. Example: https://example.gov.it."),
    '#default_value' => theme_get_setting('government_entity_url'),
  ];
  // Slim header Action.
  $form['slim_header']['action'] = [
    '#type' => 'details',
    '#title' => t('Login button and user menu'),
    '#open' => FALSE,
    '#group' => 'slim_header',
  ];
  $form['slim_header']['action']['slim_header_action_active_login'] = [
    '#type' => 'checkbox',
    '#title' => t('Show login button'),
    '#description' => t("Default: checked"),
    '#default_value' => theme_get_setting('slim_header_action_active_login'),
  ];
  $form['slim_header']['action']['slim_header_action_type'] = [
    '#type' => 'select',
    '#title' => t('Login button type'),
    '#description' => t('Choose login button variant. Default: Full responsive'),
    '#default_value' => theme_get_setting('slim_header_action_type'),
    '#options' => [
      'default' => t('Default'),
      'full' => t('Full responsive'),
    ],
  ];
  $form['slim_header']['action']['slim_header_action_url'] = [
    '#type' => 'textfield',
    '#title' => t('Login page URL'),
    '#description' => t("Fill if you use a custom login page. Default: /user/login"),
    '#placeholder' => t('/user/login'),
    '#default_value' => theme_get_setting('slim_header_action_url'),
  ];
  $form['slim_header']['action']['slim_header_action_icon'] = [
    '#type' => 'checkbox',
    '#title' => t('Show icon'),
    '#description' => t("Default: checked"),
    '#default_value' => theme_get_setting('slim_header_action_icon'),
  ];
  $form['slim_header']['action']['slim_header_action_username'] = [
    '#type' => 'checkbox',
    '#title' => t('Show username'),
    '#description' => t("Default: unchecked"),
    '#default_value' => theme_get_setting('slim_header_action_username'),
  ];
  $form['slim_header']['action']['slim_header_action_dark'] = [
    '#type' => 'checkbox',
    '#title' => t('Enable dark mode to user logged menu'),
    '#description' => t("Default: checked"),
    '#default_value' => theme_get_setting('slim_header_action_dark'),
  ];

  // Center header ------------------------------------------------------------.
  $form['center_header'] = [
    '#type' => 'details',
    '#title' => t('Center header'),
    '#description' => t('Center header settings. <a href="@link" title="@title" target="_blank">@label</a>', [
      '@link' => 'https://italia.github.io/bootstrap-italia/docs/menu-di-navigazione/header/#header-centrale',
      '@title' => 'Read the docs',
      '@label' => 'Docs',
    ]),
    '#open' => FALSE,
    '#group' => 'bootstrap',
    '#weight' => 0,
  ];
  // Center header appearance.
  $form['center_header']['appearance'] = [
    '#type' => 'details',
    '#title' => t('Appearance'),
    '#open' => FALSE,
    '#group' => 'center_header',
  ];
  $form['center_header']['appearance']['center_header_container_type'] = [
    '#type' => 'select',
    '#title' => t("Container"),
    '#description' => t('Choose container type. Default: container xxl'),
    '#default_value' => theme_get_setting('center_header_container_type'),
    '#options' => Helper::getBootstrapContainerType(TRUE),
  ];
  $form['center_header']['appearance']['center_header_light'] = [
    '#type' => 'checkbox',
    '#title' => t('Enable light variant'),
    '#description' => t("Default: unchecked"),
    '#default_value' => theme_get_setting('center_header_light'),
  ];
  $form['center_header']['appearance']['center_header_small'] = [
    '#type' => 'checkbox',
    '#title' => t('Enable small variant'),
    '#description' => t("Default: unchecked"),
    '#default_value' => theme_get_setting('center_header_small'),
  ];
  // Center header branding.
  $form['center_header']['branding'] = [
    '#type' => 'details',
    '#title' => t('Branding block'),
    '#open' => FALSE,
    '#group' => 'center_header',
  ];
  $form['center_header']['branding']['svg_logo_id'] = [
    '#type' => 'textfield',
    '#title' => t('Svg logo: group id'),
    '#description' => t("Choose your custom id ('symbol' tag of svg file). Default: 'logo'."),
    '#placeholder' => t('logo'),
    '#default_value' => theme_get_setting('svg_logo_id'),
  ];
  $form['center_header']['branding']['svg_logo_box'] = [
    '#type' => 'textfield',
    '#title' => t('Svg logo: view box'),
    '#description' => t("Choose your custom viewBox. Example: 0 0 100 82. Default: empty"),
    '#placeholder' => t('0 0 82 82'),
    '#default_value' => theme_get_setting('svg_logo_box'),
  ];
  $form['center_header']['branding']['svg_logo_box_sticky'] = [
    '#type' => 'textfield',
    '#title' => t('Svg logo: view box when header is sticky'),
    '#description' => t("Choose your custom viewBox. Example: 20 0 100 82. Default: empty"),
    '#placeholder' => t('0 0 82 82'),
    '#default_value' => theme_get_setting('svg_logo_box_sticky'),
  ];
  $form['center_header']['branding']['image_logo_fluid'] = [
    '#type' => 'checkbox',
    '#title' => t('Enable responsive feature'),
    '#description' => t("If checked and you have loaded a raster image, enable the 'img-fluid' feature. Default: checked"),
    '#default_value' => theme_get_setting('image_logo_fluid'),
  ];
  // Center header social network.
  $form['center_header']['social'] = [
    '#type' => 'details',
    '#title' => t('Social networks'),
    '#open' => FALSE,
    '#group' => 'center_header',
  ];
  $form['center_header']['social']['social_new_window'] = [
    '#type' => 'checkbox',
    '#title' => t('Open in new window'),
    '#description' => t("Open social in new window. Default: checked"),
    '#default_value' => theme_get_setting('social_new_window'),
  ];
  foreach (Helper::getSocialItems() as $social) {
    $low_social = strtolower($social);
    $form['center_header']['social'][$low_social] = [
      '#type' => 'url',
      '#title' => t('URL @social', ['@social' => $social]),
      '#description' => t("Fill with @social URL.", ['@social' => $social]),
      '#default_value' => theme_get_setting($low_social),
    ];
  }
  // Center header search.
  $form['center_header']['search'] = [
    '#type' => 'details',
    '#title' => t('Search settings'),
    '#open' => FALSE,
    '#group' => 'center_header',
  ];
  $form['center_header']['search']['search_type'] = [
    '#type' => 'select',
    '#title' => t('Search type'),
    '#description' => t('Choose search type. Default: "Search in modal window"'),
    '#default_value' => theme_get_setting('search_type'),
    '#options' => [
      'modal' => t('Search in modal window'),
  // 'inline' => t('Show inline search input'),
      'page' => t('Redirect to search page'),
    ],
  ];
  $form['center_header']['search']['search_page_url'] = [
    '#type' => 'textfield',
    '#title' => t('Search URL page'),
    '#description' => t('Fill if the "Redirect to search page" mode has been chosen. Default: search/node'),
    '#placeholder' => t('/search/node'),
    '#default_value' => theme_get_setting('search_page_url'),
  ];
  $form['center_header']['search']['search_modal_size'] = [
    '#type' => 'select',
    '#title' => t('Modal size'),
    '#description' => t('Select an option if the "Search in modal window" mode has been chosen. Default: Fullscreen.'),
    '#default_value' => theme_get_setting('search_modal_size'),
    '#options' => [
      'xs' => t('Small (xs)'),
      'md' => t('Default (md)'),
      'lg' => t('Large (lg)'),
      'xl' => t('Extra-large (xl)'),
      'fullscreen' => t('Fullscreen'),
      'fullscreen-md-down' => t('Fullscreen md down'),
      'fullscreen-lg-down' => t('Fullscreen lg down'),
      'fullscreen-xl-down' => t('Fullscreen xl down'),
      'fullscreen-xxl-down' => t('Fullscreen xxl down'),
    ],
  ];

  // Navigation header --------------------------------------------------------.
  $form['navigation_header'] = [
    '#type' => 'details',
    '#title' => t('Main navigation'),
    '#description' => t('Main navigation settings. <a href="@link" title="@title" target="_blank">@label</a>', [
      '@link' => 'https://italia.github.io/bootstrap-italia/docs/menu-di-navigazione/header/#header-nav',
      '@title' => 'Read the docs',
      '@label' => 'Docs',
    ]),
    '#open' => FALSE,
    '#group' => 'bootstrap',
    '#weight' => 0,
  ];
  // Navigation header appearance.
  $form['navigation_header']['appearance'] = [
    '#type' => 'details',
    '#title' => t('Appearance'),
    '#open' => FALSE,
    '#group' => 'navigation_header',
  ];
  $form['navigation_header']['appearance']['navigation_header_container_type'] = [
    '#type' => 'select',
    '#title' => t("Container"),
    '#description' => t('Choose container type. Default: container xxl'),
    '#default_value' => theme_get_setting('navigation_header_container_type'),
    '#options' => Helper::getBootstrapContainerType(TRUE),
  ];
  $form['navigation_header']['appearance']['navigation_header_breakpoint_expand'] = [
    '#type' => 'select',
    '#title' => t('Responsive collapsing'),
    '#description' => t("Choose from which breakpoint to expand the navigation bar. Default: Large (>= 992px)"),
    '#default_value' => theme_get_setting('navigation_header_breakpoint_expand'),
    '#options' => Helper::getBreakpoints(TRUE),
  ];
  $form['navigation_header']['appearance']['navigation_header_light_desktop'] = [
    '#type' => 'checkbox',
    '#title' => t('Enable light variant to desktop'),
    '#description' => t("Default: unchecked"),
    '#default_value' => theme_get_setting('navigation_header_light_desktop'),
  ];
  $form['navigation_header']['appearance']['navigation_header_dark_mobile'] = [
    '#type' => 'checkbox',
    '#title' => t('Enable dark variant to mobile'),
    '#description' => t("Default: unchecked"),
    '#default_value' => theme_get_setting('navigation_header_dark_mobile'),
  ];
  $form['navigation_header']['appearance']['navigation_header_sticky'] = [
    '#type' => 'checkbox',
    '#title' => t('Enable sticky on top'),
    '#description' => t("Default: checked"),
    '#default_value' => theme_get_setting('navigation_header_sticky'),
  ];
  $form['navigation_header']['appearance']['navigation_header_sticky_menu_name'] = [
    '#type' => 'textfield',
    '#title' => t('Sticky menu (machine name)'),
    '#description' => t('When sticky on top is enabled, fill in this field with the machine name of the menu to be displayed in the sticky header. Default: main'),
    '#placeholder' => t('menu_machine_name'),
    '#default_value' => theme_get_setting('navigation_header_sticky_menu_name'),
  ];
  // Navigation header menu.
  $form['navigation_header']['navbar'] = [
    '#type' => 'details',
    '#title' => t('Navbar settings'),
    '#open' => FALSE,
    '#group' => 'navigation_header',
  ];
  $form['navigation_header']['navbar']['navigation_header_show_link_description'] = [
    '#type' => 'checkbox',
    '#title' => t("Show the description of the link"),
    '#description' => t("Default: unchecked"),
    '#default_value' => theme_get_setting('navigation_header_show_link_description'),
  ];
  $form['navigation_header']['navbar']['navigation_header_active_items_large'] = [
    '#type' => 'checkbox',
    '#title' => t('Enable "large" variant for active links'),
    '#description' => t("Default: unchecked"),
    '#default_value' => theme_get_setting('navigation_header_active_items_large'),
  ];
  $form['navigation_header']['navbar']['navigation_header_active_items_bold'] = [
    '#type' => 'checkbox',
    '#title' => t('Enable "bold" variant for active links'),
    '#description' => t("Default: unchecked"),
    '#default_value' => theme_get_setting('navigation_header_active_items_bold'),
  ];
  $form['navigation_header']['navbar']['navigation_header_verbose_classes'] = [
    '#type' => 'checkbox',
    '#title' => t("Enable classy mode"),
    '#description' => t("Print multiple classes for each list and each link. Default: unchecked"),
    '#default_value' => theme_get_setting('navigation_header_verbose_classes'),
  ];
  $form['navigation_header']['navbar']['navigation_header_megamenu_columns_lg'] = [
    '#type' => 'select',
    '#title' => t('Megamenu columns in large breakpoint'),
    '#description' => t('Choose how many columns to place the megamenu on.  Default: 3 Columns.'),
    '#default_value' => theme_get_setting('navigation_header_megamenu_columns_lg'),
    '#options' => [
      '' => t('3 Columns'),
      'col-lg-3' => t('4 Columns'),
      'col-lg' => t('All sub menus in one row'),
    ],
  ];
  $form['navigation_header']['navbar']['navigation_header_megamenu_columns_xl'] = [
    '#type' => 'select',
    '#title' => t('Megamenu columns in extra-large breakpoint'),
    '#description' => t('Choose how many columns to place the megamenu on.  Default: 3 Columns.'),
    '#default_value' => theme_get_setting('navigation_header_megamenu_columns_xl'),
    '#options' => [
      '' => t('3 Columns'),
      'col-xl-3' => t('4 Columns'),
      'col-xl-2' => t('6 Columns'),
      'col-xl' => t('All sub menus in one row'),
    ],
  ];

  // Navigation Components ----------------------------------------------------.
  $form['navigation_components'] = [
    '#type' => 'details',
    '#title' => t('Navigation components'),
    '#description' => t("Navigation component settings."),
    '#open' => FALSE,
    '#group' => 'bootstrap',
    '#weight' => 0,
  ];
  // Back to top settings.
  $form['navigation_components']['back_to_top'] = [
    '#type' => 'details',
    '#title' => t('Back to top'),
    '#description' => t('Back to top settings. <a href="@link" title="@title" target="_blank">@label</a>', [
      '@link' => 'https://italia.github.io/bootstrap-italia/docs/menu-di-navigazione/torna-su/',
      '@title' => 'Read the docs',
      '@label' => 'Docs',
    ]),
    '#open' => FALSE,
    '#group' => 'navigation_components',
  ];
  $form['navigation_components']['back_to_top']['back_to_top_enable'] = [
    '#type' => 'checkbox',
    '#title' => t('Enable back to top'),
    '#description' => t("Default: checked"),
    '#default_value' => theme_get_setting('back_to_top_enable'),
  ];
  $form['navigation_components']['back_to_top']['back_to_top_small'] = [
    '#type' => 'checkbox',
    '#title' => t('Use small variant'),
    '#description' => t("Default: unchecked"),
    '#default_value' => theme_get_setting('back_to_top_small'),
  ];
  $form['navigation_components']['back_to_top']['back_to_top_dark'] = [
    '#type' => 'checkbox',
    '#title' => t('Adjust for dark background'),
    '#description' => t("Default: unchecked"),
    '#default_value' => theme_get_setting('back_to_top_dark'),
  ];
  $form['navigation_components']['back_to_top']['back_to_top_shadow'] = [
    '#type' => 'checkbox',
    '#title' => t("Enable shadow"),
    '#description' => t("Default: checked"),
    '#default_value' => theme_get_setting('back_to_top_shadow'),
  ];
  // Breadcrumbs settings.
  $form['navigation_components']['breadcrumb'] = [
    '#type' => 'details',
    '#title' => t('Breadcrumb'),
    '#description' => t('Breadcrumb settings. <a href="@link" title="@title" target="_blank">@label</a>', [
      '@link' => 'https://italia.github.io/bootstrap-italia/docs/menu-di-navigazione/breadcrumbs/',
      '@title' => 'Read the docs',
      '@label' => 'Docs',
    ]),
    '#open' => FALSE,
    '#group' => 'navigation_components',
  ];
  $form['navigation_components']['breadcrumb']['breadcrumb_include_current_page'] = [
    '#type' => 'checkbox',
    '#title' => t('Include the current page'),
    '#description' => t('If checked, include the current page as the last segment in the breadcrumb. Leave unchecked if you use a module to handle the breadcrumb and use the third-party module options. Default: checked'),
    '#default_value' => theme_get_setting('breadcrumb_include_current_page'),
  ];
  $form['navigation_components']['breadcrumb']['breadcrumb_dark_background'] = [
    '#type' => 'checkbox',
    '#title' => t('Dark Background'),
    '#description' => t('Turn on dark background. Default: unchecked'),
    '#default_value' => theme_get_setting('breadcrumb_dark_background'),
  ];
  $form['navigation_components']['breadcrumb']['breadcrumb_icon'] = [
    '#type' => 'checkbox',
    '#title' => t('Show item icon'),
    '#description' => t('If checked, displays an icon before items. Default: unchecked'),
    '#default_value' => theme_get_setting('breadcrumb_icon'),
  ];
  $form['navigation_components']['breadcrumb']['breadcrumb_separator'] = [
    '#type' => 'select',
    '#title' => t('Separator'),
    '#description' => t('Choose the element separator. Default: "/".'),
    '#default_value' => theme_get_setting('breadcrumb_separator'),
    '#options' => [
      '/' => '/',
      '>' => '>',
    ],
  ];
  // Menu in sidebar first.
  $form['navigation_components']['sidebar_first_menu'] = [
    '#type' => 'details',
    '#title' => t('First sidebar menu'),
    '#description' => t('Default settings for all menus in first sidebar region. <a href="@link" title="@title" target="_blank">@label</a>', [
      '@link' => 'https://italia.github.io/bootstrap-italia/docs/organizzare-i-contenuti/liste/#liste-per-men%C3%B9-di-navigazione',
      '@title' => 'Read the docs',
      '@label' => 'Docs',
    ]),
    '#open' => FALSE,
    '#group' => 'navigation_components',
  ];
  $form['navigation_components']['sidebar_first_menu']['sidebar_first_menu_dark'] = [
    '#type' => 'checkbox',
    '#title' => t('Enable dark variant'),
    '#description' => t('Default: unchecked.'),
    '#default_value' => theme_get_setting('sidebar_first_menu_dark'),
  ];
  $form['navigation_components']['sidebar_first_menu']['sidebar_first_menu_show_link_description'] = [
    '#type' => 'checkbox',
    '#title' => t("Show the description of the link"),
    '#description' => t("Default: unchecked"),
    '#default_value' => theme_get_setting('sidebar_first_menu_show_link_description'),
  ];
  $form['navigation_components']['sidebar_first_menu']['sidebar_first_menu_first_level_large'] = [
    '#type' => 'checkbox',
    '#title' => t('Enable "large" variant on first level'),
    '#description' => t("Default: checked"),
    '#default_value' => theme_get_setting('sidebar_first_menu_first_level_large'),
  ];
  $form['navigation_components']['sidebar_first_menu']['sidebar_first_menu_first_level_bold'] = [
    '#type' => 'checkbox',
    '#title' => t('Enable "bold" variant on first level'),
    '#description' => t("Default: checked"),
    '#default_value' => theme_get_setting('sidebar_first_menu_first_level_bold'),
  ];
  // Menu in sidebar second.
  $form['navigation_components']['sidebar_second_menu'] = [
    '#type' => 'details',
    '#title' => t('Second sidebar menu'),
    '#description' => t('Default settings for all menus in second sidebar region. <a href="@link" title="@title" target="_blank">@label</a>', [
      '@link' => 'https://italia.github.io/bootstrap-italia/docs/organizzare-i-contenuti/liste/#liste-per-men%C3%B9-di-navigazione',
      '@title' => 'Read the docs',
      '@label' => 'Docs',
    ]),
    '#open' => FALSE,
    '#group' => 'navigation_components',
  ];
  $form['navigation_components']['sidebar_second_menu']['sidebar_second_menu_dark'] = [
    '#type' => 'checkbox',
    '#title' => t('Enable dark variant'),
    '#description' => t('Default: unchecked.'),
    '#default_value' => theme_get_setting('sidebar_second_menu_dark'),
  ];
  $form['navigation_components']['sidebar_second_menu']['sidebar_second_menu_show_link_description'] = [
    '#type' => 'checkbox',
    '#title' => t("Show the description of the link"),
    '#description' => t("Default: unchecked"),
    '#default_value' => theme_get_setting('sidebar_second_menu_show_link_description'),
  ];
  $form['navigation_components']['sidebar_second_menu']['sidebar_second_menu_first_level_large'] = [
    '#type' => 'checkbox',
    '#title' => t('Enable "large" variant on first level'),
    '#description' => t("Default: unchecked"),
    '#default_value' => theme_get_setting('sidebar_second_menu_first_level_large'),
  ];
  $form['navigation_components']['sidebar_second_menu']['sidebar_second_menu_first_level_bold'] = [
    '#type' => 'checkbox',
    '#title' => t('Enable "bold" variant on first level'),
    '#description' => t("Default: unchecked"),
    '#default_value' => theme_get_setting('sidebar_second_menu_first_level_bold'),
  ];
  // Pagination.
  $form['navigation_components']['pagination'] = [
    '#type' => 'details',
    '#title' => t('Pagination'),
    '#description' => t('Default settings for all pager. <a href="@link" title="@title" target="_blank">@label</a>', [
      '@link' => 'https://italia.github.io/bootstrap-italia/docs/componenti/paginazione/',
      '@title' => 'Read the docs',
      '@label' => 'Docs',
    ]),
    '#open' => FALSE,
    '#group' => 'navigation_components',
  ];
  $form['navigation_components']['pagination']['pager_alignment'] = [
    '#type' => 'select',
    '#title' => t('Pager alignment'),
    '#description' => t('Choose pager alignment. Default "left"'),
    '#default_value' => theme_get_setting('pager_alignment'),
    '#options' => [
      '' => t('Default (left)'),
      'center' => t('Center'),
      'end' => t('Right'),
    ],
  ];
  $form['navigation_components']['pagination']['pager_responsive'] = [
    '#type' => 'checkbox',
    '#title' => t('Enable responsive pager'),
    '#description' => t("Default: checked"),
    '#default_value' => theme_get_setting('pager_responsive'),
  ];
  $form['navigation_components']['pagination']['pager_jump_to_page'] = [
    '#type' => 'checkbox',
    '#title' => t('Enable "jump to page" feature'),
    '#description' => t("Default: unchecked"),
    '#default_value' => theme_get_setting('pager_jump_to_page'),
  ];
  $form['navigation_components']['pagination']['pager_show_first_last_page_link'] = [
    '#type' => 'checkbox',
    '#title' => t('Show first and last link in pager'),
    '#description' => t("Default: checked"),
    '#default_value' => theme_get_setting('pager_show_first_last_page_link'),
  ];
  $form['navigation_components']['pagination']['pager_text_controls'] = [
    '#type' => 'checkbox',
    '#title' => t('Show textual pager (no icons)'),
    '#description' => t("Default: unchecked"),
    '#default_value' => theme_get_setting('pager_text_controls'),
  ];
  $form['navigation_components']['pagination']['pager_show_total_pages'] = [
    '#type' => 'checkbox',
    '#title' => t('Show total page info'),
    '#description' => t("Default: unchecked"),
    '#default_value' => theme_get_setting('pager_show_total_pages'),
  ];

  // Content ------------------------------------------------------------------.
  $form['content'] = [
    '#type' => 'details',
    '#title' => t('Content'),
    '#description' => t("This section shows utilities for organizing content, texts, lists, tables, and images."),
    '#open' => FALSE,
    '#group' => 'bootstrap',
    '#weight' => 0,
  ];
  // Content appearance.
  $form['content']['appearance'] = [
    '#type' => 'details',
    '#title' => t('Appearance'),
    '#open' => FALSE,
    '#group' => 'content',
  ];
  $form['content']['appearance']['content_container_type'] = [
    '#type' => 'select',
    '#title' => t("Container"),
    '#description' => t('Choose container type. Default: container xxl'),
    '#default_value' => theme_get_setting('content_container_type'),
    '#options' => Helper::getBootstrapContainerType(TRUE),
  ];
  $form['content']['appearance']['content_padding_bottom'] = [
    '#type' => 'select',
    '#title' => t("Content padding bottom"),
    '#description' => t('Add padding at the end of the content. Default: Unset'),
    '#default_value' => theme_get_setting('content_padding_bottom'),
    '#options' =>
      ['' => t('Unset')] + Spacing::getPaddingBottom(TRUE),
  ];
  $form['content']['appearance']['content_margin_bottom'] = [
    '#type' => 'select',
    '#title' => t("Content margin bottom"),
    '#description' => t('Add margin at the end of the content. Default: Unset'),
    '#default_value' => theme_get_setting('content_margin_bottom'),
    '#options' =>
      ['' => t('Unset')] + Spacing::getMarginBottom(TRUE),
  ];
  $form['content']['appearance']['show_main_content_in_front'] = [
    '#type' => 'checkbox',
    '#title' => t('Main content in front page'),
    '#description' => t('If checked, shows main content region in home page. Default: unchecked'),
    '#default_value' => theme_get_setting('show_main_content_in_front'),
  ];
  // Page title.
  $form['content']['page_title'] = [
    '#type' => 'details',
    '#title' => t('Page title'),
    '#open' => FALSE,
    '#group' => 'content',
  ];
  $form['content']['page_title']['page_title_semibold'] = [
    '#type' => 'checkbox',
    '#title' => t('Page title semibold variant'),
    '#description' => t('If checked, applies the "semibold" style to the page title. Default: unchecked'),
    '#default_value' => theme_get_setting('page_title_semibold'),
  ];
  // Editor nav tabs.
  $form['content']['editor_nav_tabs'] = [
    '#type' => 'details',
    '#title' => t('Editor nav tabs'),
    '#description' => t('Settings for editor nav tabs in content. <a href="@link" title="@title" target="_blank">@label</a>', [
      '@link' => 'https://italia.github.io/bootstrap-italia/docs/componenti/tab/',
      '@title' => 'Read the docs',
      '@label' => 'Docs',
    ]),
    '#open' => FALSE,
    '#group' => 'content',
  ];
  $form['content']['editor_nav_tabs']['editor_nav_tabs_scrollable'] = [
    '#type' => 'checkbox',
    '#title' => t('Scrollable'),
    '#description' => t('Enable scroll in nav tabs. Default: checked.'),
    '#default_value' => theme_get_setting('editor_nav_tabs_scrollable'),
  ];
  // Fields settings.
  $form['content']['field'] = [
    '#type' => 'details',
    '#title' => t('Fields'),
    '#description' => t('Settings for all fields.'),
    '#open' => FALSE,
    '#group' => 'content',
  ];
  $form['content']['field']['field_label_bold'] = [
    '#type' => 'checkbox',
    '#title' => t('Label bold.'),
    '#description' => t('Enable to apply bold to label. Default: unchecked.'),
    '#default_value' => theme_get_setting('field_label_bold'),
  ];
  $form['content']['field']['field_label_separator'] = [
    '#type' => 'textfield',
    '#title' => t('Separator for inline label.'),
    '#description' => t("Default: ':'"),
    '#default_value' => theme_get_setting('field_label_separator'),
  ];
  $form['content']['field']['field_container_vertical_padding'] = [
    '#type' => 'select',
    '#title' => t('Vertical padding'),
    '#description' => t('Apply extra vertical padding to all fields. Default: "Unset".'),
    '#default_value' => theme_get_setting('field_container_vertical_padding'),
    '#options' =>
      ['' => t('Unset')] + Spacing::getPaddingVertical(TRUE),
  ];
  $form['content']['field']['field_container_vertical_margin'] = [
    '#type' => 'select',
    '#title' => t('Vertical margin'),
    '#description' => t('Apply extra vertical margin to all fields. Default: "Unset".'),
    '#default_value' => theme_get_setting('field_container_vertical_margin'),
    '#options' =>
      ['' => t('Unset')] + Spacing::getMarginVertical(TRUE),
  ];
  // File Attachments.
  $form['content']['file'] = [
    '#type' => 'details',
    '#title' => t('File'),
    '#open' => FALSE,
    '#group' => 'content',
  ];
  $form['content']['file']['file_link_default_icon'] = [
    '#type' => 'textfield',
    '#title' => t('Default icon'),
    '#description' => t('Choose an icon from this <a href="@link" title="@title" target="_blank">@label</a>. Default: "it-clip".', [
      '@link' => 'https://italia.github.io/bootstrap-italia/docs/utilities/icone/#lista-delle-icone-disponibili',
      '@title' => 'View all icons',
      '@label' => 'icons list',
    ]),
    '#default_value' => theme_get_setting('file_link_default_icon') ?: 'it-clip',
  ];
  $form['content']['file']['file_link_icon_autodetect'] = [
    '#type' => 'checkbox',
    '#title' => t('Automatically detects file type'),
    '#description' => t('If checked, it automatically recognizes the file type and sets a consistent icon. Default: unchecked.'),
    '#default_value' => theme_get_setting('file_link_icon_autodetect') ?: FALSE,
  ];
  $form['content']['file']['file_link_show_size'] = [
    '#type' => 'checkbox',
    '#title' => t('Shows the file size'),
    '#description' => t('If checked, the file size will be displayed. Default: checked.'),
    '#default_value' => theme_get_setting('file_link_show_size') ?: TRUE,
  ];
  // Images settings.
  $form['content']['images'] = [
    '#type' => 'details',
    '#title' => t('Images'),
    '#description' => t('Settings for all images. <a href="@link" title="@title" target="_blank">@label</a>', [
      '@link' => 'https://italia.github.io/bootstrap-italia/docs/organizzare-i-contenuti/immagini/',
      '@title' => 'Read the docs',
      '@label' => 'Docs',
    ]),
    '#open' => FALSE,
    '#group' => 'content',
  ];
  $form['content']['images']['image_fluid'] = [
    '#type' => 'checkbox',
    '#title' => t('Image responsive.'),
    '#description' => t('Enable image responsive feature. Default: checked.'),
    '#default_value' => theme_get_setting('image_fluid'),
  ];
  $form['content']['images']['image_rounded'] = [
    '#type' => 'checkbox',
    '#title' => t('Rounded border.'),
    '#description' => t('Enable image rounded border. Default: unchecked.'),
    '#default_value' => theme_get_setting('image_rounded'),
  ];
  $form['content']['images']['image_border'] = [
    '#type' => 'select',
    '#title' => t('Image border color'),
    '#description' => t('Choose border style. Default: "None".'),
    '#default_value' => theme_get_setting('image_border'),
    '#options' =>
      ['' => t('None')] +
    Color::getTheme(TRUE) +
    Color::getMonochromatic(TRUE),
  ];

  // Tables.
  $form['content']['tables'] = [
    '#type' => 'details',
    '#title' => t('Tables'),
    '#description' => t('Default settings for all tables. <a href="@link" title="@title" target="_blank">@label</a>', [
      '@link' => 'https://italia.github.io/bootstrap-italia/docs/organizzare-i-contenuti/tabelle/',
      '@title' => 'Read the docs',
      '@label' => 'Docs',
    ]),
    '#open' => FALSE,
    '#group' => 'content',
  ];
  $form['content']['tables']['table_striped'] = [
    '#type' => 'checkbox',
    '#title' => t('Striped'),
    '#description' => t('Enable zebra-striping to any table row within the "tbody". Default: checked.'),
    '#default_value' => theme_get_setting('table_striped'),
  ];
  $form['content']['tables']['table_striped_columns'] = [
    '#type' => 'checkbox',
    '#title' => t('Striped columns'),
    '#description' => t('Enable zebra-striping to any table column. (Bootstrap >= 5.2) Default: unchecked.'),
    '#default_value' => theme_get_setting('table_striped_columns'),
  ];
  $form['content']['tables']['table_bg'] = [
    '#type' => 'select',
    '#title' => t('Table background.'),
    '#description' => t('Choose background color. Default: "Default"'),
    '#default_value' => theme_get_setting('table_bg'),
    '#options' =>
      ['' => t('Default')] +
    Color::getTheme(TRUE) +
    Color::getPantone(TRUE) +
    Color::getMonochromatic(TRUE) +
    Color::getMode(TRUE),
  ];
  $form['content']['tables']['table_hover'] = [
    '#type' => 'checkbox',
    '#title' => t('Hovered'),
    '#description' => t('Enable a hover state on table rows within a "tbody". Note: hoverable rows can also be combined with the striped rows variant. Default: unchecked.'),
    '#default_value' => theme_get_setting('table_hover'),
  ];
  $form['content']['tables']['table_bordered'] = [
    '#type' => 'checkbox',
    '#title' => t('Bordered'),
    '#description' => t('Enable borders on all sides of the table and cells. Default: unchecked.'),
    '#default_value' => theme_get_setting('table_bordered'),
  ];
  $form['content']['tables']['table_border_color'] = [
    '#type' => 'select',
    '#title' => t('Table border color.'),
    '#description' => t('Choose table border color. Default: "Default"'),
    '#default_value' => theme_get_setting('table_border_color'),
    '#options' => ['' => t('Default')] + Color::getAll(TRUE),
  ];
  $form['content']['tables']['table_borderless'] = [
    '#type' => 'checkbox',
    '#title' => t('Borderless'),
    '#description' => t('Enable to show all tables without borders. Note: bordered table can also be combined with the borderless variant. Default: unchecked.'),
    '#default_value' => theme_get_setting('table_borderless'),
  ];
  $form['content']['tables']['table_sm'] = [
    '#type' => 'checkbox',
    '#title' => t('Small tables'),
    '#description' => t('Enable to make any table more compact by cutting all cell padding in half. Default: unchecked.'),
    '#default_value' => theme_get_setting('table_sm'),
  ];
  $form['content']['tables']['table_align_middle'] = [
    '#type' => 'checkbox',
    '#title' => t('Vertical align middle'),
    '#description' => t('Enable to adjust vertical alignment. Default: unchecked.'),
    '#default_value' => theme_get_setting('table_align_middle'),
  ];
  $form['content']['tables']['table_thead_variant'] = [
    '#type' => 'select',
    '#title' => t('THead background.'),
    '#description' => t('Default: "Dark".'),
    '#default_value' => theme_get_setting('table_thead_variant'),
    '#options' => ['' => t('Default')] + Color::getMode(TRUE),
  ];
  $form['content']['tables']['table_caption_top'] = [
    '#type' => 'checkbox',
    '#title' => t('Caption top'),
    '#description' => t('Enable to put the caption on the top of the table. Default: checked.'),
    '#default_value' => theme_get_setting('table_caption_top'),
  ];
  $form['content']['tables']['table_responsive'] = [
    '#type' => 'select',
    '#title' => t('Table responsive'),
    '#description' => t('Enable horizontally scrolling tables. Use responsive{-sm|-md|-lg|-xl|-xxl} as needed to create responsive tables up to a particular breakpoint. From that breakpoint and up, the table will behave normally and not scroll horizontally. Default "Responsive to all breakpoints"'),
    '#default_value' => theme_get_setting('table_responsive'),
    '#options' => [
      '' => t('Disabled'),
      'table-responsive' => t('Responsive to all breakpoints'),
      'table-responsive-sm' => t('Responsive sm'),
      'table-responsive-md' => t('Responsive md'),
      'table-responsive-lg' => t('Responsive lg'),
      'table-responsive-xl' => t('Responsive xl'),
      'table-responsive-xxl' => t('Responsive xxl'),
    ],
  ];

  // Forms --------------------------------------------------------------------.
  $form['forms'] = [
    '#type' => 'details',
    '#title' => t('Forms'),
    '#description' => t("Forms settings."),
    '#open' => FALSE,
    '#group' => 'bootstrap',
    '#weight' => 0,
  ];
  // Fields.
  $form['forms']['fields'] = [
    '#type' => 'details',
    '#title' => t('Form fields'),
    '#description' => t('Form fields settings'),
    '#open' => FALSE,
    '#group' => 'forms',
  ];
  $form['forms']['fields']['forms_field_label_required_mark'] = [
    '#type' => 'checkbox',
    '#title' => t('Show an asterisk after the label when the field is required.'),
    '#default_value' => theme_get_setting('forms_field_label_required_mark'),
  ];
  // Actions.
  $form['forms']['action'] = [
    '#type' => 'details',
    '#title' => t('Form actions'),
    '#description' => t('Default settings for all forms actions. <a href="@link" title="@title" target="_blank">@label</a>', [
      '@link' => 'https://italia.github.io/bootstrap-italia/docs/form/introduzione/',
      '@title' => 'Read the docs',
      '@label' => 'Docs',
    ]),
    '#open' => FALSE,
    '#group' => 'forms',
  ];
  $form['forms']['action']['forms_action_alignment'] = [
    '#type' => 'select',
    '#title' => t('Alignment'),
    '#description' => t('Choose where to display the submit buttons. Default: "Left"'),
    '#default_value' => theme_get_setting('forms_action_alignment'),
    '#options' => [
      'left' => t('Left'),
      'center' => t('Center'),
      'right' => t('Right'),
    ],
  ];
  $form['forms']['action']['forms_action_spacing'] = [
    '#type' => 'checkbox',
    '#title' => t('Automatic spacing'),
    '#description' => t('Enable to add automatic padding. Disable for custom spacing. Note: if you use webform module, use webform ui for this setting.  Default: checked'),
    '#default_value' => theme_get_setting('forms_action_spacing'),
  ];

  // Footer -------------------------------------------------------------------.
  $form['footer'] = [
    '#type' => 'details',
    '#title' => t('Footer'),
    '#description' => t("Footer settings"),
    '#open' => FALSE,
    '#group' => 'bootstrap',
    '#weight' => 0,
  ];
  // Footer appearance.
  $form['footer']['appearance'] = [
    '#type' => 'details',
    '#title' => t('Appearance'),
    '#open' => FALSE,
    '#group' => 'footer',
  ];
  $form['footer']['appearance']['footer_container_type'] = [
    '#type' => 'select',
    '#title' => t("Container"),
    '#description' => t('Choose container type. Default: container xxl'),
    '#default_value' => theme_get_setting('footer_container_type'),
    '#options' => Helper::getBootstrapContainerType(TRUE),
  ];

  // Libraries Settings -------------------------------------------------------.
  // To load styles into ckeditor correctly,
  // check the value of 'ckeditor_stylesheets' in the 'theme.info.yml' file.
  $form['libraries_settings'] = [
    '#type' => 'details',
    '#title' => t('Libraries'),
    '#description' => t('Customize library source.<br /> To load styles into ckeditor correctly, check the value of <code class="color-success">ckeditor_stylesheets</code> in the <code class="color-success">your-sub-theme.info.yml</code> file.<br /> <strong>You need to clear the cache if you change these settings</strong>. <a href="@link" title="@title" target="_blank">@label</a>', [
      '@link' => 'https://italia.github.io/bootstrap-italia/docs/come-iniziare/introduzione/',
      '@title' => 'Read the docs',
      '@label' => 'Docs',
    ]),
    '#open' => FALSE,
    '#group' => 'bootstrap',
    '#weight' => 20,
  ];
  $form['libraries_settings']['libraries_type'] = [
    '#type' => 'select',
    '#title' => t("Choose libraries type"),
    '#description' => t("Default: vanilla libraries"),
    '#default_value' => theme_get_setting('libraries_type'),
    '#options' => Libraries::getLibraries(),
  ];
  $form['libraries_settings']['libraries_fonts_load_from_css'] = [
    '#type' => 'checkbox',
    '#title' => t("My library loads fonts via css."),
    '#description' => t('If your library loads fonts via css (<a href="@link" title="@title" target="_blank">@label</a>), check this option; you will get a small performance boost when loading fonts. Default: unchecked.', [
      '@link' => 'https://italia.github.io/bootstrap-italia/docs/come-iniziare/introduzione/#fonts',
      '@title' => 'Read the docs',
      '@label' => 'Docs',
    ]),
    '#default_value' => theme_get_setting('libraries_fonts_load_from_css'),
  ];

  // Vanilla Settings.
  $form['libraries_settings']['vanilla'] = [
    '#type' => 'details',
    '#title' => t('Vanilla Settings'),
    '#description' => t('Download <code class="color-success">bootstrap-italia</code> libraries and unzip into <code class="color-success">your-sub-theme/dist/</code>. <a href="@link" title="@title" target="_blank">@label</a>', [
      '@link' => 'https://italia.github.io/bootstrap-italia/docs/come-iniziare/introduzione/#caricare-la-libreria',
      '@title' => 'Read the docs',
      '@label' => 'Docs',
    ]),
    '#open' => FALSE,
    '#group' => 'libraries_settings',
  ];
  $form['libraries_settings']['vanilla']['libraries_vanilla_bundle'] = [
    '#type' => 'checkbox',
    '#title' => t("Use the bundle build."),
    '#description' => t("Default: checked"),
    '#default_value' => theme_get_setting('libraries_vanilla_bundle'),
  ];

  // CDN Settings.
  $form['libraries_settings']['cdn'] = [
    '#type' => 'details',
    '#title' => t('CDN Settings'),
    '#description' => t('If you use a third-party CDN, check that you are compliant with the GDPR. For example use: <a href="@cdn" title="Read the docs" target="_blank">@cdn</a>', ['@cdn' => 'https://www.jsdelivr.com/package/npm/bootstrap-italia?path=dist']),
    '#open' => FALSE,
    '#group' => 'libraries_settings',
  ];
  $form['libraries_settings']['cdn']['libraries_cdn_css'] = [
    '#type' => 'textfield',
    '#title' => t('CSS from CDN'),
    '#description' => t("Example: @cdn. Default: empty", ['@cdn' => 'https://cdn.domain.gov.it/bootstrap-italia@<version>/dist/css/bootstrap-italia.min.css']),
    '#placeholder' => t('/libraries/bootstrap-italia/dist/css/bootstrap-italia.min.css'),
    '#default_value' => theme_get_setting('libraries_cdn_css'),
  ];
  $form['libraries_settings']['cdn']['libraries_cdn_js'] = [
    '#type' => 'textfield',
    '#title' => t('JS from CDN'),
    '#description' => t("Example: @cdn. Default: empty", ['@cdn' => 'https://cdn.domain.gov.it/bootstrap-italia@<version>/dist/js/bootstrap-italia.bundle.min.js']),
    '#placeholder' => t('/libraries/bootstrap-italia/dist/js/bootstrap-italia.bundle.min.js'),
    '#default_value' => theme_get_setting('libraries_cdn_js'),
  ];
  $form['libraries_settings']['cdn']['libraries_cdn_minified'] = [
    '#type' => 'checkbox',
    '#title' => t('Check if you use minified libraries.'),
    '#description' => t("Default: checked"),
    '#default_value' => theme_get_setting('libraries_cdn_minified'),
  ];
  $form['libraries_settings']['cdn']['libraries_cdn_fonts'] = [
    '#type' => 'textfield',
    '#title' => t('Fonts from CDN'),
    '#description' => t("Example: @cdn. Default: empty", ['@cdn' => 'https://cdn.domain.gov.it/bootstrap-italia@<version>/dist/fonts']),
    '#placeholder' => t('/libraries/bootstrap-italia/dist/fonts'),
    '#default_value' => theme_get_setting('libraries_cdn_fonts'),
  ];
  $form['libraries_settings']['cdn']['libraries_cdn_icons'] = [
    '#type' => 'textfield',
    '#title' => t('Icons from CDN'),
    '#description' => t("Example: @cdn. Default: empty", ['@cdn' => 'https://cdn.domain.gov.it/bootstrap-italia@<version>/dist/svg/sprites.svg']),
    '#placeholder' => t('/libraries/bootstrap-italia/dist/svg/sprites.svg'),
    '#default_value' => theme_get_setting('libraries_cdn_icons'),
  ];

  // PA Website Validator -----------------------------------------------------.
  $form['pwv'] = [
    '#type' => 'details',
    '#title' => t('PA Website Validator'),
    '#description' => t('The theme automatically sets some data-attributes without you having to override templates. In the table below a summary of the automatically set data-attributes. You have to do everything else.'),
    '#open' => FALSE,
    '#group' => 'bootstrap',
    '#weight' => 20,
  ];
  $form['pwv']['pa_website_validator_type'] = [
    '#type' => 'select',
    '#title' => t('Site type'),
    '#description' => t(
      '<p>Settings for <a href="@mSites" title="Read the docs" target="_blank">Municipality sites</a> or <a href="@sSites" title="Read the docs" target="_blank">School sites</a>, or leave unset for generic sites.</p>',
      [
        '@mSites' => 'https://docs.italia.it/italia/designers-italia/app-valutazione-modelli-docs/it/versione-attuale/requisiti-e-modalita-verifica-comuni.html',
        '@sSites' => 'https://docs.italia.it/italia/designers-italia/app-valutazione-modelli-docs/it/versione-attuale/requisiti-e-modalita-verifica-scuole.html',
      ]
    ),
    '#default_value' => theme_get_setting('pa_website_validator_type'),
    '#options' => [
      '' => t('Unset'),
      'municipality' => t('Municipality'),
      'school' => t('School'),
    ],
  ];
  // Municipality.
  $form['pwv']['municipality'] = [
    '#type' => 'details',
    '#title' => t('Municipality'),
    '#open' => FALSE,
    '#group' => 'pwv',
  ];
  $form['pwv']['municipality']['docs'] = [
    '#type' => 'markup',
    '#markup' => t('
     <table>
      <thead><tr><th>Code</th><th>Note</th></tr></thead>
      <tbody>
        <tr>
          <td>C.SI.1.1</td>
          <td>You have to do it. To set <code class="color-success">data-element: "all-services"</code> you can use a hook or the module <a href="https://www.drupal.org/project/menu_link_attributes" target="_blank">Menu link attributes</a>.</td>
        </tr>
        <tr>
          <td class="color-success">C.SI.1.2</td>
          <td>Provided by the theme.</td>
        </tr>
        <tr>
          <td>C.SI.1.3</td>
          <td>You have to do it. To set <code class="color-success">data-element: "all-services"</code> you can use a hook or the module <a href="https://www.drupal.org/project/menu_link_attributes" target="_blank">Menu link attributes</a>.</td>
        </tr>
        <tr>
          <td class="color-error">C.SI.1.4</td>
          <td>Only for Wordpress.</td>
        </tr>
        <tr>
          <td>C.SI.1.5</td>
          <td>You have to do it. To set <code class="color-success">data-element: "all-topics"</code> you can use a hook or the module <a href="https://www.drupal.org/project/menu_link_attributes" target="_blank">Menu link attributes</a>.</td>
        </tr>
        <tr>
          <td class="color-success">C.SI.1.6</td>
          <td>Provided by the theme.</td>
        </tr>
        <tr>
          <td>C.SI.1.7</td>
          <td>You have to do it. To set <code class="color-success">data-element: "all-services"</code> you can use a hook or the module <a href="https://www.drupal.org/project/menu_link_attributes" target="_blank">Menu link attributes</a>.</td>
        </tr>
        <tr>
          <td>C.SI.2.1</td>
          <td>You have to do it. To set <code class="color-success">data-element: "all-services"</code> you can use a hook or the module <a href="https://www.drupal.org/project/menu_link_attributes" target="_blank">Menu link attributes</a>.</td>
        </tr>
        <tr>
          <td>C.SI.2.2</td>
          <td>You have to do it. To set <code class="color-success">data-element: "all-services"</code> you can use a hook or the module <a href="https://www.drupal.org/project/menu_link_attributes" target="_blank">Menu link attributes</a>.</td>
        </tr>
        <tr>
          <td>C.SI.2.3</td>
          <td>You have to do it. To set <code class="color-success">data-element: "faq"</code> you can use a hook or the module <a href="https://www.drupal.org/project/menu_link_attributes" target="_blank">Menu link attributes</a>.</td>
        </tr>
        <tr>
          <td>C.SI.2.4</td>
          <td>You have to do it. To set <code class="color-success">data-element: "report-inefficiency"</code> you can use a hook or the module <a href="https://www.drupal.org/project/menu_link_attributes" target="_blank">Menu link attributes</a>.</td>
        </tr>
        <tr>
          <td>C.SI.2.5</td>
          <td>You have to do it. To set <code class="color-success">data-element: "[management,all-services,news,live]"</code> you can use a hook or the module <a href="https://www.drupal.org/project/menu_link_attributes" target="_blank">Menu link attributes</a>.</td>
        </tr>
        <tr>
          <td>C.SI.3.1</td>
          <td>You have to do it.</td>
        </tr>
        <tr>
          <td>C.SI.3.2</td>
          <td>You have to do it.  To set <code class="color-success">data-element: "accessibility-link"</code> you can use a hook or the module <a href="https://www.drupal.org/project/menu_link_attributes" target="_blank">Menu link attributes</a>.</td>
        </tr>
        <tr>
          <td>C.SI.3.3</td>
          <td>You have to do it. To set <code class="color-success">data-element: "privacy-policy-link"</code> you can use a hook or the module <a href="https://www.drupal.org/project/menu_link_attributes" target="_blank">Menu link attributes</a>.</td>
        </tr>
        <tr>
          <td class="color-warning">C.SI.5.1</td>
          <td>You have to do it. Data-element <code class="color-success">data-element="personal-area-login"</code> is provided by the theme.</td>
        </tr>
        <tr>
          <td class="color-warning">C.SI.5.2</td>
          <td>You have to do it. Data-element <code class="color-success">data-element="personal-area-login"</code> is provided by the theme.</td>
        </tr>
        <tr>
          <td>R.SI.1.1</td>
          <td>You have to do it. To set <code class="color-success">data-element: "all-services"</code> you can use a hook or the module <a href="https://www.drupal.org/project/menu_link_attributes" target="_blank">Menu link attributes</a>.</td>
        </tr>
      </tbody>
     </table>
    '),
  ];
  // School.
  $form['pwv']['school'] = [
    '#type' => 'details',
    '#title' => t('School'),
    '#open' => FALSE,
    '#group' => 'pwv',
  ];
  $form['pwv']['school']['docs'] = [
    '#type' => 'markup',
    '#markup' => t('
     <table>
      <thead><tr><th>Code</th><th>Note</th></tr></thead>
      <tbody>
        <tr>
          <td>C.SC.1.1</td>
          <td>You have to do it. To set <code class="color-success">data-element: "service-type"</code> you can use a hook or the module <a href="https://www.drupal.org/project/menu_link_attributes" target="_blank">Menu link attributes</a>.</td>
        </tr>
        <tr>
          <td class="color-success">C.SC.1.2</td>
          <td>Provided by the theme.</td>
        </tr>
        <tr>
          <td class="color-error">C.SC.1.3</td>
          <td>Only for Wordpress.</td>
        </tr>
        <tr>
          <td class="color-success">C.SC.1.4</td>
          <td>Provided by the theme.</td>
        </tr>
        <tr>
          <td>C.SC.1.5</td>
          <td>You have to do it. To set <code class="color-success">data-element-child: "school-submenu"</code> you can use a hook or the module <a href="https://www.drupal.org/project/menu_link_attributes" target="_blank">Menu link attributes</a>.</td>
        </tr>
        <tr>
          <td>C.SC.2.1</td>
          <td>You have to do it. To set <code class="color-success">data-element: "privacy-policy-link"</code> you can use a hook or the module <a href="https://www.drupal.org/project/menu_link_attributes" target="_blank">Menu link attributes</a>.</td>
        </tr>
        <tr>
          <td>C.SC.2.2</td>
          <td>You have to do it. To set <code class="color-success">data-element: "accessibility-link"</code> you can use a hook or the module <a href="https://www.drupal.org/project/menu_link_attributes" target="_blank">Menu link attributes</a>.</td>
        </tr>
        <tr>
          <td>C.SC.2.3</td>
          <td>You have to do it.</td>
        </tr>
        <tr>
          <td>C.SC.3.1</td>
          <td>You have to do it.</td>
        </tr>
        <tr>
          <td>R.SC.1.1</td>
          <td>You have to do it. Customize <code class="color-success">/themes/contrib/bootstrap_italia/templates/layout/header/_partial.header-center.html.twig</code> template and use an hook <code class="color-warning">theme_form_search_block_x</code> to alter form.</td>
        </tr>
        <tr>
          <td>R.SC.1.2</td>
          <td>You have to do it. To set <code class="color-success">data-element: "service-type"</code> you can use a hook or the module <a href="https://www.drupal.org/project/menu_link_attributes" target="_blank">Menu link attributes</a>.</td>
        </tr>
        <tr>
          <td>4.12</td>
          <td>You have to do it.</td>
        </tr>
      </tbody>
    </table>
    '),
  ];

  $form['#validate'][] = 'bootstrap_italia_form_system_theme_settings_validate';
}

/**
 * Implements hook_form_system_theme_settings_validate().
 *
 * Ref: https://www.drupal.org/project/coding_standards/issues/3056368
 *
 * @phpstan-ignore missingType.iterableValue
 */
function bootstrap_italia_form_system_theme_settings_validate(array &$form, FormStateInterface $form_state): void {
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
