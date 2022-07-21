/*
** EPITECH PROJECT, 2022
** my_realloc
** File description:
** Source code to realloc a string already malloc with more space
** given as parameter (TAKE CARE ABOUT '\0')
*/
#include <stdlib.h>

int my_strlen(char const *str);

int my_strncpy(char *dest, char const *src, int nb);

char *my_realloc(char *str, int space)
{
    int len = my_strlen(str);
    char *temp_str = malloc((len + space + 1) * sizeof(char));

    my_strncpy(temp_str, str, len);
    free(str);
    return (temp_str);
}
