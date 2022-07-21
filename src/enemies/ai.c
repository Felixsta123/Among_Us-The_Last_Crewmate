/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** ai.c
*/

#include "enemies.h"
#include "structures.h"
#include "random.h"
#include <math.h>
#include <stdio.h>

sfVector2f handle_dest(data_t *gd, enemies_t *node)
{
    float angle = rdm_float(0, 2 * M_PI);
    float dist = rdm_float(100, 200);

    if (get_distance(node->enem->pos, node->enem->destination) < 1) {
        node->enem->destination = (sfVector2f) {node->enem->pos.x +
        cos(angle) * dist, node->enem->pos.y + sin(angle) * dist};
        return (sfVector2f) {0, 0};
    }
    if (get_distance(gd->red->pos, node->enem->pos) < AGGRO_DIST)
        node->enem->destination = node->enem->pos;
    return (sfVector2f) {node->enem->destination.x - node->enem->pos.x,
    node->enem->destination.y - node->enem->pos.y};
}

static sfVector2f computation(enemies_t *temp, sfVector2f epos,
sfVector2f intent)
{
    float target = 100;
    float spring;
    sfVector2f tmpos = temp->enem->pos;
    float dist = get_distance(epos, tmpos);

    if (dist != 0 && dist < 20) {
        spring = target / (target + pow(dist, 3)) * 4000;
        intent = (sfVector2f)
        {intent.x - (tmpos.x - epos.x) * spring,
        intent.y - (tmpos.y - epos.y) * spring};
    }
    return intent;
}

sfVector2f calculate_intent(data_t *gd, enemies_t *node)
{
    sfVector2f epos = node->enem->pos;
    sfVector2f ppos = {gd->red->pos.x, gd->red->pos.y};
    sfVector2f dir = get_direction(epos, ppos);
    float dist = get_distance(epos, ppos);
    float target = ENEM_COLLIDE_DIST;
    float spring = dist < AGGRO_DIST ? (dist - target) : 0;
    sfVector2f intent = {dir.x * spring, dir.y * spring};

    dir = handle_dest(gd, node);
    dist = get_distance(dir, (sfVector2f) {0, 0});
    spring = dist / 100;
    intent = (sfVector2f)
    {intent.x + dir.x * spring, intent.y + dir.y * spring};
    for (enemies_t *temp = gd->enemies->next; temp != NULL;
    temp = temp->next) {
        intent = computation(temp, epos, intent);
    }
    return (sfVector2f) {intent.x, intent.y};
}
