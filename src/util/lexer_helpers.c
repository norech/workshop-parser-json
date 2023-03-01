/*
** EPITECH PROJECT, 2023
** How to do a JSON parser in C - Workshop - Alexis Cheron
** File description:
** Source code
*/
#include <stdlib.h>
#include <stdio.h>
#include <jsonparser/internal/util.h>

bool is_whitespace(char **str)
{
    return (is_char(str, ' ')
        || is_char(str, '\t')
        || is_char(str, '\n')
        || is_char(str, '\r'));
}

bool is_char(char **str, char c)
{
    if (**str != c)
        return (false);
    (*str)++;
    return (true);
}

bool is_word(char **str, char *word)
{
    int i = 0;
    int len = strlen(word);

    while (**str != '\0') {
        if (!is_char(str, word[i]))
            break;
        i++;
    }
    return (i == len);
}

char read_char(char **str)
{
    char c = **str;

    (*str)++;
    if (c < 32)
        return ('\0');
    return (c);
}

char read_escaped_char(char **str)
{
    char c = *((*str)++);
    switch (c) {
        case 'b':
            return ('\b');
        case 'f':
            return ('\f');
        case 'n':
            return ('\n');
        case 'r':
            return ('\r');
        case 't':
            return ('\t');
        case 'u':
            return (26);
        case '\\':
        case '/':
        case '"':
            return (c);
    }
    return ('\0');
}