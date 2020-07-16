<?php

namespace Drupal\bootstrap_italia\Commands;

use Consolidation\OutputFormatters\StructuredData\RowsOfFields;
use Drush\Commands\DrushCommands;

/**
 * A Drush commandfile.
 *
 * In addition to this file, you need a drush.services.yml
 * in root of your module, and a composer.json file that provides the name
 * of the services file to use.
 *
 * See these files for an example of injecting Drupal services:
 *   - http://cgit.drupalcode.org/devel/tree/src/Commands/DevelCommands.php
 *   - http://cgit.drupalcode.org/devel/tree/drush.services.yml
 */
class SubThemeCommands extends DrushCommands
{

  private $folderKits = 'src/starter_kits';

  /**
   * Create a bootstrap_italia sub-theme.
   *
   * @command bootstrap_italia:new-sub-theme
   * @aliases binew
   *
   * @param $machine_name
   *   Theme machine name.
   * @param array $options
   *   An associative array of options whose values come from cli, aliases, config, etc.
   * @option full-name
   *   Theme machine name
   * @option description
   *    Theme description
   * @option kit
   *    Theme type: standard|school
   *
   * @usage bootstrap_italia:new-sub-theme name
   *   Usage description
   */
  public function newSubTheme(
    string $machine_name,
    array $options = [
      'full-name' => 'Bootstrap Italia child theme',
      'description' => 'Bootstrap Italia child theme',
      'kit' => 'standard'
    ])
  {
    // Filter everything but letters, numbers, underscores, and hyphens
    $machine_name = preg_replace('/[^a-z0-9_-]+/', '', strtolower($machine_name));
    // Eliminate hyphens
    $machine_name = str_replace('-', '_', $machine_name);

    // Path theme
    $path_bootstrap_italia = drupal_get_path('theme', 'bootstrap_italia');
    $path_source_kit =  "{$path_bootstrap_italia}/{$this->folderKits}/{$options['kit']}";


    $this->logger()->success(dt( 'Machine name: '.$machine_name ));
    $this->logger()->success(dt( 'Full name: '.$options['full-name'] ));
    $this->logger()->success(dt( 'Description: '.$options['description'] ));
    $this->logger()->success(dt( 'Kit: '.$options['kit'] ));
    $this->logger()->success(dt( 'Kit: '.$path_source_kit ));
    $this->logger()->success(dt( 'Achievement unlocked.' ));
  }

}
