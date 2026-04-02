# bootstrap_italia

For local development use [docs/composer.json](docs/composer.json).

Install Drupal with the minimal profile and set `bootstrap_italia` as default:

```shell
drush site:install minimal
drush theme:install bootstrap_italia
drush config-set system.theme default bootstrap_italia
```

## Storybook with DDEV

This setup assumes the theme is installed in
`web/themes/contrib/bootstrap_italia`, as defined by `docs/composer.json`.

Copy these files into the Drupal project:

```bash
cp web/themes/contrib/bootstrap_italia/docs/storybook/config.storybook.yaml .ddev/config.storybook.yaml
cp web/themes/contrib/bootstrap_italia/docs/storybook/storybook .ddev/commands/host/storybook
cp web/themes/contrib/bootstrap_italia/docs/storybook/storybook-setup .ddev/commands/host/storybook-setup
cp web/themes/contrib/bootstrap_italia/docs/storybook/storybook-watch .ddev/commands/host/storybook-watch
```

Merge `web/themes/contrib/bootstrap_italia/docs/storybook/services.storybook.yml`
into `web/sites/default/services.yml`. If `web/sites/default/services.yml` does
not exist, create it with that content.

Make the copied DDEV command files executable:

```bash
chmod +x .ddev/commands/host/storybook .ddev/commands/host/storybook-setup .ddev/commands/host/storybook-watch
```

Run the one-time setup:

```bash
ddev start
ddev storybook-setup
```

Start Storybook:

```bash
ddev storybook --start
```

Watch component changes and regenerate local `*.stories.json` artifacts automatically:

```bash
ddev storybook-watch
```

Storybook may print `http://localhost:6006/` or `http://0.0.0.0:6006/` in the
terminal. In DDEV this is expected and can be ignored.

Open it in the browser:

```bash
ddev storybook
```

`*.stories.json` files are generated artifacts compiled from `*.stories.twig`.
They are ignored in Git and should not be edited manually.

If you are not using `ddev storybook-watch`, regenerate the JSON files manually:

```bash
ddev drush storybook:generate-all-stories --force --omit-server-url --uri="$(ddev drush status --fields=uri --format=list | tail -n 1)"
```

The Storybook server URL is provided by [`preview.js`](./.storybook/preview.js)
through `STORYBOOK_SERVER_URL` or `DDEV_PRIMARY_URL`, so generated JSON files do
not need to embed environment-specific URLs.
