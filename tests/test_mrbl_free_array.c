/*
** EPITECH
**
** These tests will only check if json_free_array can cause crashes.
*/
#include <criterion/criterion.h>
#include <jsonparser/json.h>

Test(json_free_array, sample_recursive)
{
    char *str = "[ 1, 2, 3 ]";
    json_json_t *json = parse_json(str);
    json_free_array(json->value, true);
}

Test(json_free_array, sample_not_recursive)
{
    char *str = "{\"hello\": [ 1, 2, 3 ] }";
    json_json_t *json = parse_json(str);
    json_free_array(json->value, false);
}

Test(json_free_array, sample_recursive_with_sub_array)
{
    char *str = "[ [ 1, 2 ], 3 ]";
    json_json_t *json = parse_json(str);
    json_free_array(json->value, true);
}

Test(json_free_array, sample_recursive_with_sub_objects)
{
    char *str = "[ { \"hi\": \"there\" }, { \"world\": \"universe\" } ]";
    json_json_t *json = parse_json(str);
    json_free_array(json->value, true);
}
