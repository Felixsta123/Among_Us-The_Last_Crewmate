/*
** EPITECH PROJECT, 2022
** my_split
** File description:
** split str
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int count_char(char *str, char c);

int next_char(char *str, int start, char c);

char *my_strncpy(char *dest, char const *src, int nb);

int my_strlen(char const *str);

char **my_split(char *str, char splitter)
{
    int nb_splitter = count_char(str, splitter) + 1;
    int next_c;
    char **tab = malloc((nb_splitter + 1) * sizeof(char *));
    int line = 0;

    if (str[my_strlen(str) - 1] == splitter)
        nb_splitter--;
    for (int words = 0; words < nb_splitter; words++) {
        next_c = next_char(str, 0, splitter);
        tab[line] = malloc((next_c + 1) * sizeof(char));
        tab[line] = my_strncpy(tab[line], str, next_c);
        str += next_c + 1;
        line++;
    }
    tab[line] = NULL;
    return (tab);
}
