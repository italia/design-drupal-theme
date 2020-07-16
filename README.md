# design-drupal-theme
A Drupal theme which implements the Italia Design System

# Install
    $ cd <drupal-root>

    /* Install end Enable dependencies */
    $ drush pm:enable inline_form_errors
    $ composer require drupal/components drupal/ui_patterns
    $ drush pm:enable components ui_patterns ui_patterns_layouts ui_patterns_library ui_patterns_views
    $ composer require drupal/bootstrap_italia

    /* Copy sub-theme to destination folder */
    $ cd web/themes/
    $ mkdir custom
    $ cp -r contrib/bootstrap_italia/var/starter_kits/italiagov custom/

    /* Enable themes */
    $ drush -y theme:enable bootstrap_italia
    $ drush -y theme:enable italiagov

    /* Set default theme */
    $ drush config-set system.theme default italiagov

    /* Install assets */
    $ cd custom/italiagov
    $ npm install

# Usage
    $ npm run build:prod
    $ drush cr

or

    $ npm run build:dev

# Webform integration
    $ composer require drupal/webform
    $ drush pm:enable webform webform_ui webform_attachment webform_image_select

# How to start a ddev container
Run script in var/bin/start-dev-test.sh
