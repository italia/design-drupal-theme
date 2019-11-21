# design-drupal-theme
A Drupal theme which implements the Italia Design System

# Install
    $ cd <drupal-root>
    $ composer require drupal/bootstrap_italia
    $ drush en bootstrap_italia
    $ drush config-set system.theme default bootstrap_italia
    
    $ cd web/themes/contrib/bootstrap_italia
    $ npm install

# Usage
    $ npm run build:prod

or

    $ npm run build:dev