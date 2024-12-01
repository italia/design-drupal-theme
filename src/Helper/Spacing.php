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
   *
   * @param bool $withLabel
   *   Choose from array with label or not.
   *
   * @return array<int|string>
   *   Top paddings.
   */
  public static function getPaddingTop(bool $withLabel = FALSE): array {
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
   *
   * @param bool $withLabel
   *   Choose from array with label or not.
   *
   * @return array<int|string>
   *   Right paddings.
   */
  public static function getPaddingRight(bool $withLabel = FALSE): array {
    if ($withLabel) {
      return [
        'pe-0' => t('Zero'),
        'pe-1' => t('Extra small'),
        'pe-2' => t('Small'),
        'pe-3' => t('Medium'),
        'pe-4' => t('Large'),
        'pe-5' => t('Extra Large'),
        'pe-auto' => t('Auto'),
      ];
    }
    return ['pe-0', 'pe-1', 'pe-2', 'pe-3', 'pe-4', 'pe-5', 'pe-auto'];
  }

  /**
   * Return padding bottom.
   *
   * @param bool $withLabel
   *   Choose from array with label or not.
   *
   * @return array<int|string>
   *   Bottom paddings.
   */
  public static function getPaddingBottom(bool $withLabel = FALSE): array {
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
   *
   * @param bool $withLabel
   *   Choose from array with label or not.
   *
   * @return array<int|string>
   *   Left paddings.
   */
  public static function getPaddingLeft(bool $withLabel = FALSE): array {
    if ($withLabel) {
      return [
        'ps-0' => t('Zero'),
        'ps-1' => t('Extra small'),
        'ps-2' => t('Small'),
        'ps-3' => t('Medium'),
        'ps-4' => t('Large'),
        'ps-5' => t('Extra Large'),
        'ps-auto' => t('Auto'),
      ];
    }
    return ['ps-0', 'ps-1', 'ps-2', 'ps-3', 'ps-4', 'ps-5', 'ps-auto'];
  }

  /**
   * Return padding vertical.
   *
   * @param bool $withLabel
   *   Choose from array with label or not.
   *
   * @return array<int|string>
   *   Vertical paddings.
   */
  public static function getPaddingVertical(bool $withLabel = FALSE): array {
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
   *
   * @param bool $withLabel
   *   Choose from array with label or not.
   *
   * @return array<int|string>
   *   Horizontal paddings.
   */
  public static function getPaddingHorizontal(bool $withLabel = FALSE): array {
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
   *
   * @param bool $withLabel
   *   Choose from array with label or not.
   *
   * @return array<int|string>
   *   Top margins.
   */
  public static function getMarginTop(bool $withLabel = FALSE): array {
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
   *
   * @param bool $withLabel
   *   Choose from array with label or not.
   *
   * @return array<int|string>
   *   Right margins.
   */
  public static function getMarginRight(bool $withLabel = FALSE): array {
    if ($withLabel) {
      return [
        'me-0' => t('Zero'),
        'me-1' => t('Extra small'),
        'me-2' => t('Small'),
        'me-3' => t('Medium'),
        'me-4' => t('Large'),
        'me-5' => t('Extra Large'),
        'me-auto' => t('Auto'),
      ];
    }
    return ['me-0', 'me-1', 'me-2', 'me-3', 'me-4', 'me-5', 'me-auto'];
  }

  /**
   * Return margin bottom.
   *
   * @param bool $withLabel
   *   Choose from array with label or not.
   *
   * @return array<int|string>
   *   Bottom margins.
   */
  public static function getMarginBottom(bool $withLabel = FALSE): array {
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
   *
   * @param bool $withLabel
   *   Choose from array with label or not.
   *
   * @return array<int|string>
   *   Left margins.
   */
  public static function getMarginLeft(bool $withLabel = FALSE): array {
    if ($withLabel) {
      return [
        'ms-0' => t('Zero'),
        'ms-1' => t('Extra small'),
        'ms-2' => t('Small'),
        'ms-3' => t('Medium'),
        'ms-4' => t('Large'),
        'ms-5' => t('Extra Large'),
        'ms-auto' => t('Auto'),
      ];
    }
    return ['ms-0', 'ms-1', 'ms-2', 'ms-3', 'ms-4', 'ms-5', 'ms-auto'];
  }

  /**
   * Return margin vertical.
   *
   * @param bool $withLabel
   *   Choose from array with label or not.
   *
   * @return array<int|string>
   *   Vertical margins.
   */
  public static function getMarginVertical(bool $withLabel = FALSE): array {
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
   *
   * @param bool $withLabel
   *   Choose from array with label or not.
   *
   * @return array<int|string>
   *   Horizontal margins.
   */
  public static function getMarginHorizontal(bool $withLabel = FALSE): array {
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
