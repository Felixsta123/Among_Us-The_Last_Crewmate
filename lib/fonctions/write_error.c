/*
** EPITECH PROJECT, 2022
** write_error
** File description:
** Source code to write error (right output)
*/
#include <unistd.h>

void my_putchar(char c);

int my_strlen(char const *str);

int write_error(char const *str)
{
    write(2, str, my_strlen(str));
    return (0);
}
