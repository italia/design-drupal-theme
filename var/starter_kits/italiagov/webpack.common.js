import fs from 'fs/promises';
import MiniCssExtractPlugin from 'mini-css-extract-plugin';
import CopyWebpackPlugin from 'copy-webpack-plugin';
import SvgChunkWebpackPlugin from 'svg-chunk-webpack-plugin';
import paths from './webpack.paths.js';
import semver from 'semver';
import packageJson from './package.json' assert { type: 'json' };

if (!semver.satisfies(process.version, packageJson.engines.node)) {
  throw new Error(`The current Node.js version (${process.version}) does not satisfy the required version (${packageJson.engines.node}).`);
}

export default {
  // Entry
  entry: {
    "bootstrap-italia": [`${paths.src}/js/index.js`, `${paths.src}/scss/theme.scss`],
    //"ckeditor5": `${paths.src}/scss/ckeditor5.scss`,
  },

  // Output
  output: {
    path: paths.build,
    filename: "js/[name].min.js",
  },

  module: {
    rules: [
      {
        test: /\.svg$/,
        include: [
          `${paths.modules}/bootstrap-italia/src/svg`,
          `${paths.src}/svg`,
        ],
        use: [
          {
            loader: SvgChunkWebpackPlugin.loader,
          },
        ],
      },
    ],
  },

  plugins: [
    new MiniCssExtractPlugin({
      filename: 'css/[name].min.css',
      chunkFilename: 'css/[id].min.css',
    }),
    new SvgChunkWebpackPlugin({
      filename: 'svg/sprites.svg',
      svgstoreConfig: {
        svgAttrs: {
          'xmlns': 'http://www.w3.org/2000/svg',
        }
      }
    }),
    new CopyWebpackPlugin({
      patterns: [
        {
          from: `${paths.modules}/bootstrap-italia/src/assets/`,
          to: `${paths.build}/assets/`,
        },
        {
          from: `${paths.modules}/bootstrap-italia/src/fonts/`,
          to: `${paths.build}/fonts/`,
        },
        {
          from: './src/images/',
          to: `${paths.build}/images/`,
        },
      ],
    }),
    {
      apply: (compiler) => {
        compiler.hooks.afterEmit.tapPromise('AfterEmitPlugin', async (compilation) => {
          const ckeditorJsFile = `${compiler.options.output.path}/js/ckeditor5.min.js`;
          try {
            await fs.rm(ckeditorJsFile, { force: true });
          } catch (err) {
            console.error('Error deleting ckeditor5.min.js:', err);
          }
        });
      },
    },
  ],
};
