/*
** EPITECH PROJECT, 2022
** player_construct_tools
** File description:
** player_construct_tools
*/
#include "structures.h"
#include <stdlib.h>

void set_position(sfSprite *sprite, float x, float y)
{
    sfVector2f position = {x, y};

    sfSprite_setPosition(sprite, position);
}

sfIntRect *set_rect(int size)
{
    sfIntRect *rectangle = malloc(sizeof(sfIntRect));
    rectangle->top = 0;
    rectangle->left = 0;
    rectangle->width = size;
    rectangle->height = size;
    return rectangle;
}

sfSprite *create_sprite(char const *filepath, float x, float y)
{
    sfTexture *texture = sfTexture_createFromFile(filepath, NULL);
    sfSprite *sprite = sfSprite_create();
    sfVector2f scale = {x, y};
    sfVector2f origin = {8, 8};

    sfSprite_setTexture(sprite, texture, sfFalse);
    sfSprite_setScale(sprite, scale);
    sfSprite_setOrigin(sprite, origin);
    return (sprite);
}
