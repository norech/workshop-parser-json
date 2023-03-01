/*
** EPITECH PROJECT, 2023
** How to do a JSON parser in C - Workshop - Alexis Cheron
** File description:
** Source code
*/
#include <jsonparser/common.h>

#ifndef JSON_JSON_H
#define JSON_JSON_H

typedef struct json {
    json_value_type_t type;
    json_value_t value;
} json_t;

json_t *parse_json(char *input);
void free_json(json_t *json);

#endif //JSON_JSON_H
