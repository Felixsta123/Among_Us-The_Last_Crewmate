/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** tools.c
*/

#include "enemies.h"
#include <math.h>

float normalize(float dist, float max_speed)
{
    if (dist >= max_speed)
        return max_speed;
    return dist;
}

float get_distance(sfVector2f p1, sfVector2f p2)
{
    float distx = p2.x - p1.x;
    float disty = p2.y - p1.y;

    return sqrt(pow(distx, 2) + pow(disty, 2));
}

sfVector2f get_direction(sfVector2f p1, sfVector2f p2)
{
    int x = p2.x - p1.x;
    int y = p2.y - p1.y;

    return (sfVector2f) {x, y};
}

sfVector2f get_vector(float dir, float speed)
{
    return (sfVector2f) {speed * cos(dir), speed * sin(dir)};
}

int enem_count(enemies_t *node)
{
    if (node == NULL)
        return 0;
    return enem_count(node->next) + 1;
}
