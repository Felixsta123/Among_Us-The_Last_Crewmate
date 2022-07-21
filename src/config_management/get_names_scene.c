/*
** EPITECH PROJECT, 2022
** get_names_scene
** File description:
** Source code to get an array that contain names of the scenes
*/
#include "get_names_scene.h"

int get_nb_scene(scene_t **scene_list)
{
    int counter;

    for (counter = 0; scene_list[counter] != NULL; counter++);
    return (counter);
}

char **get_names_scene(scene_t **scene_list)
{
    int nb_scenes = get_nb_scene(scene_list);
    char **names_scene = malloc((nb_scenes + 1) * sizeof(char *));
    int index;
    int len;

    for (index = 0; scene_list[index] != NULL; index++) {
        len = my_strlen(scene_list[index]->name);
        names_scene[index] = malloc((len + 1) * sizeof(char));
        names_scene[index] = my_strcpy(names_scene[index],
        scene_list[index]->name);
        names_scene[index][len] = '\0';
    }
    names_scene[index] = NULL;
    return (names_scene);
}
