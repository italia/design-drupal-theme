<?php

namespace Drupal\bootstrap_italia_views_carousel\Plugin\views\style;

use Drupal\core\form\FormStateInterface;
use Drupal\views\Plugin\views\style\StylePluginBase;

/**
 * Style plugin to render carousel component.
 *
 * @ingroup views_style_plugins
 *
 * @ViewsStyle(
 *   id = "bootstrap_italia_views_carousel_style",
 *   title = @Translation("Bootstrap Italia Carousel"),
 *   help = @Translation("Render a Bootstrap Italia Carousel."),
 *   theme = "views_bootstrap_italia_views_carousel",
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

    // Carousel type.
    $form['bi_carousel_settings']['carousel_col_type'] = [
      '#type' => 'select',
      '#title' => $this->t('Column type'),
      '#description' => $this->t('Select slide column type. Default: "Landscape abstract: 3 cols"'),
      '#options' => [
        'it-carousel-landscape-abstract' => $this->t('Landscape abstract: 1 col'),
        'it-carousel-landscape-abstract-three-cols' => $this->t('Landscape abstract: 3 cols'),
        'it-carousel-landscape-abstract-three-cols-arrow-visible' => $this->t('Landscape abstract: 3 cols with arrows'),
      ],
      '#default_value' =>
      $this->options['bi_carousel_settings']['carousel_col_type'] ?? 'it-carousel-landscape-abstract-three-cols',
    ];

    // Slide spacing.
    $form['bi_carousel_settings']['slide_spacing'] = [
      '#type' => 'select',
      '#title' => $this->t('Slide spacing'),
      '#description' => $this->t('Select slide separator. Default: "Automatic padding"'),
      '#options' => [
        '' => $this->t('Unset'),
        'slide_track_padding' => $this->t('Automatic padding'),
        'slide_lined' => $this->t('Vertical line'),
      ],
      '#default_value' =>
      $this->options['bi_carousel_settings']['slide_spacing'] ?? 'slide_track_padding',
    ];

    // Carousel image type.
    $form['bi_carousel_settings']['carousel_image_type'] = [
      '#type' => 'select',
      '#title' => $this->t('Image type'),
      '#description' => $this->t('If you are building an image carousel, select how you want to display the images. Note: if you choose "standard" or "big" the images will be displayed with the theme "Landscape abstract: 3 cols". Default: "Use field image formatter".'),
      '#options' => [
        '' => $this->t('Use field image formatter.'),
        'standard' => $this->t('Standard'),
        'big' => $this->t('Big'),
      ],
      '#default_value' =>
      $this->options['bi_carousel_settings']['carousel_image_type'] ?? '',
    ];

  }

}
