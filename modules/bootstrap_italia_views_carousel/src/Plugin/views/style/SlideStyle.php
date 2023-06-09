<?php

namespace Drupal\bootstrap_italia_views_carousel\Plugin\views\style;

use Drupal\Core\Form\FormStateInterface;
use Drupal\views\Plugin\views\style\StylePluginBase;

/**
 * Style plugin to render a slide carousel.
 *
 * @ingroup views_style_plugins
 *
 * @ViewsStyle(
 *   id = "bootstrap_italia_views_carousel_slide_style",
 *   title = @Translation("Bootstrap Italia Carousel slide"),
 *   help = @Translation("Render a slide of Bootstrap Italia Carousel."),
 *   theme = "views_bootstrap_italia_views_carousel_slide",
 *   display_types = { "normal" }
 * )
 */
class SlideStyle extends StylePluginBase {

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
  protected $usesGrouping = TRUE;

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
  public function buildOptionsForm(&$form, FormStateInterface $form_state): void {
    parent::buildOptionsForm($form, $form_state);

    // Carousel image type.
    $form['bi_carousel_slide_settings']['carousel_image_type'] = [
      '#type' => 'select',
      '#title' => $this->t('Image type'),
      '#description' => $this->t('If you are building an image carousel, select how you want to display the images. Note: if you choose "standard" or "big" the images will be displayed with the theme "Landscape abstract: 3 cols". Default: "Use field image formatter".'),
      '#options' => [
        '' => $this->t('Use field image formatter.'),
        'standard' => $this->t('Standard'),
        'big' => $this->t('Big'),
      ],
      '#default_value' =>
      $this->options['bi_carousel_slide_settings']['carousel_image_type'] ?? '',
    ];

  }

}
