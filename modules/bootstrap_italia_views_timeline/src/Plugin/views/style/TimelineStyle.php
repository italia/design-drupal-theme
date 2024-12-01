<?php

namespace Drupal\bootstrap_italia_views_timeline\Plugin\views\style;

use Drupal\Core\Form\FormStateInterface;
use Drupal\views\Plugin\views\style\StylePluginBase;

/**
 * Style plugin to render list component.
 *
 * @ingroup views_style_plugins
 *
 * @ViewsStyle(
 *   id = "bootstrap_italia_views_timeline_style",
 *   title = @Translation("Bootstrap Italia Timeline"),
 *   help = @Translation("Render a Bootstrap Italia Timeline."),
 *   theme = "views_bootstrap_italia_views_timeline",
 *   display_types = { "normal" }
 * )
 */
class TimelineStyle extends StylePluginBase {

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
    $options['timeline_settings'] = ['default' => []];
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

    // Date format.
    $form['bi_timeline_settings']['date_format'] = [
      '#type' => 'textfield',
      '#title' => $this->t('Date format'),
      '#description' => $this->t('Valid PHP <a href="@url" target="_blank">Date function</a> parameter to display date.', ['@url' => 'https://www.php.net/manual/en/datetime.format.php#refsect1-datetime.format-parameters']),
      '#default_value' =>
      $this->options['bi_timeline_settings']['date_format'] ?? 'F Y',
    ];

    // Today check.
    $form['bi_timeline_settings']['today_check'] = [
      '#type' => 'checkbox',
      '#title' => $this->t('Today automatic check'),
      '#description' => $this->t('If checked enable "Today" feature. Default: checked.'),
      '#default_value' =>
      $this->options['bi_timeline_settings']['today_check'] ?? TRUE,
    ];
    $form['bi_timeline_settings']['today_check_period'] = [
      '#type' => 'select',
      '#title' => $this->t('Today check period'),
      '#description' => $this->t('Period of time when an element is marked as current. Default: "Week".'),
      '#options' => [
        'month' => $this->t('Month'),
        'week' => $this->t('Week'),
        'day' => $this->t('Day'),
      ],
      '#default_value' =>
      $this->options['bi_timeline_settings']['today_check_period'] ?? 'month',
    ];

    // Heading.
    $form['bi_timeline_settings']['pin_heading_tag'] = [
      '#type' => 'select',
      '#title' => $this->t('Pin heading level'),
      '#description' => $this->t('Choose a pin heading level. Default: "Heading 3 (h3)".'),
      '#options' => [
        'h1' => $this->t('Heading 1 (h1)'),
        'h2' => $this->t('Heading 2 (h2)'),
        'h3' => $this->t('Heading 3 (h3)'),
        'h4' => $this->t('Heading 4 (h4)'),
        'h5' => $this->t('Heading 5 (h5)'),
        'h6' => $this->t('Heading 6 (h6)'),
      ],
      '#default_value' =>
      $this->options['bi_timeline_settings']['pin_heading_tag'] ?? 'h3',
    ];

    // Icons.
    $form['bi_timeline_settings']['icon_past_event'] = [
      '#type' => 'textfield',
      '#title' => $this->t('Icon for past event'),
      '#description' => $this->t('Fill with icon name. <a href="@iconList" target="_blank">Icon list</a>. Default: "it-check"', ['@iconList' => 'https://italia.github.io/bootstrap-italia/docs/utilities/icone/#lista-delle-icone-disponibili']),
      '#placeholder' => 'it-name',
      '#default_value' =>
      $this->options['bi_timeline_settings']['icon_past_event'] ?? 'it-check',
    ];
    $form['bi_timeline_settings']['icon_event'] = [
      '#type' => 'textfield',
      '#title' => $this->t('Icon for events that have not passed'),
      '#description' => $this->t('Fill with icon name. <a href="@iconList" target="_blank">Icon list</a>. Default: "it-refresh"', ['@iconList' => 'https://italia.github.io/bootstrap-italia/docs/utilities/icone/#lista-delle-icone-disponibili']),
      '#placeholder' => 'it-name',
      '#default_value' =>
      $this->options['bi_timeline_settings']['icon_event'] ?? 'it-refresh',
    ];

  }

}
