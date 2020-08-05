/*
 * https://www.drupal.org/docs/8/api/javascript-api/javascript-api-overview
 */

(function () {
  'use strict';

  Drupal.behaviors.componentLibraryInitialization = {
    attach: function (context, settings) {

      // Initialize tooltip
      jQuery('[data-toggle="tooltip"]').tooltip()

    }
  };

})(jQuery, Drupal);
