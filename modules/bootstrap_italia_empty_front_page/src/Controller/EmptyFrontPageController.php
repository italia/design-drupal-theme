<?php

namespace Drupal\bootstrap_italia_empty_front_page\Controller;

use Drupal\Core\Controller\ControllerBase;

/**
 * Default Controller class for Empty Front Page.
 */
class EmptyFrontPageController extends ControllerBase {

  /**
   * Content callback method.
   *
   * @return array
   *   Return an empty string in a markup render array.
   */
  public function content(): array {
    return [
      '#type' => 'markup',
      '#markup' => '',
    ];
  }

}
