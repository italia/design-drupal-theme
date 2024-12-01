<?php

namespace Drupal\bootstrap_italia_views_list\Plugin\views\style;

use Drupal\Core\Form\FormStateInterface;
use Drupal\views\Plugin\views\style\StylePluginBase;

/**
 * Style plugin to render list component.
 *
 * @ingroup views_style_plugins
 *
 * @ViewsStyle(
 *   id = "bootstrap_italia_views_list_style",
 *   title = @Translation("Bootstrap Italia List"),
 *   help = @Translation("Render a Bootstrap Italia List."),
 *   theme = "views_bootstrap_italia_views_list",
 *   display_types = { "normal" }
 * )
 */
class ListStyle extends StylePluginBase {

  /**
   * Does this Style plugin allow Row plugins?
   *
   * @var bool
   */
  protected $usesRowPlugin = TRUE;

  /**
   * {@inheritdoc}
   *
   * @return array<string, mixed>
   *   Options array.
   */
  protected function defineOptions(): array {
    $options = parent::defineOptions();
    $options['list_settings'] = ['default' => []];
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

    // Manage title.
    $form['bi_list_settings']['list_title_show'] = [
      '#type' => 'checkbox',
      '#title' => $this->t('Show title'),
      '#description' => $this->t('If checked shows title.'),
      '#default_value' =>
      $this->options['bi_list_settings']['list_title_show'] ?? TRUE,
    ];

    // Title tag.
    $form['bi_list_settings']['list_title_tag'] = [
      '#type' => 'select',
      '#title' => $this->t('Title tag'),
      '#description' => $this->t('Select title tag. Default: "Heading 2"'),
      '#options' => [
        'h1' => $this->t('Heading 1'),
        'h2' => $this->t('Heading 2'),
        'h3' => $this->t('Heading 3'),
        'h4' => $this->t('Heading 4'),
        'h5' => $this->t('Heading 5'),
        'h6' => $this->t('Heading 6'),
        'p' => $this->t('Paragraph'),
        'div' => $this->t('Generic container'),
      ],
      '#default_value' =>
      $this->options['bi_list_settings']['list_title_tag'] ?? 'h2',
    ];

    // Title class.
    $form['bi_list_settings']['list_title_classes'] = [
      '#type' => 'textfield',
      '#title' => $this->t('Custom classes'),
      '#description' => $this->t('Fill with custom class, use space as separator.'),
      '#default_value' =>
      $this->options['bi_timeline_settings']['list_title_classes'] ?? '',
    ];

  }

}
