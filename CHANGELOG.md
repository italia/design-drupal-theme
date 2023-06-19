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
