(function (Drupal, once) {
  Drupal.behaviors.enableAllTooltip = {
    attach(context) {
      once('enableAllTooltip', '[data-bs-toggle="tooltip"]', context).forEach(
        function (element) {
          return new bootstrap.Tooltip(element);
        },
      );
    },
  };
})(Drupal, once);
