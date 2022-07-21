/*
** EPITECH PROJECT, 2022
** next_char
** File description:
** Source code to know the next char passed as argument
*/

int next_char(char *str, int start, char c)
{
    int index;

    for (index = start; str[index] != c && str[index] != '\0'; index++);
    return (index);
}
