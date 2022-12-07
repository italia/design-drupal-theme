# Summary 2.0.0
## Release notes
- Upgrade `<sub-theme>/italiagov.info.yml`

## Removed feature
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

## Update from 0.x
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
  - layout bloks set language block
  - update src folder in your sub-theme
