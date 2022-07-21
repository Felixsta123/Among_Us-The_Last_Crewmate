/*
** EPITECH PROJECT, 2022
** free_tab
** File description:
** Source code to free a tab
*/

#include <stdlib.h>
#include <stddef.h>

void free_str_tab(char **tab)
{
    for (int index = 0; tab[index] != NULL; index++)
        free(tab[index]);
    free(tab);
}

void free_int_tab(int **tab)
{
    for (int index = 0; tab[index] != NULL; index++)
        free(tab[index]);
    free(tab);
}
