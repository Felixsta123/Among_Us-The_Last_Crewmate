/*
** EPITECH PROJECT, 2022
** build_scene_entities
** File description:
** Header
*/

#ifndef BUILD_SCENE_ENTITIES_H_
    #define BUILD_SCENE_ENTITIES_H_
    #include "stddef.h"
    #include "structures.h"
    #include <stdlib.h>

typedef struct ent_opt_s {
    char *name;
    int (*func)(entity_t *entity, char *value);
} ent_opt_t;

int build_ent_name(entity_t *entity, char *value);
int build_ent_posx(entity_t *entity, char *value);
int build_ent_posy(entity_t *entity, char *value);
int build_ent_width(entity_t *entity, char *value);
int build_ent_height(entity_t *entity, char *value);
int build_ent_scale(entity_t *entity, char *value);
int build_ent_rotation(entity_t *entity, char *value);
int build_ent_texture(entity_t *entity, char *value);
int build_ent_action_sound(entity_t *entity, char *value);
int build_ent_dialogue(entity_t *entity, char *value);
int build_ent_quest(entity_t *entity, char *value);
int build_ent_back_texture(entity_t *entity, char *value);

__attribute__((unused)) static ent_opt_t ENT_OPT_TAB[] = {
    {"name", build_ent_name},
    {"posx", build_ent_posx},
    {"posy", build_ent_posy},
    {"width", build_ent_width},
    {"height", build_ent_height},
    {"scale", build_ent_scale},
    {"rotation", build_ent_rotation},
    {"texture", build_ent_texture},
    {"back_texture", build_ent_back_texture},
    {"action_sound", build_ent_action_sound},
    {"dialogue", build_ent_dialogue},
    {"quest", build_ent_quest},
    {NULL, NULL}
};

float my_atof(char *str);
char *is_a_scene_opt(char **content, int *line);
char *get_obj_opt(char **content, int *line, int *index);
char *get_opt_value(char **content, int *line, int *index);
int my_getnbr(char *str);
char *my_strdup(char const *src);
int my_strcmp(char *str1, char *str2);
int write_error(char const *str);
int build_butt_texture(button_t *button, char *value);
int build_butt_ho_texture(button_t *button, char *value);
int build_butt_sound(button_t *button, char *value);

#endif /* !BUILD_SCENE_ENTITIES_H_ */
