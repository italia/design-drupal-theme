# Description
`bootstrap_italia` is a base theme for Drupal that implements
[the Italian guidelines for designing public digital services](https://docs.italia.it/italia/designers-italia/design-linee-guida-docs/).
This theme uses `webpack` as a module bundler and includes the
[bootstrap-italia](https://github.com/italia/bootstrap-italia/)
library as a dependency.

# Drupal configuration
Install `drupal` and `drush` with `composer` (https://getcomposer.org/)
```
$ composer create drupal/recommended-project my_site_name_dir --no-install
$ cd my_site_name_dir
$ composer require drush/drush --no-install
$ composer install
```

Install drupal, you can use drush or your browser
```
$ drush site:install
```

# Install theme
```
$ cd <drupal-root>

/* 1. Install end enable dependencies */
$ composer require drupal/components:^3.0@beta
$ drush pm:enable components
$ composer require drupal/bootstrap_italia:^2.1

/* 2. Copy sub-theme to destination folder */
$ cd web/themes/
$ mkdir custom
$ cp -r contrib/bootstrap_italia/var/starter_kits/italiagov custom/

/* 3. Enable themes */
$ drush -y theme:enable bootstrap_italia
$ drush -y theme:enable italiagov

/* 4. Set default theme */
$ drush config-set system.theme default italiagov
```

Edit `custom/italiagov/italiagov.info.yml`
and change `hidden` variable to `false`
```
sed -i 's/hidden: true/hidden: false/g' custom/italiagov/italiagov.info.yml
```

# Manage and generate assets
You can install the bootstrap-Italy library in several ways.

## A. Bootstrap-italia vanilla

Download https://github.com/italia/bootstrap-italia/releases/download/v2.1.1/bootstrap-italia.zip
and unzip in `<your-subtheme>/dist`.

## B. For developer or advanced user
`npm` is required: https://www.npmjs.com/get-npm

Install assets
```
$ cd custom/italiagov
$ npm install
```

Run watcher:
```
$ npm run watch:dev
```
Build assets:
```
$ npm run build:dev
$ drush cr
```

### Production mode:
Run watcher:
```
$ npm run watch:prod
```
Build assets:
```
$ npm run build:prod
$ drush cr
```

### Hot mode:
To properly activate hot mode, do this:

- Make sure your host port 8080 is not filtered,
or exposed if you are using a container.
- In the `<sub-theme>/<sub-theme>.info.yml` file edit the `libraries` array
to load only `italiagov/hot` and `bootstrap_italia/base`
```
$ drush cr && npm run build:dev && npm run hot
```

***Note*** that you need to run `drush cr` then `build:dev`
and finally `hot`, otherwise it won't work.

If you need customize `host` and `port`,
copy `<sub-theme>/webpack.settings.dist.js`
in `<sub-theme>/webpack.settings.js` and edit
`devServer.allowedHosts` and `devServer.port`.

If you use ddev use this tip to expose 8080 port and view the site with
the URL `http://127.0.0.1:<ddev-port>`
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

## C. For developer or expert user
By appropriately modifying `*.info.yml` and `*.libraries.yml` you can adapt
the loading of libraries according to your infrastructure.

## D. How to use bootstrap-italia library from github (for developer)
Replace in `<sub-theme>/package.json`

```
"bootstrap-italia": "<version>"
```
with
```
"bootstrap-italia": "github:italia/bootstrap-italia#<branch>"
```
example
```
"bootstrap-italia": "github:italia/bootstrap-italia#main"
```

# Optional modules
This theme provides several modules that allow you to manage the components
with the Drupal administration panel. Below is a list

## Bootstrap Italia Image Styles
This module adds different image styles in
Admin -> Configurations -> Media -> Image Styles.
```
$ composer require drupal/focal_point
$ drush -y pm:enable responsive_image focal_point bootstrap_italia_image_style
```

## Bootstrap Italia Text editor
This module adds new text editor format (ckeditor 4) in
"Configuration" -> "Text formats and editors".
```
$ drush -y pm:enable bootstrap_italia_text_editor
```

## Bootstrap Italia Text editor 2 (Experimental)
This module adds new text editor format (ckeditor 5) in
"Configuration" -> "Text formats and editors".
```
$ drush -y pm:enable bootstrap_italia_text_editor2
```

## Bootstrap Italia Layouts
This module adds several layouts that can be used immediately
with Layout Builder, Display Suite or any other layout consuming module.
```
$ drush -y pm:enable bootstrap_italia_layouts
```

## Bootstrap Italia Paragraph
This is the base module for paragraphs integration.
```
$ composer require drupal/paragraphs drupal/field_group drupal/imce drupal/color_field
$ drush -y pm:enable paragraphs field_group imce color_field
$ drush -y pm:enable bootstrap_italia_paragraph
```
Install third-party libraries via the Drupal administration panel
or with this script by positioning yourself in the same folder
in which `composer.json` is located
```
#!/bin/bash
curl --request GET -sL \
  --url 'https://github.com/recurser/jquery-simple-color/archive/master.zip' \
  --output './web/libraries/master.zip'

unzip ./web/libraries/master.zip -d ./web/libraries/
mv ./web/libraries/jquery-simple-color-master ./web/libraries/jquery-simple-color
rm -Rf ./web/libraries/master.zip

curl --request GET -sL \
  --url 'https://github.com/bgrins/spectrum/archive/master.zip' \
  --output './web/libraries/master.zip'

unzip ./web/libraries/master.zip -d ./web/libraries/
mv ./web/libraries/spectrum-master ./web/libraries/spectrum
rm -Rf ./web/libraries/master.zip
```

## Bootstrap Italia Paragraph Accordion
This module manages the accordion component through the paragraph module.
```
$ drush -y pm:enable bootstrap_italia_paragraph_accordion
```

## Bootstrap Italia Paragraph Attachments
This module manages the attachments through the paragraph module.
```
$ drush -y pm:enable media media_library bootstrap_italia_paragraph_attachments
```

## Bootstrap Italia Paragraph Callout
This module manages the callout component through the paragraph module.
```
$ drush -y pm:enable bootstrap_italia_paragraph_callout
```

## Bootstrap Italia Paragraph Carousel
This module manages the splide carousel component through the paragraph module.
```
$ drush -y pm:enable media media_library bootstrap_italia_paragraph_carousel
```

## Bootstrap Italia Paragraph Citation
This module manages the citation component through the paragraph module.
```
$ drush -y pm:enable bootstrap_italia_paragraph_citation
```

## Bootstrap Italia Paragraph Gallery
This module manages the gallery component (image list)
through the paragraph module.
```
$ drush -y pm:enable bootstrap_italia_paragraph_gallery
```

## Bootstrap Italia Paragraph Hero
This module manages the hero component through the paragraph module.
```
$ drush -y pm:enable bootstrap_italia_paragraph_hero
```

## Bootstrap Italia Paragraph Map
This module manages the map component through the paragraph module.
This module uses leaflets and open street maps.
```
$ composer require drupal/geofield drupal/leaflet
$ drush -y pm:enable geofield leaflet bootstrap_italia_paragraph_map
```

## Bootstrap Italia Paragraph Node Reference
This module, through a paragraph, refers to other nodes
and allows you to choose the view with which they must be displayed.
```
$ composer require drupal/entity_reference_display
$ drush -y pm:enable entity_reference_display
$ drush -y pm:enable bootstrap_italia_paragraph_node_reference
```

## Bootstrap Italia Paragraph Section
This module manages the section component through the paragraph module.
```
$ drush -y pm:enable bootstrap_italia_paragraph_section
```

## Bootstrap Italia Paragraph Timeline
This module manages the timeline component through the paragraph module.
```
$ drush -y pm:enable bootstrap_italia_paragraph_timeline
```

## Bootstrap Italia Paragraph Webform
This module manages the integration of webform with paragraph.
```
$ composer require drupal/webform wikimedia/composer-merge-plugin
$ drush -y pm:enable webform webform_bootstrap webform_ui
$ drush -y pm:enable bootstrap_italia_paragraph_webform
```
Install third-party libraries by edit the `composer.json` file
of your website and under the "extra": { section add:
```
"merge-plugin": {
  "include": [
    "web/modules/contrib/webform/composer.libraries.json"
  ]
},
```
Then run:
```
$ composer update -W
```
[Learn more](https://www.drupal.org/node/3003140)

## Bootstrap Italia Views Accordion
This module manages the integration of the accordion component
into the views module.
```
$ drush -y pm:enable bootstrap_italia_views_accordion
```

## Bootstrap Italia Views Carousel
This module manages the integration of the carousel component
into the views module.
```
$ drush -y pm:enable bootstrap_italia_views_carousel
```

## Bootstrap Italia Views Gallery
This module manages the integration of the gallery component
into the views module.
```
$ drush -y pm:enable bootstrap_italia_views_gallery
```

## Bootstrap Italia Views List
This module manages the integration of the list component into the views module.
```
$ drush -y pm:enable bootstrap_italia_views_list
```

## Bootstrap Italia Views Timeline
This module manages the integration of the timeline component
into the views module.
```
$ drush -y pm:enable bootstrap_italia_views_timeline
```

## Bootstrap Italia content News
This module adds the "News" content type (second level content).
*Note: this is an example of how to develop a reusable content type.*
```
$ composer require drupal/toc_js drupal/focal_point
$ drush -y pm:enable responsive_image toc_js focal_point  \
    bootstrap_italia_paragraph bootstrap_italia_paragraph_accordion \
    bootstrap_italia_paragraph_attachments bootstrap_italia_paragraph_callout \
    bootstrap_italia_paragraph_carousel bootstrap_italia_paragraph_citation \
    bootstrap_italia_paragraph_map bootstrap_italia_paragraph_webform  \
    bootstrap_italia_content_news
```
Install third-party libraries via the Drupal administration panel
or with this script by positioning yourself in the same folder
in which `composer.json` is located
```
#!/bin/bash
curl --request GET -sL \
  --url 'https://github.com/jgallen23/toc/archive/refs/heads/greenkeeper/update-all.zip' \
  --output './web/libraries/master.zip'

unzip ./web/libraries/master.zip -d ./web/libraries/
mv ./web/libraries/toc-greenkeeper-update-all/dist ./web/libraries/toc
rm -Rf ./web/libraries/toc-greenkeeper-update-all
rm -Rf ./web/libraries/master.zip
```

## Bootstrap Italia empty front page
By default, Drupal fills the front page with the latest content from your site.
This module modifies the front page to have an empty page. This way, only the
blocks will be displayed. Useful as in the case of Municipalities
whose home page is built only with blocks in custom zones, thus avoiding
recalling the frontpage view which isn't used. The same view is also disabled.
```
$ composer require drupal/empty_front_page
$ drush -y pm:enable empty_front_page bootstrap_italia_empty_front_page
```


# How to manage components via the user interface.
The components of the theme are mapped with the drupal graphical interface,
so you can manage cards, lists, etc., without writing code or templates.
First install and enable `ui_patterns` (>= 1.5), `ui_patterns_library`
and `ui_patterns_settings`.
```
$ composer require 'drupal/ui_patterns:^1.5' drupal/ui_patterns_settings
$ drush en ui_patterns ui_patterns_library ui_patterns_settings
```
To the `https://domain.example/patterns` page you will see
the list of components/patterns that you can manage from the UI.

## Display
Enable `ui_patterns_ds` to use components as layouts
via Display suite.
```
$ composer require drupal/ds
$ drush en ds ds_extras ds_switch_view_mode ui_patterns_ds
```

## Layout
Enable `ui_patterns_layouts` to use components as layouts
via the Layout Discovery module.
```
$ drush en ui_patterns_layouts
```

## Views
Enable `ui_patterns_views` to use components with views.
```
$ drush en ui_patterns_views
```

# Italian Language
Import/edit `translations/bootstrap_italia-2.x.it.po`
```
$ drush locale-import it /absolute/path/to/bootstrap_italia-2.2.0.it.po --type=customized --override=all
```

# How to start a ddev container
If you want an automated script that works for you, run script located at
`themes/bootstrap_italia/var/bin/build-ddev-installation.sh` and enjoy it

This script works for ddev >= 1.18.0 (Sept 2021)

Download ad run:
```
$ bash <(curl -s https://git.drupalcode.org/project/bootstrap_italia/-/raw/2.x/var/bin/build-ddev-installation.sh)
```
