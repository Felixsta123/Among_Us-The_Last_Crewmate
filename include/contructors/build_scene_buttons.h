/*
** EPITECH PROJECT, 2022
** build_scene_buttons
** File description:
** Header
*/

#ifndef BUILD_SCENE_BUTTONS_H_
    #define BUILD_SCENE_BUTTONS_H_
    #include "stddef.h"
    #include "structures.h"
    #include <stdlib.h>

typedef struct butt_opt_s {
    char *name;
    int (*func)(button_t *button, char *value);
} butt_opt_t;

int build_butt_name(button_t *button, char *value);
int build_butt_posx(button_t *button, char *value);
int build_butt_posy(button_t *button, char *value);
int build_butt_width(button_t *button, char *value);
int build_butt_height(button_t *button, char *value);
int build_butt_scale(button_t *button, char *value);
int build_butt_rotation(button_t *button, char *value);
int build_butt_texture(button_t *button, char *value);
int build_butt_ho_texture(button_t *button, char *value);
int build_butt_sound(button_t *button, char *value);
int build_butt_callback(button_t *button, char *value);

__attribute__((unused)) static butt_opt_t BUTT_OPT_TAB[] = {
    {"name", build_butt_name},
    {"posx", build_butt_posx},
    {"posy", build_butt_posy},
    {"width", build_butt_width},
    {"height", build_butt_height},
    {"scale", build_butt_scale},
    {"rotation", build_butt_rotation},
    {"texture", build_butt_texture},
    {"ho_texture", build_butt_ho_texture},
    {"sound", build_butt_sound},
    {"callback", build_butt_callback},
    {NULL, NULL}
};

char *is_a_scene_opt(char **content, int *line);
char *get_obj_opt(char **content, int *line, int *index);
char *get_opt_value(char **content, int *line, int *index);
int my_getnbr(char *str);
int my_strcmp(char *str1, char *str2);
char *my_strdup(char const *src);
int write_error(char const *str);
float my_atof(char *str);
hitbox_t *init_hitbox(button_t *button);
#endif /* !BUILD_SCENE_BUTTONS_H_ */
