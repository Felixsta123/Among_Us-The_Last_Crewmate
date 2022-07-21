/*
** EPITECH PROJECT, 2021
** my_strlen
** File description:
** Source code to know the len of a string
*/

int my_strlen(char const *str)
{
    int nb = 0;

    while (str[nb] != '\0') {
        nb++;
    }
    return (nb);
}
