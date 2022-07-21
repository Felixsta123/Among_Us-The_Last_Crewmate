/*
** EPITECH PROJECT, 2022
** my_add_char
** File description:
** Source code to add a char to an existing str
*/
#include <stdlib.h>

char *my_realloc(char *str, int space);

int my_strlen(char const *str);

char *add_char(char *str, char c)
{
    int len = my_strlen(str);

    str = my_realloc(str, 2);
    str[len] = c;
    str[len + 1] = '\0';
    return (str);
}
