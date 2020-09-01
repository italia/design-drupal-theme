# Description
`bootstrap_italia` is a base theme for Drupal that implements [the Italian guidelines for designing public digital services](https://docs.italia.it/italia/designers-italia/design-linee-guida-docs/).
This theme uses `webpack` as a module bundler and includes the https://github.com/italia/bootstrap-italia/ library as a dependency.

# Drupal configuration
Install `drupal 8.9` and `drush 10` with `composer` (https://getcomposer.org/)

    $ composer create "drupal/recommended-project:^8.9.0 < 9.0" my_site_name_dir
    $ composer require drush/drush:10

Install drupal with the Italian language, you can use drush or your browser

    $ drush site:install --locale=it

After installation, if you wish, also install the English language

    $ drush en locale
    $ drush language-add en

Install `npm`: https://www.npmjs.com/get-npm

# Install theme
    $ cd <drupal-root>

    /* 1. Install end enable dependencies */
    $ drush pm:enable inline_form_errors responsive_image
    $ composer require drupal/components drupal/ui_patterns
    $ drush pm:enable components ui_patterns ui_patterns_layouts ui_patterns_library ui_patterns_views
    $ composer require drupal/bootstrap_italia

    /* 2. Copy sub-theme to destination folder */
    $ cd web/themes/
    $ mkdir custom
    $ cp -r contrib/bootstrap_italia/var/starter_kits/italiagov custom/

    /* 3. Enable themes */
    $ drush -y theme:enable bootstrap_italia
    $ drush -y theme:enable italiagov

    /* 4. Set default theme */
    $ drush config-set system.theme default italiagov

    /* 5. Install assets */
    $ cd custom/italiagov
    $ npm install

# Manage and generate assets
    $ npm run build:prod
    $ drush cr

or

    $ npm run build:dev

# Optional
If you want to install optional plugins.

## Image styles
This is a module that installs/uninstalls the image styles.
This module is dependent on `focal_point`.

    $ composer require drupal/focal_point
    $ drush pm:enable focal_point bootstrap_italia_image_styles

## Paragraphs
This is the base module for `paragraphs` integration and adds paragraph `content` and paragraph `configuration`.
This module is dependent on `paragraphs`, `field_group` and `imce`.

    $ composer require drupal/paragraphs drupal/field_group drupal/imce
    $ drush pm:enable paragraphs field_group ui_patterns_field_group imce bootstrap_italia_paragraphs

## Webform
Enables the creation of webforms and questionnaires.

    $ composer require drupal/webform
    $ drush pm:enable webform webform_ui webform_attachment webform_image_select

# How to start a ddev container
If you want an automated script that works for you, run script located at [var/bin/start-dev-test.sh](https://git.drupalcode.org/project/bootstrap_italia/-/tree/8.x-0.x/var/bin/start-dev-test.sh) and enjoy it
