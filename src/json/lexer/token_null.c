/*
** EPITECH PROJECT, 2023
** How to do a JSON parser in C - Workshop - Alexis Cheron
** File description:
** Source code
*/
#include <jsonparser/internal/util.h>

bool token_null(char **str)
{
    return (is_word(str, "null"));
}