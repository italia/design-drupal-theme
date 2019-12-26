# design-drupal-theme
A Drupal theme which implements the Italia Design System

# Install
    $ cd <drupal-root>
    $ drush pm:enable inline_form_errors
    $ composer require drupal/components drupal/ui_patterns
    $ drush pm:enable components ui_patterns ui_patterns_layouts ui_patterns_library ui_patterns_views
    $ composer require drupal/bootstrap_italia
    $ drush theme:enable bootstrap_italia
    $ drush config-set system.theme default bootstrap_italia

    $ cd web/themes/contrib/bootstrap_italia
    $ npm install

# Usage
    $ npm run build:prod
    $ drush cr

or

    $ npm run build:dev

# Webform integration
    $ composer require drupal/webform
    $ drush pm:enable webform webform_ui webform_attachment webform_image_select
