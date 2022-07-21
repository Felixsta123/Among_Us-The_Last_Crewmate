/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** destory.c
*/

#include "particles.h"
#include <stdlib.h>

void destroy_particle(particle_t *particle)
{
    sfCircleShape_destroy(particle->circle);
}

void destroy_partic_arr(partic_arr_t *partic_arr)
{
    for (int i = 0; i < partic_arr->count; ++i) {
        destroy_particle(&partic_arr->particles[i]);
    }
    free(partic_arr->particles);
}
