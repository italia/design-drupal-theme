const semver = require('semver')
const { engines } = require('./package')

if ( !semver.satisfies(process.version, engines.node) ) {
  throw new Error('The current node version of node (' + process.version + ') does not satisfy the required version (' + engines.node + ').')
}
