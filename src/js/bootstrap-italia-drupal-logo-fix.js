// is-sticky fix. Sticky clones the "id" attributes.
(function () {
  'use strict';

  const headerWrapperObserver = new MutationObserver(
    function (mutationList) {
      mutationList.forEach(function(mutation) {
        if (mutation.type === 'attributes' && mutation.attributeName === 'class') {
          if (mutation.target.className.includes('is-sticky')) {
            // fix for logo
            let logoElementSelector = '.it-brand-wrapper.cloned-element .icon'
            let stickyViewbox = document.querySelector(logoElementSelector).dataset.stickyViewbox
            if (stickyViewbox) {
              document.querySelector(logoElementSelector)
                .setAttribute('viewBox', stickyViewbox);
            }
            // fix for search button
            let searchButtonSelector = '.it-search-wrapper.cloned-element a.search-link'
            let searchButtonElement = document.querySelector(searchButtonSelector)
            let searchModalSelector = '.it-search-wrapper.cloned-element div#modal-header-center-search'
            let searchModal = document.querySelector(searchModalSelector)

            if (searchButtonElement && searchModal) {
              document.querySelector(searchModalSelector)
                .setAttribute('id', 'modal-header-center-search-cloned');
              document.querySelector(searchButtonSelector)
                .setAttribute('data-bs-target', '#modal-header-center-search-cloned');
            }
          }
        }
      })
    }
  )

  headerWrapperObserver.observe(
    document.querySelector(".it-header-wrapper"),
    {attributes: true}
  )

})(Drupal);
