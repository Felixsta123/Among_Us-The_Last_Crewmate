/*
** EPITECH PROJECT, 2022
** B-MUL-200-PAR-2-3-myrpg-gabriel.lepinay
** File description:
** my_getstr
*/

#include <stdlib.h>

#define ABS(x) ((x) > 0 ? (x) : (-(x)))

char *my_strdup(char *str);

char *my_strconc(char *str1, char *str2);

int int_len(int nb, int base)
{
    int i;
    for (i = 0; nb >= base; i++)
        nb /= base;
    i++;
    return i;
}

char *basestrcore(int nb, int base)
{
    char *digits = "0123456789abcdefghijklmnopqrstuvwxyz";
    int len = int_len(nb, base);
    char *str = malloc(len + 1);
    int i;

    for (i = 1; i <= len; i++) {
        str[len - i] = digits[nb % base];
        nb = nb / base;
    }
    str[i - 1] = 0;
    return str;
}

char *basestr(int nb, int base)
{
    int pos = ABS(nb);
    char *result = basestrcore(pos, base);
    char *minus = malloc(2);
    char *finalresult;
    minus[0] = '-';
    minus[1] = 0;
    if (nb < 0) {
        finalresult = my_strconc(minus, result);
    } else {
        finalresult = my_strdup(result);
    }
    free(minus);
    free(result);
    return finalresult;
}

char *my_getstr(int nb)
{
    return basestr(nb, 10);
}
