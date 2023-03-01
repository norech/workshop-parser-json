/*
** EPITECH PROJECT, 2023
** How to do a JSON parser in C - Workshop - Alexis Cheron
** File description:
** Source code
*/
#include <jsonparser/common.h>

#ifndef JSON_PARSER_H
#define JSON_PARSER_H

json_value_type_t parse_json_value(char **str, json_value_t *value);
json_array_t *parse_json_array(char **str);
json_object_t *parse_json_object(char **str);

#endif //JSON_PARSER_H