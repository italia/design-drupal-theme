const MiniCssExtractPlugin = require('mini-css-extract-plugin')
const CopyWebpackPlugin = require('copy-webpack-plugin')
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
        use: [
          {
            loader: 'svg-url-loader',
            options: {
              limit: 10000,
            },
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
    new CopyWebpackPlugin({
      patterns:[
        {
          from: paths.modules + '/bootstrap-italia/src/assets/',
          to: paths.build + '/assets/'
        },
        {
          from: paths.modules + '/bootstrap-italia/src/fonts/',
          to: paths.build + '/fonts/'
        },
        {
          from: paths.modules + '/bootstrap-italia/src/svg/',
          to: paths.build + '/svg/',
        },
        {
          from: './src/images/',
          to: paths.build + '/images/'
        }
      ]
    }),
  ],
};
