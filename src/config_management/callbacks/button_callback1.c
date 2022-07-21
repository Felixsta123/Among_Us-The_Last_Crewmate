/*
** EPITECH PROJECT, 2022
** button_callback.c
** File description:
** Source code of every callback
*/
#include "build_callback.h"

int nothing(data_t *game_data, char **scenes_name, int *index_run)
{
    (void)game_data;
    (void)scenes_name;
    (void)index_run;
    return (0);
}

int play(data_t *game_data, char **scenes_name, int *index_run)
{
    (void)game_data;
    for (int index = 0; scenes_name[index] != NULL; index++) {
        if (my_strcmp(scenes_name[index], "game_scene") == 1)
            *index_run = index;
    }
    return (0);
}

int quit(data_t *game_data, char **scenes_name, int *index_run)
{
    (void)game_data;
    (void)scenes_name;
    *index_run = -1;
    return 0;
}

int options(data_t *game_data, char **scenes_name, int *index_run)
{
    (void)game_data;
    for (int index = 0; scenes_name[index] != NULL; index++) {
        if (my_strcmp(scenes_name[index], "option_menu") == 1)
            *index_run = index;
    }
    return (0);
}

int main_options(data_t *game_data, char **scenes_name, int *index_run)
{
    (void)game_data;
    for (int index = 0; scenes_name[index] != NULL; index++) {
        if (my_strcmp(scenes_name[index], "main_options") == 1)
            *index_run = index;
    }
    return (0);
}
