/*
** EPITECH PROJECT, 2022
** main
** File description:
** Header
*/

#ifndef MAIN_H_
    #define MAIN_H_
    #include <stddef.h>
    #include <unistd.h>
    #include <stdlib.h>
    #include <time.h>
    #include "structures.h"

int init_game(int ac, char **av, data_t *game_data);
int my_putstr(char const *str);
void open_window(int width, int height, data_t *game_data);
char **get_names_scene(scene_t **scene_list);
int get_run_index(char **scene_names, char *name);
void free_data(data_t *game_data);
float my_atof(char *str);
int my_strcmp(char *str1, char *str2);
player_t *player_constructor(void);
#endif /*MAIN_H_*/
