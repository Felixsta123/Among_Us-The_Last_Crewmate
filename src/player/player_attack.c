/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** player_attack.c
*/

#include "movement.h"
#include <stdbool.h>
#include <math.h>
#include "enemies.h"
#include "random.h"

float get_distance(sfVector2f p1, sfVector2f p2);

void spawn_enem_blood(data_t *gd, enemies_t *enem);

static bool is_in_front(data_t *gd, sfVector2f pos)
{
    int facing = gd->red->facing;
    sfVector2f dist = {pos.x - gd->red->pos.x, pos.y - gd->red->pos.y};

    if (facing == 0 && dist.y > 0)
        return true;
    if (facing == 1 && dist.x < 0)
        return true;
    if (facing == 2 && dist.x > 0)
        return true;
    if (facing == 3 && dist.y < 0)
        return true;
    return false;
}

static void attack_enem(data_t *gd, enemies_t *enem)
{
    sfVector2f ppos;
    sfVector2f epos;
    float dir;

    epos = enem->enem->pos;
    ppos = gd->red->pos;
    dir = atan2((ppos.y - epos.y), (ppos.x - epos.x)) + M_PI;
    if (get_distance(epos, ppos) < 60 && is_in_front(gd, enem->enem->pos)) {
        sfSound_setPitch(gd->red->effects->slash, rdm_float(0.8, 2));
        sfSound_play(gd->red->effects->slash);
        enem->enem->kb_speed = 10;
        enem->enem->life -= gd->red->stats->att;
        enem->enem->kb_dir = dir;
        spawn_enem_blood(gd, enem);
    }
}

void push_enemies(data_t *gd)
{
    enemies_t *tmp;

    tmp = gd->enemies->next;
    while (tmp != NULL) {
        attack_enem(gd, tmp);
        tmp = tmp->next;
    }
    gd->red->attack_state = 1;
}
