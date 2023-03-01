/*
** EPITECH PROJECT, 2023
** How to do a JSON parser in C - Workshop - Alexis Cheron
** File description:
** Source code
*/
#include <stdbool.h>

#ifndef LEXERER_H
#define LEXERER_H

bool token_array_close(char **str);
bool token_array_open(char **str);
bool token_object_close(char **str);
bool token_object_open(char **str);
char *token_string(char **str);
int token_whitespace(char **str);
int token_pair_separator(char **str);
bool token_comma(char **str);
bool token_float(char **str, double *value);
bool token_integer(char **str, long *value);
bool token_null(char **str);
bool token_bool(char **str, bool *value);

#endif //LEXERER_H