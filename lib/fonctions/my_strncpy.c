/*
** EPITECH PROJECT, 2022
** my_strncpy
** File description:
** Source code to copy n char of a str_src into str_dest
*/

int my_strlen(char const *);

char *my_strncpy(char *dest, char const *src, int nb)
{
    int counter;

    for (counter = 0; counter <= nb - 1 && src[counter] != '\0'; counter++) {
        dest[counter] = src[counter];
    }
    dest[counter] = '\0';
    return dest;
}
