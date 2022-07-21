/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** type.c
*/

#include "particles.h"
#include "random.h"

particle_param_t setup_lava_param(void)
{
    particle_param_t param;
    param.pos = (sfVector2f) {960, 540};
    param.spawn_radius = (sfVector2f) {0, 0};
    param.rdm_vel = (sfVector2f) {2, 2};
    param.init_vel = (sfVector2f) {0, 0};
    param.color = (sfColor) {234 + 20 *
    get_rdm(), 98 + 20 * get_rdm(), 0, 100 + 100 * get_rdm()};
    param.max_duration = 10000;
    param.size = 0.5 + get_rdm() * 1.5;
    param.gravity = (sfVector2f) {0, 0};
    param.resistance = (sfVector2f) {0.001, 0.001};
    param.count = 2;
    param.is_xp = false;
    return param;
}

particle_param_t setup_blood_param(void)
{
    particle_param_t param;
    param.pos = (sfVector2f) {960, 540};
    param.spawn_radius = (sfVector2f) {0, 0};
    param.rdm_vel = (sfVector2f) {3, 3};
    param.init_vel = (sfVector2f) {0, 0};
    param.color = (sfColor) {220, 10, 10, 255};
    param.max_duration = 20;
    param.size = 1.3;
    param.gravity = (sfVector2f) {0, 0.3};
    param.resistance = (sfVector2f) {0, 0.01};
    param.count = 50;
    param.is_xp = false;
    return param;
}

particle_param_t setup_fire_param(void)
{
    particle_param_t param;
    param.pos = (sfVector2f) {960, 540};
    param.spawn_radius = (sfVector2f) {15, 15};
    param.rdm_vel = (sfVector2f) {0.1, 0.1};
    param.init_vel = (sfVector2f) {0, 0};
    param.color = (sfColor) {230, 50 + get_rdm() * 50, 10, 200};
    param.max_duration = 60;
    param.size = 1.5;
    param.gravity = (sfVector2f) {0, -0.1};
    param.resistance = (sfVector2f) {0, 0.1};
    param.count = 8;
    param.is_xp = false;
    return param;
}

particle_param_t setup_step_param(void)
{
    particle_param_t param;
    param.pos = (sfVector2f) {960, 540};
    param.spawn_radius = (sfVector2f) {15, 15};
    param.rdm_vel = (sfVector2f) {2, 2};
    param.init_vel = (sfVector2f) {0, 0};
    param.color = (sfColor) {80, 80, 80, 150};
    param.max_duration = 20;
    param.size = 1.5;
    param.gravity = (sfVector2f) {0, 0.1};
    param.resistance = (sfVector2f) {0, 0.1};
    param.count = 5;
    param.is_xp = false;
    return param;
}

particle_param_t setup_smoke_param(void)
{
    particle_param_t param;
    float brightness = rdm_float(50, 150);
    param.pos = (sfVector2f) {960, 540};
    param.spawn_radius = (sfVector2f) {30, 15};
    param.rdm_vel = (sfVector2f) {0.1, 0.1};
    param.init_vel = (sfVector2f) {0, 0};
    param.color = (sfColor) {brightness, brightness, brightness, 150};
    param.max_duration = 500;
    param.size = rdm_float(1, 3);
    param.gravity = (sfVector2f) {0, -0.02};
    param.resistance = (sfVector2f) {0.1, 0.1};
    param.count = 1;
    param.is_xp = false;
    return param;
}
