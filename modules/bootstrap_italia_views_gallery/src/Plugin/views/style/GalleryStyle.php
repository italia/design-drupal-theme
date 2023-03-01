<?php

namespace Drupal\bootstrap_italia_views_gallery\Plugin\views\style;

use Drupal\core\form\FormStateInterface;
use Drupal\views\Plugin\views\style\StylePluginBase;

/**
 * Style plugin to render gallery component.
 *
 * @ingroup views_style_plugins
 *
 * @ViewsStyle(
 *   id = "bootstrap_italia_views_gallery_style",
 *   title = @Translation("Bootstrap Italia Gallery"),
 *   help = @Translation("Render a Bootstrap Italia Gallery."),
 *   theme = "views_bootstrap_italia_views_gallery",
 *   display_types = { "normal" }
 * )
 */
class GalleryStyle extends StylePluginBase {

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
    $options['gallery_settings'] = ['default' => []];
    return $options;
  }

  /**
   * {@inheritdoc}
   */
  public function buildOptionsForm(&$form, FormStateInterface $form_state) {
    parent::buildOptionsForm($form, $form_state);

    $form['bi_gallery_settings']['grid_type'] = [
      '#type' => 'select',
      '#title' => $this->t('Grid type'),
      '#description' => $this->t('Display type. Default: "Default".'),
      '#options' => [
        '' => $this->t('Default'),
        'quilted' => $this->t('Quilted'),
        'double' => $this->t('First image double (4 items min.)'),
        'masonry' => $this->t('Masonry'),
      ],
      '#default_value' =>
      $this->options['bi_gallery_settings']['grid_type'] ?? '',
    ];
    $form['bi_gallery_settings']['show_image_caption'] = [
      '#type' => 'checkbox',
      '#title' => $this->t('Show caption'),
      '#description' => $this->t('If checked enable "caption" feature. Default: checked.'),
      '#default_value' => $this->options['bi_gallery_settings']['show_image_caption'] ?? TRUE,
    ];

  }

}
