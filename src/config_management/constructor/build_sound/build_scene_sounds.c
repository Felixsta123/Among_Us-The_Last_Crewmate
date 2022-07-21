/*
** EPITECH PROJECT, 2022
** build_scene_sounds
** File description:
** Source code to build a scene
*/
#include "build_scene_sounds.h"

int build_music_opt(scene_t *scene, char *opt, char *value)
{
    if (opt == NULL || value == NULL)
        return (0);
    for (int index = 0; SOUND_OPT_TAB[index].name != NULL; index++) {
        if (my_strcmp(opt, SOUND_OPT_TAB[index].name) == 1)
            (*SOUND_OPT_TAB[index].func)(scene, value);
    }
    free(opt);
    free(value);
    return (1);
}

int build_scene_sounds(scene_t *scene, char **content, int *line)
{
    char *opt = NULL;
    char *value = NULL;

    *line += 1;
    scene->music = sfSound_create();
    while (content[*line] != NULL && is_a_scene_opt(content, line) == NULL) {
        for (int index = 0; content[*line][index] != '\0'; index++) {
            opt = get_obj_opt(content, line, &index);
            value = get_opt_value(content, line, &index);
            build_music_opt(scene, opt, value);
        }
        if (is_a_scene_opt(content, line) == NULL)
            break;
        *line += 1;
    }
    return (0);
}
