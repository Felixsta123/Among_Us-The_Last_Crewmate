/*
** EPITECH PROJECT, 2022
** build_keys
** File description:
** SOurce code to build key to move play
*/
#include "structures.h"
#include <stdlib.h>

keys_t *build_keys(void)
{
    keys_t *keys = malloc(sizeof(keys_t));
    keys->up = sfKeyZ;
    keys->right = sfKeyD;
    keys->down = sfKeyS;
    keys->left = sfKeyQ;
    return keys;
}
