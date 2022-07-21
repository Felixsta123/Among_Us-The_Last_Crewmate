/*
** EPITECH PROJECT, 2021
** my_put_nbr
** File description:
** Source code of my_put_nbr
*/

void my_putchar(char c);

void my_putnbr(int nb)
{
    int modulo = 0;

    if (nb < 0) {
        my_putchar('-');
        nb = nb * (-1);
    } else if (nb >= 0 && nb >= 10) {
        modulo = (nb % 10);
        nb = (nb - modulo) / 10;
        my_putnbr(nb);
        my_putchar(48 + modulo);
    } else {
        my_putchar(48 + nb % 10);
    }
}
