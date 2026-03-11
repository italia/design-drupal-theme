/**
 * Bootstrap Italia v3 – font loader entry point.
 *
 * Calls the upstream fonts-loader with the theme's dist/fonts/ path,
 * injected by Drupal via drupalSettings.bootstrapItalia.fontsPath.
 * Falls back to the default path for a standard Drupal install.
 */

import fontsLoader from 'bootstrap-italia/src/js/plugins/fonts-loader.js'

const fontsPath =
  window.drupalSettings?.bootstrapItalia?.fontsPath ??
  '/themes/contrib/bootstrap_italia/dist/fonts'

fontsLoader(fontsPath)
