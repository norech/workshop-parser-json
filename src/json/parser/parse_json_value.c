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

json_value_type_t parse_json_value(char **str, json_value_t *value)
{
    if (token_null(str)) {
        value->intval = 0;
        return (JSON_NULL);
    }
    if (token_float(str, &(value->floatval))) {
        return (JSON_FLOAT);
    }
    if (token_integer(str, &(value->intval))) {
        return (JSON_INT);
    }

    ///
    ///
    ///

    if (**str == '{') {
        value->objval = parse_json_object(str);
        return (JSON_OBJECT);
    }
    if (**str == '[') {
        value->arrval = parse_json_array(str);
        return (JSON_ARRAY);
    }
    return (JSON_INVALID);
}