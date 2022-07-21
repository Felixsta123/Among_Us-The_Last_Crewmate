/*
** EPITECH PROJECT, 2022
** main
** File description:
** Source code of the main
*/
#include "main.h"

static void usage(void)
{
    my_putstr("./my_rpg\n");
}

int my_rpg(int ac, char *av[])
{
    data_t *game_data = malloc(sizeof(data_t));
    int flag = 0;

    srand(time(NULL));
    if (init_game(ac, av, game_data) == -1)
        flag = 1;
    if (flag == 0)
        open_window(1920, 1080, game_data);
    free_data(game_data);
    return (flag);
}

int main(int ac, char *av[])
{
    if (ac == 2 && my_strcmp(av[1], "-h") == 1) {
        usage();
        return (0);
    }
    my_rpg(ac, av);
    return (0);
}
