# Summary 2.12.0
## Release notes

🎉🎉🎉 With this 60th release we celebrate 5 years of development of this project.

This release brings significant updates and improvements.
The Bootstrap Italia library has been upgraded to version 2.12.1,
introducing changes to components and default configurations,
such as setting the default size of the header container to `container-xxl`.
Skiplinks functionality has been enhanced to improve usability
and customization options.

A key highlight of this release is full compatibility with Drupal 11,
ensuring smooth integration with the latest core updates.
Additionally, several accessibility fixes have been implemented
including updates to breadcrumb and footer sections.
Additionally, the code has been updated to achieve compliance
with PHPStan level 7 (compared to level 5 in the previous version),
ensuring more rigorous code analysis and overall greater reliability.

Please note that this release includes breaking changes that require
manual intervention, particularly in managing specific components like menus,
link-lists, and timelines.
Comprehensive instructions are provided to guide you through these updates.

### Upgrade from CommonJS to ECMAScript Modules (ESM)

With this release, the sub-theme build process moves from CommonJS
to ECMAScript Modules (ESM).
This shift is intended to leverage modern JavaScript features,
improve compatibility with current tooling,
and ensure better optimization opportunities during the build process.

### ⚠️ Breaking changes!!!
This release introduces breaking changes that require your attention.
The following changes must be handled manually and
cannot be managed automatically.

1. Menus and link lists: if an item is set as a title without a link,
it will now be rendered with an `h<n>` tag instead of a `span`. If not handled
properly, this may lead to accessibility issues. This change only affects cases
where titles without links are used in menus or lists.
https://italia.github.io/bootstrap-italia/docs/organizzare-i-contenuti/liste/#intestazione-e-divisore

2. Similar to the previous point,
but it applies to the "Multiline with icon" variant.
https://italia.github.io/bootstrap-italia/docs/organizzare-i-contenuti/liste/#multiline-con-icona

3. Similar to the previous points,
but it applies to the "With additional text, multiple actions,
and metadata" variant.
https://italia.github.io/bootstrap-italia/docs/organizzare-i-contenuti/liste/#con-testo-aggiuntivo-azioni-multiple-e-metadata

4. Similar to the previous points, but it applies to the "Timeline" component
https://italia.github.io/bootstrap-italia/docs/componenti/timeline/

5. **[Important!] Before applying this update**,
you need to uninstall the "Bootstrap Italia Text Editor"
(`drush pm:uninstall boostrap_italia_text_editor`) submodule.
Don't worry, no configuration will be lost.
If you are using a custom CKEditor 4 module, it will continue to work fine.

## Update libraries
### Vanilla libraries
If you use vanilla libraries, download bootstrap-italia v2.12.1
and update `<your-sub-theme>/dist` folder.

### Custom build
If you use custom libraries built with webpack, do:
```shell
$ npm install bootstrap-italia@2.12.1 --save-exact
$ npm install sass-loader@^16 webpack-merge@^6
$ npm uninstall svg-sprite-loader rimraf
$ npm install svg-chunk-webpack-plugin --save-dev
$ npm install terser-webpack-plugin css-minimizer-webpack-plugin --save-dev
$ npm update
```

Using as reference the files contained in `/var/starter_kits/italiagov/...`
and update `/themes/custom/<your-sub-theme>`
- add:
  - `svgo.config.js`
- update:
  - `<your-sub-theme>.theme` (example: `italiagov.theme`)
  - `src/scss/_bootstrap.scss`
  - `src/js/index.js` (added .js extension to imported files)
  - `webpack.*.js`
  - `package.json` (add field `"type": "module"`)
- remove:
  - `webpack.check.js`

Add the `.js` extension when importing a javascript otherwise you will receive
an error during the build process.
Before:
```
import './example'
```
after
```
import './example.js'
```

Finally execute:
```shell
$ npm run build:prod
$ drush cr
```

### CDN libraries
If you load libraries from CDN, update `<sub-theme>/<sub-theme>.liraries.yml`
and clear cache.

## Update your sub-theme for Drupal 11
Change `core_version_requirement` in your `<sub-theme>/<sub-theme>.info.yml`
from: `core_version_requirement: ^9 || ^10` to
`core_version_requirement: ^10.3 || ^11`

## All changes
- feat(components,card): review 2.11.0
- feat(components,chip): review 2.12.0
- feat(components,backtotop): review 2.12.0
- feat(components,forms): review 2.11.0
- feat(components,header): review 2.11.0 and change default size to xxl
- feat(components,list-image,gallery,icon): review 2.11.0
- feat(components,list,link-list)!: review 2.11.0 and manage breaking change
- feat(components,skiplinks): review 2.11.0 and add block for override
- feat(components,timeline)!: review 2.11.0 and manage breaking change
- feat(modules): image style drupal 11 compatibility
- feat(modules): news example drupal 11 compatibility
- feat(modules): paragraph content drupal 11 compatibility
- feat(modules): paragraph accordion drupal 11 compatibility
- feat(modules): paragraph attachments drupal 11 compatibility
- feat(modules): paragraph callout drupal 11 compatibility
- feat(modules): paragraph carousel drupal 11 compatibility
- feat(modules): paragraph citation drupal 11 compatibility
- feat(modules): paragraph gallery drupal 11 compatibility
- feat(modules): paragraph hero drupal 11 compatibility
- feat(modules): paragraph map drupal 11 compatibility
- feat(modules): paragraph node reference drupal 11 compatibility
- feat(modules): paragraph section drupal 11 compatibility
- feat(modules): paragraph timeline drupal 11 compatibility
- feat(modules): paragraph webform drupal 11 compatibility
- feat(modules): text editor (on ckeditor4) remove deprecated
- feat(modules): text editor2 drupal 11 compatibility
- feat(modules): views styles modules drupal 11 compatibility
- feat: base-theme drupal 11 compatibility
- feat: sub-theme drupal 11 compatibility
- feat: upgrade sub-theme from CommonJS to ECMAScript Modules (ESM)
- feat: up to bootstrap-italia 2.12.1 library
- fix: phpstan level 7 compliance
- fix(a11y): add aria label in breadcrumb section
- fix(a11y): add aria label in footer sections
- fix(modules): use div tag for sections wrapper

# Summary 2.11.0
The version 2.11, even though it was not released, is fully incorporated
into version 2.12. This means that all the changes, fixes, and new features
planned for 2.11 are available in 2.12.

# Summary 2.10.0
The version 2.10, even though it was not released, is fully incorporated
into version 2.12. This means that all the changes, fixes, and new features
planned for 2.10 are available in 2.12.

# Summary 2.9.0
The version 2.9, even though it was not released, is fully incorporated
into version 2.12. This means that all the changes, fixes, and new features
planned for 2.9 are available in 2.12.

# Summary 2.8.2
## Release notes
This release fixes some issue and add small features.

If you are upgrading from versions prior to 2.8.0, please read the 2.8.0
release notes as it contains several breaking changes.

## All changes
- feat(suggestions): add route to block suggestions
- feat(suggestions): add page title suggestions
- fix(modules): update editor configuration
- fix(modules): update map configuration
- fix(suggestions): issue #3387106 Invalid file name suggestion

# Summary 2.8.1
## Release notes
This release fixes the issue documented here:
https://github.com/italia/bootstrap-italia/issues/1119

If you are upgrading from versions prior to 2.8.0, please read the 2.8.0
release notes as it contains several breaking changes.

## Update libraries
### Vanilla libraries
If you use vanilla libraries, download bootstrap-italia v2.8.8
and update `<your-sub-theme>/dist` folder.

### Custom build
If you use custom libraries built with webpack, do:
```shell
$ npm install bootstrap-italia@2.8.8 --save-exact
$ npm update
$ npm run build:prod
$ drush cr
```

## All changes
- feat(components,callout): review v2.8.8
- feat(libraries): up to bootstrap-italia v2.8.8
- fix(template): missing attributes in menu-local-tasks


# Summary 2.8.0
## Release notes
This version 2.8.0 of Bootstrap Italia introduces new features, improvements,
and bug fixes.
There are some significant changes that may require attention during
the update, including changes in the style build process and
the removal of the "Comuni" variant.
Please make sure to read the following sections carefully to ensure
a smooth transition to the new version.

### Breaking changes!!!
1. After the update check the "Theme Settings -> Navigation settings ->
Breadcrumb -> Include the current page" option if you want to display
the current page as the last element of the breadcrumb.
2. The "Comuni" variant has been removed, for more information see
https://github.com/italia/bootstrap-italia/commit/35d56a266f27b53b90c4c66be0bc23513e1a86bb,
new version are in https://github.com/italia/design-comuni-pagine-statiche
3. If you use the twig namespace `@bootstrap_italia_paragraph` in your
sub-theme, replace it with `@bootstrap_italia_paragraph_components`,
issue #3449377 highlighted a bug that caused this change.
4. The style build process has changed, new features have been added,
if you want to use the new features you need to update your sub-theme
as described in the following paragraphs.
If you don't want the new features you don't have to change anything.
It's almost a breaking change :).

**Refresh all caches.** `drush cr`

### Known issues
- Callout component https://github.com/italia/bootstrap-italia/issues/1119

## Update libraries
### Vanilla libraries
If you use vanilla libraries, download bootstrap-italia v2.8.7
and update `<your-sub-theme>/dist` folder.

### Custom build
If you use custom libraries built with webpack, do:
```shell
$ npm install bootstrap-italia@2.8.7 --save-exact
$ npm install copy-webpack-plugin@^12 --save-dev
$ npm install css-loader@^7 --save-dev
$ npm install postcss-loader@^8 --save-dev
$ npm install sass-loader@^14 --save-dev
$ npm install style-loader@^4 --save-dev
$ npm install webpack-dev-server@^5 --save-dev
$ npm update
$ npm run build:prod
$ drush cr
```
Using as reference the files contained in `/var/starter_kits/italiagov/...`
and update `/themes/custom/<your-sub-theme>`
- update:
  - `.nvmrc`
  - `src/scss/_bootstrap-italia.scss`
  - `src/scss/theme.scss`
  - `src/scss/ckeditor5.scss`
  - `webpack.common.js`
- rename:
  - `src/scss/custom/_palette.sccs` in `_colors_vars.scss`
- add:
  - `src/scss/_bootstrap.scss`
  - `src/scss/_bootstrap_ckeditor5.scss`
  - `src/scss/_bootstrap-italia_ckeditor5.scss`
  - `src/scss/custom/_bootstrap_configuration.sccs`
  - `src/scss/custom/_custom_ckeditor5.sccs`
- delete:
  - `<your-sub-theme>/src/scss/custom-comuni/*`
  - `<your-sub-theme>/src/scss/ckeditor5-comuni.scss`
  - `<your-sub-theme>/src/scss/theme-comuni.scss`

## Update modules
To update "Paragraph Timeline" run:
```shell
$ drush config:import --source=/absolute/path/drupal/web/themes/contrib/bootstrap_italia/modules/bootstrap_italia_paragraph_timeline/config/optional/ --partial
```

If you use the experimental module `boostrap_italia_text_editor2` run:
```shell
$ drush config:import --source=/absolute/path/drupal/web/themes/contrib/bootstrap_italia/modules/bootstrap_italia_text_editor2/config/optional/ --partial
```

## All changes
- feat(component): add point-list component
- feat(component): add data-attribute to pager components
- feat(component): add blocks to modal component
- feat(component,breadcrumbs): add option to include current page
- feat(component,megamenu): review 2.8.0
- feat(component,socials): add Threads
- feat(core,performance): Added an option in the Library settings to specify
  whether fonts are loaded via CSS
- feat(deps): up node version to 20 (lts/iron)
- feat(libraries)!: remove comuni variant
- feat(libraries): review of the style build process, ckeditor customization
and bootstrap-italia variants
- feat(modules): add point-list component to timeline paragraph
- feat(suggestion): add views_view suggestion
- feat(template): add block footerEnd in footer template
- fix(a11y): add correct landmark attribute to skip-links
- fix(a11y): remove wrong landmark attribute from navbar
- fix(a11y): remove wrong aria-label attribute from navbar
- fix(a11y): add aria-description attribute to navbar
- fix(a11y): add aria-label to login navbar
- fix(a11y): remove wrong landmark attribute from pagination
- fix(a11y): add unique aria-label attribute to pagination
- fix(a11y): landmark h1 home, footer and remove duplicate id in home
- fix(component,accordion): review v2.8.2, add demo, improve code
- fix(component,alert): review v2.8.2
- fix(component,avatar): review v2.8.2
- fix(component,button): review v2.8.2
- fix(component,card): review v2.8.2
- fix(component,carousel): review v2.8.2
- fix(component,chip): review v2.8.2
- fix(component,form): fix bad practice for adding classes
- fix(component,form): manage breaking change prepend input v2.8.0
- fix(component,form): review textarea v2.8.2
- fix(component,hero): review v2.8.2
- fix(component,image): refactoring
- fix(component,input-number): review v2.8.2
- fix(component,menu-recursive): set a default value if empty title attribute
- fix(component,menu-recursive): empty variables in recursive macro
- fix(component,modal): review v2.8.2
- fix(component,pagination): review v2.8.2
- fix(component,select): review v2.8.2
- fix(component,timeline): review v2.8.2
- fix(component,field): fixed badges overflowing the container
- fix(core,js): fix mutation is null when a scrolled page is refreshed and
big_pipe has not finished loading
- fix(module,ckeditor5): fix The <img> tag is not yet supported by
the Style plugin
- fix: issue #3368907
- fix(sec): phpstan --level 5
- Fix!: issue #3449377 bi-paragraph-base.html.twig not found

# Summary 2.7.2
## Release notes
This release brings significant enhancements and fixes by updating
compatibility to Bootstrap Italia library version 2.7.7.

New Features:
- The attachments component can now automatically identify file types and
display a specific icon. To activate this feature, navigate to
the theme settings and enable it manually;
- You can now choose the tag for the accordion titles according
to your preferences;
- Customize the colors and style of the "Share" component directly
through code. A graphical interface for this feature is still in development;
- Added a new suggestion: you can now theme Content Types in relation
to the 'view-mode'.

Fixes:
- Addressed accessibility issues and errors identified through analysis
with tools such as WAVE, MAUVE++, and similar.

For more details, please refer to the "All changes" section.

## Update libraries
### Vanilla libraries
If you use vanilla libraries, download bootstrap-italia v2.7.7
and update `<your-sub-theme>/dist` folder.

### Custom build
If you use custom libraries built with webpack, do:

```shell
$ npm install bootstrap-italia@2.7 --save-exact
$ npm update
$ npm run build:prod
$ drush cr
```

## Update modules
To update "Paragraph Accordion" run:
```shell
$ drush config:import --source=/absolute/path/drupal/web/themes/contrib/bootstrap_italia/modules/bootstrap_italia_paragraph_accordion/config/optional/ --partial
```

## All changes
- feat(deps): up bootstrap-italia library to 2.7.6
- feat(deps): up bootstrap-italia library to 2.7.7
- feat(components,accordion): allow to customize accordion title tag
- feat(components,field): add option to customize title tag
- feat(components,field): field label code optimization
- feat(component,share): add options to customize component
- feat(paragraph_accordion): allow to customize accordion title tag
- feat(patterns,accordion): allow to customize accordion title tag
- feat(suggestions): add suggestion to select field view-mode in all bundles
- feat(template,file): add options to customize component
- fix(paragraph_carousel): remove require from legacy image
- fix(component,icon): fix icon role when element is decorative
- fix(component,share): fix dropdown icon size
- fix(component,share): fix X (ex-twitter) share url
- fix(component,pagination): duplicate aria-current
- fix(template,header): fix attributes search button
- fix(template,links--language): fix attributes search button
- fix(template,menu-nav): the navigation role is unnecessary for element nav
- fix(drupal-core,block-menu): navigation role is unnecessary for element nav
- fix(a11y): aria-controls must point to an element in the same document
- fix(breadcrumb): the navigation role is unnecessary for element nav
- fix(template,layout): the main role is unnecessary for element main
- fix(image): trailing slash on void elements has no effect and interacts badly
  with unquoted attribute values
- fix(input): trailing slash on void elements has no effect and interacts badly
  with unquoted attribute values


# Summary 2.7.1
## Release notes
This release updates the bootstrap-italia library to version 2.7.5 and fixes
several minor bugs. Bootstrap-Italia version 2.7.1 introduces a new component:
the "Footer".
This theme since its first versions (0.x) has used this component in
the same way it was implemented in version 2.7.1 with the only difference
being that the `div.row` elements are now enclosed in a `<section>` tag.
This version incorporates this change and the update is automatic.
If you have made any overrides, be sure to review them.

## Update libraries
### Vanilla libraries
If you use vanilla libraries, download bootstrap-italia v2.7.5
and update `<your-sub-theme>/dist` folder.

### Custom build
If you use custom libraries built with webpack,
Using as reference the files contained in `/var/starter_kits/italiagov/...`,
update:
- `src/js/index.js`
- `src/scss/_bootstrap-italia.scss`

```shell
$ npm install bootstrap-italia@2.7 --save-exact
$ npm update
$ npm run build:prod
$ drush cr
```

## All changes
- feat(deps): up bootstrap-italia library to 2.7.1
- feat(deps): up bootstrap-italia library to 2.7.2
- feat(deps): up bootstrap-italia library to 2.7.3
- feat(deps): up bootstrap-italia library to 2.7.4
- feat(deps): up bootstrap-italia library to 2.7.5
- feat(component,icon): add new icons 2.7.1 e fix Moodle icon
- fix(component,button): in some particular cases the assistive information
was duplicated generating the "Elements with visible text labels do not have
matching accessible names." error
- fix(component,button-badge): fix class in button badge example
- feat(component,demo): add link to example code
- fix(component,footer): wrap `row` with `section` tag for compliance v2.7.1
- fix(footer-menu): fixed the issue of the title without URL reported by
search engines and the visual appearance
- fix(footer-menu): check external links and add aria-label attribute


# Summary 2.7.0
## Release notes
- Updated bootstrap-italia library to 2.7.0.

**Important Change for Developers Overriding Card Component with Twig**

If you're overriding the card component in your Drupal project
using the following code:
```
{% embed '@bi-bcl/card/card.html.twig' with { foo: bar } %}
 {% block cardText %}
  Your custom code
 {% endblock %}
{% endembed %}
```
You need to review your card component override.
In this specific case, we have added the class `font-serif` to the
`<div class="card-text font-serif">...</div>` tag.
For all other use cases of the card component, no action is required.

## Update libraries
### Vanilla libraries
If you use vanilla libraries, download bootstrap-italia v2.7.0
and update `<your-sub-theme>/dist` folder.

### Custom build
If you use custom libraries built with webpack,
Using as reference the files contained in `/var/starter_kits/italiagov/...`,
update:
- `<your-sub-theme>/src/scss/_bootstrap-italia.scss`

```shell
$ npm install bootstrap-italia@2.7 --save-exact
$ npm update
$ npm run build:prod
$ drush cr
```

## All changes
- fix(component,card): compliance with bootstrap-italia >=2.7
- fix(core): switch em to rem fix css
- fix(drupal): toolbar regression with bootstrap-italia >= 2.7
- fix(italiagov): up to bootstrap-italia 2.7
- fix(script): update install script

# Summary 2.6.1
## Release notes
- Updated bootstrap-italia library to 2.6.2.
- Various Fix

## Update libraries
### Vanilla libraries
If you use vanilla libraries, download bootstrap-italia v2.6.2
and update `<your-sub-theme>/dist` folder.

### Custom build
If you use custom libraries built with webpack, do:

```shell
$ npm install bootstrap-italia@2.6 --save-exact
$ npm update
$ npm run build:prod
$ drush cr
```

## All changes
- feat(templates): add new twig blocks in region--header-nav
- feat(templates): add new twig block in block--system-branding-block
  and link_attributes
- fix(deps): bump to bootstrap-italia 2.6.1
- fix(deps): bump to bootstrap-italia 2.6.2
- fix(components,dropdown): fix margin lg-down in dropdown with icon
  and remove wrong space
- fix(components,card): remove empty h3 tag if title is empty
- fix(components,linklist-item): missing class in wrapper
- fix(core): improved performance when fetching the social URL
- fix(patterns,accordion): accordion title description
- fix(suggestions,form): issue #3387106: Invalid file name suggestion
  on Drupal >= 10.1 hook_theme_suggestions_HOOK_alter()
- fix(suggestions,block): issue #3387106: Invalid file name suggestion
  on Drupal >= 10.1 hook_theme_suggestions_HOOK_alter()


# Summary 2.6.0
## Release notes
- Updated bootstrap-italia library to 2.6.0.
- Various bug fix.
- Review library loads.
- Sub-theme update
- New features:
  - button pattern (Crescenzo Velleca);
  - ckeditor5 styles (Arturo Panetta)
  - custom svg icon to sprites built with webpack (Arturo Panetta)
  - H1 in home page (Maurizio Cavalletti)
  - hook to customize bootstrap map with webpack (Arturo Panetta)
  - taxonomy suggestions (Maurizio Cavalletti)
  - view carousel style: add new styles and columns options

### Breaking changes!!!
1. Font loading has been overhauled, it is now more flexible and allows
   experienced developers to customize the sub-theme without going crazy.
2. The same thing was done for the javascript which activates
   all the tooltips automatically;
3. Added `h1` with "site name" in home page layout

Updating is simple, just add two lines to the theme configuration file.
To keep your sub-theme working, edit the
`/themes/custom/<your-sub-theme>/<theme-name>.info.yml` file and add
after `- bootstrap_italia/base` the following strings:

```yaml
  - bootstrap_italia/enable-all-tooltips
  - bootstrap_italia/load-fonts
```
N.B. Note the two spaces before the `-` character, don't delete them.
Use this [file](var/starter_kits/italiagov/italiagov.info.yml) as a reference.

This is the result:
```yaml
# omissis [...]
# Choose libraries to use. Global is managed with theme settings UI.
libraries:
  - italiagov/libraries-ui
#  - italiagov/vanilla
#  - italiagov/custom
#  - italiagov/cdn
#  - italiagov/hot
#  - italiagov/ddev
  - bootstrap_italia/base
  - bootstrap_italia/enable-all-tooltips
  - bootstrap_italia/load-fonts

# Check these settings, they must match the "libraries" choices.
# [...] omissis
```

Check `h1` in home page.

## Update libraries
### Vanilla libraries
If you use vanilla libraries, download bootstrap-italia v2.6.0
and update `<your-sub-theme>/dist` folder.

### Custom build
If you use custom libraries built with webpack, do:
```shell
$ npm install bootstrap-italia@2.6 --save-exact
$ npm install rimraf --save-dev
$ npm update
```
Using as reference the files contained in `/var/starter_kits/italiagov/...`
- update:
  - `<your-sub-theme>/src/scss/_bootstrap-italia.scss`
  - `<your-sub-theme>/src/js/index.js`
  - `<your-sub-theme>/webpack.common.js`
  - `<your-sub-theme>/<your-sub-theme>.info.yml` check `ckeditor5-stylesheets`
- add:
  - `<your-sub-theme>/src/scss/custom/_maps.scss`
  - `<your-sub-theme>/src/scss/custom-comuni/_maps.scss`
  - `<your-sub-theme>/src/scss/_fonts.scss`
  - `<your-sub-theme>/src/scss/ckeditor5.scss`
  - `<your-sub-theme>/src/scss/ckeditor5-comuni.scss`
- add (optional):
  - `<your-sub-theme>/src/js/custom/icons.js`
  - add line `import './icons'` to `<your-sub-theme>/src/js/custom/custom.js`
  - `<your-sub-theme>/src/svg/it-drupal.svg`
```shell
$ npm run build:prod
$ drush cr
```

## Templates changes
- `templates/layout/html.html.twig`
- `templates/layout/page--front.html.twig`

## All changes
- Update callout component to 2.4.1
- Update card subtitle to 2.4.1
- Update steppers to 2.4.2
- update italiagov sub-theme
- update demo code
- Attachment Paragraph: remove required to field File Legacy
- Fix: the dividing line of the sidebar menu is reversed between left and right
- Fix: the expanded element is assigned an incorrect href value which causes
  a 404 error in search engines
- Fix: sticky-menu returns Uncaught TypeError if menu not exists
- Fix: moved the "back to top" component code to the bottom of the page
- Fix(components,icon): sometimes libraries_cdn_icons is not set correctly.
- Fix(components,button): fix button_attributes example
- Fix(sub-modules): fix dependencies syntax
- Fix(suggestions,taxonomy): Term is not defined on line 49
- Fix(toolbar): fix toolbar padding in Drupal 10.1
- Fix(views,accordion): fix wrong views suggestions
- Fix(views,carousel): fix wrong views suggestions
- Fix(views,gallery): fix wrong views suggestions
- Fix(views,list): fix wrong views suggestions,
enable grouping and grouping title options
- Fix(views,timeline): fix wrong views suggestions
- Fix(sub-theme,deps): remove progressbar.js Objects
  [CVE-2023-26133](https://github.com/advisories/GHSA-89qm-hm2x-mxm3)
- New: add custom svg icon to sprites built with webpack
- Add a scss hook to customize bootstrap maps
- Add: term suggestion
- Feat(template)!: add block to home page title
- Feat(sub-theme,ckeditor5): add ckeditor5 styles
- Feat(views,carousel): add new styles and new columns options

# Summary 2.5.0
The version 2.5, even though it was not released, is fully incorporated
into version 2.6. This means that all the changes, fixes, and new features
planned for 2.5 are available in 2.6.

# Summary 2.4.0
The version 2.4, even though it was not released, is fully incorporated
into version 2.6. This means that all the changes, fixes, and new features
planned for 2.4 are available in 2.6.

# Summary 2.3.5
This release fix:
- Fix(components,icon): sometimes libraries_cdn_icons is not set correctly
- Fix(sub-theme): build library in dev mode don't work

## Update custom build
If you use custom libraries built with webpack, update:
- `<your-sub-theme>/src/js/index.js`
  and run
```shell
$ npm update
$ npm run build:prod # or build:dev
$ drush cr
```

# Summary 2.3.4
This release remove autoload for unused components: donuts.

### Custom build
If you use custom libraries built with webpack, update:
- `<your-sub-theme>/src/scss/_bootstrap-italia.scss`
- `<your-sub-theme>/src/js/index.js`
  and run
```shell
$ npm run build:prod
$ drush cr
```

# Summary 2.3.3
This release fixes a library build problem reported here
https://github.com/italia/bootstrap-italia/issues/910.

# Summary 2.3.2
## Release notes
Updated bootstrap-italia library to 2.3.8.

## Update libraries
### Vanilla libraries
If you use vanilla libraries, download bootstrap-italia v2.3.8
and update `<your-sub-theme>/dist` folder.

### Custom build
If you use custom libraries built with webpack, do:
```shell
$ npm install bootstrap-italia@^2.3
$ npm update
$ npm run build:prod
$ drush cr
```

## All changes
- Add new option to manage padding in card UI

# Summary 2.3.1
## Release notes
Updated bootstrap-italia library to 2.3.7, minor fix and new feature.

## Update libraries
### Vanilla libraries
If you use vanilla libraries, download bootstrap-italia v2.3.7
and update `<your-sub-theme>/dist` folder.

### Custom build
If you use custom libraries built with webpack, do:
```shell
$ npm install bootstrap-italia@^2.3
$ npm update
$ npm run build:prod
$ drush cr
```

## All changes
- Added fast and minimalistic 404-page template
- Added header shadow feature in theme settings
- Fix:
  - maintenance-page id
  - update share component
  - wrong bootstrap5 class in dropdown component
  - user menu, dropdown tag
  - update install script

# Summary 2.3.0
## Release notes
Compliance bootstrap-italia v2.3

## Update from 2.2.x
### Vanilla libraries
If you use vanilla libraries, download bootstrap-italia v2.3.6
and update `<your-sub-theme>/dist` folder.

### Custom build
If you use custom libraries built with webpack, do:
```shell
$ npm install bootstrap-italia@^2.3
$ npm update
```
update:
- `<your-sub-theme>/src/scss/_bootstrap-italia.scss`
- `<your-sub-theme>/src/scss/custom-comuni/_variables.scss`
```shell
$ npm run build:prod
$ drush cr
```

# All changes
- Update bootstrap-italia compliance with v2.3.x
- Check all components and update:
  - badge
  - chips
  - dropdown (direction variant)
  - steppers
- New `mastodon` icon

# Summary 2.2.3
## Release notes

This release are covered by the security advisory policy. 🥳🥳🥳

## All changes
- Fix(a11y): dropdown link in navbar [0d6671ca](https://git.drupalcode.org/project/bootstrap_italia/-/commit/0d6671caab67141fff7896c5af5197a31c152116)
- Fix(a11y): spacing footer menu link [6b5715a0](https://git.drupalcode.org/project/bootstrap_italia/-/commit/6b5715a06658355308809bbca23df3fb8d4928ad)
- Fix(a11y): H hierarchy in footer blocks [f497bb4a](https://git.drupalcode.org/project/bootstrap_italia/-/commit/f497bb4aec73b57b1e88f92b64c256261c80aa25)
- Fix(sec): phpstan level 5 compliance [a58861b9](https://git.drupalcode.org/project/bootstrap_italia/-/commit/a58861b91fd550d92ce6e462ef60adf1fa090e95)
- Fix(sec): return type [ad0cea33](https://git.drupalcode.org/project/bootstrap_italia/-/commit/ad0cea33863ed805478bf4d66e02ba082b4b0aaf)
- Fix(sec): Issue #3346670 fix phpstan issue [7e9f53a2](https://git.drupalcode.org/project/bootstrap_italia/-/commit/7e9f53a2a6c1bec394dc43ebf34c96c7cf4408c1)
- Fix(bug): sometimes the $region variable is empty
  because if condition is always true [d4305ff8](https://git.drupalcode.org/project/bootstrap_italia/-/commit/d4305ff8ac9c2426b087e76377ab1897c7bf0141)
- Fix(bug): variable $element in isset() is never defined [05ff9446](https://git.drupalcode.org/project/bootstrap_italia/-/commit/05ff9446f674e3f9676f5bdcd560bd89f53c92c6)
- Issue #3346670 remove unused module and install file [443012f8](https://git.drupalcode.org/project/bootstrap_italia/-/commit/443012f8a8c85a447eaf87ee78e772e61f19781e)
- Optimize footer-blocks code [1f4f6172](https://git.drupalcode.org/project/bootstrap_italia/-/commit/1f4f6172d1da4e5a1e522d6d09de25e05879913f)
- Issue #3346670 move css and js folder in the root dir [c55cf3d2](https://git.drupalcode.org/project/bootstrap_italia/-/commit/c55cf3d289d3fda75dbff2db505c48203ecad108)
- Update translations
- Fix(docs): pattern card preview text [76d0dcd2](https://git.drupalcode.org/project/bootstrap_italia/-/commit/76d0dcd215e82e809b4fe3b130e5c42e67358a45)
- Fix(docs): pattern card preview text [ce590bf5](https://git.drupalcode.org/project/bootstrap_italia/-/commit/ce590bf5b4baaaaef933cd7e9c36d18f0d3524b6)

# Summary 2.2.2
## Release notes
- Fix font bug

# Summary 2.2.1
## Release notes
- Fix font bug

# Summary 2.2.0
## Release notes
- Update sub-theme dependencies for compliance v2.2.0 bootstrap-italia library
- Various accessibility fix
- New module for full blocks home page

## Update from 2.1.x
If you use vanilla libraries, download bootstrap-italia v2.2.0
and update `<your-sub-theme>/dist` folder.

If you use custom libraries built with webpack, do:
```shell
$ npm install bootstrap-italia@2.2.0 --save-exact
$ npm update
```
- update `<your-sub-theme>/src/js/index.js`
```shell
$ npm run build:prod
$ drush cr
```

# Summary 2.1.1
## Release notes
- Accessibility of external links in the menus

If you have custom template overrides, check:
- `templates/region/small-prints/menu--footer-small-prints.html.twig`

# Summary 2.1.0
## Release notes
- Update sub-theme dependencies for compliance v2.1.1 bootstrap-italia library
- Various fix

## Update from 2.0.1
If you have custom template overrides, check:
- `templates/layout/html.html.twig`
- `templates/layout/header/_partial.header-slim.html.twig`
- `templates/layout/header/_partial.header-center.html.twig`
- `templates/layout/header/_partial.header-navbar.html.twig`
- `templates/layout/content/_partial.content.html.twig`
- `templates/layout/footer/_partial.footer.html.twig`
- `templates/region/header-slim-menu/block--header-slim-menu.html.twig`
- `templates/region/header-slim-language/links--language-block.html.twig`
- `templates/region/header-nav/region--header-nav.html.twig`
- `templates/region/header-nav/menu--header-nav.html.twig`
- `templates/region/footer-menu/menu--footer-menu.html.twig`
- `templates/region/small-prints/menu--footer-small-prints.html.twig`

If you use custom libraries built with webpack, check:
- `var/starter_kits/italiagov/package.json`
- `var/starter_kits/italiagov/webpack.common.js`

## All changes
- Sub-theme dependencies update
- Sub-theme up to bootstrap-italia 2.1.1
- Add option to modal component
- Fix bug to Bootstrap Italia Text Editor 2 (Experimental module)
- Fix accessibility slim header, header center, navbar, skipping,
  follow-us, footer
- Fix bug in navbar burger icon
- Review all component
- Update italian translations (thanks @braintec)
- Update ddev installer

# Summary 2.0.1
- Fix data-attribute for schools sites

# Summary 2.0.0
## Release notes
First v2 release.

## Update from 2.0@RC1
`$ composer require 'drupal/bootstrap_italia:^2.0'`

Go to your sub-theme settings -> PA Website Validator and choose your site type.

Edit `<your-sub-theme>italiagov/package.json` and change
```json
"dependencies": {
  "bootstrap-italia": "^2.0.9"
}
```
in
```json
"dependencies": {
  "bootstrap-italia": "2.0.9"
}
```

Update `<your-sub-theme>italiagov/src/js/index.js`

Package.json and index.js diff:
https://git.drupalcode.org/project/bootstrap_italia/-/compare/2.0.0-rc1...2.x?from_project_id=61656&page=2&straight=false#4707d11b57f77fd9a16fd8a8ac18cb111ef72865

## Removed feature from 8.x-0.x
- `macro.icon` (deprecated in 0.11)

- `macro.password_icon`, if you use this feature
  switch to `components/icon/password_icon` (deprecated in 0.21)

- `bootstrap_italia/templates/views/views-view-unformatted--novita--novita-evidenza.html.twig`
  (deprecated in 0.22)
- `bootstrap_italia/templates/views/views-view-unformatted--novita--novita-home.html.twig`
  (deprecated in 0.22)
- `italiagov/src/components/card/card-hp-intro.twig` (deprecated in 0.22)
- `bootstrap_italia.libraries.yml` (deprecated in 0.22)

## Breaking changes
- Removed experimental modules.
  If you want to continue using the old experimental modules
  (Bootstrap Italia Image Styles, Bootstrap Italia overlays and
  Bootstrap Italia Paragraphs), before performing the version upgrade,
  move all modules to the `/modules` folder in your `<sub-theme>/modules/`,
  move `/templates/paragraphs/paragraph--content--default.html.twig`
  in your sub-theme and clear cache (`drush cr`).

- Regions changes:
  - `header_slim_lingua` to `header_slim_language`. After the update,
    you will find the blocks of the "Search" region in the "Disabled" position,
    place the blocks in the right region.

- Refactoring `theme_library_info_build()`,
  update `<sub-theme>/<sub-theme>.theme`.

- Theme Settings changes:
  - `theme_variants` to `libraries_source`
  - `ente_appartenenza_nome` to `government_entity_name`
  - `ente_appartenenza_url` to `government_entity_url`
  - `right_action_size` to `slim_header_action_type`

- Suggestions change (check in your sub-theme if
  `template-name.html.twig` work correctly)
  - menu new formats:
    - `theme_hook_original`;
    - `theme_hook_original + region_name`
    - `menu__ + region_name`

## Update from 0.x (Work in progress)
- copy `bootstrap_italia/templates/patterns` in `<sub-theme>/templates/`
- if you use experimental modules 0.x copy `/bootstrap_italia/modules`
  in `<sub-theme>/`
- admin/config/development/configuration/single/export ->
  simple configuration -> italiagov.settings
- composer require 'drupal/bootstrap_italia:^2.0@beta'
- drush cr
- update sub-theme settings
  - `ente_appartenenza_nome` -> `government_entity_name`
  - `ente_appartenenza_url` -> `government_entity_url`
  - new slim_header_action_active_login
  - `right_action_size` -> `slim_header_action_type`
- update in sub-theme: composer.json, *.yml, *.theme, webpack.*
- drush cr
- layout blocks set language block
- update src folder in your sub-theme
- update template folder in your sub-theme
