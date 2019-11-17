var path = require('path');
const UglifyJsPlugin = require('uglifyjs-webpack-plugin');

module.exports = {
  entry: './src/js/index.js',

  output: {
    path: path.resolve(__dirname, 'assets'),
    filename: "bundle.js",
    publicPath: "/assets/"
  }
};