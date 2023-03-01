/*
** EPITECH PROJECT, 2023
** How to do a JSON parser in C - Workshop - Alexis Cheron
** File description:
** Source code
*/
#include <jsonparser/internal/util.h>

void add_char_to_string(char **str_ptr, char c)
{
    char *str = *str_ptr;
    int len = strlen(str);

    expand_string(str_ptr, len + 1);

    str[len] = c;
    str[len + 1] = '\0';
}