<?php

namespace Drupal\bootstrap_italia_views_accordion\Plugin\views\style;

use Drupal\Core\Form\FormStateInterface;
use Drupal\views\Plugin\views\style\StylePluginBase;

/**
 * Style plugin to render accordion component.
 *
 * @ingroup views_style_plugins
 *
 * @ViewsStyle(
 *   id = "bootstrap_italia_views_accordion_style",
 *   title = @Translation("Bootstrap Italia Accordion"),
 *   help = @Translation("Render a Bootstrap Italia Accordion."),
 *   theme = "views_bootstrap_italia_views_accordion",
 *   display_types = { "normal" }
 * )
 */
class AccordionStyle extends StylePluginBase {

  /**
   * Does this Style plugin allow Row plugins?
   *
   * @var bool
   */
  protected $usesRowPlugin = TRUE;

  /**
   * Does the Style plugin support grouping of rows?
   *
   * @var bool
   */
  protected $usesGrouping = FALSE;

  /**
   * {@inheritdoc}
   *
   * @return array<string, mixed>
   *   Options array.
   */
  protected function defineOptions(): array {
    $options = parent::defineOptions();
    $options['accordion_settings'] = ['default' => []];
    return $options;
  }

  /**
   * {@inheritdoc}
   *
   * @param array<string, mixed> $form
   *   Nested array of form elements that comprise the form.
   * @param \Drupal\Core\Form\FormStateInterface $form_state
   *   The current state of the form.
   */
  public function buildOptionsForm(&$form, FormStateInterface $form_state): void {
    parent::buildOptionsForm($form, $form_state);

    // Background active.
    $form['bi_accordion_settings']['accordion_background_active'] = [
      '#type' => 'checkbox',
      '#title' => $this->t('Accordion background active'),
      '#description' => $this->t('Adds the primary background to the active element.'),
      '#default_value' =>
      $this->options['bi_accordion_settings']['accordion_background_active'] ?? FALSE,
    ];

    // Background hover.
    $form['bi_accordion_settings']['accordion_background_hover'] = [
      '#type' => 'checkbox',
      '#title' => $this->t('Accordion background hover'),
      '#description' => $this->t('Adds the primary background to the element that has focus.'),
      '#default_value' =>
      $this->options['bi_accordion_settings']['accordion_background_hover'] ?? FALSE,
    ];

    // Left icon.
    $form['bi_accordion_settings']['accordion_left_icon'] = [
      '#type' => 'checkbox',
      '#title' => $this->t('Accordion left icon'),
      '#description' => $this->t('Show the icon on the left instead of on the right.'),
      '#default_value' =>
      $this->options['bi_accordion_settings']['accordion_left_icon'] ?? FALSE,
    ];

    // Flush.
    $form['bi_accordion_settings']['accordion_flush'] = [
      '#type' => 'checkbox',
      '#title' => $this->t('Accordion flush'),
      '#description' => $this->t('Enable to remove the default background color, some borders, and some rounded corners to render accordions edge-to-edge with their parent container.'),
      '#default_value' =>
      $this->options['bi_accordion_settings']['accordion_flush'] ?? FALSE,
    ];

  }

}
