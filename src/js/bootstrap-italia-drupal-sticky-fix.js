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
            let logoElement = document.querySelector(logoElementSelector)
            if (logoElement) {
              let stickyViewboxData = logoElement.dataset.stickyViewbox
              if (stickyViewboxData) {
                document.querySelector(logoElementSelector)
                  .setAttribute('viewBox', stickyViewboxData);
              }
            }

            // fix for search button
            let searchButtonSelector = '.it-search-wrapper.cloned-element a.search-link'
            let searchButtonElement = document.querySelector(searchButtonSelector)
            let searchModalSelector = '.it-search-wrapper.cloned-element div#modal-header-center-search'
            let searchModalElement = document.querySelector(searchModalSelector)

            if (searchButtonElement && searchModalElement) {
              let newID = 'modal-header-center-search-cloned'
              document.querySelector(searchModalSelector)
                .setAttribute('id', newID);
              document.querySelector(searchButtonSelector)
                .setAttribute('data-bs-target', '#'+newID);
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
