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

read -r -p "Drupal version [9|10] (9): " drupal_version
if [ -z "$drupal_version" ] || [ "$drupal_version" == "9" ]; then
  drupal_version="9"
else
  drupal_version="10"
fi

read -r -p "Bootstrap Italia version [2.0...x|2.x-dev|latest] (2.x-dev): " bootstrap_italia_version
bootstrap_italia_version=${bootstrap_italia_version:-2.x-dev}

read -r -p "Do you want enable italian language? [y|n] (y): " enable_locale
enable_locale=${enable_locale:-y}

read -r -p "Do you want to install extra modules? [y|n] (n): " enable_modules
enable_modules=${enable_modules:-n}

read -r -p "Do you want to install extra content type? [y|n] (n): " enable_content_type
enable_content_type=${enable_content_type:-n}

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
  ddev composer create 'drupal/recommended-project' --no-install
else
  ddev composer create --no-install 'drupal/recommended-project:^10@alpha'
fi

ddev composer require drush/drush --no-install
ddev composer install

echo "==[ Installing Drupal ${drupal_version} ]=="
ddev exec drush -y site:install

echo '==[ Install end enable bootstrap_italia dependencies ]=='
ddev exec drush -y pm:enable inline_form_errors responsive_image
ddev composer require 'drupal/components:^3@beta'
ddev exec drush -y pm:enable components

if [ "$enable_locale" == "y" ]; then
  echo 'Language settings'
  ddev exec drush -y en locale
  ddev exec drush -y language-add it
fi

echo "==[ Downloading and activating bootstrap_italia:${bootstrap_italia_version} ]=="
if [ "$bootstrap_italia_version" == "latest" ]; then
  ddev composer require 'drupal/bootstrap_italia'
else
  ddev composer require "drupal/bootstrap_italia:${bootstrap_italia_version}"
fi

echo 'Copy sub-theme to destination folder'
ddev exec mkdir /var/www/html/web/themes/custom/
ddev exec cp -r /var/www/html/web/themes/contrib/bootstrap_italia/var/starter_kits/italiagov /var/www/html/web/themes/custom/

echo 'Show italiagov sub-theme in theme list'
ddev exec sed "-i 's/hidden: true/hidden: false/g' /var/www/html/web/themes/custom/italiagov/italiagov.info.yml"

echo 'Enable themes'
ddev exec drush -y theme:enable bootstrap_italia
ddev exec drush -y theme:enable italiagov

echo 'Set default theme'
ddev exec drush -y config:set system.theme default italiagov

echo 'Install italiagov assets'
ddev exec npm install --prefix web/themes/custom/italiagov/
ddev exec npm run build:prod --prefix web/themes/custom/italiagov/

echo 'Change libraries settings to webpack assets'
ddev drush -y config-set italiagov.settings libraries_type bootstrap-italia

echo '==[ Cache rebuild ]=='
ddev exec drush cr

if [ "$enable_modules" == "y" ]; then
  echo "==[ Install theme modules ]=="

  if [ ! -d "./web/libraries" ]; then
    echo "Make libraries directory"
    mkdir ./web/libraries
  fi

  echo 'Install module: Bootstrap Italia Image Style'
  ddev composer require drupal/focal_point
  ddev exec drush -y pm:enable focal_point bootstrap_italia_image_styles

  echo 'Install module: Bootstrap Italia Paragraph'
  ddev composer require drupal/paragraphs drupal/field_group drupal/imce drupal/color_field
  ddev exec drush -y pm:enable paragraphs field_group imce color_field bootstrap_italia_paragraph

  echo 'Installing color_field library'
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

  echo 'Install module: Bootstrap Italia Paragraph Accordion'
  ddev exec drush -y pm:enable bootstrap_italia_paragraph_accordion

  echo 'Install module: Bootstrap Italia Paragraph Attachments'
  ddev exec drush -y pm:enable bootstrap_italia_paragraph_attachments

  echo 'Install module: Bootstrap Italia Paragraph Carousel'
  ddev exec drush -y pm:enable bootstrap_italia_paragraph_carousel

  echo 'Install module: Bootstrap Italia Paragraph Map'
  ddev composer require drupal/geofield drupal/leaflet
  ddev exec drush -y pm:enable geofield leaflet bootstrap_italia_paragraph_map

  echo 'Install module: Bootstrap Italia Paragraph Webform'
  ddev composer require drupal/webform wikimedia/composer-merge-plugin
  ddev exec drush -y pm:enable webform webform_bootstrap webform_ui bootstrap_italia_paragraph_webform

  echo 'Install module: Bootstrap Italia Paragraph views carousel'
  ddev exec drush -y pm:enable bootstrap_italia_views_carousel

fi

if [ "$enable_content_type" == "y" ]; then
  echo "==[ Install content type ]=="

  echo 'Install module: Bootstrap Italia content News'
  ddev composer require drupal/toc_js drupal/focal_point
  ddev exec drush -y pm:enable responsive_image toc_js focal_point  \
    bootstrap_italia_paragraph bootstrap_italia_paragraph_accordion \
    bootstrap_italia_paragraph_attachments bootstrap_italia_paragraph_map \
    bootstrap_italia_paragraph_webform bootstrap_italia_content_news

  curl --request GET -sL \
    --url 'https://github.com/jgallen23/toc/archive/refs/heads/greenkeeper/update-all.zip' \
    --output './web/libraries/master.zip'

  echo 'Installing toc_js library'
  unzip ./web/libraries/master.zip -d ./web/libraries/
  mv ./web/libraries/toc-greenkeeper-update-all/dist ./web/libraries/toc
  rm -Rf ./web/libraries/toc-greenkeeper-update-all
  rm -Rf ./web/libraries/master.zip
fi

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
