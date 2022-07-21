/*
** EPITECH PROJECT, 2022
** get_run_index
** File description:
** Source code to get the index of the name passed as argument
*/
#include "get_run_index.h"

int get_run_index(char **scene_names, char *name)
{
    for (int index = 0; scene_names[index] != NULL; index++) {
        if (my_strcmp(scene_names[index], name))
            return (index);
    }
    write_error("This name of scene does not exist.\n");
    return (-1);
}

scene_t *get_scene(scene_t **scene_list, char *name)
{
    for (int index = 0; scene_list[index] != NULL; index++) {
        if (my_strcmp(scene_list[index]->name, name))
            return (scene_list[index]);
    }
    write_error("This name of scene does not exist.\n");
    return (NULL);
}
