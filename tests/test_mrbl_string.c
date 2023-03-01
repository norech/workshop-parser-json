/*
** EPITECH PROJECT, 2023
** How to do a JSON parser in C - Workshop - Alexis Cheron
** File description:
** Source code
*/
#include <criterion/criterion.h>
#include <jsonparser/internal/lexer.h>
#include <jsonparser/internal/util.h>

Test(token_string, can_get_string)
{
    char *str = strdup("\"hello world\"");
    cr_assert_str_eq(token_string(&str), "hello world");
}

Test(token_string, can_get_string_with_escape)
{
    char *str = strdup("\"say \\\"hello\\\" to the world\"");
    cr_assert_str_eq(token_string(&str), "say \"hello\" to the world");
}

Test(token_string, can_get_string_not_ended)
{
    char *str = strdup("\"say");
    cr_assert_eq(token_string(&str), NULL);
}