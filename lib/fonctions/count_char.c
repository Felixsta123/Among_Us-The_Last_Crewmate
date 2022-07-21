/*
** EPITECH PROJECT, 2022
** count_char
** File description:
** Source code to count number of a char as argument in a string
*/

int count_char(char *str, char c)
{
    int res = 0;

    for (int counter = 0; str[counter] != '\0'; counter++) {
        if (str[counter] == c) {
            res++;
        }
    }
    return (res);
}
