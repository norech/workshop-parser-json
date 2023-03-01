/*
** EPITECH PROJECT, 2023
** How to do a JSON parser in C - Workshop - Alexis Cheron
** File description:
** Source code
*/
#include <stdlib.h>

void expand_string(char **str, size_t new_size)
{
    char *old_str = *str;
    char *new_str = malloc(sizeof(char) * new_size);
    size_t i = 0;

    while (old_str[i] != '\0') {
        new_str[i] = old_str[i];
        i++;
    }
    new_str[i] = '\0';
    *str = new_str;
    free(old_str);
}