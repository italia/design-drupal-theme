(function (bootstrap) {
  Drupal.behaviors.bootstrapItaliaLoadFonts = {
    attach: function (context) {
      bootstrap.loadFonts();
    },
  };
})(bootstrap);
