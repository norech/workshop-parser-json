/*
** EPITECH PROJECT, 2023
** How to do a JSON parser in C - Workshop - Alexis Cheron
** File description:
** Source code
*/
#include <jsonparser/common.h>
#include <jsonparser/internal/lexer.h>
#include <jsonparser/internal/parser.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

static json_object_t *parse_object_pairs(char **str)
{
    json_object_t *object = malloc(sizeof(json_object_t));

    object->next = NULL;
    token_whitespace(str);
    if ((object->key = token_string(str)) == NULL)
        return (NULL);
    token_whitespace(str);
    token_pair_separator(str);
    token_whitespace(str);
    object->type = parse_json_value(str, &(object->value));
    if (object->type == JSON_INVALID) {
        json_free_object(object, false);
        return (NULL);
    }
    token_whitespace(str);
    if (token_comma(str)) {
        object->next = parse_object_pairs(str);
    }
    token_whitespace(str);
    return (object);
}

json_object_t *parse_json_object(char **str)
{
    json_object_t *object = NULL;

    if (!token_object_open(str)) {
        return (NULL);
    }
    token_whitespace(str);
    if (token_object_close(str)) {
        object = malloc(sizeof(json_object_t));
        object->type = JSON_EMPTY;
        object->value.intval = 0;
        object->next = NULL;
        return (object);
    }
    object = parse_object_pairs(str);
    if (!token_object_close(str)) {
        return (NULL);
    }
    return (object);
}