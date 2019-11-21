# Variabili fornite in tutti i template
Di seguito un elenco di tutte le variabili disponibili in tutti i template organizzati per tipologia

## Utenti
- "is_admin" - bool - È *true* se l'utente è amministratore  
- "logged_in" - bool - È *true* se il visitatore ha eseguito il login
- "user" - object - Rappresenta l'utente

## Theme engine
- "page" - array - La configurazione delle regioni della pagina
- "theme_hook_original" - string - Il nome del template prima dell'eventuale modifica
- "theme_hook_suggestions" - string - Il nome del template modificato con un *hook*
- "directory" - string - Il path relativo del tema senza: "/" iniziale e finale; senza eventuale cartella di installazione drupal
- "base_path" - string - Restituisce la cartella di installazione di drupal. Se non si trova in una sottocartella della webroot restituisce "/"
- "front_page" - string - Indica il path relativo della *home page*. Se non impostata home page alternativa restituisce "/"
- "language" - object - Informazioni sulla lingua (della pagina generata, non del visitatore)
- "is_front" - bool - Restituise *true* se si sta visualizzando l'home page
- "attributes" - object -
- "title_attributes" - object -
- "content_attributes" - object -
- "title_prefix" - array -
- "title_suffix" - array -

## Drupal
- "db_is_active" - bool -
    "is_front"
    
## Theme Variables:
- "ente_appartenenza" - L'ente di appartenenza
