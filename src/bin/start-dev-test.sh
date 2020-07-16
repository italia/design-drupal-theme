#!/bin/bash

# https://ddev.readthedocs.io/en/latest/#intro-to-ddev-local

mkdir test-bootstrap-italia
cd test-bootstrap-italia || exit

ddev config --project-type=drupal8 --docroot=web --create-docroot

ddev start
ddev composer create "drupal/recommended-project:8.9"
ddev composer require drush/drush
#ddev composer require 'drupal/console:~1.0'

ddev exec drush -y site:install

ddev composer require 'drupal/bootstrap_italia:0.x-dev'
ddev composer require drupal/components drupal/ui_patterns

ddev exec drush -y pm:enable inline_form_errors
ddev exec drush -y pm:enable components ui_patterns ui_patterns_layouts ui_patterns_library ui_patterns_views
ddev exec drush -y theme:enable bootstrap_italia
ddev exec drush -y config:set system.theme default bootstrap_italia
ddev exec npm install --prefix themes/contrib/bootstrap_italia/
ddev exec npm run build:prod --prefix themes/contrib/bootstrap_italia/
#ddev exec drush -y config:set system.site name \'Bootstrap Italia Test\'
#dde#v exec drush -y config:set system.site slogan \'Bootstrap Italia Test v0.x-dev\'

ddev exec drush cr

ddev auth ssh

#ddev launch
