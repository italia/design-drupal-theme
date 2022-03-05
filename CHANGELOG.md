# Summary 8.x-0.23
## Release notes

## All changes

## Deprecated feature
- `macro.icon` (deprecated in 0.11)
- `macro.password_icon`, if you use this feature switch to `components/icon/password_icon` (deprecated in 0.21)
- `bootstrap_italia/templates/views/views-view-unformatted--novita--novita-evidenza.html.twig` (deprecated in 0.22)
- `bootstrap_italia/templates/views/views-view-unformatted--novita--novita-home.html.twig` (deprecated in 0.22)
- `italiagov/src/components/card/card-hp-intro.twig` (deprecated in 0.22)
- `bootstrap_italia.libraries.yml` (deprecated in 0.22)

# Summary 8.x-0.22
## Release notes
Big news in this release:

- update of the bootstrap-italia library to version 1.5.2;
- variants of themes for multisite sub-themes (sponsored by https://www.drupal.org/akabit);
- various closed issues (look at All changes);
- some templates are now deprecated.

Below are the changes to the sub-theme.

1. `/italiagov.info.yml`
  - Remove `seven/global-styling: false` at `libraries-override` (line ~12), like:
  ```
  libraries-override:
    bootstrap_italia/global: false
  ```
  - change ckeditor styles (line ~116)
  ```
  ckeditor_stylesheets:
    - assets/css/bootstrap-italia.css
  ```
2. `/italiagov.libraries.yml`: whole file.
3. `/italiagov.theme`: whole file.
4. `/src/js/index.js`:
   - removed line 1 (`import '../scss/theme.scss';`)
   - For compliance with [#590](https://github.com/italia/bootstrap-italia/pull/590)
     - uncommented line 28 (`import '../../node_modules/bootstrap-italia/src/js/plugins/forms'`)
     - removed line 29 (`import './custom/forms'`)
     - deleted `/src/js/custom/forms.js`
   - Added new components after line 46
     - `import '../../node_modules/bootstrap-italia/src/js/plugins/datepicker-validation.js'`
     - `import '../../node_modules/bootstrap-italia/src/js/bootstrap-italia'`
     - `import '../../node_modules/bootstrap-italia/src/js/plugins/version'`
5. `/src/scss/_fix.scss`: replace the whole file if you haven't edited it, otherwise use diff
6. `/webpack.common.js`: replace entry and output with:
```
  // Entry
  entry: {
    "bootstrap-italia": [paths.src + '/js/index.js', paths.src + '/scss/theme.scss']
  },

  // Output
  output: {
    path: paths.build,
    filename: "js/[name].js",
  },
```
7. `/package.json`: replaced `node-sass` with `sass` and updated all dependencies
  ```
    $ npm remove node-sass
    $ npm install sass --save-dev
    $ npm install bootstrap-italia@^1.5
    $ npm update
  ```
Finally run
```
$ npm run build:prod
$ drush cr
```

## All changes
- Issue #3263341: New release for Bootstrap-italia library
- Issue #3258871: TypeError: MiniCssExtractPlugin is not a constructor
- Fix: removing unnecessary dependencies ([aef4f7c3](https://git.drupalcode.org/project/bootstrap_italia/-/commit/aef4f7c332a4becb45c3f1dce828cc16f9a6643c))
- Fix: Removal of non-existent style sheets, they are loaded from the sub-theme ([49a0aa3f](https://git.drupalcode.org/project/bootstrap_italia/-/commit/49a0aa3f2c9e380dfd1bcfd9a62da9e4f8a94814))
- Issue #3263808 by Luca Pagani: Filter two columns layout
- Issue #3263332 by arturopanetta: Views: Exposed filters not aligned
- Issue #3260877: Block brandingdelsito quick edit contextual-links inherit logo a colour class
- Fixed tabledrag when bootstrap-italia is set as admin theme
- Issue #3222822 by maurizio_akabit: Change the main view template
- Issue #3266502: Develop a feature that allows you to reuse scss and js with variations in multisite sub-themes (sponsored by https://www.drupal.org/akabit)
- Added suggestions for image formatter

## Deprecated feature
- `macro.icon` (deprecated in 0.11)
- `macro.password_icon`, if you use this feature switch to `components/icon/password_icon` (deprecated in 0.21)
- `bootstrap_italia/templates/views/views-view-unformatted--novita--novita-evidenza.html.twig`
- `bootstrap_italia/templates/views/views-view-unformatted--novita--novita-home.html.twig`
- `italiagov/src/components/card/card-hp-intro.twig`
- `bootstrap_italia.libraries.yml`

# Summary 8.x-0.21
## Release notes

## All changes
- Fix for empty values in button component
- ddev script updated, added Drupal 10 option.
- Added LICENSE, CONTRIBUTING.md and various things
for synchronization with the github repository.
- Issue #3258460 by desix75: Support drush 11.
- Fix: empty value passed to file_url.
- Fix: example hot mode in libraries.
- Added user theme suggestions
- Issue #3259930: xlink:href deprecated
- Issue #3260099: Drupal 10 compatibility for Bootstrap Italia.
QuickEdit is deprecated in Drupal Core 9.3 and removed in Drupal Core 10

# Summary 8.x-0.20
## Release notes
This is a major update of the sub-theme development tools.
If you use `italiagov` starter kit do this to update correctly:

- Delete in your sub-theme:
  - /assets
  - /node_modules
  - /package.json
  - /package-lock.json
  - /webpack.config.js
- Copy the following files from
`/themes/contrib/bootstrap_italia/var/starter_kits/italiagov/`
into your sub-theme:
  - /.nvmrc
  - /package.json
  - /webpack.*.js
- Run `npm install`
- Reinstall your dependencies, eg: `npm install swiper --save-dev`
if you previously had swiper installed.
- Run `run build:prod && drush cr`

That's all.

**Note**

If you don't use `italiagov` as your sub-theme, note that `sprite.svg`
has changed path, the correct path is `<sub-theme>/assets/svg/sprite.svg`
(Issue #3252337)

In writing these update instructions I assumed that:
- you have a backup of the sub-theme;
- you have tried this upgrade in a test/dev environment;
- you have never edited the files built in `<sub-theme>/asset`.

## All changes
- The webpack configuration has been updated to version 5.
[Guide](https://webpack.js.org/guides/production/)
- Added webpack hot mode
- Issue #3252337: Path mismatch of icons and resources
- Issue #3215311: Il footer non prende correttamente il template twig
- Issue #3215313: icona it-expand su ente_appartenenza in modalità responsive
- Issue #3215315 by braintec: Breadcrumb su cerca
- In the `header-slim-menu` region it is possible to insert a menu
with a generic name.
- [Bug Fix] Icon component - Switch merge order (classes + icon_classes).
In some cases js scripts only work correctly if the custom class is before
the icon characteristics.
- Fix accessibility attribute in all block container (`data-block`).
- Fix accessibility attribute in menu-header-nav (`aria-expanded`).
- Added maintenance page

## Deprecated function
- `macro.icon` (this feature has been deprecated in version 0.11).
- `macro.password_icon` is now deprecated, if you use this feature switch to `components/icon/password_icon`

# Summary 8.x-0.19
## Release notes
In this version some bugs have been fixed, the development mode of the theme
has been corrected and new settings have been added
to the theme (container sections).

If you use `italiagov` starter kit, update your sub-theme using the files in
`/themes/contrib/bootstrap_italia/var/starter_kits/italiagov` as a reference :
- update `"scripts":` statement in `<your-sub-theme>/package.json`

## All changes
- Fixed condition in suggestion.
- Removed support for field_data_recur.
- Fixed link description. Improved compatibility with language
and other modules.
- Issue #3232091 by nessunluogo: Child theme dev webpack script doesn't work.
- Issue #3240864 by scalas89: Check class on hook_theme_suggestions_page_alter.
- Issue #3248290: Contenuti del blocco contenuti non vengono visualizzati
e layout non si adatta a larghezze superiori a 1200px
- Issue #3251536: I link del blocco cambio lingua non funzionano.
- Fixed breadcrumb separator on last item

# Summary 8.x-0.18
## Release notes

If you use `italiagov` starter kit, update your sub-theme using
the files in `/themes/contrib/bootstrap_italia/var/starter_kits/italiagov`
as a reference :

- add `<your-sub-theme>/src/scss/mixin/_modal-fullscreen.scss` file
- add one line that contains `@import "mixin/modal-fullscreen";`
in `<your-sub-theme>/src/scss/theme.scss`
- update `<your-sub-theme>/src/scss/_fix.scss`,
we added 2 rules (from line 49 to 56).
- update `<your-sub-theme>/src/js/custom/form.js`

**If you use `components:^2`, it is very important to update the syntax
for declaring twig namespaces**.
At the end of the file `/themes/custom/<sub-theme>/<sub-theme>.info.yml`,
you need to replace this code
```
component-libraries:
  italiagov_components:
    paths:
      ./src/components
```
with this code
```
components:
  namespaces:
    italiagov_components:
      - ./src/components
```
If you don't make the change, when you upgrade to `components:^3` the theme
will be broken (https://www.drupal.org/project/components).

Go to the sub-theme settings (`/admin/appearance/settings/italiagov`),
then click on `Content` -> `Search modal` and choose the size you prefer,
then click on "Save configuration"

Run in your sub-theme
```
$ npm run build:prod
$ drush cr
```

## All changes
- Added Hero component https://italia.github.io/bootstrap-italia/docs/componenti/hero/
- Added Avatar with text component
https://italia.github.io/bootstrap-italia/docs/componenti/avatar/#avatar-con-testo-aggiuntivo
- Fixed the accessibility issue for Back to top component, we added attribute
`title` to `a` tag
- Fixed modal search. When the navbar is sticky, the modal disappears.
- Fixed forms label width, the size of the label in some cases was zero.
- Fixed callout component. The message was not displayed.
- Drupal coding standard.
- Cards pattern: added the icon to teaser variant.
- Issue #3198903 by braintec: breadcrumb cache issue.
- Added timeline component.
- Updated the syntax for declaring twig namespaces.
- Updated ddev script (`var/bin/start-ddev-test`): you can choose which
versions to test
- Added new image style for image styles module.
- Generic names can be used in the footer menus
- Fixed mismatch variable in `templates/patterns/cards/pattern-card.html.twig`
- Added compatibility for `changed date` field and `date_recur` module
- Fixed hook name `hook_theme_suggestions_page_alter()`
- Added taxonomy suggestions
- Fixed bug that didn't show the card date with the image
on the `/patterns` page.


# Summary 8.x-0.17
## Release notes
Fix social icons on theme settings

# Summary 8.x-0.16
## Release notes
1) In your sub-theme
```
$ npm update
```

2) If you use `italiagov` starter kit, update your sub-theme with the files
inside in `/thmes/contrib/bootstrap_italia/var/starter_kits/italiagov`:
   - `/themes/custom/<your-sub-theme>/webpack.config.js` from line  67 to 70
   - delete `/themes/custom/<your-sub-theme>/src/js/custom/isIE.js`
   - `/themes/custom/<your-sub-theme>/src/js/index.js` uncomment line 21
   and remove line 22, like:

```
20 import '../../node_modules/bootstrap-italia/src/js/plugins/sticky-wrapper'
21 import '../../node_modules/bootstrap-italia/src/js/plugins/ie'
22 import '../../node_modules/bootstrap-italia/src/js/plugins/fonts-loader'
```

3) Run in your sub-theme
```
$ npm run build:prod
$ drush cr
```

## All changes
- Fix image folder
- Update bootstrap-library
to 1.4.3 https://github.com/italia/bootstrap-italia/releases
- Removed from starter kit old cards and templates.
    - card-hp-intro
    - region-home-first-row-full-width
    - region-home-second-row-full-width
    - views-view-unformatted-govitalia-hp-intro-second-row

# Summary 8.x-0.15
## Release notes
If you update from 0.11 see 0.12 release notes and update your sub-theme files.

## All changes
- views-view.html.twig: fixed pager wrapper
- Removed old files from base theme:
  - `src/js`,
  - `src/scss`,
  - `src/fonts` and `src/images`;
  - `webpack.config.js` and `package.json`
- Card pattern updated: title optional, custom variant.
- Card component updated
- Fixed Dependencies

# Summary 8.x-0.14
## Release notes
If you update from 0.11 see 0.12 release notes and update your sub-theme files.

## All changes
- New feature: upload logo in svg format
- Drupal 9 compatibility
- Fix card_category bug: restore 4019c2c720c670fcc2b0ce3a72f66922cfa49f1c
version

# Summary 8.x-0.13
## Release notes
Saltata per scaramanzia e per questioni di stato quantistico
quando si sviluppa una v13.

# Summary 8.x-0.12
## Release notes
See README for enable optional features

Update file in your sub-theme:
- `config/optional/block.block.smallprints.yml`
- `config/optional/block.block.slim.yml`
- `config/install/italiagov.settings.yml`
- `src/scss/theme.scss`
- `src/scss/paragraphs/*`
- `src/scss/misc/_patterns-overview.scss`
- `src/components/cards/card-hp-intro.twig`
- `templates/layout/regions/region--home-first-row-full-width.html.twig`
- `templates/layout/regions/region--home-second-row-full-width.html.twig`
- `templates/patterns/cards/card-hp-intro.patterns.yml`
- `templates/patterns/cards/pattern-card-hp-intro.html.twig`
- `templates/views/views-view-unformatted--govitalia-hp-intro--second-row.html.twig`

Build assets and drush cr

## known issues
- After upgrade to 0.12, if main menu not work fine, go to
"Admin -> Appearance -> Your sub-theme Settings -> Navigazione -> Menu principale"
then choice "Large (>= 992px)" option and save.
- When your views use AJAX, exposed filter and UI Patterns you receive
"Pattern Views row plugin does not support preview.".
This is the [Issue](https://github.com/nuvoleweb/ui_patterns/issues/239)
and this is the [patch](https://github.com/nuvoleweb/ui_patterns/pull/269)
- You don't see Views Theme Suggestions:
[issue](https://drupal.stackexchange.com/questions/249854/i-dont-see-views-theme-suggestions)
and [patch](https://www.drupal.org/files/issues/2020-05-16/2118743-183-twig-debug-info.patch)
- Dependencies https://www.drupal.org/project/bootstrap_italia/issues/3169891

## All changes
- Issue #3139480: Add image style configurations from optional module
- Issue #3099905: Image looks broken on all devices
- Remove wrong configuration: image quality 100%
- Fix megamenu <nolink> option
- Fix bold all items on menu-recursive.twig
- Add theme breakpoints
- Fix Megamenu title
- Fix sidebar options: font weight
- Add paragraphs base module
- Switch to classy base theme
- Add block configuration for: slim menu and small prints menu
- Add paragraph overlay
- Add a module to manage image styles with focal_point and
add setting for quality image
- Issue #3171227 by gabrimonfa: Wrong href in header login link in
multisite using subdirectories
- Issue #3171528: Card width not 100% of container
- Fix 'Ente di appartenenza' collapsed
- Rearrange e sync settings, Fix annotations in theme-settings.inc
- Review hook and suggestions
- Refactoring card Pattern
- Add Card Home Page in sub-theme
- Theming title and subtitle in sub-theme with "Comune template"
and various specific component
- Fix logo image responsive if it's a raster image
- Fix navbar tag
- Add a link to chips component
- Add dropdown component
- Add views-view.html.twig without row content wrapper
- Fix Suggestions with context module
- Removed wrong class `mt-5` in `footer.it-footer`
- Issue #3169891 by robertom: Theme dependencies break config install
or config import

# Summary 8.x.0.11
## Release notes
Update/add file in your sub-theme with:
- `var/starter_kits/italiagov/config/install/italiagov.settings.yml`
- `var/starter_kits/italiagov/src/js/custom/component-library-initialization.js`
- `var/starter_kits/italiagov/src/js/custom/isIe.js`
- `var/starter_kits/italiagov/src/js/index.js`
- `var/starter_kits/italiagov/src/scss/_fix.scss`
- `var/starter_kits/italiagov/src/scss/_variables.scss`
- `var/starter_kits/italiagov/src/scss/layout/_layout.scss`
- `var/starter_kits/italiagov/src/scss/layout/_sidebar.scss`
- `var/starter_kits/italiagov/src/scss/misc/_patterns-overview.scss`
- `var/starter_kits/italiagov/src/scss/navigation/_header-nav.scss`
- `var/starter_kits/italiagov/src/scss/navigation/_navigation.scss`
- `var/starter_kits/italiagov/src/scss/variables/_palette-red.scss`

In your sub-theme
- rename: `italiagov/src/scss/layout/page--user--login.scss` → `italiagov/src/scss/layout/_page--user--login.scss`
- delete: italiagov/src/scss/misc/patterns-overview.scss
- If the file `italiagov/theme-settings.php` is present in your sub-theme,
and you have not modified it, you can delete it and save the settings
from appearance -> your sub-theme

Build assets with `npm run build:prod` and `drush cr`

## Important Note
**In the next release will be removed scss, js, webpack.config.js
and package.json from the main theme, please switch to sub-theme if you use
the main theme as a default theme.**

## All changes
- Callout component and UI
- Add icon component, **macro.icon is deprecated**
- Theme for "https://<site>/patterns"
- Update avatar component
- Add tooltip component
- Fix drupal toolbar
- Fix "isIe() is not a function"
- Add chips component
- Add sticky header feature
- Add overlay component
- Add link-list component
- Add menu link-list recursive component
- Add pagination components
- Theming tables
- Add palette
- Add modal component
- New version for Main menu
- Add theme options for the main menu and sidebar menu
- New Feature: two menus in main navbar and any menu can be inserted
into the navbar.
- Theme for menu title block in sidebar
- Add the current page to breadcrumb

# Summary 8.x.0.10
## Release notes
Update THEME.info.yml in your sub-theme with the new version placed
in `/var/starter_kits/italiagov/italiagov.info.yml`.
Please update `<your-theme>/src/scss/_fix.scss` with the new version placed
in `/var/starter_kits/src/scss/_fix.scss`.

**This is the last release that support the use main theme
as default theme. Please switch to sub-theme.**

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
- Fix console error "Problema di sicurezza: i contenuti in x non possono
caricare dati da https://x/assets/icons/sprite.svg."
- Add 'back to top' component
- Add suggestions for views unformatted
- Add full width button to slim header
- Add theme options: Slim header light, Header center light and
header center small
- Rearrange theme settings
- Expose card component through Drupal UI

# Summary 8.x-0.9
## Release notes
This version implements child themes, and we recommend that you set
the child theme as the default theme.
Setting the main theme as the default theme is obsolete,
but for compatibility with previous versions it will be kept until version 1.0.
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
```
  $ drush --include="web/themes/contrib/bootstrap_italia" bootstrap_italia:new-sub-theme theme_name
```
- Drush commands, compatibility with drush 10
- Remove Drush commands
- Add sub-theme in `/var/starter_kits/italiagov`
- Add ddev start script in `/var/bin/start-dev-test.sh`
for test in docker container
- Update README.md
- Add comments in `var/bin/start-dev-test.sh`
- Auto-configure default block during sub-theme installation
- Add regions:
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
- Fix drupal version on the README.md
- Add sidebars regions to template
- Remove "compilato" form feedback
- CSS Style for block demo view
- Remove mt-5 on content region

# Summary 8.x-0.8
- Removing compatibility with Core 9.x

# Summary 8.x-0.7

- Update dependencies: bootstrap_italia 1.3.9 -> 1.3.10
- Sub-theme skeleton
- I have moved the components' folder from templates to src
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
- Issue #3100956 by arturopanetta: In the mobile breakpoint,
the expansion icon is not displayed under "Ente di appartenenza"

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
- Issue #3099937 by arturopanetta:
Save and Preview buttons looks untidy on the node pages
- Add ckeditor stylesheets
