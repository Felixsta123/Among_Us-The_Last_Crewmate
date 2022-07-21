/*
** EPITECH PROJECT, 2022
** event_management
** File description:
** Header
*/

#ifndef EVMAN_H_
    #define EVMAN_H_
    #include <stddef.h>
    #include <unistd.h>
    #include "structures.h"

int button_collision(sfVector2i mouse_loc, button_t *button);
void manage_hover_buttons(button_t *buttons, sfVector2i mouse_loc);
void manage_clic_buttons(data_t *game_data, button_t *buttons,
sfVector2i mouse_loc);
int options(data_t *game_data, char **scenes_name, int *index_run);
void spawn_enem_blood(data_t *gd, sfVector2f pos);
void add_enem(enemies_t *enemies, sfVector2f pos);
void destroy_next_enemies(enemies_t *node);
int my_strcmp(char *str1, char *str2);
void interact_pnj(data_t *game_data, float distance, entity_t *tmp_ent);
#endif /*MAIN_H_*/
