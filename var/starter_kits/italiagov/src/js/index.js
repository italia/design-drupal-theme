// Import Bootstrap-italia

import { Alert, Button, Carousel, Collapse, Dropdown, Modal, Offcanvas, Popover, ScrollSpy, Tab, Toast, Tooltip } from 'bootstrap' //importing bootstrap.bundle throws a rollup compiling warning/error

import { loadPlugin } from 'bootstrap-italia/src/js/load-plugin'
import * as fontsLoader from 'bootstrap-italia/src/js/plugins/fonts-loader'
import * as icons from 'bootstrap-italia/src/js/icons.js'
import * as headerSticky from 'bootstrap-italia/src/js/plugins/header-sticky'

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
} from 'bootstrap-italia/src/js/bootstrap-italia'

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

// example js
//import './custom/example'

// Custom theme script
import './custom/component-library-initialization'
