const path = require('path')

const fs = require('fs')
const customSettingsFile = './webpack.settings.js'
const settings = fs.existsSync(customSettingsFile)
    ? require('./webpack.settings')
    : require('./webpack.settings.dist')

module.exports = {
  // Source files
  src: path.resolve(__dirname, settings.sourceDir),

  // Destination build files
  build: path.resolve(__dirname, settings.destinationDir),

  modules: path.resolve(__dirname, settings.moduleDir),
}
