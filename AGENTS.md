# Bootstrap Italia v3 Agent Guide

## Purpose

This file is the consolidated working guide for AI agents and human reviewers
working on `web/themes/contrib/bootstrap_italia`.

It is the primary repository-specific instruction set for:

- architecture and product direction
- component contract design
- library resolution strategy
- repository migration decisions
- Storybook-specific exceptions

This guide is intentionally practical. It records decisions stable enough to
guide implementation and review, while keeping open questions explicit.

## Audience

The primary audience is AI coding agents and LLM-based reviewers.

The text must also remain understandable to human maintainers, reviewers, and
contributors.

## Scope

This guide applies to:

- the Bootstrap Italia base theme under `web/themes/contrib/bootstrap_italia`
- all SDC components under `components/`
- theme templates, helpers, library resolution, and starter-kit boundaries
- architectural review of the v2-to-v3 rewrite direction

This guide does not preserve legacy v2 internals as a normative source.

## Product Direction

Bootstrap Italia v3 is a full rewrite, not a compatibility layer over v2.

The main goals are:

- Drupal minimum `11.4`
- PHP minimum `8.4`
- close fidelity to upstream Bootstrap Italia `3.x`
- a base theme that works on its own, without a sub-theme
- an official starter kit for projects that need custom assets
- one single component system based on Drupal SDC
- explicit, predictable contracts instead of v2-style implicit behavior

Non-goals:

- preserving internal v2 implementation details
- carrying deprecated component APIs into v3
- maintaining duplicated component trees such as `components-0x`
- keeping the `patterns` runtime system
- keeping runtime legacy shims, alias layers, or hidden fallback behavior
- deciding `empty_front_page` at this stage
- porting `content_news` to v3

## Architectural Principles

Use these principles as defaults in both implementation and review.

### 1. No legacy runtime layer

Do not introduce:

- deprecated wrapper templates
- old variable aliases
- fallback namespaces
- alternate Twig APIs for v2 consumers
- preprocess logic whose only purpose is preserving historical behavior

If a contract changes, it should change explicitly and be documented.

### 2. Upstream first

The base theme is the fidelity layer. The starter kit and sub-themes are the
freedom layer.

Prefer:

- upstream naming when practical
- upstream markup semantics
- upstream variants and composition model
- minimal Drupal-specific abstraction, only where justified

### 3. Deterministic contracts

Prefer:

- explicit props
- explicit slots
- explicit blocks
- explicit nested component objects
- explicit library modes

Avoid behavior that emerges from theme settings, preprocess side effects, or
ad hoc variable passing.

### 4. Composition from small primitives

Build components bottom-up. The preferred order is:

1. `icon`
2. `button`
3. `badge`
4. `chip`
5. `avatar`
6. `dropdown-item`
7. `link-item`
8. `card` subparts
9. `card`
10. larger composed structures such as carousel, navigation, and timeline

### 5. Thin base theme, precise integration

The base theme should stay conceptually smaller than v2, but stricter where it
does provide Drupal integration.

It must own:

- Drupal integration
- SDC components
- templates and theme hooks
- minimal integration JS/CSS where strictly necessary
- deterministic library resolution
- layout support that is foundational to the theme

It must not own:

- project-specific asset pipelines
- project-specific CSS overrides
- project-specific JS
- rebuild logic for upstream assets

## Component System

v3 has one component system only:

- `components/`

There must be no parallel legacy trees, no runtime bridge to older APIs, and no
second source of truth for contracts.

Patterns, previews, demos, and Storybook are secondary authoring surfaces. They
must derive from the component contract, not redefine it.

## Component Contract Rules

These rules are normative.

### Structured values, not fragmented flags

Do not expose public component APIs like:

- `icon_name`
- `icon_color`
- `icon_size`
- `button_icon`
- `button_icon_color`

Use structured nested values instead, for example:

```twig
{% include 'bootstrap_italia:button' with {
  label: 'Download',
  icon: {
    name: 'it-file',
    color: 'white'
  }
} only %}
```

or blocks when the content is caller-owned markup:

```twig
{% embed 'bootstrap_italia:button' with { label: 'Download' } %}
  {% block before %}
    {% include 'bootstrap_italia:icon' with {
      name: 'it-file',
      color: 'white'
    } only %}
  {% endblock %}
{% endembed %}
```

### Props, slots, and blocks each have a role

Use props for:

- stable configuration values
- scalars
- booleans
- enums
- structured configuration objects
- convenience variants when they map to documented defaults

Use slots for:

- nested content
- nested components
- caller-owned markup
- flexible content regions not well expressed as scalars

Use blocks for:

- advanced structural override points
- `embed`-based extension
- a small number of intentional authoring escape hatches

Important metadata rule:

- `.component.yml` declares props, real SDC slots, and variants
- Twig blocks must be documented in the `.twig` file and project docs
- do not declare fake SDC slots just to mirror Twig blocks

### Explicit contracts are mandatory

Each component should define:

- required props
- optional props and defaults
- allowed enums
- nested object shapes
- supported slots
- supported Twig blocks
- accessibility expectations
- one or more usage examples

If the contract cannot be described clearly, the component is not ready.

### Smallest useful data model

Pass the minimum explicit data required by the component.

Good:

```twig
{% include 'bootstrap_italia:button' with {
  label: item.title,
  url: item.url,
  icon: item.icon ?? null
} only %}
```

Bad:

```twig
{% include 'bootstrap_italia:button' with {
  item: menu_item
} only %}
```

### Nested objects need documented shapes

If a component accepts a nested object such as `icon`, `image`, `action`, or
metadata entries, that nested shape must be documented in `.component.yml`.

### Nested Attribute handling

Some component props use `Drupal\Core\Template\Attribute`.

Rules:

- in component Twig, when rendering a nested component that accepts
  `attributes` or `wrapper_attributes`, verify that those nested values are
  present
- if they are missing, provide them explicitly with `create_attribute()`
- prefer doing this at the handoff point to the nested component instead of
  weakening the component metadata contract
- for nested objects inside `.component.yml`, use JSON Schema-compatible types
  such as `object`; do not use `Drupal\Core\Template\Attribute` in nested
  property definitions because SDC schema validation rejects it there
- this is especially important for nested `icon`, `link`, `button`, `badge`,
  and `alert` usage

### Variants are convenience defaults, not the main API

Variants are allowed only as an optional convenience layer.

Rules:

- use the machine-name form `{tone}[__{modifier}]*`
- declare variants in the metadata `variants:` section, not again as a
  redundant `props.variant` entry
- parse `variant` locally in the component Twig
- derive internal defaults from `variant`
- explicit props always override variant-derived defaults

Variants must not:

- replace the primary prop contract
- hide required data
- encode large unrelated catalogs

### Blocks must be deliberate

A block should exist only if:

- there is a real extension use case
- the override preserves the component contract
- the component does not become an unbounded template shell

### Avoid boolean explosion

If a component accumulates many booleans such as `is_primary`, `is_outline`,
`with_icon`, `icon_right`, `small`, `large`, or `full_width`, the contract is
probably wrong.

Prefer:

- enums
- structured nested props
- variants
- slots

### Accessibility is part of the contract

Accessibility is not optional implementation detail.

Document:

- required accessible labels
- aria relationships where relevant
- keyboard expectations where relevant
- heading semantics where relevant
- when decorative icons must be hidden from assistive technologies

For `icon` specifically:

- if `decorative` is `true`, the icon must not expose assistive text
- if `decorative` is `false`, an accessible name is required by contract

## Primitive Component Expectations

These are the first contracts that should stabilize.

### `icon`

Purpose:

- render one icon consistently

Typical props:

- `variant`
- `name`
- `size`
- `color`
- `decorative`
- `label`

### `button`

Purpose:

- render actionable button or CTA primitives

Typical props:

- `label`
- `url`
- `variant`
- `size`
- `disabled`
- `icon`
- `icon_position`
- `attributes`

Typical blocks:

- `before`
- `after`

### `badge`

Purpose:

- render compact status or metadata labels

Typical props:

- `label`
- `variant`
- `color`
- `small`
- `rounded`
- `url`

Keep the contract intentionally narrow.

### `alert`

Purpose:

- render contextual feedback with a narrow default structure and explicit
  override points

Typical props:

- `variant`
- `color`
- `icon`
- `default_icon`
- `dismissible`
- `dismissible_effects`
- `dismiss_label`
- `attributes`

Typical slot:

- `content`

Typical block:

- `alert_content`

The default body should remain narrow. Complex bodies should override the block
instead of expanding the base prop surface indefinitely.

### `link-item`

Purpose:

- render normalized text-link items with optional supporting content

### `card`

Purpose:

- render composed content containers built on top of primitives

Large components should be internally layered. For `card`, likely subareas are:

- media
- title
- eyebrow
- text
- metadata
- actions

If variants diverge too far, split them into explicit subcomponents.

## Naming Conventions

Prefer these prop names when they fit:

- `variant`
- `size`
- `label`
- `url`
- `title`
- `summary`
- `icon`
- `image`
- `metadata`
- `attributes`

Avoid:

- component-prefixed prop names inside the same component
- multiple synonyms for the same concept
- transport-style names inherited from preprocess logic

## Library Resolver Strategy

The v3 library resolver must be:

- deterministic
- explicit
- easy to validate
- suitable for a standalone base theme
- compatible with an official starter kit

### Goals

- the base theme works standalone using the upstream library installed through
  `composer.libraries.json`
- sub-themes may provide their own compiled assets explicitly
- CDN mode is optional and explicit
- the active mode is validated
- invalid modes fail loudly

### Non-goals

- preserving v2 runtime library-selection behavior as the primary architecture
- supporting many overlapping modes
- silently falling back from one broken source to another

### Supported modes

Only these modes should exist:

1. `composer-upstream`
2. `subtheme-custom`
3. `cdn`

### Resolution model

Use this model:

1. detect the active theme and whether it is base theme or sub-theme
2. read the declared mode from explicit metadata or tightly scoped config
3. resolve the expected asset source for that mode
4. validate that the source exists and is coherent
5. attach the correct library
6. if validation fails, surface a clear status error and do not switch modes

Base theme owns:

- Drupal-side library definitions
- mode selection logic
- validation

Starter kit or sub-theme owns:

- custom compiled assets when using `subtheme-custom`

## Starter Kit Direction

The starter kit exists to provide customization freedom without bloating the
base theme.

### Base theme contains

- canonical SDC components
- canonical Drupal integration
- library resolution and validation
- foundational layout support

### Starter kit contains

- custom asset build tooling
- custom SCSS
- custom JS
- project assets
- project visual overrides
- freedom to diverge from upstream presentation

The starter kit stays official and supported. Its toolchain must be chosen on
merit, not by inertia. Do not assume Webpack automatically.

## Storybook Rules

These rules are important for review quality.

### Generated files

Treat these files as generated artefacts:

- `components/*/*.stories.json`

They are derived from:

- `components/*/*.stories.twig`

Rules:

- do not use `*.stories.json` as an authoritative source when reviewing
  contracts
- do not report inconsistencies based only on `*.stories.json`
- if `*.stories.json` and `*.stories.twig` differ, `*.stories.twig` is the
  source of truth

Repository note:

- `*.stories.json` is already ignored in the theme `.gitignore`

### Storybook-only contract exception

The public component contract must still use structured values.

However, `*.stories.twig` may expose flat args such as `icon_name` as a
Storybook control workaround.

This exception is narrow:

- it applies only to Storybook story templates
- it does not change the public SDC API
- component `.component.yml` and component `.twig` files must continue to use
  structured nested objects

When reviewing, do not infer a component contract violation solely from
Storybook control workarounds.

Storybook may also expose control-specific flat args or adapter values when
needed to compensate for Storybook limitations or Drupal-specific rendering
constraints.

Review rule:

- do not report Storybook-only adapter props as component API violations when
  the underlying component contract remains structured and unchanged

### Storybook Attribute rule

Storybook validates props before Twig defaults are applied.

Rules:

- in `*.stories.twig`, always pass `create_attribute()` explicitly for any prop
  typed as `Drupal\Core\Template\Attribute`, even when the component already
  defaults it internally
- for `icon`, this applies to both `attributes` and `wrapper_attributes`
- for nested components rendered inside stories, pass explicit
  `create_attribute()` values to the nested component too
- if a story embeds a component that in turn renders nested components with
  `Attribute` props, prefer fixing the story first and then the component Twig
  handoff only when needed

## Repository Migration Decisions

This section records mature v2-to-v3 decisions.

### Areas to drop

- `components/components-0x`
- the `patterns` runtime system
- `content_news`
- deprecated wrapper templates
- runtime demo templates as production contracts

### Areas to rewrite

- the base theme manifest and bootstrap
- `bootstrap_italia.libraries.yml`
- `composer.libraries.json` integration
- the entire v3 SDC component tree
- core Drupal templates such as page, html, menu, pager, file link, status
  messages, header, footer, and page structure
- most preprocess logic
- most helper classes
- theme settings and schema

### Areas to merge or consolidate

- layouts into the main project
- Views integrations into one dedicated optional module
- Paragraphs integrations into one dedicated optional module
- duplicated card families into one coherent card system

### Areas to defer

- `empty_front_page`
- front-page specialization beyond the foundation
- some non-core template areas such as specific Webform or TOC integrations
- translation realignment until component contracts stabilize

## Current Repository Classification

Use this simplified action vocabulary when evaluating v2 material:

- `rewrite`: rebuild cleanly in v3
- `merge`: consolidate into a broader, simpler destination
- `drop`: do not port
- `backportable`: can improve v2 safely
- `defer`: revisit later

## Theme and Template Guidance

### Templates

Prefer:

- smaller, clearer base templates
- explicit page and layout structure
- component-driven rendering where appropriate
- minimal wrappers and minimal hidden logic

Avoid:

- proliferating specialized templates with weak contracts
- region-specific or view-mode-specific templates that exist only because of
  legacy fragmentation

### Preprocess

Preprocess should exist only when Drupal truly requires normalization.

Rules:

- drastically reduce preprocess usage compared to v2
- every remaining preprocess must have a precise and testable purpose
- do not use preprocess as a transport bus for component variables
- isolate unavoidable normalization in small helpers

## Optional Modules

Optional integrations should stay optional.

### Views

Use one dedicated optional module for Views integrations.

### Paragraphs

Use one dedicated optional module for Paragraphs integrations.

### Layouts

Layouts belong to the main project, not to a fragmented optional packaging
story.

## Backport Policy

### Backportable to v2

- code quality improvements
- safer validation
- test coverage
- bug fixes
- documentation improvements
- selective non-breaking cleanup

### Not backportable to v2

- redesigned component APIs
- slot/prop/block contract changes
- removal of legacy aliases
- package-boundary changes
- module consolidation that changes install contracts
- library resolution redesigns that break existing v2 workflows

## Mature Decisions

These decisions are stable enough to treat as fixed unless a new RFC explicitly
reopens them:

- `components/components-0x` does not enter v3
- `patterns` does not enter v3 as a runtime system
- `content_news` does not enter v3
- layouts are absorbed into the main project
- Views modules are unified
- Paragraphs modules are unified
- the base theme must work without a sub-theme
- the starter kit stays official and supported
- upstream Bootstrap Italia `3.x` is the fidelity target

## Open Questions

These questions are real and should not be guessed away:

- the exact on-disk location of the Composer-installed upstream library
- the final concrete shape of the library resolver classes
- whether CDN mode ships in `3.0.0` or later
- the exact SDC convention for all nested component patterns
- the minimal allowed settings surface in v3
- the exact boundary between base-theme templates and optional-module templates
- the final starter-kit toolchain

## Known Issues

These items are intentional or currently constrained tradeoffs.

- `icon` keeps a fallback icon name as a deliberate visual warning signal when
  the caller fails to pass a valid icon name; the rendered SVG is marked with
  `data-missing-icon-name="true"` for future automated checks
- `icon` ignores `label` when `decorative` is `true`; for non-decorative usage
  it still falls back to the resolved icon name as a pragmatic compromise rather
  than an ideal accessibility contract
- `link` keeps a fallback `href` of `#` as a pragmatic guard because some
  Drupal menu flows can end up normalizing placeholder links to an empty string
  before rendering
- `button` intentionally overrides nested icon size and color in Twig to match
  upstream Bootstrap Italia button rules, even when callers provide those icon
  values explicitly

Review rule:

- do not report the items above as contract regressions unless the underlying
  tooling limitation has been resolved first

## Review Heuristics

When reviewing code in this theme, prioritize these failure modes:

- hidden legacy compatibility sneaking back in
- undocumented or implicit component contracts
- Storybook or demo code becoming a second source of truth
- preprocess logic carrying component state implicitly
- ambiguous library resolution or silent fallback behavior
- excessive divergence from upstream markup semantics
- optional integrations leaking into the base theme
