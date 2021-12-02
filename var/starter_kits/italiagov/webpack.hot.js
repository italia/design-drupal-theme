const { merge } = require('webpack-merge')

const fs = require('fs')
const customSettingsFile = './webpack.settings.js'
const settings = fs.existsSync(customSettingsFile)
  ? require('./webpack.settings')
  : require('./webpack.settings.dist')

const dev = require('./webpack.dev')

module.exports = merge(dev, {
  output: {
    publicPath: settings.hotPublicPath,
  },
  devServer: settings.devServer,
})
