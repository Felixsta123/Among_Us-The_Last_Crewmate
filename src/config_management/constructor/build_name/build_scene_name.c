/*
** EPITECH PROJECT, 2022
** build_scene_name
** File description:
** Source code to build a scene
*/
#include "build_scene_name.h"

int build_name_opt(scene_t *scene, char *opt, char *value)
{
    if (opt == NULL || value == NULL)
        return (0);
    for (int index = 0; NAME_OPT_TAB[index].name != NULL; index++) {
        if (my_strcmp(opt, NAME_OPT_TAB[index].name) == 1)
            (*NAME_OPT_TAB[index].func)(scene, value);
    }
    free(opt);
    free(value);
    return (1);
}

int build_scene_name(scene_t *scene, char **content, int *line)
{
    char *opt = NULL;
    char *value = NULL;

    for (int index = 0; content[*line][index] != '>' &&
    content[*line] != NULL; index++)
    {
        if (content[*line][index] == '\0' && content[*line + 1] != NULL) {
            index = 0;
            *line += 1;
        }
        opt = get_obj_opt(content, line, &index);
        value = get_opt_value(content, line, &index);
        if (build_name_opt(scene, opt, value) == 0)
            break;
    }
    return (0);
}
