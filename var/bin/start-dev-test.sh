#!/bin/bash

# https://ddev.readthedocs.io/en/latest/#intro-to-ddev-local

echo 'Make test folder'
mkdir test-bootstrap-italia
cd test-bootstrap-italia || exit

echo 'Configuration'
ddev config --project-type=drupal8 --docroot=web --create-docroot

echo 'Run docker container'
ddev start

echo 'Download drupal and drush'
ddev composer create "'drupal/recommended-project':'^8.9.0 < 9.0'"
ddev composer require drush/drush
#ddev composer require 'drupal/console:>=1.9'

echo 'Install drupal'
ddev exec drush -y site:install --locale=it

echo 'Install end Enable dependencies'
ddev exec drush -y pm:enable inline_form_errors responsive_image
ddev composer require drupal/components drupal/ui_patterns
ddev exec drush -y pm:enable components ui_patterns ui_patterns_layouts ui_patterns_library ui_patterns_views

echo 'Language settings'
ddev exec drush -y en locale
ddev exec drush -y language-add en

echo 'Download bootstrap_italia'
ddev composer require 'drupal/bootstrap_italia:0.x-dev'

echo 'Copy sub-theme to destination folder'
ddev exec mkdir /var/www/html/web/themes/custom/
ddev exec cp -r /var/www/html/web/themes/contrib/bootstrap_italia/var/starter_kits/italiagov /var/www/html/web/themes/custom/

echo 'Enable themes'
ddev exec drush -y theme:enable bootstrap_italia
ddev exec drush -y theme:enable italiagov

echo 'Set default theme'
ddev exec drush -y config:set system.theme default italiagov

echo 'Install assets'
ddev exec npm install --prefix themes/custom/italiagov/
ddev exec npm run build:prod --prefix themes/custom/italiagov/

# Set site
#ddev exec drush -y config:set system.site name \'Bootstrap Italia Test\'
#dde#v exec drush -y config:set system.site slogan \'Bootstrap Italia Test v0.x-dev\'

echo 'Enable optional module: Bootstrap Italia Image Styles'
ddev composer require drupal/focal_point
ddev exec drush -y pm:enable focal_point bootstrap_italia_image_styles

echo 'Enable optional module: Bootstrap Italia Image Paragraphs'
ddev composer require drupal/paragraphs drupal/field_group drupal/imce
ddev exec drush -y pm:enable paragraphs field_group ui_patterns_field_group imce bootstrap_italia_paragraphs

echo 'Enable optional module: Bootstrap Italia Overlay'
ddev composer require drupal/ds
ddev exec drush -y pm:enable ds ds_extras ds_switch_view_mode ui_patterns_ds ui_patterns_layouts bootstrap_italia_overlay

echo 'Cache rebuild'
ddev exec drush cr

echo 'Push ssh public key in to container, if you have many keys press CRTL+C after first push'
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
