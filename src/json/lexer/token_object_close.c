/*
** EPITECH PROJECT, 2023
** How to do a JSON parser in C - Workshop - Alexis Cheron
** File description:
** Source code
*/
#include <jsonparser/internal/util.h>

bool token_object_close(char **str)
{
    return (is_char(str, '}'));
}