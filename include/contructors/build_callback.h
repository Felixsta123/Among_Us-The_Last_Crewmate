/*
** EPITECH PROJECT, 2022
** construct_callbacks
** File description:
** Header
*/

#ifndef CALL_H_
    #define CALL_H_
    #include "structures.h"

typedef struct but_call_s {
    char *name;
    int (*func)(data_t *game_data, char **scenes_name, int *index_run);
} but_call_t;

int nothing(data_t *game_data, char **scenes_name, int *index_run);
int play(data_t *game_data, char **scenes_name, int *index_run);
int quit(data_t *game_data, char **scenes_name, int *index_run);
int options(data_t *game_data, char **scenes_name, int *index_run);
int arrows(data_t *game_data, char **scenes_name, int *index_run);
int zqsd(data_t *game_data, char **scenes_name, int *index_run);
int thirty_fps(data_t *game_data, char **scenes_name, int *index_run);
int sixty_fps(data_t *game_data, char **scenes_name, int *index_run);
int hundred_and_twenty_fps(data_t *game_data,
char **scenes_name, int *index_run);
int volume_bar(data_t *game_data, char **scenes_name, int *index_run);
int update_att(data_t *game_data, char **scenes_name, int *index_run);
int update_heal(data_t *game_data, char **scenes_name, int *index_run);
int update_spd(data_t *game_data, char **scenes_name, int *index_run);
int main_options(data_t *game_data, char **scenes_name, int *index_run);
int main_volume_bar(data_t *game_data, char **scenes_name, int *index_run);
int home(data_t *game_data, char **scenes_name, int *index_run);
int defeat(data_t *game_data, char **scenes_name, int *index_run);
int victory(data_t *game_data, char **scenes_name, int *index_run);

static const but_call_t BUT_CALL[19] = {
    {"no", nothing},
    {"play", play},
    {"quit", quit},
    {"option", options},
    {"arrows", arrows},
    {"zqsd", zqsd},
    {"30", thirty_fps},
    {"60", sixty_fps},
    {"120", hundred_and_twenty_fps},
    {"bar", volume_bar},
    {"update_att", update_att},
    {"update_heal", update_heal},
    {"update_spd", update_spd},
    {"main_options", main_options},
    {"main_bar", main_volume_bar},
    {"home", home},
    {"defeat", defeat},
    {"victory", victory},
    {NULL, NULL}
};

void load_vertices(hitbox_t *hitbox);
button_t *get_button(button_t *buttons, char *name);
int my_strcmp(char *str1, char *str2);
scene_t *get_scene(scene_t **scene_list, char *name);

#endif /*CALL_H_*/
