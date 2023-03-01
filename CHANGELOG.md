# Summary 2.2.0
## Release notes
- Update sub-theme dependencies for compliance v2.2.0 bootstrap-italia library
- Various accessibility fix
- New module for full blocks home page

## Update from 2.1.x
If you use vanilla libraries, download bootstrap-italia v2.2.0
and update `<your-sub-theme>/dist` folder.

If you use custom libraries built with webpack, do:
```
$ npm install bootstrap-italia@2.2.0 --save-exact
$ npm update
```
- update `<your-sub-theme>/src/js/index.js`
```
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
- Fix accessibility slim header, header center, navbar, skipping, follow-us, footer
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
```
"dependencies": {
  "bootstrap-italia": "^2.0.9"
}
```
in
```
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

- `bootstrap_italia/templates/views/views-view-unformatted--novita--novita-evidenza.html.twig` (deprecated in 0.22)
- `bootstrap_italia/templates/views/views-view-unformatted--novita--novita-home.html.twig` (deprecated in 0.22)
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
- if you use experimental modules 0.x copy `/bootstrap_italia/modules` in `<sub-theme>/`
- admin/config/development/configuration/single/export -> simple configuration -> italiagov.settings
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
