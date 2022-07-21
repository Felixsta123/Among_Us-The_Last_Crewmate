/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** update.c
*/

#include "particles.h"
#include "structures.h"
#include <math.h>
#include "random.h"

sfVector2f get_vector(float dir, float speed);

float get_distance(sfVector2f p1, sfVector2f p2);

sfVector2f get_gravity(data_t *gd, particle_t *p)
{
    sfVector2f pos = {p->pos.x, p->pos.y};
    sfVector2f intent = {gd->red->pos.x - pos.x, gd->red->pos.y - pos.y};
    float angle = atan2(intent.y, intent.x);
    float dist = get_distance((sfVector2f) {0, 0}, intent);
    sfVector2f gravity = get_vector(angle, 100 / pow(dist, 2));

    return gravity;
}

static sfVector2f set_grav(data_t *gd, float posx, float posy, particle_t *p)
{
    sfVector2f grav = p->grav;
    if (get_distance(gd->red->pos, (sfVector2f) {posx, posy}) < 10) {
        p->duration = 0;
        gd->red->stats->xp += 1;
        sfSound_setPitch(gd->red->effects->xp, 0.8 + get_rdm());
        sfSound_play(gd->red->effects->xp);
        return grav;
    }
    grav = get_gravity(gd, p);
    return grav;
}

void update_particle(data_t *gd, particle_t *p, bool is_xp)
{
    float d = 60.0 / gd->framerate;
    float posx = p->pos.x + p->vel.x * d;
    float posy = p->pos.y + p->vel.y * d;
    float velx = ((p->vel.x * (1 - p->res.x) + p->grav.x) - p->vel.x) * d;
    float vely = ((p->vel.y * (1 - p->res.y) + p->grav.y) - p->vel.y) * d;
    sfVector2f grav = p->grav;
    if (is_xp) {
        grav = set_grav(gd, posx, posy, p);
    }
    velx = ((p->vel.x * (1 - p->res.x) + grav.x) - p->vel.x) * d;
    vely = ((p->vel.y * (1 - p->res.y) + grav.y) - p->vel.y) * d;
    p->pos = (sfVector2f) {posx, posy};
    p->vel = (sfVector2f) {p->vel.x + velx, p->vel.y + vely};
    p->duration -= 1 * d;
    sfCircleShape_setPosition(p->circle, p->pos);
}

void update_partic_arr(data_t *gd, partic_arr_t *partic, bool is_xp)
{
    int i;

    partic->duration -= 1;
    for (i = 0; i < partic->count; i++) {
        if (partic->particles[i].duration > 0)
            update_particle(gd, &partic->particles[i], is_xp);
    }
}

void update_groups(data_t *gd, partic_ll_t *groups)
{
    if (groups == NULL)
        return;
    update_partic_arr(gd, groups->partic_arr, groups->is_xp);
    update_groups(gd, groups->next);
}
