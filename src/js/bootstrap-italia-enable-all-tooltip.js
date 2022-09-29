(function (Drupal, once) {
  'use strict';

  Drupal.behaviors.enableAllTooltip = {
    attach: function (context) {
      once('enableAllTooltip', '[data-bs-toggle="tooltip"]', context).forEach(function (element) {
        return new bootstrap.Tooltip(element)
      });
    }
  };

})(Drupal, once);
