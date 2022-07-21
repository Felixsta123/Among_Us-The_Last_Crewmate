/*
** EPITECH PROJECT, 2021
** MyRPG
** File description:
** get_nb_row_tab.c
*/
#include <stddef.h>

int get_nb_row(char **tab)
{
    int row;

    for (row = 0; tab[row] != NULL; row++);
    return (row);
}
