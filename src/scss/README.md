# Modifica dei file in questa cartella
Non modificare il file "theme.scss"

Per sovrascrivere le variabili di bootstrap italia modifica il file "_varibales.scss"

Per aggiungere funzioni custom modifica il file "_functions.scss"

Per fix, drupal o bootstrap, modifica il file "_fix.scss"

# Aggiungere stile custom
Ad esempio, per aggiungere lo stile di una vista si procede nel seguente modo:

1. aggiungere dentro la cartella "views" un file denominato "_id-vista.scss" con il seguente codice


        #id-vista { ... }

2. aggiungere il seguente codice dentro "views/_views.scss"


        @import "id-vista"

Procedere in maniera analoga per tutto il resto.
Le cartelle rispecchiano la struttura del tema base di Drupal 8.
