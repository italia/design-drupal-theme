<?php

namespace Drupal\bootstrap_italia;

use Drupal\Core\Extension\Requirement\RequirementSeverity;
use Drupal\Core\StringTranslation\StringTranslationTrait;

/**
 * Checks Bootstrap Italia theme build output availability.
 *
 * The upstream bootstrap-italia library is a devDependency (npm) used only
 * at build time. Runtime assets (CSS, fonts, SVG sprite) are compiled by Vite
 * and committed to dist/ inside the theme.
 *
 * This class verifies that dist/ has been built, providing an actionable
 * warning when the compiled output is missing (e.g. after a fresh clone
 * without pre-built dist/).
 */
class LibraryResolver {

  use StringTranslationTrait;

  /**
   * Theme-relative path to the compiled base CSS (Vite output).
   */
  const COMPILED_BASE_CSS = 'dist/css/base.css';

  /**
   * Theme-relative path to the copied SVG icon sprite (Vite static copy).
   */
  const COMPILED_SVG_SPRITE = 'dist/svg/sprites.svg';

  /**
   * Returns a requirement entry describing the build output status.
   */
  public function getRequirement(): array {
    if ($this->isThemeBuilt()) {
      return [
        'title'    => $this->t('Bootstrap Italia compiled assets'),
        'value'    => $this->t('Present'),
        'severity' => RequirementSeverity::OK,
      ];
    }

    return [
      'title'       => $this->t('Bootstrap Italia compiled assets'),
      'value'       => $this->t('Missing'),
      'severity'    => RequirementSeverity::Error,
      'description' => $this->t(
        'Bootstrap Italia dist/ not found at <code>@path</code>. Run <code>npm install && npm run build</code> inside the theme directory.',
        ['@path' => self::COMPILED_BASE_CSS]
      ),
    ];
  }

  /**
   * Checks whether the theme's Vite build output is present.
   */
  public function isThemeBuilt(): bool {
    $themePath = \Drupal::service('extension.list.theme')->getPath('bootstrap_italia');
    return file_exists(DRUPAL_ROOT . '/' . $themePath . '/' . self::COMPILED_BASE_CSS);
  }

}
