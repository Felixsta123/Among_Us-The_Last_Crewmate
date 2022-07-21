/*
** EPITECH PROJECT, 2022
** init_game
** File description:
** Header
*/

#ifndef INIT_GAME_H_
    #define INIT_GAME_H_
    #include "structures.h"
    #include "stdlib.h"

int my_putstr(char const *str);
int my_strcmp(char *str1, char *str2);
int data_constructor(data_t *game_data);
scene_t **get_scene_list();
#endif /* !INIT_GAME_H_ */
