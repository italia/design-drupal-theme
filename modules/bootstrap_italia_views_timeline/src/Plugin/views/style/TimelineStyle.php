<?php

namespace Drupal\bootstrap_italia_views_timeline\Plugin\views\style;

use Drupal\core\form\FormStateInterface;
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
   */
  protected function defineOptions() {
    $options = parent::defineOptions();
    $options['timeline_settings'] = ['default' => []];
    return $options;
  }

  /**
   * {@inheritdoc}
   */
  public function buildOptionsForm(&$form, FormStateInterface $form_state) {
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
