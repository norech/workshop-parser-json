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
#include <unistd.h>

static json_array_t *parse_array_elements(char **str)
{
    json_array_t *array = malloc(sizeof(json_array_t));

    token_whitespace(str);
    array->type = parse_json_value(str, &(array->value));
    token_whitespace(str);
    array->next = NULL;
    if (token_comma(str)) {
        array->next = parse_array_elements(str);
    }
    token_whitespace(str);
    return (array);
}

json_array_t *parse_json_array(char **str)
{
    json_array_t *array = NULL;

    if (!token_array_open(str)) {
        return (NULL);
    }
    token_whitespace(str);
    if (token_array_close(str)) {
        array = malloc(sizeof(json_array_t));
        array->type = JSON_EMPTY;
        array->next = NULL;
        return (array);
    }

    array = parse_array_elements(str);
    if (!token_array_close(str)) {
        return (NULL);
    }
    return (array);
}