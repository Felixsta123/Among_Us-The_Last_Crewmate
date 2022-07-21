/*
** EPITECH PROJECT, 2021
** my_strcpy
** File description:
** Source code of task01
*/
#include <unistd.h>
#include <stdio.h>

int my_strlen(char const *);

char *my_strcpy(char *dest, char const *src)
{
    int len = my_strlen(src);

    for (int counter = 0; counter <= len; counter++) {
        dest[counter] = src[counter];
    }
    return dest;
}
