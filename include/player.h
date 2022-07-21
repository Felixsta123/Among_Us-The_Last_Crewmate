/*
** EPITECH PROJECT, 2021
** MyRPG
** File description:
** player.h
*/

#ifndef _PLAYER_
    #define _PLAYER_

    #include "structures.h"

static const int PLAYER_DAMAGES = 5;
static const int PLAYER_HEAL_PER_MINUTES = 5;
static const int PLAYER_SPEED = 5;

sfIntRect *set_rect(int size);
sfSprite *create_sprite(char const *filepath, float x, float y);

#endif
