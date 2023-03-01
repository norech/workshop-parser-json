/*
** EPITECH PROJECT, 2023
** How to do a JSON parser in C - Workshop - Alexis Cheron
** File description:
** Source code
*/
#include <jsonparser/internal/util.h>

int token_pair_separator(char **str)
{
    return (is_char(str, ':'));
}
