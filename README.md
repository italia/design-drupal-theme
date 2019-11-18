# design-drupal-theme
A Drupal theme which implements the Italia Design System

# Install
    $ cd <drupal-root>
    $ composer require drupal/bootstrap-italia
    $ drush en bootstrap-italia
    $ drush config-set system.theme default bootstrap-italia
    
    $ cd web/themes/contrib/bootstrap-italia
    $ npm install
    
    $ npm run build:prod

or

    $ npm run build:dev