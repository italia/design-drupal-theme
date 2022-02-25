# Modifica dei file in questa cartella
Il file `theme.scss` non viene modificato spesso.

Per sovrascrivere le variabili di bootstrap italia modifica il file
"_varibales.scss". Tutte le variabili le puoi trovare nel file:
`node_modules/bootstrap-italia/src/scss/_variables.scss`

Per aggiungere funzioni custom modifica il file "_functions.scss"

Il file "_fix.scss" viene modificato spesso, è consigliato non
aggiungere modifiche custom.

# Aggiungere uno stile custom
Per aggiungere lo stile di una vista puoi procede nel seguente modo:

1. aggiungi dentro la cartella "views" un file denominato
  `_id-vista.scss` con il seguente codice
```
#id-vista { ... }
```
2. aggiungi il seguente codice dentro "views/_views.scss"
```
@import "id-vista"
```

Procedi in maniera analoga per tutto il resto.
Le cartelle rispecchiano la struttura del tema base di Drupal 8.
