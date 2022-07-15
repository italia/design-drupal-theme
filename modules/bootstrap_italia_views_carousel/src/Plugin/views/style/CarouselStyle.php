<?php

namespace Drupal\bootstrap_italia_views_carousel\Plugin\views\style;

use Drupal\core\form\FormStateInterface;
use Drupal\views\Plugin\views\style\StylePluginBase;

/**
 * Style plugin to render swiper carousel.
 *
 * @ingroup views_style_plugins
 *
 * @ViewsStyle(
 *   id = "bootstrap_italia_views_carousel_style",
 *   title = @Translation("Bootstrap Italia Carousel component"),
 *   help = @Translation("Render a Bootstrap Italia Carousel."),
 *   theme = "bootstrap_italia_views_carousel",
 *   display_types = { "normal" }
 * )
 */
class CarouselStyle extends StylePluginBase {

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
    $options['carousel_settings'] = ['default' => []];
    return $options;
  }

  /**
   * {@inheritdoc}
   */
  public function buildOptionsForm(&$form, FormStateInterface $form_state) {
    parent::buildOptionsForm($form, $form_state);

    // select examples
    $form['bi_carousel_settings']['type'] = array(
      '#type' => 'select',
      '#title' => $this->t('Select an example'),
      '#options' => [
        'title_card' => 'Simple title and card',
        'hl_image_card' => 'Highlited image card',
      ],
      '#default_value' => (isset($this->options['bi_carousel_settings']['type'])) ? $this->options['bi_carousel_settings']['type'] : 'hl_image_card',
      '#description' => $this->t('Select one example.'),
    );

  }

}

