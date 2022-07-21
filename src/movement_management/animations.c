/*
** EPITECH PROJECT, 2021
** MyRPG
** File description:
** animations.c
*/

#include "movement.h"

void step_particles(data_t *game_data)
{
    partic_ll_t *node;
    particle_param_t param;
    scene_t *game_scene = get_scene(game_data->scene_list, "game_scene");

    param = setup_step_param();
    param.pos = (sfVector2f) {game_data->red->pos.x,
    game_data->red->pos.y + 14};
    node = setup_partic_node(&param);
    add_partic_group(game_scene->partic, node);
}

void knife(data_t *game_data)
{
    set_position(game_data->red->attack_sprite,
    game_data->red->pos.x + OFFSET[game_data->red->facing].x,
    game_data->red->pos.y + OFFSET[game_data->red->facing].y);
    if (game_data->red->attack_state != 5) {
        sfRenderWindow_drawSprite(game_data->window,
        game_data->red->attack_sprite, NULL);
    }
    game_data->red->attack_time =
    sfClock_getElapsedTime(game_data->red->attack_clock);
    game_data->red->attack_seconds =
    game_data->red->attack_time.microseconds / 1000000.0;
    if (game_data->red->attack_seconds > 0.10) {
        if (game_data->red->attack_state !=  5) {
            move_rect(game_data->red->attack_rect, 32, 160);
            sfClock_restart(game_data->red->attack_clock);
            game_data->red->attack_state++;
        }
    }
}

void move_rect(sfIntRect *rect, int offset, int max_value)
{
    rect->top += offset;
    if (rect->top >= max_value) {
        rect->top = 0;
    }
}

void player_walk(data_t *game_data, int offset, int max_value)
{
    if (game_data->red->seconds > 0.15) {
        move_rect(game_data->red->player_rect, offset, max_value);
        sfClock_restart(game_data->red->clock);
        step_particles(game_data);
    }
}
