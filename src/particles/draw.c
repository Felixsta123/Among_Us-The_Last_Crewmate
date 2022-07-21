/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** particles.c
*/

#include "particles.h"
#include "structures.h"
#include "random.h"
#include <stdbool.h>
#include "manage_display.h"

bool is_in_screen(data_t *gd, sfVector2f pos);

void draw_partic_arr(sfRenderWindow *win, partic_arr_t *partic)
{
    int i;
    for (i = 0; i < partic->count; ++i) {
        if (partic->particles[i].duration > 0)
            sfRenderWindow_drawCircleShape(win,
            partic->particles[i].circle, NULL);
    }
}

void draw_groups(sfRenderWindow *win, partic_ll_t *groups)
{
    if (groups == NULL)
        return;
    draw_partic_arr(win, groups->partic_arr);
    draw_groups(win, groups->next);
}

static void spawn_special_particles(data_t *game_data, scene_t *scene)
{
    particle_param_t param;
    partic_ll_t *node;

    param = setup_smoke_param();
    param.pos = (sfVector2f) {512, 304};
    if (is_in_screen(game_data, param.pos) && get_rdm() > 0.5) {
        node = setup_partic_node(&param);
        add_partic_group(scene->partic, node);
    }
    param = setup_spark_param();
    param.pos = (sfVector2f) {467, 294};
    if (is_in_screen(game_data, param.pos) && get_rdm() > 0.97) {
        node = setup_partic_node(&param);
        add_partic_group(scene->partic, node);
    }
}

void handle_particles(sfRenderWindow *win,
data_t *gd, scene_t *scene)
{
    particle_param_t lava = setup_lava_param();
    partic_ll_t *node_lava;

    if (scene->map != NULL) {
        update_groups(gd, scene->partic->next);
        sup_partic_groups(scene->partic->next);
        draw_groups(win, scene->partic->next);
        lava.pos = (sfVector2f) {get_rdm() * 1920, get_rdm() * 1080};
        if (is_in_screen(gd, lava.pos) && get_rdm() > 0.7) {
            node_lava = setup_partic_node(&lava);
            add_partic_group(scene->partic, node_lava);
        }
        spawn_special_particles(gd, scene);
    }
}

void spawn_blood(data_t *game_data)
{
    partic_ll_t *node;
    particle_param_t param;
    scene_t *game_scene = get_scene(game_data->scene_list, "game_scene");

    param = setup_blood_param();
    param.pos = (sfVector2f) {game_data->red->pos.x,
    game_data->red->pos.y};
    node = setup_partic_node(&param);
    add_partic_group(game_scene->partic, node);
}
