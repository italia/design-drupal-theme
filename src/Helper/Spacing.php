<?php

namespace Drupal\bootstrap_italia\Helper;

/**
 * Helper class for spacing.
 *
 * Docs: https://italia.github.io/bootstrap-italia/docs/organizzare-gli-spazi/spaziature/
 * https://getbootstrap.com/docs/5.1/utilities/spacing/.
 *
 * Why isn't it a service? https://www.drupal.org/project/drupal/issues/2002606.
 */
class Spacing {

  /**
   * Return padding top.
   */
  public static function getPaddingTop($withLabel = FALSE): array {
    if ($withLabel) {
      return [
        'pt-0' => t('Zero'),
        'pt-1' => t('Extra small'),
        'pt-2' => t('Small'),
        'pt-3' => t('Medium'),
        'pt-4' => t('Large'),
        'pt-5' => t('Extra Large'),
        'pt-auto' => t('Auto'),
      ];
    }
    return ['pt-0', 'pt-1', 'pt-2', 'pt-3', 'pt-4', 'pt-5', 'pt-auto'];
  }

  /**
   * Return padding right.
   */
  public static function getPaddingRight($withLabel = FALSE): array {
    if ($withLabel) {
      return [
        'pr-0' => t('Zero'),
        'pr-1' => t('Extra small'),
        'pr-2' => t('Small'),
        'pr-3' => t('Medium'),
        'pr-4' => t('Large'),
        'pr-5' => t('Extra Large'),
        'pr-auto' => t('Auto'),
      ];
    }
    return ['pr-0', 'pr-1', 'pr-2', 'pr-3', 'pr-4', 'pr-5', 'pr-auto'];
  }

  /**
   * Return padding bottom.
   */
  public static function getPaddingBottom($withLabel = FALSE): array {
    if ($withLabel) {
      return [
        'pb-0' => t('Zero'),
        'pb-1' => t('Extra small'),
        'pb-2' => t('Small'),
        'pb-3' => t('Medium'),
        'pb-4' => t('Large'),
        'pb-5' => t('Extra Large'),
        'pb-auto' => t('Auto'),
      ];
    }
    return ['pb-0', 'pb-1', 'pb-2', 'pb-3', 'pb-4', 'pb-5', 'pb-auto'];
  }

  /**
   * Return padding left.
   */
  public static function getPaddingLeft($withLabel = FALSE): array {
    if ($withLabel) {
      return [
        'pl-0' => t('Zero'),
        'pl-1' => t('Extra small'),
        'pl-2' => t('Small'),
        'pl-3' => t('Medium'),
        'pl-4' => t('Large'),
        'pl-5' => t('Extra Large'),
        'pl-auto' => t('Auto'),
      ];
    }
    return ['pl-0', 'pl-1', 'pl-2', 'pl-3', 'pl-4', 'pl-5', 'pl-auto'];
  }

  /**
   * Return padding vertical.
   */
  public static function getPaddingVertical($withLabel = FALSE): array {
    if ($withLabel) {
      return [
        'py-0' => t('Zero'),
        'py-1' => t('Extra small'),
        'py-2' => t('Small'),
        'py-3' => t('Medium'),
        'py-4' => t('Large'),
        'py-5' => t('Extra Large'),
        'py-auto' => t('Auto'),
      ];
    }
    return ['py-0', 'py-1', 'py-2', 'py-3', 'py-4', 'py-5', 'py-auto'];
  }

  /**
   * Return padding horizontal.
   */
  public static function getPaddingHorizontal($withLabel = FALSE): array {
    if ($withLabel) {
      return [
        'px-0' => t('Zero'),
        'px-1' => t('Extra small'),
        'px-2' => t('Small'),
        'px-3' => t('Medium'),
        'px-4' => t('Large'),
        'px-5' => t('Extra Large'),
        'px-auto' => t('Auto'),
      ];
    }
    return ['px-0', 'px-1', 'px-2', 'px-3', 'px-4', 'px-5', 'px-auto'];
  }

  /**
   * Return margin top.
   */
  public static function getMarginTop($withLabel = FALSE): array {
    if ($withLabel) {
      return [
        'mt-0' => t('Zero'),
        'mt-1' => t('Extra small'),
        'mt-2' => t('Small'),
        'mt-3' => t('Medium'),
        'mt-4' => t('Large'),
        'mt-5' => t('Extra Large'),
        'mt-auto' => t('Auto'),
      ];
    }
    return ['mt-0', 'mt-1', 'mt-2', 'mt-3', 'mt-4', 'mt-5', 'mt-auto'];
  }

  /**
   * Return margin right.
   */
  public static function getMarginRight($withLabel = FALSE): array {
    if ($withLabel) {
      return [
        'mr-0' => t('Zero'),
        'mr-1' => t('Extra small'),
        'mr-2' => t('Small'),
        'mr-3' => t('Medium'),
        'mr-4' => t('Large'),
        'mr-5' => t('Extra Large'),
        'mr-auto' => t('Auto'),
      ];
    }
    return ['mr-0', 'mr-1', 'mr-2', 'mr-3', 'mr-4', 'mr-5', 'mr-auto'];
  }

  /**
   * Return margin bottom.
   */
  public static function getMarginBottom($withLabel = FALSE): array {
    if ($withLabel) {
      return [
        'mb-0' => t('Zero'),
        'mb-1' => t('Extra small'),
        'mb-2' => t('Small'),
        'mb-3' => t('Medium'),
        'mb-4' => t('Large'),
        'mb-5' => t('Extra Large'),
        'mb-auto' => t('Auto'),
      ];
    }
    return ['mb-0', 'mb-1', 'mb-2', 'mb-3', 'mb-4', 'mb-5', 'mb-auto'];
  }

  /**
   * Return margin left.
   */
  public static function getMarginLeft($withLabel = FALSE): array {
    if ($withLabel) {
      return [
        'ml-0' => t('Zero'),
        'ml-1' => t('Extra small'),
        'ml-2' => t('Small'),
        'ml-3' => t('Medium'),
        'ml-4' => t('Large'),
        'ml-5' => t('Extra Large'),
        'ml-auto' => t('Auto'),
      ];
    }
    return ['ml-0', 'ml-1', 'ml-2', 'ml-3', 'ml-4', 'ml-5', 'ml-auto'];
  }

  /**
   * Return margin vertical.
   */
  public static function getMarginVertical($withLabel = FALSE): array {
    if ($withLabel) {
      return [
        'my-0' => t('Zero'),
        'my-1' => t('Extra small'),
        'my-2' => t('Small'),
        'my-3' => t('Medium'),
        'my-4' => t('Large'),
        'my-5' => t('Extra Large'),
        'my-auto' => t('Auto'),
      ];
    }
    return ['my-0', 'my-1', 'my-2', 'my-3', 'my-4', 'my-5', 'my-auto'];
  }

  /**
   * Return margin horizontal.
   */
  public static function getMarginHorizontal($withLabel = FALSE): array {
    if ($withLabel) {
      return [
        'mx-0' => t('Zero'),
        'mx-1' => t('Extra small'),
        'mx-2' => t('Small'),
        'mx-3' => t('Medium'),
        'mx-4' => t('Large'),
        'mx-5' => t('Extra Large'),
        'mx-auto' => t('Auto'),
      ];
    }
    return ['mx-0', 'mx-1', 'mx-2', 'mx-3', 'mx-4', 'mx-5', 'mx-auto'];
  }

}
