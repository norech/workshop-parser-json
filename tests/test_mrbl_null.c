/*
** EPITECH PROJECT, 2023
** How to do a JSON parser in C - Workshop - Alexis Cheron
** File description:
** Source code
*/
#include <criterion/criterion.h>
#include <jsonparser/internal/lexer.h>
#include <jsonparser/internal/util.h>

Test(token_null, null)
{
    char *str = strdup("null");
    cr_assert_eq(token_null(&str), true);
}

Test(token_null, not_null)
{
    char *str = strdup("none");
    cr_assert_eq(token_null(&str), false);
}

Test(token_null, nothing)
{
    char *str = strdup("");
    cr_assert_eq(token_null(&str), false);
}
