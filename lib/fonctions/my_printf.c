/*
** EPITECH PROJECT, 2021
** my_printf
** File description:
** Source code to do the my_printf
*/
#include <stdarg.h>

void my_putchar(char);

void my_putstr(char const *);

void my_putnbr(int nb);

void type_args(va_list args, char type)
{
    switch (type) {
    case 's':
        my_putstr(va_arg(args, char *));
        break;
    case 'i':
        my_putnbr(va_arg(args, int));
        break;
    case 'd':
        my_putnbr(va_arg(args, int));
        break;
    case 'c':
        my_putchar(va_arg(args, int));
        break;
    }
}

void my_printf(char *str, ...)
{
    va_list args;
    int counter = 0;

    va_start(args, str);
    for (counter = 0; str[counter] != '\0'; counter++) {
        if (str[counter] == '%') {
            type_args(args, str[counter + 1]);
            counter += 1;
        } else {
            my_putchar(str[counter]);
        }
    }
}
