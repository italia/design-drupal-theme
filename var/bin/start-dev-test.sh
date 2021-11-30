#!/bin/bash

# https://ddev.readthedocs.io/en/latest/#intro-to-ddev-local

echo "==[ Settings ]=="

read -r -p "Project machine name [a-zA-Z0-9] (new-project): " project_name
project_name=${project_name:-new-project}

if [ -d "$project_name" ]; then
  echo "${project_name} already exists! Exit..."
  exit
fi

# Search project in ddev
ddev_search=$(ddev list | grep -w "$project_name" | awk '{name = $1}; END {print name}')
if [ "$project_name" == "$ddev_search" ]; then
  echo "Error! The project name ${ddev_search} already exists! Exit..."
  exit
fi

read -r -p "Drupal version [8|9] (9): " drupal_version
if [ -z "$drupal_version" ] || [ "$drupal_version" == "9" ]; then
  drupal_version="9"
else
  drupal_version="8"
fi

read -r -p "Bootstrap Italia version [0.1...x|0.x-dev|latest] (0.x-dev): " bootstrap_italia_version
bootstrap_italia_version=${bootstrap_italia_version:-0.x-dev}

read -r -p "Do you want to activate the experimental modules? [y|n] (n): " enable_experimental_modules
enable_experimental_modules=${enable_experimental_modules:-n}


echo "==[ Configuration ]=="

echo "Make ${project_name}"
mkdir "$project_name"
cd "$project_name" || exit

echo "Installing ddev config files in ${pwd} ..."
ddev config --project-type=drupal${drupal_version} --docroot=web --create-docroot

echo 'Run docker containers'
ddev start

echo "Download Drupal ${drupal_version} and drush"
if [ "$drupal_version" == "9" ]; then
  ddev composer create "'drupal/recommended-project'"
else
  ddev composer create "'drupal/recommended-project':'^8.9.0 < 9.0'"
fi

ddev composer require drush/drush
#ddev composer require 'drupal/console'

echo "==[ Installing Drupal ${drupal_version} ]=="
ddev exec drush -y site:install --locale=it

echo '==[ Install end enable bootstrap_italia dependencies ]=='
ddev exec drush -y pm:enable inline_form_errors responsive_image
ddev composer require drupal/components drupal/ui_patterns
ddev exec drush -y pm:enable components ui_patterns ui_patterns_layouts ui_patterns_library ui_patterns_views

echo 'Language settings'
ddev exec drush -y en locale
ddev exec drush -y language-add en

echo "==[ Downloading and activating bootstrap_italia:${bootstrap_italia_version} ]=="
if [ "$bootstrap_italia_version" == "latest" ]; then
  ddev composer require 'drupal/bootstrap_italia'
else
  ddev composer require "drupal/bootstrap_italia:${bootstrap_italia_version}"
fi

echo 'Copy sub-theme to destination folder'
ddev exec mkdir /var/www/html/web/themes/custom/
ddev exec cp -r /var/www/html/web/themes/contrib/bootstrap_italia/var/starter_kits/italiagov /var/www/html/web/themes/custom/

echo 'Enable themes'
ddev exec drush -y theme:enable bootstrap_italia
ddev exec drush -y theme:enable italiagov

echo 'Set default theme'
ddev exec drush -y config:set system.theme default italiagov

echo 'Install assets'
ddev exec npm install --prefix web/themes/custom/italiagov/
ddev exec npm run build:prod --prefix web/themes/custom/italiagov/

# Set site
#ddev exec drush -y config:set system.site name \'Bootstrap Italia Test\'
#ddev exec drush -y config:set system.site slogan \'Bootstrap Italia Test v0.x-dev\'

if [ "$enable_experimental_modules" == "y" ]; then
  echo "==[ I am going to activate the experimental modules ]=="

  echo 'Enable optional module: Bootstrap Italia Image Styles'
  ddev composer require drupal/focal_point
  ddev exec drush -y pm:enable focal_point bootstrap_italia_image_styles

  echo 'Enable optional module: Bootstrap Italia Image Paragraphs'
  ddev composer require drupal/paragraphs drupal/field_group drupal/imce
  ddev exec drush -y pm:enable paragraphs field_group ui_patterns_field_group imce bootstrap_italia_paragraphs

  echo 'Enable optional module: Bootstrap Italia Overlay'
  ddev composer require drupal/ds
  ddev exec drush -y pm:enable ds ds_extras ds_switch_view_mode ui_patterns_ds ui_patterns_layouts bootstrap_italia_overlay
fi

echo '==[ Cache rebuild ]=='
ddev exec drush cr

echo 'Push ssh public key in to container, if you have many keys press CRTL+C after first push'
ddev auth ssh

# ddev info
ddev describe

# Reset password message
echo -e "Run -> \e[1m\e[31m ddev exec drush upwd admin my_password \e[0m <- if you don't know the Drupal administrator password"

# Open browser
#ddev launch

# Remove test
# ddev stop $project_name && ddev delete $project_name

# then delete $project_name folder
