/*
** EPITECH
**
** These tests will only check if json_free_object can cause crashes.
*/
#include <criterion/criterion.h>
#include <jsonparser/json.h>

Test(json_free_object, sample_recursive)
{
    char *str = "{\"hello\": \"world\", \"sample\": 10}";
    json_json_t *json = parse_json(str);
    json_free_object(json->value, true);
}

Test(json_free_object, sample_not_recursive)
{
    char *str = "{\"hello\": \"world\", \"sample\": 10}";
    json_json_t *json = parse_json(str);
    json_free_object(json->value, false);
}

Test(json_free_object, sample_recursive_with_array)
{
    char *str = "{\"hello\": \"world\", \"sample\": [10, 20]}";
    json_json_t *json = parse_json(str);
    json_free_object(json->value, false);
}

Test(json_free_object, sample_recursive_with_sub_objects)
{
    char *str = "{\"hello\": \"world\", \"sample\": { \"data1\": 10, \"data2\": 20 }}";
    json_json_t *json = parse_json(str);
    json_free_object(json->value, false);
}
