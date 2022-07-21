/*
** EPITECH PROJECT, 2022
** scene_option
** File description:
** Header
*/

#ifndef SOURCE_OPTION_H_
    #define SOURCE_OPTION_H_
    #include "stddef.h"
    #include <stdlib.h>
    #include "structures.h"

typedef struct game_func_s {
    char *name;
    int (*func)(scene_t *scene, char **content, int *line);
} game_func_t;

int build_scene_name(scene_t *scene, char **content, int *line);
int build_scene_background(scene_t *scene, char **content, int *line);
int build_scene_buttons(scene_t *scene, char **content, int *line);
int build_scene_entities(scene_t *scene, char **content, int *line);
int build_scene_texts(scene_t *scene, char **content, int *line);
int build_scene_images(scene_t *scene, char **content, int *line);
int build_scene_sounds(scene_t *scene, char **content, int *line);

static const game_func_t TAB_SOPT[] = {
    {"scene_name", build_scene_name},
    {"background", build_scene_background},
    {"button", build_scene_buttons},
    {"entity", build_scene_entities},
    {"text", build_scene_texts},
    {"image", build_scene_images},
    {"sound", build_scene_sounds},
    {NULL, NULL}
};

int my_strcmp(char *str1, char *str2);
#endif /* !SOURCE_OPTION_H_ */
