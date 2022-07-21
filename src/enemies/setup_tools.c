/*
** EPITECH PROJECT, 2021
** MyRPG
** File description:
** setup_tools.c
*/

#include "enemies.h"
#include <stdlib.h>
#include "random.h"

sfTexture *random_enemy_texture(void)
{
    int index = rdm_int(1, 3);
    sfTexture *texture = NULL;
    if (index == 1) {
        texture = sfTexture_createFromFile(
        "assets/img/enemies/enemy1_walk_left.png", NULL);
    } else if (index == 2) {
        texture = sfTexture_createFromFile(
        "assets/img/enemies/enemy2_walk_left.png", NULL);
    } else {
        texture = sfTexture_createFromFile(
        "assets/img/enemies/enemy3_walk_left.png", NULL);
    }
    return texture;
}

sfIntRect *set_enemy_rect(void)
{
    sfIntRect *rectangle = malloc(sizeof(sfIntRect));
    rectangle->top = 0;
    rectangle->left = 0;
    rectangle->width = 32;
    rectangle->height = 32;
    return rectangle;
}

void setup_values_enem(enem_t *enem)
{
    enem->damage = 0;
    enem->speed = 1.2;
    enem->direction = 0;
    enem->life = rdm_int(15, 30);
    enem->kb_speed = 0;
    enem->kb_dir = 0;
}
