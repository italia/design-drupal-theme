# Summary 8.x.0.10
## Release note
Update THEME.info.yml in your sub-theme with the new version placed in "/var/starter_kits/italiagov/italiagov.info.yml".
Please

Update "<your-theme>/src/scss/_fix.scss" with the new version placed in "/var/starter_kits/src/scss/_fix.scss"

**This is the last release that support the use main theme as default theme. Please switch to sub-theme.**

## All changes
- Add cards components
- Issue #3131103 by braintec: fix theme path function
- Breadcrumb settings and component template
- Add classes parameter to macro icons
- Refactoring theme hook
- Add more suggestions to block
- Add menu template to secondary sidebar
- Fix various typo
- Sub-theme: inherit settings
- Refactoring settings variables name
- Header slim: add avatar
- Add alert component template
- Add input-number template
- Fix console error "Problema di sicurezza: i contenuti in x non possono caricare dati da https://x/assets/icons/sprite.svg."
- Add 'back to top' component
- Add suggestions for views unformatted
- Add full width button to slim header
- Add theme options: Slim header light, Header center light and header center small
- Rearrange theme settings
- Expose card component through Drupal UI

# Summary 8.x-0.9
## Release note
This version implements child themes and we recommend that you set the child theme as the default theme. Setting the main theme as the default theme is obsolete, but for compatibility with previous versions it will be kept until version 1.0.
Before updating make sure that:
- the Italian language is set as "default language"
- the English language is installed
The instructions are in the README.md file.
Make a backup before upgrading to version 0.9.

## All changes
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
- Auto-configure default block during sub-theme installation
- Add reggions:
  - Before content: full width, first, second, third a fourth
  - After content: full width, first, second, third a fourth
 - Add home template
 - Add home page regions
   - First row: full width, first, second, third a fourth
   - Second row: full width, first, second, third a fourth
   - Third row: full width, first, second, third a fourth
   - Fourth row: full width, first, second, third a fourth
   - Last row: full width
- Fix drupal version on start-dev-test.sh
- Add description ddev container
- Fix drupal version on README.md
- Add sidebars regions to template
- Remove "compilato" form feedback
- CSS Style for block demo view
- Remove mt-5 on content region

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
