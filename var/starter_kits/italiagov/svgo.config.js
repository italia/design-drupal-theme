// https://svgo.dev/docs/plugins/
export default {
  multipass: true,
  plugins: [
    'cleanupAttrs',
    'cleanupAttrs',
    'removeEmptyAttrs',
    'removeComments',
    'convertStyleToAttrs',
    'removeEmptyContainers',
    'removeEmptyText',
    'removeRasterImages',
    'removeUnknownsAndDefaults',
    'reusePaths',
    {
      name: 'removeAttrs',
      params: {
        attrs: '(fill)',
      },
    },
  ],
};
