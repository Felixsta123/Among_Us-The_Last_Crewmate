/*
** EPITECH PROJECT, 2022
** count_line
** File description:
** Source code to count the number o line in a tab
*/

#include <stddef.h>

int count_line(char **tab)
{
    int counter = 0;

    for (int index = 0; tab[index] != NULL; index++)
        counter++;
    return (counter);
}
