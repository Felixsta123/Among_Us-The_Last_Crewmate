/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** type_more.c
*/

#include "particles.h"
#include "random.h"

particle_param_t setup_spark_param(void)
{
    particle_param_t param;
    float brightness = rdm_float(0, 255);
    param.pos = (sfVector2f) {960, 540};
    param.spawn_radius = (sfVector2f) {0, 0};
    param.rdm_vel = (sfVector2f) {1, 1};
    param.init_vel = (sfVector2f) {0, -1};
    param.color = (sfColor) {brightness, 255, 255, 255};
    param.max_duration = 50;
    param.size = 1;
    param.gravity = (sfVector2f) {0, 0.06};
    param.resistance = (sfVector2f) {0, 0.001};
    param.count = 1;
    param.is_xp = false;
    return param;
}

particle_param_t setup_xp_param(void)
{
    particle_param_t param;
    float brightness = get_rdm() * 50;
    param.spawn_radius = (sfVector2f) {5, 5};
    param.rdm_vel = (sfVector2f) {3, 3};
    param.init_vel = (sfVector2f) {0, 0};
    param.color = (sfColor) {brightness, 220 + get_rdm()
                                * 35, brightness, 255};
    param.max_duration = 1000;
    param.size = 1.5 + get_rdm();
    param.gravity = (sfVector2f) {0, 0};
    param.resistance = (sfVector2f) {0.1, 0.1};
    param.count = 1;
    param.is_xp = true;
    return param;
}
