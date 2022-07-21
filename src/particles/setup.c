/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** setup->c
*/

#include "random.h"
#include <math.h>
#include "particles.h"
#include <stdio.h>

particle_param_t setup_default_param(void)
{
    particle_param_t param;
    param.pos = (sfVector2f) {960, 540};
    param.spawn_radius = (sfVector2f) {0, 0};
    param.rdm_vel = (sfVector2f) {10, 10};
    param.init_vel = (sfVector2f) {0, 0};
    param.color = (sfColor) {255, 255, 255, 255};
    param.max_duration = 50;
    param.size = 1;
    param.gravity = (sfVector2f) {0, 0.5};
    param.resistance = (sfVector2f) {0.01, 0.01};
    param.count = 1000;
    return param;
}

sfCircleShape *setup_circle(particle_param_t *p, particle_t particle)
{
    sfCircleShape *circle = sfCircleShape_create();
    sfCircleShape_setFillColor(circle, p->color);
    sfCircleShape_setRadius(circle, p->size);
    sfCircleShape_setOrigin(circle, (sfVector2f) {p->size, p->size});
    sfCircleShape_setPosition(circle, particle.pos);
    return circle;
}

particle_t setup_particle(particle_param_t *p)
{
    particle_t particle;
    float angle_pos = get_rdm() * M_PI * 2;
    float dist_pos = get_rdm();
    float angle_vel = get_rdm() * M_PI * 2;
    float dist_vel = rdm_exp(0.2) + 0.1;
    particle.pos = (sfVector2f) {dist_pos * cos(angle_pos) *
    p->spawn_radius.x + p->pos.x, dist_pos *
    sin(angle_pos) * p->spawn_radius.y + p->pos.y};
    particle.vel = (sfVector2f) {p->init_vel.x + dist_vel * cos(angle_vel) *
    p->rdm_vel.x, p->init_vel.y + dist_vel * sin(angle_vel) * p->rdm_vel.y};
    particle.duration = p->max_duration * get_rdm();
    particle.circle = setup_circle(p, particle);
    particle.res = (sfVector2f) {p->resistance.x * get_rdm(), p->resistance.y
    * get_rdm()};
    particle.grav = (sfVector2f) {p->gravity.x * get_rdm(), p->gravity.y
    * get_rdm()};
    return particle;
}

partic_arr_t *setup_partic_arr(particle_param_t *param)
{
    partic_arr_t *particles = malloc(sizeof(partic_arr_t));
    int i;

    particles->particles = malloc(param->count * sizeof(particle_t));
    particles->count = param->count;
    particles->duration = param->max_duration;
    for (i = 0; i < param->count; i++)
        particles->particles[i] = setup_particle(param);
    return particles;
}

partic_ll_t *setup_partic_node(particle_param_t *p)
{
    partic_ll_t *node = malloc(sizeof(partic_ll_t));
    node->partic_arr = setup_partic_arr(p);
    node->next = NULL;
    node->is_xp = p->is_xp;
    return node;
}
