/**
 * Main entry
 * This file will be updated periodically by the maintainers,
 * if you modify it check the version changes before opening an issue.
 *
 * For your custom scripts use the 'custom' folder,
 * import your scripts using './custom/custom.js'.
 */

// Import Bootstrap-italia components.
import { loadPlugin } from 'bootstrap-italia/src/js/load-plugin'
import init from 'bootstrap-italia/src/js/plugins/init'
import * as icons from 'bootstrap-italia/src/js/icons'

/**
 * Import all components, to choose components use
 * import {ComponentA, ComponentB, ...} from 'bootstrap-italia'.
 *
 * Docs: https://italia.github.io/bootstrap-italia/docs/come-iniziare/introduzione/#javascript
 * Examples: https://github.com/astagi/demo-bsitalia-2
 */
import {
  Alert,
  Button,
  Carousel,
  Collapse,
  Dropdown,
  Modal,
  Offcanvas,
  Popover,
  ScrollSpy,
  Tab,
  Toast,
  Tooltip,
  Accordion,
  BackToTop,
  CarouselBI,
  Cookiebar,
  Dimmer,
  FormValidate,
  Forward,
  HistoryBack,
  Input,
  InputNumber,
  InputPassword,
  InputSearchAutocomplete,
  List,
  Masonry,
  NavBarCollapsible,
  NavScroll,
  Notification,
//  ProgressDonut,
  SelectAutocomplete,
  Sticky,
  HeaderSticky,
  Transfer,
  UploadDragDrop,
  ValidatorSelectAutocomplete,
  loadFonts,
} from 'bootstrap-italia'

loadPlugin(icons)
init()

const bootstrap = {
  Alert,
  Button,
  Carousel,
  Collapse,
  Dropdown,
  Modal,
  Offcanvas,
  Popover,
  ScrollSpy,
  Tab,
  Toast,
  Tooltip,
  Accordion,
  BackToTop,
  CarouselBI,
  Cookiebar,
  Dimmer,
  FormValidate,
  Forward,
  HistoryBack,
  Input,
  InputNumber,
  InputPassword,
  InputSearchAutocomplete,
  List,
  Masonry,
  NavBarCollapsible,
  NavScroll,
  Notification,
  SelectAutocomplete,
  Sticky,
  HeaderSticky,
  Transfer,
  UploadDragDrop,
  ValidatorSelectAutocomplete,
  loadFonts,
}

// Component library initialization.
import './component-library-initialization'

// Import custom JS.
import './custom/custom'

/**
 * Export all bootstrap-italia components as `bootstrap`,
 * use your custom.js to customize object.
 *
 * @type {any}
 */
window.bootstrap = bootstrap
