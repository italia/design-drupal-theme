(function () {
  Drupal.behaviors.bootstrapItaliaLoadFonts = {
    attach() {
      window?.bootstrap?.loadFonts();
    },
  };
})();
