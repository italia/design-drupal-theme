import { merge } from 'webpack-merge';
import fs from 'fs';
import dev from './webpack.dev.js';

const customSettingsFile = './webpack.settings.js';
const settings = fs.existsSync(customSettingsFile)
  ? await import('./webpack.settings.js')
  : await import('./webpack.settings.dist.js');

export default merge(dev, {
  output: {
    publicPath: settings.hotPublicPath,
  },
  devServer: settings.devServer,
});
