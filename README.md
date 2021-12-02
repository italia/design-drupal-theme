# Description
`bootstrap_italia` is a base theme for Drupal that implements [the Italian guidelines for designing public digital services](https://docs.italia.it/italia/designers-italia/design-linee-guida-docs/).
This theme uses `webpack` as a module bundler and includes the [bootstrap-italia](https://github.com/italia/bootstrap-italia/) library as a dependency.

# Drupal configuration
Install `drupal` and `drush` with `composer` (https://getcomposer.org/)

    $ composer create drupal/recommended-project my_site_name_dir
    $ composer require drush/drush

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
    $ drush pm:enable components \
        ui_patterns ui_patterns_layouts ui_patterns_library ui_patterns_views
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
### Developement mode:
Run watcher:

    $ npm run watch:dev

Build assets:

    $ npm run build:dev
    $ drush cr

### Production mode:
Run watcher:

    $ npm run watch:prod

Build assets:

    $ npm run build:prod
    $ drush cr

### Hot mode
To properly activate hot mode, do this:

- Make sure your host port 8080 is not filtered, or exposed if you are using a container.
- In the file `<sub-theme>/<sub-theme>.libraries.yml` load the css and js as in the example commented.

```
$ drush cr && npm run build:dev && npm run hot
```

***Note*** that you need to run `drush cr` then `build:dev` and finally `hot`, otherwise it won't work.

If you need customize `host` and `port`,
copy `<sub-theme>/webpack.settings.dist.js` in `<sub-theme>/webpack.settings.js` and edit
`devServer.allowedHosts` and `devServer.port`.

If you use ddev use this tip to expose 8080 port

```
<project-name>/.ddev/docker-compose.ports.yaml

version: '3.6'

services:
  web:
    expose:
      - 8080
    ports:
      - 8080:8080
```

# Optional
If you want to install optional plugins.

## Image styles [EXPERIMENTAL]
This is a module that installs/uninstalls the image styles.
This module is dependent on `focal_point`.

    $ composer require drupal/focal_point
    $ drush pm:enable focal_point bootstrap_italia_image_styles

## Paragraphs [EXPERIMENTAL]
This is the base module for `paragraphs` integration.
This module adds paragraph `content` and paragraph `configuration`.
This module is dependent on `paragraphs`, `field_group` and `imce`.

    $ composer require drupal/paragraphs drupal/field_group drupal/imce
    $ drush pm:enable paragraphs \
        field_group \
        ui_patterns_field_group \
        imce \
        bootstrap_italia_paragraphs

## Paragraphs overlay [EXPERIMENTAL]
This module adds paragraph [overlay component](https://italia.github.io/bootstrap-italia/docs/componenti/overlay/).
This module is dependent on `bootstrap_italia_paragraphs`, `ds_extras`,
`ds_switch_view_mode`, `ui_patterns_layouts` and `ui_patterns_ds`.

    $ composer require drupal/ds
    $ drush pm:enable bootstrap_italia_paragraphs \
        ds ds_extras ds_switch_view_mode \
        ui_patterns_ds ui_patterns_layouts \
        bootstrap_italia_overlay

## Webform
Enables the creation of webforms and questionnaires.

    $ composer require drupal/webform
    $ drush pm:enable webform webform_ui webform_attachment webform_image_select

# How to start a ddev container
If you want an automated script that works for you, run script located at [var/bin/start-dev-test.sh](https://git.drupalcode.org/project/bootstrap_italia/-/tree/8.x-0.x/var/bin/start-dev-test.sh) and enjoy it
