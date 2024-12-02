// is-sticky fix. Sticky clones the "id" attributes.
(function (Drupal, once) {
  'use strict';

  Drupal.behaviors.stickyFix = {
    attach: function (context, settings) {

      const headerWrapperObserver = new MutationObserver(
        function (mutationList) {
          mutationList.forEach(function (mutation) {
            if (mutation.type === 'attributes' && mutation.attributeName === 'class') {
              if (mutation.target.className.includes('is-sticky')) {

                // fix for logo
                let logoElementSelector = '.it-brand-wrapper.cloned-element .icon';
                let logoElement = document.querySelector(logoElementSelector);
                if (logoElement) {
                  let stickyViewboxData = logoElement.dataset.stickyViewbox;
                  if (stickyViewboxData) {
                    document.querySelector(logoElementSelector)
                      .setAttribute('viewBox', stickyViewboxData);
                  }
                }

                // fix for search button
                let searchButtonSelector = '.it-search-wrapper.cloned-element a.search-link';
                let searchButtonElement = document.querySelector(searchButtonSelector);
                let searchModalSelector = '.it-search-wrapper.cloned-element div#modal-header-center-search';
                let searchModalElement = document.querySelector(searchModalSelector);

                if (searchButtonElement && searchModalElement) {
                  let newID = 'modal-header-center-search-cloned';
                  document.querySelector(searchModalSelector)
                    .setAttribute('id', newID);
                  document.querySelector(searchButtonSelector)
                    .setAttribute('data-bs-target', '#' + newID);

                  searchModalElement.addEventListener('shown.bs.modal', () => {
                    document.getElementById('toolbar-administration')?.classList.add('d-none');
                  });
                  searchModalElement.addEventListener('hidden.bs.modal', () => {
                    document.getElementById('toolbar-administration')?.classList.remove('d-none');
                  });
                }
              }
            }
          })
        }
      );

      once('stickyFix', '.it-header-wrapper').forEach(function (headerWrapperObserverTarget) {
        //let headerWrapperObserverTarget = document.querySelector(".it-header-wrapper")
        let headerNavWrapper = document.getElementById("header-nav-wrapper");
        if (headerWrapperObserverTarget && headerNavWrapper) {
          headerWrapperObserver.observe(
            headerWrapperObserverTarget,
            {attributes: true}
          );
        }
      });
    }
  };

})(Drupal, once);
