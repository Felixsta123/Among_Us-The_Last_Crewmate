/*
** EPITECH PROJECT, 2022
** my_strconc
** File description:
** Source code to concatenate two str
*/
#include <stdlib.h>

int my_strlen(char const *str);

char *my_strconc(char *str1, char *str2)
{
    int lens = my_strlen(str1) + my_strlen(str2);
    char *res = malloc((lens + 1) * sizeof(char));
    int i_str1;
    int i_str2;
    int index = 0;

    for (i_str1 = 0; str1[i_str1] != '\0'; i_str1++) {
        res[index] = str1[i_str1];
        index++;
    }
    for (i_str2 = 0; str2[i_str2] != '\0'; i_str2++) {
        res[index] = str2[i_str2];
        index++;
    }
    res[index] = '\0';
    return (res);
}
