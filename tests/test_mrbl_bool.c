/*
** EPITECH PROJECT, 2023
** How to do a JSON parser in C - Workshop - Alexis Cheron
** File description:
** Source code
*/
#include <criterion/criterion.h>
#include <jsonparser/internal/lexer.h>
#include <jsonparser/internal/util.h>

Test(token_bool, _true_)
{
    char *str = strdup("true");
    bool value;

    cr_assert_eq(token_bool(&str, &value), true);
    cr_assert_eq(value, true);
}

Test(token_bool, _false_)
{
    char *str = strdup("false");
    bool value;

    cr_assert_eq(token_bool(&str, &value), true);
    cr_assert_eq(value, false);
}

Test(token_bool, not_bool)
{
    char *str = strdup("null");
    bool value;

    cr_assert_eq(token_bool(&str, &value), false);
}