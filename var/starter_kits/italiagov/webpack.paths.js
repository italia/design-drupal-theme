import path from 'path';
import fs from 'fs';
import { fileURLToPath } from 'url';

const __filename = fileURLToPath(import.meta.url);
const __dirname = path.dirname(__filename);

// Path setting files
const customSettingsFile = path.resolve(__dirname, './webpack.settings.js');
const defaultSettingsFile = path.resolve(__dirname, './webpack.settings.dist.js');

// Verifica se il file delle impostazioni personalizzato esiste
let settings;
if (fs.existsSync(customSettingsFile)) {
  settings = await import(customSettingsFile);
} else {
  settings = await import(defaultSettingsFile);
}

// Assicurati che `settings` sia il modulo esportato come default
settings = settings.default;

// Definizione dei percorsi
const paths = {
  // Source files
  src: path.resolve(__dirname, settings.sourceDir),

  // Destination build files
  build: path.resolve(__dirname, settings.destinationDir),

  // Modules directory
  modules: path.resolve(__dirname, settings.moduleDir),
};

export default paths;
