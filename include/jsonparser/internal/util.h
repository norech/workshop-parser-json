/*
** EPITECH PROJECT, 2023
** How to do a JSON parser in C - Workshop - Alexis Cheron
** File description:
** Source code
*/
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#ifndef JSON_HELPERS_H
#define JSON_HELPERS_H

enum next_token_action {
    ACTION_TOKEN_STOP,
    ACTION_TOKEN_CONTINUE
};

void add_char_to_string(char **buff_ptr, char c);
bool is_whitespace(char **str);
bool is_char(char **str, char c);
bool is_word(char **str, char *word);
char read_char(char **str);
char read_escaped_char(char **str);
void expand_string(char **str, size_t new_size);

#endif //JSON_HELPERS_H