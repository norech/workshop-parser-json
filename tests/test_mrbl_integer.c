/*
** EPITECH PROJECT, 2023
** How to do a JSON parser in C - Workshop - Alexis Cheron
** File description:
** Source code
*/
#include <criterion/criterion.h>
#include <jsonparser/internal/lexer.h>
#include <jsonparser/internal/util.h>
#include <stdio.h>

Test(token_integer, integer_v1)
{
    char *str = strdup("1");
    long value = 0;

    cr_assert_eq(token_integer(&str, &value), true);
    cr_assert_eq(value, 1.0);
}

Test(token_integer, negative_integer)
{
    char *str = strdup("-2");
    long value = 0;

    cr_assert_eq(token_integer(&str, &value), true);
    cr_assert_eq(value, -2);
}

Test(token_integer, integer_v2)
{
    char *str = strdup("24");
    long value = 0;

    cr_assert_eq(token_integer(&str, &value), true);
    cr_assert_eq(value, 24);
}

Test(token_integer, integer_exp)
{
    char *str = strdup("24e+1");
    long value = 0;

    cr_assert_eq(token_integer(&str, &value), true);
    cr_assert_eq(value, 240);
}

Test(token_integer, integer_exp_upper)
{
    char *str = strdup("24E+1");
    long value = 0;

    cr_assert_eq(token_integer(&str, &value), true);
    cr_assert_eq(value, 240);
}

Test(token_integer, integer_exp_neg)
{
    char *str = strdup("24e-1");
    long value = 0;

    cr_assert_eq(token_integer(&str, &value), true);
    cr_assert_eq(value, 2);
}

Test(token_integer, integer_exp_neg_upper)
{
    char *str = strdup("24E-1");
    long value = 0;

    cr_assert_eq(token_integer(&str, &value), true);
    cr_assert_eq(value, 2);
}