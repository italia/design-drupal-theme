const MiniCssExtractPlugin = require('mini-css-extract-plugin')
const CopyWebpackPlugin = require('copy-webpack-plugin')
const SpriteLoaderPlugin = require('svg-sprite-loader/plugin')
const webpack = require('webpack')
const check = require('./webpack.check')

const paths = require('./webpack.paths')

module.exports = {
  // Entry
  entry: {
    "bootstrap-italia": [paths.src + '/js/index.js', paths.src + '/scss/theme.scss']
  },

  // Output
  output: {
    path: paths.build,
    filename: "js/[name].js",
  },
  module: {
    rules: [
      {
        test: /\.svg$/,
        include: paths.modules + '/bootstrap-italia/src/svg',
        use: [
          {
            loader: 'svg-sprite-loader',
            options: {
              extract: true,
              outputPath: '/svg/',
              spriteFilename: 'sprites.svg',
            }
          },
        ],
      },
    ],
  },

  plugins: [
    new MiniCssExtractPlugin({
      filename: 'css/[name].css',
      chunkFilename: 'css/[id].css'
    }),
    new SpriteLoaderPlugin({
      plainSprite: true
    }),
    new CopyWebpackPlugin({
      patterns:[
        {
          from: paths.modules + '/bootstrap-italia/src/assets/resizer-3x2.svg',
          to: paths.build + '/assets/'
        },
        {
          from: paths.modules + '/bootstrap-italia/src/assets/upload-drag-drop-icon.svg',
          to: paths.build + '/assets/'
        },
        {
          from: paths.modules + '/bootstrap-italia/src/fonts/',
          to: paths.build + '/fonts/'
        },
        {
          from: paths.modules + '/bootstrap-italia/dist/svg/sprite.svg',
          to: paths.build + '/svg/',
        },
        {
          from: './src/images/',
          to: paths.build + '/images/'
        }
      ]
    }),
    new webpack.ProvidePlugin({
      $: 'jquery',
      jQuery: 'jquery'
    }),
  ],
};
