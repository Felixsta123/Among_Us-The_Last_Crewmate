/*
** EPITECH PROJECT, 2022
** back_opt
** File description:
** Source code to construct background option
*/
#include "build_scene_background.h"

int build_back_map(scene_t *scene)
{
    scene->map = map_constructor();
    return (0);
}

int build_back_img(scene_t *scene, char *path)
{
    scene->background_sprite = sfSprite_create();
    scene->background_texture = sfTexture_createFromFile(path, NULL);
    sfSprite_setTexture(scene->background_sprite,
                            scene->background_texture, sfFalse);
    return (0);
}

int build_back_type(scene_t *scene, char *value)
{
    if (my_strcmp(value, "map") == 1)
        build_back_map(scene);
    return (0);
}

int build_back_path(scene_t *scene, char *value)
{
    build_back_img(scene, value);
    return (0);
}
