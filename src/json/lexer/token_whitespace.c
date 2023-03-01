/*
** EPITECH PROJECT, 2023
** How to do a JSON parser in C - Workshop - Alexis Cheron
** File description:
** Source code
*/
#include <jsonparser/internal/util.h>
#include <stdbool.h>

int token_whitespace(char **str)
{
    int i = 0;
    while (is_whitespace(str))
        i++;
    return (i);
}