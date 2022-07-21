/*
** EPITECH PROJECT, 2022
** build_scene_name
** File description:
** Header
*/

#ifndef BUILD_SCENE_NAME_H_
    #define BUILD_SCENE_NAME_H_
    #include "stddef.h"
    #include "structures.h"
    #include <stdlib.h>

typedef struct name_opt_s {
    char *name;
    int (*func)(scene_t *scene, char *value);
} name_opt_t;

int build_name_name(scene_t *scene, char *value);

__attribute__((unused)) static name_opt_t NAME_OPT_TAB[] = {
    {"name", build_name_name},
    {NULL, NULL}
};

char *get_obj_opt(char **content, int *line, int *index);
char *get_opt_value(char **content, int *line, int *index);
int my_strcmp(char *str1, char *str2);
char *my_strdup(char const *src);
#endif /* !BUILD_SCENE_NAME_H_ */
