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

Test(token_float, float_v1)
{
    char *str = strdup("1.0");
    double value = 0;

    cr_assert_eq(token_float(&str, &value), true);
    cr_assert_eq(value, 1.0);
}

Test(token_float, float_v2)
{
    char *str = strdup("2.5");
    double value = 0;

    cr_assert_eq(token_float(&str, &value), true);
    cr_assert_eq(value, 2.5);
}

Test(token_float, float_v3)
{
    char *str = strdup("24.50");
    double value = 0;

    cr_assert_eq(token_float(&str, &value), true);
    cr_assert_eq(value, 24.50);
}

Test(token_float, float_exp)
{
    char *str = strdup("24.5e+1");
    double value = 0;

    cr_assert_eq(token_float(&str, &value), true);
    cr_assert_eq(value, 245.0);
}

Test(token_float, float_exp_upper)
{
    char *str = strdup("24.5E+1");
    double value = 0;

    cr_assert_eq(token_float(&str, &value), true);
    cr_assert_eq(value, 245.0);
}

Test(token_float, float_exp_neg)
{
    char *str = strdup("245.0e-1");
    double value = 0;

    cr_assert_eq(token_float(&str, &value), true);
    cr_assert_eq(value, 24.5);
}

Test(token_float, float_exp_neg_upper)
{
    char *str = strdup("24.5E-1");
    double value = 0;

    cr_assert_eq(token_float(&str, &value), true);
    cr_assert_eq(value, 2.45);
}