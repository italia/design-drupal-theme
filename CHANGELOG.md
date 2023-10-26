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
