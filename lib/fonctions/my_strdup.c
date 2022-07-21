/*
** EPITECH PROJECT, 2022
** my_strdup
** File description:
** Source code to allocates memory and copies
** the string given as argument in it.
*/
#include <stdlib.h>
#include <unistd.h>

int my_strlen(char const *);

char *my_strdup(char const *src)
{
    char *dest = malloc((my_strlen(src) + 1) * sizeof(char));
    int counter = 0;

    while (src[counter] != '\0') {
        dest[counter] = src[counter];
        counter++;
    }
    dest[counter] = '\0';
    return dest;
}
