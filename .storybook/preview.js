const serverUrl =
  process.env.STORYBOOK_SERVER_URL ||
  (process.env.DDEV_PRIMARY_URL
    ? `${process.env.DDEV_PRIMARY_URL}/storybook/stories/render`
    : undefined);

/** @type { import('@storybook/server-webpack5').Preview } */
const preview = {
  ...(serverUrl ? { server: { url: serverUrl } } : {}),
  parameters: {
    // options: {
    //   storySort: {
    //     order: ['Bootstrap Italia', ['Content', 'Components', 'Utilities']],
    //   },
    // },
    controls: {
      matchers: {
        color: /(background|color)$/i,
        date: /Date$/i,
      },
    },
  },
};

export default preview;
