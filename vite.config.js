import { defineConfig } from 'vite'
import { glob } from 'glob'
import path from 'path'
import { fileURLToPath } from 'url'
import { viteStaticCopy } from 'vite-plugin-static-copy'

const __dirname = path.dirname(fileURLToPath(import.meta.url))

// Path to Bootstrap Italia in node_modules (build-time only).
const UPSTREAM = path.resolve(__dirname, 'node_modules/bootstrap-italia')

// Auto-discover component entries: components/NAME/_NAME.js
// Build-time map: { 'button': '/abs/path/components/button/_button.js', ... }
const componentEntries = Object.fromEntries(
  glob.sync('components/*/_*.js', { cwd: __dirname }).map((file) => {
    const name = path.basename(file, '.js').replace(/^_/, '')
    return [name, path.resolve(__dirname, file)]
  })
)

// For a component entry, returns the relative directory (e.g. 'components/button').
const componentDir = (name) => {
  const entryPath = componentEntries[name]
  return path.relative(__dirname, path.dirname(entryPath))
}

export default defineConfig({
  build: {
    // outDir is the theme root so component outputs land at components/NAME/NAME.css
    // without a dist/ prefix. Use emptyOutDir: false — never wipe the theme directory.
    outDir: '.',
    emptyOutDir: false,
    cssCodeSplit: true,
    rollupOptions: {
      // bootstrap-italia marks src/js/plugins/* as side-effect-free in package.json.
      // Override: preserve side effects for upstream plugins so that their data-api
      // event handlers (e.g. EventHandler.on for data-bs-toggle) are not tree-shaken.
      treeshake: {
        moduleSideEffects: (id) => id.includes('bootstrap-italia/src/js'),
      },
      input: {
        base: path.resolve(__dirname, 'src/base.entry.js'),
        fonts: path.resolve(__dirname, 'src/fonts.entry.js'),
        ...componentEntries,
      },
      output: {
        // base/fonts → dist/js/NAME.js
        // components → components/NAME/NAME.js
        entryFileNames: (chunk) => {
          if (componentEntries[chunk.name]) {
            return `${componentDir(chunk.name)}/${chunk.name}.js`
          }
          return 'dist/js/[name].js'
        },
        // base/fonts CSS → dist/css/NAME.css
        // component CSS → components/NAME/NAME.css
        assetFileNames: (info) => {
          if (info.name?.endsWith('.css')) {
            const name = info.name.replace('.css', '')
            if (componentEntries[name]) {
              return `${componentDir(name)}/${info.name}`
            }
            return `dist/css/${info.name}`
          }
          return info.name ?? '[name][extname]'
        },
        chunkFileNames: 'dist/js/chunks/[name]-[hash].js',
      },
    },
  },
  css: {
    preprocessorOptions: {
      scss: {
        loadPaths: [
          path.resolve(UPSTREAM, 'src/scss'),
          path.resolve(__dirname, 'node_modules'),
        ],
      },
    },
  },
  plugins: [
    viteStaticCopy({
      targets: [
        { src: path.resolve(UPSTREAM, 'dist/svg/sprites.svg'), dest: 'dist/svg' },
        { src: path.resolve(UPSTREAM, 'dist/fonts/*'), dest: 'dist/fonts' },
      ],
    }),
  ],
})
