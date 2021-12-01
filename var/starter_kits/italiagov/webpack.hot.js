const { merge } = require('webpack-merge')

const dev = require('./webpack.dev')

module.exports = merge(dev, {
  output: {
    // if change this, remember to change relative path in "theme.libraries.yml"
    publicPath: '/',
  },
  devServer: {
    allowedHosts: '127.0.0.1', // or project-name.ddev.site
    historyApiFallback: true,
    compress: true,
    https: false,
    hot: true,
    port: 8080,
  },
})
