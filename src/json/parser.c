/*
** EPITECH PROJECT, 2023
** How to do a JSON parser in C - Workshop - Alexis Cheron
** File description:
** Source code
*/
#include <jsonparser/internal/parser.h>
#include <jsonparser/json.h>
#include <stdbool.h>
#include <stdlib.h>

json_t *parse_json(char *input)
{
    json_t *json = malloc(sizeof(json_t));
    char *str = input;

    if (*input == '\0') {
        free(json);
        return (NULL);
    }
    json->type = parse_json_value(&str, &(json->value));
    if (json->type == JSON_INVALID) {
        free(json);
        return (NULL);
    }
    return (json);
}