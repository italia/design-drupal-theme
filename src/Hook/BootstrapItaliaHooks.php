<?php

namespace Drupal\bootstrap_italia\Hook;

use Drupal\bootstrap_italia\LibraryResolver;
use Drupal\Core\Hook\Attribute\Hook;
use Drupal\Core\Messenger\MessengerInterface;
use Drupal\Core\Session\AccountProxyInterface;
use Drupal\Core\StringTranslation\StringTranslationTrait;

/**
 * Hook implementations for the Bootstrap Italia theme.
 *
 * OOP hooks are supported in themes since Drupal 11.3.
 * Note: themes do not support Hook order/module parameters,
 * ReorderHook or RemoveHook. Base theme hooks run before the active theme.
 *
 * NOTE: hook_runtime_requirements() is invoked by ModuleHandler, not
 * ThemeManager. Themes cannot contribute to /admin/reports/status via that
 * hook. Build output status is surfaced here via Messenger to admin users.
 * A formal requirements check will be added in a companion module (Milestone 5).
 */
class BootstrapItaliaHooks {

  use StringTranslationTrait;

  public function __construct(
    private readonly MessengerInterface $messenger,
    private readonly AccountProxyInterface $currentUser,
  ) {}

  /**
   * Implements hook_page_attachments_alter().
   *
   * Warns admin users when the compiled theme assets are missing.
   * This happens on a fresh clone when dist/ has not been committed or
   * the Vite build has not been run yet.
   */
  #[Hook('page_attachments_alter')]
  public function pageAttachmentsAlter(array &$attachments): void {
    $resolver = new LibraryResolver();

    if (!$resolver->isThemeBuilt() && $this->currentUser->hasPermission('administer site configuration')) {
      $this->messenger->addWarning($this->t(
        'Bootstrap Italia: compiled assets not found (<code>@path</code>). Run <code>npm install && npm run build</code> inside the theme directory.',
        ['@path' => LibraryResolver::COMPILED_BASE_CSS]
      ));
    }
  }

}
