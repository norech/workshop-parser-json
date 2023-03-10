/*
** EPITECH PROJECT, 2023
** How to do a JSON parser in C - Workshop - Alexis Cheron
** File description:
** Source code
*/
#include <criterion/criterion.h>
#include <jsonparser/internal/lexer.h>
#include <jsonparser/internal/util.h>
#include <jsonparser/common.h>
#include <jsonparser/json.h>

Test(parse_json, empty_parse)
{
    char *str = "{}";
    json_json_t *json = parse_json(str);
    cr_assert_not_null(json);
    cr_assert_eq(json->type, JSON_OBJECT);
    json_object_t *object = json->value;
    cr_assert_not_null(object);
    cr_assert_eq(object->type, JSON_EMPTY);
    cr_assert_eq(object->next, (void *)0);
}

Test(parse_json, parse_with_single_prop)
{
    char *str = "{ \"hello\": null }";
    json_json_t *json = parse_json(str);
    cr_assert_not_null(json);
    cr_assert_eq(json->type, JSON_OBJECT);
    json_object_t *object = json->value;
    cr_assert_not_null(object);
    cr_assert_str_eq(object->key, "hello");
    cr_assert_eq(object->type, JSON_NULL);
    cr_assert_eq(object->next, (void *)0);
}

Test(parse_json, parse_with_multiple_props)
{
    char *str = "{ \"hello\": null, \"world\": 18 }";
    json_json_t *json = parse_json(str);
    cr_assert_not_null(json);
    cr_assert_eq(json->type, JSON_OBJECT);
    json_object_t *object = json->value;
    cr_assert_not_null(object);
    cr_assert_str_eq(object->key, "hello");
    cr_assert_eq(object->type, JSON_NULL);
    cr_assert_str_eq(object->next->key, "world");
    cr_assert_eq(object->next->type, JSON_INT);
    cr_assert_eq(object->next->value, 18);
    cr_assert_eq(object->next->next, (void *)0);
}

Test(parse_json, parse_with_object_nested)
{
    char *str = "{ \"hello\": { \"world\": null } }";
    json_json_t *json = parse_json(str);
    cr_assert_not_null(json);
    cr_assert_eq(json->type, JSON_OBJECT);
    json_object_t *object = json->value;
    cr_assert_not_null(object);
    cr_assert_str_eq(object->key, "hello");
    cr_assert_eq(object->type, JSON_OBJECT);

    json_object_t *subobject = object->value;
    cr_assert_not_null(subobject);
    cr_assert_str_eq(subobject->key, "world");
    cr_assert_eq(subobject->type, JSON_NULL);
}

Test(parse_json, parse_with_array_nested)
{
    char *str = "{ \"greeting\": [ \"hello\", \"world\" ] }";
    json_json_t *json = parse_json(str);
    cr_assert_not_null(json);
    cr_assert_eq(json->type, JSON_OBJECT);
    json_object_t *object = json->value;
    cr_assert_not_null(object);
    cr_assert_str_eq(object->key, "greeting");
    cr_assert_eq(object->type, JSON_ARRAY);

    json_array_t *array = object->value;
    cr_assert_not_null(array);
    cr_assert_eq(array->type, JSON_STRING);
    cr_assert_str_eq(array->value, "hello");
    cr_assert_not_null(array->next);
    cr_assert_eq(array->next->type, JSON_STRING);
    cr_assert_str_eq(array->next->value, "world");
}

Test(parse_json, parse_with_object_nested_in_array)
{
    char *str = "{ \"greeting\": [ { \"hello\": \"world\" } ] }";
    json_json_t *json = parse_json(str);
    cr_assert_not_null(json);
    cr_assert_eq(json->type, JSON_OBJECT);
    json_object_t *object = json->value;
    cr_assert_not_null(object);
    cr_assert_str_eq(object->key, "greeting");
    cr_assert_eq(object->type, JSON_ARRAY);

    json_array_t *array = object->value;
    cr_assert_not_null(array);
    cr_assert_eq(array->type, JSON_OBJECT);
    json_object_t *subobject = array->value;
    cr_assert_eq(subobject->type, JSON_STRING);
    cr_assert_str_eq(subobject->key, "hello");
    cr_assert_str_eq(subobject->value, "world");
}

Test(parse_json, parse_with_two_objects_nested_in_array)
{
    char *str = "{ \"greeting\": [ { \"hello\": \"world\" } , { \"marvin\": 42 } ] }";
    json_json_t *json = parse_json(str);
    cr_assert_not_null(json);
    cr_assert_eq(json->type, JSON_OBJECT);
    json_object_t *object = json->value;
    cr_assert_not_null(object);
    cr_assert_str_eq(object->key, "greeting");
    cr_assert_eq(object->type, JSON_ARRAY);

    json_array_t *array = object->value;
    cr_assert_not_null(array);
    cr_assert_eq(array->type, JSON_OBJECT);
    json_object_t *subobject = array->value;
    json_object_t *subobject_2 = array->next->value;
    cr_assert_eq(subobject->type, JSON_STRING);
    cr_assert_str_eq(subobject->key, "hello");
    cr_assert_str_eq(subobject->value, "world");
    cr_assert_eq(subobject_2->type, JSON_INT);
    cr_assert_str_eq(subobject_2->key, "marvin");
    cr_assert_eq(subobject_2->value, 42);
}

Test(parse_json, parse_array)
{
    char *str = "[ 1, 2, 3 ]";
    json_json_t *json = parse_json(str);
    cr_assert_not_null(json);
    cr_assert_eq(json->type, JSON_ARRAY);
    json_array_t *array = json->value;
    cr_assert_not_null(array);
    cr_assert_eq(array->type, JSON_INT);
    cr_assert_eq(array->value, 1);
    cr_assert_not_null(array->next);
    cr_assert_eq(array->next->type, JSON_INT);
    cr_assert_eq(array->next->value, 2);
    cr_assert_not_null(array->next->next);
    cr_assert_eq(array->next->next->type, JSON_INT);
    cr_assert_eq(array->next->next->value, 3);
    cr_assert_null(array->next->next->next);
}

Test(parse_json, parse_empty)
{
    char *str = "";
    json_json_t *json = parse_json(str);
    cr_assert_null(json);
}