/*
** EPITECH
**
** This project will simply print the parsed content of the sample.json file.
** The sample file was taken from https://www.json.org/example.html
*/
#include <jsonparser/json.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

void display_object(json_object_t *node, int indent);
void display_array(json_array_t *node, int indent);

void print_indent(int indent)
{
    for (int i = 0; i < indent; i++)
        printf("    ");
}

void display_value(json_value_type_t type, json_value_t value, int indent)
{
    switch (type) {
        case JSON_OBJECT:
            display_object(value.objval, indent + 1);
            break;
        case JSON_ARRAY:
            display_array(value.arrval, indent + 1);
            break;
        case JSON_STRING:
            printf("%s", value.strval);
            break;
        case JSON_FLOAT:
            printf("%.8lf", value.floatval);
            break;
        case JSON_INT:
            printf("%ld", value.intval);
            break;
        case JSON_BOOL:
            printf("%s", value.boolval ? "true" : "false");
            break;
        case JSON_NULL:
            printf("NULL");
            break;
        case JSON_EMPTY:
            printf("empty");
            break;
        case JSON_INVALID:
            printf("error");
            break;
    }
}

void display_object(json_object_t *node, int indent)
{
    printf("{\n");

    for (; node != NULL; node = node->next) {
        print_indent(indent);
        printf("%s : ", node->key);
        display_value(node->type, node->value, indent + 1);
        printf("\n");
    }

    print_indent(indent - 1);
    printf("}\n");
}

void display_array(json_array_t *node, int indent)
{
    printf("[\n");

    for (; node != NULL; node = node->next) {
        print_indent(indent);
        display_value(node->type, node->value, indent);
        printf("\n");
    }

    print_indent(indent - 1);
    printf("]\n");
}

char *read_file(char *file)
{
    int fd = open(file, O_RDONLY);
    struct stat s;
    char *buffer;
    int readed = 0;

    if (stat(file, &s) < 0)
        exit(84);

    buffer = malloc(sizeof(char) * (s.st_size + 1));
    if ((readed = read(fd, buffer, s.st_size)) < 0)
        exit(84);
    buffer[readed] = '\0';

    return (buffer);
}

int main(void)
{
    char *buffer = read_file("./sample.json");
    json_t *root = parse_json(buffer);

    if (root == NULL)
        exit(84);

    printf("Displaying content generated from JSON tree:\n");
    display_value(root->type, root->value, 0);

    free_json(root);
    free(buffer);

    return (0);
}