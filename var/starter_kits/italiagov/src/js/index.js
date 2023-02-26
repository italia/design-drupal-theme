/**
 * Main entry
 * This file will be updated periodically by the maintainers,
 * please do not make any changes.
 *
 * For your custom scripts use the 'custom' folder,
 * import your scripts using './custom/custom.js'.
 */

// Import Bootstrap 5.
import { Alert, Button, Carousel, Collapse, Dropdown, Modal, Offcanvas, Popover, ScrollSpy, Tab, Toast, Tooltip } from 'bootstrap'

// Import Bootstrap Italia.
import { loadPlugin } from 'bootstrap-italia/src/js/load-plugin'
import init from 'bootstrap-italia/src/js/plugins/init'
import loadFonts from 'bootstrap-italia/src/js/plugins/fonts-loader'
import * as icons from 'bootstrap-italia/src/js/icons'

import {
  Dimmer,
  Notification,
  Cookiebar,
  NavBarCollapsible,
  Accordion,
  NavScroll,
  CarouselBI,
  FormValidate,
  ValidatorSelectAutocomplete,
  Input,
  SelectAutocomplete,
  InputSearchAutocomplete,
  InputPassword,
  InputNumber,
  ProgressDonut,
  UploadDragDrop,
  BackToTop,
  Sticky,
  HeaderSticky,
  HistoryBack,
  Forward,
  Masonry,
  List,
  Transfer,
} from 'bootstrap-italia/src/js/bootstrap-italia.esm'

loadPlugin(icons)
init()

window.bootstrap = {
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
  ProgressDonut,
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
