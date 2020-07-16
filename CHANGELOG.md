# Summary 8.x-0.9
- Update webpack dependencies and webpack configuration
- Update bootstrap_italia 1.3.10 -> 1.4.0
- Added theme dependency declaration
- Review configuration: webpack.config.js, package.json and composer.json
- Add drush command skeleton

      $ drush --include="web/themes/contrib/bootstrap_italia" bootstrap_italia:new-sub-theme theme_name

- Drush commands, compatibility with drush 10
- Remove Drush commands
- Add sub-theme in /var/starter_kits/italiagov
- Add ddev start script in /var/bin/start-dev-test.sh for test in docker container
- Update README.md
- Add comments in var/bin/start-dev-test.sh

# Summary 8.x-0.8
- Removing compatibility with Core 9.x

# Summary 8.x-0.7

- Update dependencies: bootstrap_italia 1.3.9 -> 1.3.10
- Sub-theme skeleton
- I have moved the components folder from templates to src
- Fix mistake in info.yml line 12
- Issue #3143842 by karishmaamin: Property 'base theme' needs to be set
- webpack.config.js fix double slash
- Issue #3157569 Set NAME and URL for "Ente di Appartenenza"
- Issue #3146293 Automated Drupal 9 compatibility fixes
- Core ^8 || ^9

# Summary 8.x-0.6

- Add class 'form-text' and 'text-muted' to form description
- Icon show/hide password field
- Webform: support for 'form-control-plaintext' class
- Update dependencies: bootstrap_italia 1.3.8 -> 1.3.9
- Remove fix https://github.com/italia/bootstrap-italia/pull/417

# Summary 8.x-0.5

- Disable webform_bootstrap and webform_template module
- Enable inline_form_errors core module
- Fix margin-top on 'form-text' bootstrap 4
- Add form validation and feedback message
- Layout Login form, register e recovery password
- Add body classes

# Summary 8.x-0.4

Bug
- #3100956 by arturopanetta: In the mobile breakpoint, the expansion icon is not displayed under "Ente di appartenenza"

New
- Optimize libraries.yml
- Add table template
- Add ui_patterns module
- Add blockquote pattern
- Form: input, form-element, textarea
- Add breadcrumb template
- Add local tasks nav tabs template
- Add content region
- Add user login template
- Add checkbox template
- Add radio template
- Add select template
- Add components module
- #3099937 by arturopanetta: Save and Preview buttons looks untidy on the node pages
- Add ckeditor stylesheets
