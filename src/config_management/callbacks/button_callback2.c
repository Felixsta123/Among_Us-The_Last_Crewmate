/*
** EPITECH PROJECT, 2021
** MyRPG
** File description:
** button_callback_2.c
*/
#include "build_callback.h"
#include <stdlib.h>

int arrows(data_t *game_data, char **scenes_name, int *index_run)
{
    (void)scenes_name;
    (void)index_run;
    keys_t *new_keys = malloc(sizeof(keys_t));
    new_keys->up = sfKeyUp;
    new_keys->right = sfKeyRight;
    new_keys->down = sfKeyDown;
    new_keys->left = sfKeyLeft;
    game_data->keys = new_keys;
    return 0;
}

int zqsd(data_t *game_data, char **scenes_name, int *index_run)
{
    (void)scenes_name;
    (void)index_run;
    keys_t *new_keys = malloc(sizeof(keys_t));
    new_keys->up = sfKeyZ;
    new_keys->right = sfKeyD;
    new_keys->down = sfKeyS;
    new_keys->left = sfKeyQ;
    game_data->keys = new_keys;
    return 0;
}

int thirty_fps(data_t *game_data, char **scenes_name, int *index_run)
{
    (void)scenes_name;
    (void)index_run;
    game_data->framerate = 30;
    sfRenderWindow_setFramerateLimit(game_data->window, game_data->framerate);
    return 0;
}

int sixty_fps(data_t *game_data, char **scenes_name, int *index_run)
{
    (void)scenes_name;
    (void)index_run;
    game_data->framerate = 60;
    sfRenderWindow_setFramerateLimit(game_data->window, game_data->framerate);
    return 0;
}

int hundred_and_twenty_fps(data_t *game_data,
char **scenes_name, int *index_run)
{
    (void)scenes_name;
    (void)index_run;
    game_data->framerate = 120;
    sfRenderWindow_setFramerateLimit(game_data->window, game_data->framerate);
    return 0;
}
