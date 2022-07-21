/*
** EPITECH PROJECT, 2022
** image_opt
** File description:
** Source code to build image opt
*/
#include "build_scene_images.h"

int build_img_name(image_t *image, char *value)
{
    image->name = my_strdup(value);
    return (0);
}

int build_img_posx(image_t *image, char *value)
{
    int coord_x = my_atof(value);

    image->position.x = coord_x;
    return (0);
}

int build_img_posy(image_t *image, char *value)
{
    int coord_y = my_atof(value);

    image->position.y = coord_y;
    return (0);
}

int build_img_width(image_t *image, char *value)
{
    int width = my_getnbr(value);

    image->width = width;
    return (0);
}

int build_img_height(image_t *image, char *value)
{
    int height = my_getnbr(value);

    image->height = height;
    return (0);
}
