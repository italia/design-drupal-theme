// is-sticky fix. Sticky clones the "id" attributes.
(function (Drupal, once) {
  Drupal.behaviors.stickyFix = {
    attach: function (context, settings) {
      const headerWrapperObserver = new MutationObserver(
        function (mutationList) {
          mutationList.forEach(function (mutation) {
            if (
              mutation.type === 'attributes' &&
              mutation.attributeName === 'class'
            ) {
              if (mutation.target.className.includes('is-sticky')) {
                // fix for logo
                const logoElement = document.querySelector(
                  '.it-brand-wrapper.cloned-element .icon',
                );
                if (logoElement?.dataset?.stickyViewbox) {
                  logoElement.setAttribute(
                    'viewBox',
                    logoElement.dataset.stickyViewbox
                  );
                }

                // fix for search button
                const searchButtonElement = document.querySelector(
                  '.it-search-wrapper.cloned-element a.search-link',
                );

                const searchModalElement = document.querySelector(
                  '.it-search-wrapper.cloned-element div#modal-header-center-search',
                );

                if (searchButtonElement && searchModalElement) {
                  const newID = 'modal-header-center-search-cloned';
                  searchModalElement.setAttribute('id', newID);
                  searchButtonElement.setAttribute('data-bs-target', `#${newID}`);

                  if (!searchModalElement.dataset.listenerAttached) {
                    searchModalElement.addEventListener('shown.bs.modal', () => {
                      document
                        .getElementById('toolbar-administration')
                        ?.classList.add('d-none');
                    });
                    searchModalElement.addEventListener('hidden.bs.modal', () => {
                      document
                        .getElementById('toolbar-administration')
                        ?.classList.remove('d-none');
                    });
                    searchModalElement.dataset.listenerAttached = 'true';
                  }
                }
              }
            }
          });
        }
      );

      once('stickyFix', '.it-header-wrapper').forEach(
        function (headerWrapperObserverTarget) {
          // const headerWrapperObserverTarget = document.querySelector(".it-header-wrapper")
          const headerNavWrapper = document.getElementById('header-nav-wrapper');
          if (headerWrapperObserverTarget && headerNavWrapper) {
            headerWrapperObserver.observe(headerWrapperObserverTarget, {
              attributes: true,
            });
          }
        },
      );
    },
  };
})(Drupal, once);
