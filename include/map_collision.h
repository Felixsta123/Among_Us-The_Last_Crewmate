/*
** EPITECH PROJECT, 2022
** map_collision
** File description:
** header
*/

#ifndef MCOL
    #define MCOL
    #include "structures.h"
    #include <math.h>

static const int BLUE_ENTRANCE = 38;
static const int BLUE_EXIT = 69;

int is_blocking_tile(map_t *map, sfVector2f pos);

#endif /* !MCOL */
