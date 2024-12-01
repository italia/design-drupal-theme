import path from 'path';
import fs from 'fs';
import { fileURLToPath } from 'url';

const __filename = fileURLToPath(import.meta.url);
const __dirname = path.dirname(__filename);

// Path setting files
const customSettingsFile = path.resolve(__dirname, './webpack.settings.js');
const defaultSettingsFile = path.resolve(__dirname, './webpack.settings.dist.js');

// Check if the custom settings file exists
let settings;
if (fs.existsSync(customSettingsFile)) {
  settings = await import(customSettingsFile);
} else {
  settings = await import(defaultSettingsFile);
}

// Export setting as default
settings = settings.default;

const paths = {
  // Source files
  src: path.resolve(__dirname, settings.sourceDir),

  // Destination build files
  build: path.resolve(__dirname, settings.destinationDir),

  // Modules directory
  modules: path.resolve(__dirname, settings.moduleDir),
};

export default paths;
