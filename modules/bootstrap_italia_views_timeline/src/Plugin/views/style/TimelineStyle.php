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

    // Today check type.
    $form['bi_timeline_settings']['today_check_period'] = array(
      '#type' => 'select',
      '#title' => $this->t('Today check'),
      '#description' => $this->t('Period of time when an element is marked as current. Default: "Week"'),
      '#options' => [
        'month' => 'Month',
        'week' => 'Week',
        'day' => 'Day'
      ],
      '#default_value' =>
          $this->options['bi_timeline_settings']['today_check_period'] ?? 'week',
    );

  }

}

