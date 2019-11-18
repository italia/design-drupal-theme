var path = require('path');
const UglifyJsPlugin = require('uglifyjs-webpack-plugin');
const MiniCssExtractPlugin = require('mini-css-extract-plugin');

module.exports = {
  entry: './src/js/index.js',

  output: {
    path: path.resolve(__dirname, 'assets'),
    filename: "js/bundle.js",
    publicPath: "/assets/",
  },

  devtool: "source-map",

  module: {
    rules: [{
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
    }],
  },

  plugins: [
    new UglifyJsPlugin(),
    new MiniCssExtractPlugin({
      filename: 'css/[name].css',
      chunkFilename: 'css/[id].css'
    }),
  ],
};