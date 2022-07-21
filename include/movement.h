/*
** EPITECH PROJECT, 2021
** MyRPG
** File description:
** movement.h
*/

#ifndef _MOVEMENT_
    #define _MOVEMENT_

    #include <SFML/Graphics.h>
    #include <SFML/System.h>
    #include <SFML/Window.h>
    #include <stdbool.h>
    #include "structures.h"

static const int VIEW_WIDTH  = 600;
static const int VIEW_HEIGHT  = 400;
static const int WINDOW_WIDTH = 1920;
static const int WINDOW_HEIGHT = 1008;

static const sfVector2f OFFSET[4] =
{{-16, 0}, {-32, -32}, {0, -32}, {-16, -35}};

void set_position(sfSprite *sprite, float x, float y);
int is_blocking_tile(map_t *map, sfVector2f pos);
void init_view(sfRenderWindow *window, data_t *game_data);
void move_rect(sfIntRect *rect, int offset, int max_value);
void player_walk(data_t *game_data, int offset, int max_value);
bool is_in_screen(data_t *gd, sfVector2f pos);
char *my_getstr(int nb);
char *my_strdup(char *str);
char *my_strconc(char *str1, char *str2);
particle_param_t setup_step_param(void);
partic_ll_t *setup_partic_node(particle_param_t *p);
void add_partic_group(partic_ll_t *groups, partic_ll_t *node);
scene_t *get_scene(scene_t **scene_list, char *name);
int defeat(data_t *game_data, char **scenes_name, int *index_run);
int victory(data_t *game_data, char **scenes_name, int *index_run);
bool is_all_lava(scene_t *scene, int x, int y);

#endif
