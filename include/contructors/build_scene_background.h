/*
** EPITECH PROJECT, 2022
** build_scene_background
** File description:
** Header
*/

#ifndef BUILD_SCENE_BACKGROUND_H_
    #define BUILD_SCENE_BACKGROUND_H_
    #include "stddef.h"
    #include "structures.h"
    #include <stdlib.h>

typedef struct back_opt_s {
    char *name;
    int (*func)(scene_t *scene, char *value);
} back_opt_t;

int build_back_type(scene_t *scene, char *value);
int build_back_path(scene_t *scene, char *value);

__attribute__((unused)) static back_opt_t BACK_OPT_TAB[] = {
    {"type", build_back_type},
    {"path", build_back_path},
    {NULL, NULL}
};

char *get_obj_opt(char **content, int *line, int *index);
char *get_opt_value(char **content, int *line, int *index);
int my_strcmp(char *str1, char *str2);
map_t *map_constructor(void);
#endif /* !BUILD_SCENE_BACKGROUND_H_ */
