/**
 * Main entry
 * This file will be updated periodically by the maintainers,
 * if you modify it check the version changes before opening an issue.
 *
 * For your custom scripts use the 'custom' folder,
 * import your scripts using './custom/custom.js'.
 */

// Import Bootstrap-italia components.
import { loadPlugin } from 'bootstrap-italia/src/js/load-plugin.js';
import init from 'bootstrap-italia/src/js/plugins/init.js';
import * as icons from 'bootstrap-italia/src/js/icons.js';

/**
 * Import all components, to choose components use
 * import {ComponentA, ComponentB, ...} from 'bootstrap-italia'.
 *
 * Docs: https://italia.github.io/bootstrap-italia/docs/come-iniziare/introduzione/#javascript
 * Examples: https://github.com/astagi/demo-bsitalia-2
 */
import * as bootstrap from 'bootstrap-italia';

loadPlugin(icons);
init();

// Component library initialization.
import './component-library-initialization.js';

// Import custom JS.
import './custom/custom.js';

/**
 * Export all bootstrap-italia components as `bootstrap`,
 * use your custom.js to customize object.
 *
 * @type {any}
 */
window.bootstrap = bootstrap;
