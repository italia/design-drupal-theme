const MiniCssExtractPlugin = require('mini-css-extract-plugin')
const { CleanWebpackPlugin } = require('clean-webpack-plugin')
const CopyWebpackPlugin = require('copy-webpack-plugin')
const webpack = require('webpack')
const check = require('./webpack.check')

const paths = require('./webpack.paths')

module.exports = {
  // Entry
  entry: [paths.src + '/js/index.js'],

  // Output
  output: {
    path: paths.build,
    filename: "js/bundle.js",
    publicPath: "/",
  },

  devtool: "source-map",

  plugins: [
    // Removes/cleans build folders and unused assets when rebuilding
    new CleanWebpackPlugin(),

    new MiniCssExtractPlugin({
      filename: 'css/[name].css',
      chunkFilename: 'css/[id].css'
    }),
    new CopyWebpackPlugin({
      patterns:[
        {
          from: paths.modules + '/bootstrap-italia/dist/svg/sprite.svg',
          to: paths.build + '/icons/',
        },
        {
          from: paths.modules + '/bootstrap-italia/src/assets/resizer-3x2.svg',
          to: paths.build + '/icons/'
        },
        {
          from: paths.modules + '/bootstrap-italia/src/assets/upload-drag-drop-icon.svg',
          to: paths.build + '/icons/'
        },
        {
          from: paths.modules + '/bootstrap-italia/src/fonts/',
          to: paths.build + '/fonts/'
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
