const path = require('path');

module.exports = {
  // Source files
  src: path.resolve(__dirname, 'src'),

  // Destination build files
  build: path.resolve(__dirname, 'assets'),

  modules: path.resolve(__dirname, 'node_modules'),
}
