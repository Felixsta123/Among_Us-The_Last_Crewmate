/*
** EPITECH PROJECT, 2021
** my_putchar
** File description:
** Source code of my_putchar
*/
#include <unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}
