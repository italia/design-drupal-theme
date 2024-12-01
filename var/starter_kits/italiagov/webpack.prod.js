import MiniCssExtractPlugin from 'mini-css-extract-plugin';
import { CleanWebpackPlugin } from 'clean-webpack-plugin';
import { merge } from 'webpack-merge';
import TerserPlugin from 'terser-webpack-plugin';
import CssMinimizerPlugin from 'css-minimizer-webpack-plugin';

import common from './webpack.common.js';

export default merge(common, {
  mode: 'production',
  devtool: false,

  plugins: [
    // Removes/cleans build folders and unused assets when rebuilding
    new CleanWebpackPlugin(),
  ],

  module: {
    rules: [
      {
        test: /\.(sa|sc|c)ss$/i,
        use: [
          MiniCssExtractPlugin.loader,
          {
            loader: 'css-loader',
            options: {
              importLoaders: 2,
              sourceMap: false,
              modules: false,
            },
          },
          'postcss-loader',
          'sass-loader',
        ],
      },
    ],
  },

  optimization: {
    minimize: true,
    minimizer: [
      new TerserPlugin({
        terserOptions: {
          compress: {
            drop_console: true, // Removes console.logs from production code
          },
          format: {
            comments: false, // Remove all comments
          },
        },
        extractComments: false, // Prevents extracting comments into separate files
      }),
      new CssMinimizerPlugin({
        minimizerOptions: {
          preset: [
            'default',
            {
              svgo: false, // Disable SVGO (inline scss issue)
            },
          ],
        },
      }),
    ],
  },

  performance: {
    hints: false,
    maxEntrypointSize: 860000,
    maxAssetSize: 860000,
  },
});
