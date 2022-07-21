/*
** EPITECH PROJECT, 2021
** MyRPG
** File description:
** death.c
*/

#include "movement.h"

bool is_all_lava(scene_t *scene, int x, int y)
{
    for (int i = 0; i < 9; ++i) {
        if (!(scene->map->tiles[y / 32 +
        (i / 3 - 1)][x / 32 + (i % 3 - 1)] >= 4 && scene->map->tiles[y / 32 +
        (i / 3 - 1)][x / 32 + (i % 3 - 1)] <= 7)) {
            return false;
        }
    }
    return true;
}
