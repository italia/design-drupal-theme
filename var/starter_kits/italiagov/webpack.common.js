const MiniCssExtractPlugin = require('mini-css-extract-plugin')
const CopyWebpackPlugin = require('copy-webpack-plugin')
const SpriteLoaderPlugin = require('svg-sprite-loader/plugin')
const check = require('./webpack.check')

const paths = require('./webpack.paths')

module.exports = {
  // Entry
  entry: {
    "bootstrap-italia": [paths.src + '/js/index.js', paths.src + '/scss/theme.scss'],
    //"bootstrap-italia-comuni": [paths.src + '/js/index.js', paths.src + '/scss/theme-comuni.scss']
  },

  // Output
  output: {
    path: paths.build,
    filename: "js/[name].min.js",
  },
  module: {
    rules: [
      {
        test: /\.svg$/,
        include: paths.modules + '/bootstrap-italia/src/svg',
        use: [
          {
            loader: 'svg-sprite-loader',
            options: {
              extract: true,
              outputPath: '/svg/',
              spriteFilename: 'sprites.svg',
            }
          },
          {
            loader: 'svgo-loader',
            options: {
              plugins: [
                {
                  name: 'removeAttrs',
                  params: {
                    attrs: '(fill)',
                  },
                }
              ]
            }
          }
        ],
      },
    ],
  },
  plugins: [
    new MiniCssExtractPlugin({
      filename: 'css/[name].min.css',
      chunkFilename: 'css/[id].min.css'
    }),
    new SpriteLoaderPlugin({
      plainSprite: true
    }),
    new CopyWebpackPlugin({
      patterns:[
        {
          from: paths.modules + '/bootstrap-italia/src/assets/',
          to: paths.build + '/assets/'
        },
        {
          from: paths.modules + '/bootstrap-italia/src/fonts/',
          to: paths.build + '/fonts/'
        },
        {
          from: './src/images/',
          to: paths.build + '/images/'
        }
      ]
    }),
  ],
};
