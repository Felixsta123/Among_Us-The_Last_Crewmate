/*
** EPITECH PROJECT, 2022
** my_strcmp
** File description:
** Source code to compare two string
*/
#include <stddef.h>

int my_strlen(char const *str);

int my_strcmp(char *str1, char *str2)
{
    if (str1 == NULL || str2 == NULL) {
        return (0);
    } else if (my_strlen(str1) != my_strlen(str2)) {
        return (0);
    }
    for (int index = 0; str1[index] != '\0' || str2[index] != '\0'; index++) {
        if (str1[index] != str2[index]) {
            return (0);
        }
    }
    return (1);
}
