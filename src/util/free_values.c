/*
** EPITECH PROJECT, 2023
** How to do a JSON parser in C - Workshop - Alexis Cheron
** File description:
** Source code
*/
#include <jsonparser/common.h>
#include <jsonparser/json.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>

static void json_free_value(json_value_type_t type, json_value_t *value)
{
    switch (type) {
        case JSON_OBJECT:
            json_free_object(value->objval, true);
            break;
        case JSON_ARRAY:
            json_free_array(value->arrval, true);
            break;
        case JSON_STRING:
            if (value->strval != NULL) {
                free(value->strval);
            }
            break;
        default:
            break;
    }
}

void json_free_object(json_object_t *object, bool recursive)
{
    json_object_t *tmp;

    while (object != NULL) {
        tmp = object->next;
        if (recursive)
            json_free_value(object->type, &(object->value));
        if (object->type != JSON_EMPTY)
            free(object->key);
        free(object);
        object = tmp;
    }
}

void json_free_array(json_array_t *array, bool recursive)
{
    json_array_t *tmp;

    while (array != NULL) {
        tmp = array->next;
        if (array == NULL)
            return;
        if (recursive)
            json_free_value(array->type, &(array->value));
        free(array);
        array = tmp;
    }
}

void free_json(json_t *json)
{
    json_free_value(json->type, &(json->value));
    free(json);
}