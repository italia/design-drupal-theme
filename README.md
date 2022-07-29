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
$ composer require drush/drush --no-install
$ composer install
```

Install drupal, you can use drush or your browser
```
$ drush site:install
```

Install `npm`: https://www.npmjs.com/get-npm

# Install theme
```
$ cd <drupal-root>

/* 1. Install end enable dependencies */
$ composer require drupal/components:^3@beta
$ drush pm:enable components
$ composer require drupal/bootstrap_italia:2.x-dev

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

Edit `custom/italiagov/italiagov.info.yml` and change `hidden` variable to `false`
```
sed "-i 's/hidden: true/hidden: false/g' custom/italiagov/italiagov.info.yml"
```

# Manage and generate assets
You can install the bootstrap-Italy library in several ways.

## A. Bootstrap-italia vanilla

Download https://github.com/italia/bootstrap-italia-next/releases/download/v2.0.0-rc5/bootstrap-italia.zip
and unzip in `<your-subtheme>/dist`.

## B. For developer or advanced user

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
- In the file `<sub-theme>/<sub-theme>.libraries.yml` load the css and js
as in the example commented.
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
"bootstrap-italia": "github:italia/bootstrap-italia#development"
```

# Optional
If you want to install optional plugins.

*Cooming soon*

# How to start a ddev container
If you want an automated script that works for you, run script located at
`themes/bootstrap_italia/var/bin/start-dev-test.sh` and enjoy it
