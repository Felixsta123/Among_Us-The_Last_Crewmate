/*
** EPITECH PROJECT, 2021
** MyRPG
** File description:
** char_move.c
*/

#include "movement.h"
#include "particles.h"
#include "math.h"
#include <stdlib.h>

void spawn_enem(data_t *gd);

void handle_killstreak(data_t *gd, scene_t *scene);

void init_quest(data_t *gd);

void win_game(data_t *gd, map_t *map, sfVector2f pos);

sfVector2f get_move_vector(data_t *gd, sfVector2f dir)
{
    float delta = 60.0 / gd->framerate;
    float movex = gd->red->stats->spd * dir.x * delta / 3.0;
    float movey = gd->red->stats->spd * dir.y * delta / 3.0;
    return (sfVector2f) {movex, movey};
}

static int check_block(data_t *gd, sfVector2f dir)
{
    sfVector2f move_vector = get_move_vector(gd, dir);
    sfVector2f temp_pos = (sfVector2f) {gd->red->pos.x + move_vector.x,
    gd->red->pos.y + move_vector.y};
    if (is_blocking_tile(gd->scene_list[gd->run_index]->map, temp_pos) == 1)
        return 1;
    if (is_blocking_tile(gd->scene_list[gd->run_index]->map, temp_pos) == 2) {
        gd->red->pos.x = 2352;
        gd->red->pos.y = 656;
        gd->red->is_in_house = true;
        gd->red->kb_speed = 0;
        return 1;
    } else if (is_blocking_tile(gd->scene_list[gd->run_index]->map,
                temp_pos) == 3) {
        gd->red->pos.x = 1102;
        gd->red->pos.y = 734;
        gd->red->is_in_house = false;
        return 1;
    }
    win_game(gd, gd->scene_list[gd->run_index]->map, temp_pos);
    return 0;
}

void move_dir(data_t *gd, sfVector2f dir, int key, int sprite)
{
    sfVector2f move_vector = get_move_vector(gd, dir);
    if (!sfKeyboard_isKeyPressed(key))
        return;
    gd->red->facing = sprite;
    gd->red->player_rect->left = sprite * 16;
    gd->red->attack_rect->left = sprite * 32;
    if (check_block(gd, dir))
        return;
    if (sfKeyboard_isKeyPressed(sfKeyLShift)) {
        gd->red->pos.x += move_vector.x * 0.6;
        gd->red->pos.y += move_vector.y * 0.6;
    }
    gd->red->pos.x += move_vector.x;
    gd->red->pos.y += move_vector.y;
    player_walk(gd, 16, 64);
}

void player_knockback(data_t *gd, scene_t *scene)
{
    player_t *red = gd->red;
    float newx = red->pos.x + red->kb_speed * cos(red->kb_dir);
    float newy = red->pos.y + red->kb_speed * sin(red->kb_dir);
    int x = floor(newx);
    int y = floor(newy);

    red->pos = (sfVector2f) {newx, newy};
    if (!(is_blocking_tile(scene->map, gd->red->pos))) {
        red->kb_speed *= 0.9;
    }
    if (is_all_lava(scene, x, y)) {
        sfSound_play(gd->red->effects->fall);
        gd->red->pos.x = 13 * 32;
        gd->red->pos.y = 11 * 32;
        gd->red->percentage = 0;
        gd->red->kill_streak = 0;
        gd->red->stats->xp = 0;
        gd->red->kb_speed = 0;
        defeat(gd, gd->scene_names, &gd->run_index);
    }
}

void player_move(data_t *game_data, scene_t *scene)
{
    game_data->red->time = sfClock_getElapsedTime(game_data->red->clock);
    game_data->red->seconds = game_data->red->time.microseconds / 1000000.0;

    if (scene->map != NULL) {
        move_dir(game_data, (sfVector2f) {0, -1}, game_data->keys->up, 3);
        move_dir(game_data, (sfVector2f) {0, 1}, game_data->keys->down, 0);
        move_dir(game_data, (sfVector2f) {-1, 0}, game_data->keys->left, 1);
        move_dir(game_data, (sfVector2f) {1, 0}, game_data->keys->right, 2);
        set_position(game_data->red->player_sprite,
        game_data->red->pos.x, game_data->red->pos.y);
        player_knockback(game_data, scene);
    }
    handle_killstreak(game_data, scene);
}
