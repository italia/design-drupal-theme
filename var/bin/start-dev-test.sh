#!/bin/bash

# https://ddev.readthedocs.io/en/latest/#intro-to-ddev-local

# Make test folder
mkdir test-bootstrap-italia
cd test-bootstrap-italia || exit

# Config
ddev config --project-type=drupal8 --docroot=web --create-docroot

# Run docker container
ddev start

# Download drupal
ddev composer create "'drupal/recommended-project':'^8.9.0 < 9.0'"
ddev composer require drush/drush
#ddev composer require 'drupal/console:>=1.9'

# Install drupal
ddev exec drush -y site:install --locale=it

# Install end Enable dependencies
ddev exec drush -y pm:enable inline_form_errors
ddev composer require drupal/components drupal/ui_patterns
ddev exec drush -y pm:enable components ui_patterns ui_patterns_layouts ui_patterns_library ui_patterns_views

# Language settings
ddev exec drush -y en locale
ddev exec drush -y language-add en

# Download bootstrap_italia
ddev composer require 'drupal/bootstrap_italia:0.x-dev'

# Copy sub-theme to destination folder
ddev exec mkdir /var/www/html/web/themes/custom/
ddev exec cp -r /var/www/html/web/themes/contrib/bootstrap_italia/var/starter_kits/italiagov /var/www/html/web/themes/custom/

# Enable themes
ddev exec drush -y theme:enable bootstrap_italia
ddev exec drush -y theme:enable italiagov

# Set default theme
ddev exec drush -y config:set system.theme default italiagov

# Install assets
ddev exec npm install --prefix themes/custom/italiagov/
ddev exec npm run build:prod --prefix themes/custom/italiagov/

# Set site
#ddev exec drush -y config:set system.site name \'Bootstrap Italia Test\'
#dde#v exec drush -y config:set system.site slogan \'Bootstrap Italia Test v0.x-dev\'

# Cache rebuild
ddev exec drush cr

# Push ssh key in to container
ddev auth ssh

# ddev info
ddev describe

# Reset password message
echo -e "Run \e[1m\e[31m ddev exec drush upwd admin my_password \e[0m if you don't know the administrator password"

# Open browser
#ddev launch

# Remove test
# ddev stop test-bootstrap-italia && ddev delete test-bootstrap-italia

# then delete "test-bootstrap-italia" folder
