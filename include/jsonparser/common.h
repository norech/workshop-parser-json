/*
** EPITECH PROJECT, 2023
** How to do a JSON parser in C - Workshop - Alexis Cheron
** File description:
** Source code
*/
#include <stdbool.h>

#ifndef JSON_COMMON_H
#define JSON_COMMON_H

typedef enum {
    JSON_EMPTY,
    JSON_NULL,
    JSON_BOOL,
    JSON_INT,
    JSON_FLOAT,
    JSON_STRING,
    JSON_ARRAY,
    JSON_OBJECT,
    JSON_INVALID
} json_value_type_t;

typedef union json_value {
    char *strval;
    bool boolval;
    long intval;
    double floatval;
    struct json_array *arrval;
    struct json_object *objval;
} json_value_t;

typedef struct json_object {
    json_value_type_t type;
    char *key;
    union json_value value;
    struct json_object *next;
} json_object_t;

typedef struct json_array {
    json_value_type_t type;
    union json_value value;
    struct json_array *next;
} json_array_t;

void json_free_object(json_object_t *object, bool recursive);
void json_free_array(json_array_t *array, bool recursive);

#endif //JSON_COMMON_H