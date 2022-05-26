(function () {
  'use strict';

  const headerWrapperObserver = new MutationObserver(
    function (mutationList) {
      mutationList.forEach(function(mutation) {
        if (mutation.type === 'attributes' && mutation.attributeName === 'class') {
          if (mutation.target.className.includes('is-sticky')) {
            let logoElementSelector = '.it-brand-wrapper.cloned-element .icon'
            let stickyViewbox = document.querySelector(logoElementSelector).dataset.stickyViewbox
            if (stickyViewbox) {
              document.querySelector(logoElementSelector)
                .setAttribute('viewBox', stickyViewbox);
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
