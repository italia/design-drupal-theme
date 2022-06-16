<?php

/**
 * @file
 * Theme settings.
 */

use Drupal\bootstrap_italia\Helper\Helper;
use Drupal\bootstrap_italia\Helper\Libraries;
use Drupal\Core\Form\FormStateInterface;

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

  // Main vertical tabs.
  $form['bootstrap'] = [
    '#type' => 'vertical_tabs',
    '#weight' => -10,
  ];

  // Header slim --------------------------------------------------------------.
  $form['slim_header'] = [
    '#type' => 'details',
    '#title' => t('Slim header'),
    '#description' => t("Slim header settings"),
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
    '#description' => t('Choose container type. Default: Container fixed'),
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
    '#description' => t("Center header settings"),
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
    '#description' => t('Choose container type. Default: Container fixed'),
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
    '#description' => t("Open social in new window. Default: unchecked"),
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
    '#description' => t('Choose search type.'),
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
    '#description' => t("Main navigation settings"),
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
    '#description' => t('Choose container type. Default: Container fixed'),
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
  $form['navigation_header']['navbar']['navigation_header_main_menu_name'] = [
    '#type' => 'textfield',
    '#title' => t('Main menu machine name'),
    '#description' => t('If there are two menus in the "Header Nav - Main Menu" region, fill in this field with the machine name of the main menu. Default: main'),
    '#placeholder' => t('menu_machine_name'),
    '#default_value' => theme_get_setting('navigation_header_main_menu_name'),
  ];
  // Back to top settings.
  $form['navigation_header']['back_to_top'] = [
    '#type' => 'details',
    '#title' => t('Back to top'),
    '#open' => FALSE,
    '#group' => 'navigation_header',
  ];
  $form['navigation_header']['back_to_top']['back_to_top_enable'] = [
    '#type' => 'checkbox',
    '#title' => t('Enable back to top'),
    '#description' => t("Default: checked"),
    '#default_value' => theme_get_setting('back_to_top_enable'),
  ];
  $form['navigation_header']['back_to_top']['back_to_top_small'] = [
    '#type' => 'checkbox',
    '#title' => t('Use small variant'),
    '#description' => t("Default: unchecked"),
    '#default_value' => theme_get_setting('back_to_top_small'),
  ];
  $form['navigation_header']['back_to_top']['back_to_top_dark'] = [
    '#type' => 'checkbox',
    '#title' => t('Adjust for dark background'),
    '#description' => t("Default: unchecked"),
    '#default_value' => theme_get_setting('back_to_top_dark'),
  ];
  $form['navigation_header']['back_to_top']['back_to_top_shadow'] = [
    '#type' => 'checkbox',
    '#title' => t("Enable shadow"),
    '#description' => t("Default: checked"),
    '#default_value' => theme_get_setting('back_to_top_shadow'),
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
  // Tables.
  $form['content']['tables'] = [
    '#type' => 'details',
    '#title' => t('Tables'),
    '#description' => t('Default settings for all tables.'),
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
    '#description' => t('Enable zebra-striping to any table column. Default: unchecked.'),
    '#default_value' => theme_get_setting('table_striped_columns'),
  ];
  $form['content']['tables']['table_bg'] = [
    '#type' => 'select',
    '#title' => t('Table background.'),
    '#description' => t('Choose background color. Default: "Default"'),
    '#default_value' => theme_get_setting('table_bg'),
    '#options' => ['' => t('Default')] + Helper::getColorsName(TRUE),
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
    '#options' => ['' => t('Default')] + Helper::getColorsName(TRUE),
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
    '#options' => [
      '' => t('Default'),
      'light' => t('Light'),
      'dark' => t('Dark'),
    ],
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
  // Editor nav tabs.
  $form['content']['editor_nav_tabs'] = [
    '#type' => 'details',
    '#title' => t('Editor nav tabs'),
    '#description' => t('Settings for editor nav tabs in content.'),
    '#open' => FALSE,
    '#group' => 'content',
  ];
  $form['content']['editor_nav_tabs']['editor_nav_tabs_scrollable'] = [
    '#type' => 'checkbox',
    '#title' => t('Scrollable'),
    '#description' => t('Enable scroll in nav tabs. Default: checked.'),
    '#default_value' => theme_get_setting('editor_nav_tabs_scrollable'),
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
  // Actions.
  $form['forms']['action'] = [
    '#type' => 'details',
    '#title' => t('Form actions'),
    '#description' => t('Default settings for all forms actions.'),
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
    '#description' => t('Choose container type. Default: Container fixed'),
    '#default_value' => theme_get_setting('footer_container_type'),
    '#options' => Helper::getBootstrapContainerType(TRUE),
  ];

  // Libraries Settings -------------------------------------------------------.
  $form['libraries_settings'] = [
    '#type' => 'details',
    '#title' => t('Libraries'),
    '#description' => t("Customize library source. You need to clear the cache if you change these settings."),
    '#open' => FALSE,
    '#group' => 'bootstrap',
    '#weight' => 20,
  ];
  $form['libraries_settings']['libraries_type'] = [
    '#type' => 'select',
    '#title' => t("Choose libraries type"),
    '#description' => t("Default: Use italiagov.libraries.yml"),
    '#default_value' => theme_get_setting('libraries_type'),
    '#options' => Libraries::getLibraries(),
  ];

  // Vanilla Settings.
  $form['libraries_settings']['vanilla'] = [
    '#type' => 'details',
    '#title' => t('Vanilla Settings'),
    '#open' => FALSE,
    '#group' => 'libraries_settings',
  ];
  $form['libraries_settings']['vanilla']['libraries_bundle'] = [
    '#type' => 'checkbox',
    '#title' => t("Use the bundle version (only for vanilla option)."),
    '#description' => t("Default: checked"),
    '#default_value' => theme_get_setting('libraries_bundle'),
  ];

  // CDN Settings.
  $form['libraries_settings']['cdn'] = [
    '#type' => 'details',
    '#title' => t('CDN Settings'),
    '#description' => t("If you use a third-party CDN, check that you are compliant with the GDPR."),
    '#open' => FALSE,
    '#group' => 'libraries_settings',
  ];
  $form['libraries_settings']['cdn']['libraries_cdn_css'] = [
    '#type' => 'textfield',
    '#title' => t('CSS from CDN'),
    '#description' => t("Put resource URI. Default: empty"),
    '#default_value' => theme_get_setting('libraries_cdn_css'),
  ];
  $form['libraries_settings']['cdn']['libraries_cdn_js'] = [
    '#type' => 'textfield',
    '#title' => t('JS from CDN'),
    '#description' => t("Put resource URI. Default: empty"),
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
    '#description' => t("Default: empty"),
    '#placeholder' => t('/libraries/fonts'),
    '#default_value' => theme_get_setting('libraries_cdn_fonts'),
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
