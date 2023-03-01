/*
** EPITECH PROJECT, 2023
** How to do a JSON parser in C - Workshop - Alexis Cheron
** File description:
** Source code
*/

#include <criterion/criterion.h>
#include <jsonparser/internal/parser.h>
#include <jsonparser/internal/util.h>
#include <stdio.h>

Test(parse_json_value, boolean)
{
    char *str = strdup("true");
    void *value;

    cr_assert_eq(parse_json_value(&str, &value), token_bool);
}

Test(parse_json_value, float_)
{
    char *str = strdup("1.0");
    void *value;

    cr_assert_eq(parse_json_value(&str, &value), token_float);
}

Test(parse_json_value, int_)
{
    char *str = strdup("3");
    void *value;
    cr_assert_eq(parse_json_value(&str, &value), JSON_INT);
}

Test(parse_json_value, null_)
{
    char *str = strdup("null");
    void *value;

    cr_assert_eq(parse_json_value(&str, &value), JSON_NULL);
}

Test(parse_json_value, string_)
{
    char *str = strdup("\"hello\"");
    void *value;

    cr_assert_eq(parse_json_value(&str, &value), JSON_STRING);
}

Test(parse_json_value, empty)
{
    char *str = strdup("this is a random input");
    void *value;

    cr_assert_eq(parse_json_value(&str, &value), JSON_INVALID);
}