/*
** EPITECH PROJECT, 2022
** image_opt
** File description:
** Source code to build image opt
*/
#include "build_scene_images.h"

int build_img_scale(image_t *image, char *value)
{
    sfVector2f scale = (sfVector2f) {my_atof(value), my_atof(value)};

    image->scale = scale;
    return (0);
}

int build_img_rotation(image_t *image, char *value)
{
    float rot = my_atof(value);

    image->rotation = rot;
    return (0);
}

int build_img_texture(image_t *image, char *value)
{
    sfVector2f origin = (sfVector2f) {image->width / (2 * image->scale.x),
    image->height / (2 * image->scale.y)};

    image->sprite = sfSprite_create();
    image->texture = sfTexture_createFromFile(value, NULL);
    if (image->texture == NULL) {
        write_error("Enable to load texture:");
        write_error(value);
        write_error(".\n");
        return (-1);
    }
    sfSprite_setPosition(image->sprite, image->position);
    sfSprite_setRotation(image->sprite, image->rotation);
    sfSprite_setScale(image->sprite, image->scale);
    sfSprite_setOrigin(image->sprite, origin);
    sfSprite_setTexture(image->sprite, image->texture, sfFalse);
    return (0);
}
