export default {
  // Basic settings
  sourceDir: 'src',
  destinationDir: 'dist',
  moduleDir: 'node_modules',

  // Hot mode settings
  /**
   * If you edit this variable, change relative path in "<theme>.libraries.yml" on 'hot' array.
   */
  hotPublicPath: '/',

  devServer: {
    /**
     * This option allows you to whitelist services that are allowed to access the dev server.
     * https://webpack.js.org/configuration/dev-server/#devserverallowedhosts
     *
     * 'auto' | 'all' [string]
     */
    allowedHosts: 'all',

    /**
     * https://webpack.js.org/configuration/dev-server/#devserverclient
     */
    client: {
      logging: 'info', // 'log' | 'info' | 'warn' | 'error' | 'none' | 'verbose'
      overlay: true,
      progress: true,
      reconnect: true,
    },

    /**
     * https://webpack.js.org/configuration/dev-server/#devserverhttps
     */
    https: false,

    /**
     * https://webpack.js.org/configuration/dev-server/#devserverport
     */
    port: 8080,
  }
};
