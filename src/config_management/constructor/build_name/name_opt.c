/*
** EPITECH PROJECT, 2022
** name_opt
** File description:
** Source code to construct name option
*/
#include "build_scene_name.h"

int build_name_name(scene_t *scene, char *value)
{
    scene->name = my_strdup(value);
    return (0);
}
