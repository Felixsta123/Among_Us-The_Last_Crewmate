/*
** EPITECH PROJECT, 2022
** build_scene_sounds
** File description:
** Header
*/

#ifndef BUILD_SCENE_SOUNDS_H_
    #define BUILD_SCENE_SOUNDS_H_
    #include "stddef.h"
    #include "structures.h"
    #include <stdlib.h>

typedef struct sound_opt_s {
    char *name;
    int (*func)(scene_t *scene, char *value);
} sound_opt_t;

int build_sound_path(scene_t *scene, char *value);
int build_sound_volume(scene_t *scene, char *value);
int build_sound_pitch(scene_t *scene, char *value);
int build_sound_looping(scene_t *scene, char *value);

__attribute__((unused)) static sound_opt_t SOUND_OPT_TAB[] = {
    {"path", build_sound_path},
    {"volume", build_sound_volume},
    {"pitch", build_sound_pitch},
    {"looping", build_sound_looping},
    {NULL, NULL}
};

char *is_a_scene_opt(char **content, int *line);
char *get_obj_opt(char **content, int *line, int *index);
char *get_opt_value(char **content, int *line, int *index);
int my_strcmp(char *str1, char *str2);
int write_error(char const *str);
float my_atof(char *str);
int my_strcmp(char *str1, char *str2);
#endif /* !BUILD_SCENE_SOUNDS_H_ */
