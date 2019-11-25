var path = require('path');
const CopyPlugin = require('copy-webpack-plugin');
const MiniCssExtractPlugin = require('mini-css-extract-plugin');
const MinifyPlugin = require('babel-minify-webpack-plugin');
const webpack = require('webpack');

module.exports = {
  entry: './src/js/index.js',

  output: {
    path: path.resolve(__dirname, 'assets'),
    filename: "js/bundle.js",
    publicPath: "/assets/",
  },

  devtool: "source-map",

  module: {
    rules: [
      {
        test: /\.(sa|sc|c)ss$/i,
        use: [
          {
            loader: MiniCssExtractPlugin.loader,
            options: {
              hmr: process.env.NODE_ENV === 'development',
              reloadAll: true,
            },
          },
          {
            loader: 'css-loader',
            options: {
              sourceMap: true,
            }
          },
          {
            loader: 'sass-loader',
            options: {
              sourceMap: true,
            },
          },
        ],
      },
    ],
  },

  plugins: [
    new MinifyPlugin({},{}),
    new MiniCssExtractPlugin({
      filename: 'css/[name].css',
      chunkFilename: 'css/[id].css'
    }),
    new CopyPlugin([
      {
        from: './node_modules//bootstrap-italia/dist/svg/sprite.svg',
        to: 'icons/',
      },
      {
        from: './node_modules/bootstrap-italia/src/assets/resizer-3x2.svg',
        to: 'icons/'
      },
      {
        from: './node_modules/bootstrap-italia/src/assets/upload-drag-drop-icon.svg',
        to: 'icons/'
      },
      {
        from: './node_modules/bootstrap-italia/src/fonts/',
        to: 'fonts/'
      },
    ]),
    new webpack.ProvidePlugin({
      $: 'jquery',
      jQuery: 'jquery'
    }),
  ],
};
