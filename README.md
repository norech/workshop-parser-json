# Faire un parser JSON en C

WORKSHOP - Alexis CHERON - 2023

[Merci de cloner le repo localement pour le bon déroulement du workshop!](https://github.com/norech/workshop-parser-json).

## Introduction

### Ce qu'est un parser JSON

Un parser JSON permet d'analyser une chaîne de caractères formatée en JSON, qui est un format de données léger utilisé pour échanger des données entre des applications. Le rôle du parser JSON est d'interpréter la syntaxe JSON et de produire une structure de données exploitable par une application.

Concrètement, un parser JSON prend en entrée une chaîne de caractères formatée en JSON et la transforme en un format de données utilisable. Cela permet de faciliter l'échange de données entre différentes applications, car le JSON est un format de données largement utilisé et pris en charge par de nombreux langages de programmation.

Le JSON peut être utilisé pour représenter de nombreuses formes de données, y compris des tableaux, des objets, des chaînes de caractères et des nombres.

Dans ce workshop, nous allons voir comment réaliser la base d'un parser JSON très simple.

## Les tokens

Un token (ou jeton en français) est une unité de base utilisée dans l'analyse lexicale (ou lexing) d'un texte, généralement du code source. Le rôle du lexing est de découper le texte en tokens, c'est-à-dire en éléments lexicaux individuels qui ont une signification syntaxique dans le langage utilisé.

Les tokens peuvent être de différents types, tels que des identificateurs, des mots-clés, des symboles, des nombres, des chaînes de caractères, des commentaires, etc. Prenons le fichier JSON suivant :

```json
{"hello":"world"}
```

les tokens sont :

    le symbole `{`
    la chaine de caractère `"hello"`
    le symbole `:`
    la chaine de caractère `"world"`
    le symbole `}`

Une manière de le représenter serait:
```
TOKEN_OBJECT_OPEN TOKEN_STRING{"hello"} TOKEN_PAIR_SEPARATOR TOKEN_STRING{"world"} TOKEN_OBJECT_CLOSE
```

Ces tokens seront ensuite utilisés dans le parsing pour déterminer la structure syntaxique.

### Faire un token d'un seul caractère

Faites une fonction nommée `is_char`, dans un fichier `exercices/is_char.c`.

Votre code doit s'exécuter comme indiqué dans les cas suivant:

#### Cas 1

```c
char *str = "abc";

printf("str before = %s\n", str);
printf("valid token = %d\n", is_char(&str, 'a'));
printf("str after = %s\n", str);
```

celle ci doit retourner:

```
str before = abc
valid token = 1
str after = bc
```

#### Cas 2

```c
char *str = "abc";

printf("str before = %s\n", str);
printf("valid token = %d\n", is_char(&str, 'b'));
printf("str after = %s\n", str);
```

celle ci doit retourner:

```
str before = abc
valid token = 0
str after = abc
```

#### Cas 3

```c
char *str = "abc";

printf("str before = %s\n", str);
printf("valid token = %d\n", is_char(&str, 'a'));
printf("valid token = %d\n", is_char(&str, 'b'));
printf("str after = %s\n", str);
```

celle ci doit retourner:

```
str before = abc
valid token = 1
valid token = 1
str after = c
```

#### Cas 4

```c
char *str = "abc";

printf("str before = %s\n", str);
printf("valid token = %d\n", is_char(&str, 'a'));
printf("valid token = %d\n", is_char(&str, 'c'));
printf("str after = %s\n", str);
```

celle ci doit retourner:

```
str before = abc
valid token = 1
valid token = 0
str after = bc
```

### Faire un token de plusieurs caractères (un mot)

Faites une fonction nommée `is_word`, dans un fichier `exercices/is_word.c`.

Votre code doit s'exécuter comme indiqué dans les cas suivant:

#### Cas 1

```c
char *str = "HelloWorldAndUniverse";

printf("str before = %s\n", str);
printf("valid token = %d\n", is_word(&str, "Hello"));
printf("str after = %s\n", str);
```

celle ci doit retourner:

```
str before = HelloWorldAndUniverse
valid token = 1
str after = WorldAndUniverse
```

#### Cas 2

```c
char *str = "HelloWorldAndUniverse";

printf("str before = %s\n", str);
printf("valid token = %d\n", is_word(&str, "Hi"));
printf("str after = %s\n", str);
```

celle ci doit retourner:

```
str before = HelloWorldAndUniverse
valid token = 0
str after = HelloWorldAndUniverse
```

#### Cas 3

```c
char *str = "HelloWorldAndUniverse";

printf("str before = %s\n", str);
printf("valid token = %d\n", is_word(&str, "Hello"));
printf("valid token = %d\n", is_word(&str, "World"));
printf("str after = %s\n", str);
```

celle ci doit retourner:

```
str before = HelloWorldAndUniverse
valid token = 1
valid token = 1
str after = AndUniverse
```

#### Cas 4

```c
char *str = "HelloWorldAndUniverse";

printf("str before = %s\n", str);
printf("valid token = %d\n", is_word(&str, "Hello"));
printf("valid token = %d\n", is_word(&str, "There"));
printf("str after = %s\n", str);
```

celle ci doit retourner:

```
str before = HelloWorldAndUniverse
valid token = 1
valid token = 0
str after = WorldAndUniverse
```

## Parsing de `token_bool`

L'un des types primitifs les plus simples en JSON sont les booléens.

Exemple de booléens:
```
true
false
```

### Simple


**Aide:** Remarquez quelle est la valeur de `output_bool` dans le cas suivant:
```c
bool output_bool = false;
bool *ptr = &output_bool;  // magie
*ptr = true;
printf("%d", output_bool);  // ou plutôt sorcellerie ?
```

Faites une fonction nommée `token_bool`, dans un fichier `exercices/token_bool.c`.

Votre code doit s'exécuter comme indiqué dans les cas suivant:

#### Cas 1

```c
char *str = "true42";
bool output_bool = false;

printf("str before = %s\n", str);
printf("valid token = %d\n", token_bool(&str, &output_bool));
printf("str after = %s\n", str);
printf("output bool = %d\n", output_bool);
```

celle ci doit retourner:

```
str before = true42
valid token = 1
str after = 42
output bool = 1
```

#### Cas 2

```c
char *str = "false42";
bool output_bool = false;

printf("str before = %s\n", str);
printf("valid token = %d\n", token_bool(&str, &output_bool));
printf("str after = %s\n", str);
printf("output bool = %d\n", output_bool);
```

celle ci doit retourner:

```
str before = false42
valid token = 1
str after = 42
output bool = 0
```

#### Cas 3

```c
char *str = "42false";
bool output_bool = false;

printf("str before = %s\n", str);
printf("valid token = %d\n", token_bool(&str, &output_bool));
printf("str after = %s\n", str);
printf("output bool = %d\n", output_bool);
```

celle ci doit retourner:

```
str before = 42false
valid token = 0
str after = 42false
output bool = 0
```

## Parsing de `token_string`

L'un des types primitifs les plus utiles en JSON est la chaîne de caractères. Il permet de stocker toute forme de données.

Exemple de chaine de caractères:
```
"Hello world!"
```

On peut remarquer qu'une chaine de caractères est délimitée par des `"`.

### Bases

Faites une fonction nommée `token_string`, dans un fichier `exercices/token_string.c`.

Votre code doit s'exécuter comme indiqué dans les cas suivant:

#### Cas 1

```c
char *str = "\"hello world\"42";

printf("str before = %s\n", str);
printf("valid str = %s\n", token_string(&str));
printf("str after = %s\n", str);
```

celle ci doit retourner:

```
str before = "hello world"42
valid str = hello world
str after = 42
```

#### Cas 2

```c
char *str = "42\"hello world\"";

printf("str before = %s\n", str);
printf("valid token = %d\n", token_string(&str));
printf("str after = %s\n", str);
```

celle ci doit retourner:

```
str before = 42"hello world"
valid str = (null)
str after = 42"hello world"
```

#### Cas 3

```c
char *str = "\"hello\"\"world\"42";

printf("str before = %s\n", str);
printf("valid str = %s\n", token_string(&str));
printf("valid str = %s\n", token_string(&str));
printf("str after = %s\n", str);
```

celle ci doit retourner:

```
str before = "hello""world"42
valid str = hello
valid str = world
str after = 42
```

#### Cas 4

```c
char *str = "\"hello\"42\"world\"";
char *output_str1 = NULL;
char *output_str2 = NULL;

printf("str before = %s\n", str);
printf("valid str = %s\n", token_string(&str));
printf("valid str = %s\n", token_string(&str));
printf("str after = %s\n", str);
```

celle ci doit retourner:

```
str before = "hello"42"world"
valid str = hello
valid str = (null)
str after = 42"world"
```

## Parsing d'item (`"clé":"valeur"`)

### Bases

Faites une fonction nommée `parse_object_item`, dans un fichier `exercices/parse_object_item.c`.

Votre code doit s'exécuter comme indiqué dans les cas suivant:

#### Cas 1

```c
struct object_item {
    char *key;
    char *value;
};

char *str = "\"key\":\"value\"";
struct object_item output_item = {0};

printf("str before = %s\n", str);
printf("valid token = %d\n", parse_object_item(&str, &output_item));
printf("str after = %s\n", str);
printf("output key = %s\n", output_item.key);
printf("output value = %s\n", output_item.value);
```

celle ci doit retourner:

```
str before = "key":"value"
valid token = 1
str after = 
output key = key
output value = value
```

#### Cas 2

```c
struct object_item {
    char *key;
    char *value;
};

char *str = "\"hello\":\"world\"";
struct object_item output_item = {0};

printf("str before = %s\n", str);
printf("valid token = %d\n", parse_object_item(&str, &output_item));
printf("str after = %s\n", str);
printf("output key = %s\n", output_item.key);
printf("output value = %s\n", output_item.value);
```

celle ci doit retourner:

```
str before = "hello":"world"
valid token = 1
str after = 
output key = hello
output value = world
```

## Parsing d'array

### Bases

Faites une fonction nommée `parse_array`, dans un fichier `exercices/parse_array.c`.

Votre code doit s'exécuter comme indiqué dans les cas suivant:

#### Cas 1

```c
struct my_json_array {
    char *value;
    struct my_json_array *next;
};

char *str = "[\"hello\",\"world\"]";
struct my_json_array output_array = {0};

printf("str before = %s\n", str);
printf("valid token = %d\n", parse_array(&str, &output_array));
printf("str after = %s\n", str);
printf("output value 0 = %s\n", output_array.value);
printf("output value 1 = %s\n", output_array.next->value);
```

celle ci doit retourner:

```
str before = ["hello","world"]
valid token = 1
str after = 
output value 0 = hello
output value 1 = world
```

#### Cas 2

```c
struct my_json_array {
    char *value;
    struct my_json_array *next;
};

char *str = "[\"hello\"]";
struct my_json_array output_array = {0};

printf("str before = %s\n", str);
printf("valid token = %d\n", parse_array(&str, &output_array));
printf("str after = %s\n", str);
printf("output value 0 = %s\n", output_array.value);
printf("output value 1 = %p\n", output_array.next);
```

celle ci doit retourner:

```
str before = ["hello"]
valid token = 1
str after = 
output value 0 = hello
output value 1 = (null)
```

## Récursion

Recodez votre `parse_array` pour gérer le cas suivant.

#### Cas

```c
struct my_json_array {
    struct my_json_value *value;
    struct my_json_array *next;
};

enum my_json_type {
    MY_JSON_STRING = 0,
    MY_JSON_ARRAY = 1
};

union my_json_value_content {
    char *str;
    struct my_json_array *arr;
};

struct my_json_value {
    enum my_json_type type;
    union my_json_value_content value;
};

char *str = "[[\"GNU\"],\"Not\",\"UNIX\"]";
struct my_json_array output_array = {0};

printf("str before = %s\n", str);
printf("valid token = %d\n", parse_array(&str, &output_array));
printf("str after = %s\n", str);
printf("output type 0 = %d\n", output_array.value->arr->type);
printf("output type 1 = %d\n", output_array.next->type);
printf("output type 2 = %d\n", output_array.next->next->type);
printf("output value 0 = %s\n", output_array.value->arr->value.str);
printf("output value 1 = %s\n", output_array.next->value.str);
printf("output value 2 = %s\n", output_array.next->next->value.str);
```

celle ci doit retourner:

```
str before = [["GNU"],"Not","UNIX"]
valid token = 1
str after = 
output type 0 = 1
output type 1 = 0
output type 2 = 0
output value 0 = GNU
output value 1 = Not
output value 1 = UNIX
```

## Vers un parser complet

Mettez vos fichiers `token_*.c` dans le dossier `src/json/lexer/`, ainsi que votre `is_char.c` et votre `is_word.c`.

Modifiez le fichier `src/json/parser/parse_json_value.c`.

Modifiez la fonction `parse_json_value` de sorte qu'elle puisse parser les tokens `bool` et les tokens `string`, retournant respectivement `JSON_BOOL` et `JSON_STRING` dans les cas où ces tokens sont trouvés, et remplissant `value->boolval` et `value->strval` des valeurs trouvée.

Lancez ensuite le `Makefile` situé dans `example_program`.

Si tout s'est correctement déroulé, vous devriez ensuite être capable de lancer `./example_program` et voir un aperçu du contenu JSON s'afficher sous vos yeux.