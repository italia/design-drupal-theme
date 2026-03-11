/**
 * Bootstrap Italia v3 – global base entry point.
 *
 * Vite extracts all imported CSS as dist/css/base.css.
 * No JS is exported from this entry.
 *
 * Import order matters:
 * 1. Design tokens CSS (--it-* CSS custom properties) must precede the SCSS
 *    output so that the browser resolves --it-* references in :root correctly.
 *    Imported as CSS here because dart-sass treats .css @imports as plain CSS
 *    passthrough (not inline inclusion), while Vite inlines CSS imports from JS.
 */

// 1. Design tokens: --it-* CSS custom properties
import 'design-tokens-italia/dist/css/variables.css'

// 2. Bootstrap Italia base layer (compiled from upstream SCSS)
import './base.scss'
