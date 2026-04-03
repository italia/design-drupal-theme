

/** @type { import('@storybook/server-webpack5').StorybookConfig } */
const config = {
  stories: ["../components/**/*.stories.@(json|yaml|yml)"],
  staticDirs: [
    {
      from: "../../../../libraries",
      to: "/libraries",
    },
  ],
  addons: [
    "@storybook/addon-webpack5-compiler-swc",
    "@storybook/addon-a11y",
    "@storybook/addon-docs"
  ],
  core: {
    allowedHosts: true
  },
  framework: "@storybook/server-webpack5"
};
export default config;
