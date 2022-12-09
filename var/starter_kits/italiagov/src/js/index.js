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
import * as fontsLoader from 'bootstrap-italia/src/js/plugins/fonts-loader'
import * as icons from 'bootstrap-italia/src/js/icons'
import * as headerSticky from 'bootstrap-italia/src/js/plugins/header-sticky'

import BOOTSTRAP_ITALIA_VERSION from 'bootstrap-italia/src/js/version'

loadPlugin(icons)
loadPlugin(fontsLoader)
loadPlugin(headerSticky)

import {
  Dimmer,
  Notification,
  Cookiebar,
  NavBarCollapsible,
  Accordion,
  NavScroll,
  TrackFocus,
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
  HistoryBack,
  Forward,
  Masonry,
  List,
  Transfer,
} from 'bootstrap-italia/src/js/bootstrap-italia.esm'

window.BOOTSTRAP_ITALIA_VERSION = BOOTSTRAP_ITALIA_VERSION

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
  TrackFocus,
  Transfer,
  UploadDragDrop,
  ValidatorSelectAutocomplete,
}

// Component library initialization.
import './component-library-initialization'

// Import custom JS.
import './custom/custom'
