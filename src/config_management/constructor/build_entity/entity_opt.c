/*
** EPITECH PROJECT, 2022
** entity_opt
** File description:
** SOurce code of entities's options
*/
#include "build_scene_entities.h"

int build_ent_name(entity_t *entity, char *value)
{
    entity->name = my_strdup(value);
    return (0);
}

int build_ent_posx(entity_t *entity, char *value)
{
    int coord_x = my_getnbr(value);

    entity->position.x = coord_x;
    return (0);
}

int build_ent_posy(entity_t *entity, char *value)
{
    int coord_y = my_getnbr(value);

    entity->position.y = coord_y;
    return (0);
}

int build_ent_width(entity_t *entity, char *value)
{
    int width = my_getnbr(value);

    entity->width = width;
    return (0);
}

int build_ent_height(entity_t *entity, char *value)
{
    int height = my_getnbr(value);

    entity->height = height;
    return (0);
}
