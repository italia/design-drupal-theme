/*
(function (Drupal, once) {
  'use strict';

  Drupal.behaviors.customBIAlert = {
    attach: function (context, settings) {
      // once() is run only once after the dom is loaded
      once('customBIAlert', '<your-custom-selector>', context).forEach(function (element) {

        // example from https://italia.github.io/bootstrap-italia/docs/componenti/alert/#eventi
        element.addEventListener('closed.bs.alert', function () {
          // do something, for instance, explicitly move focus to the most appropriate element,
          // so it doesn't get lost/reset to the start of the page
          // document.getElementById('...').focus()
        })

      });
    }
  };

})(Drupal, once);
*/
