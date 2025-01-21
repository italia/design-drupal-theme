(function () {
  Drupal.behaviors.bootstrapItaliaLoadFonts = {
    attach: function (context) {
      bootstrap.loadFonts();
    },
  };
})();
