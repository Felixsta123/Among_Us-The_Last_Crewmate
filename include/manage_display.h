/*
** EPITECH PROJECT, 2022
** manage_display
** File description:
** Header
*/

#ifndef MDIS_H_
    #define MDIS_H_
    #include <stddef.h>
    #include "structures.h"

void display_map(sfRenderWindow *window, map_t *map_data);
void set_position(sfSprite *sprite, float x, float y);
void handle_particles(sfRenderWindow *win, data_t *game_data, scene_t *scene);
void update_enemies(data_t *gd, enemies_t *enemies);
void update_groups(data_t *gd, partic_ll_t *groups);
void update_stats(data_t *game_data, scene_t *option_scene);
void knife(data_t *game_data);
char *my_getstr(int nb);
int my_strcmp(char *str1, char *str2);
scene_t *get_scene(scene_t **scene_list, char *name);
text_t *get_text(text_t *texts, char *name);
void draw_buttons(sfRenderWindow *window, data_t *game_data, scene_t *scene);
void draw_images(sfRenderWindow *window, scene_t *scene);
void draw_texts(sfRenderWindow *window, scene_t *scene);
void player_move(data_t *game_data, scene_t *scene);
void draw_entities(sfRenderWindow *window, data_t *game_data, scene_t *scene);
void draw_enemies(sfRenderWindow *win, enemies_t *enemies);
void print_xp(data_t *game_data, scene_t *option_scene);
int my_strlen(char *str);

#endif /*MDIS_H_*/
