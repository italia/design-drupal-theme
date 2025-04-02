(function (Drupal, once, bootstrap) {
  Drupal.behaviors.enableAllTooltip = {
    attach: function (context) {
      once('enableAllTooltip', '[data-bs-toggle="tooltip"]', context).forEach(function (element) {
        return new bootstrap.Tooltip(element);
      });
    },
  };
})(Drupal, once, bootstrap);
