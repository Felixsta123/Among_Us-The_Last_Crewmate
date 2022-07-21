/*
** EPITECH PROJECT, 2021
** MyRPG
** File description:
** free_struct.c
*/

#include "free_data.h"

static void free_sounds(data_t *game_data)
{
    sfSound_destroy(game_data->red->effects->fall);
    sfSoundBuffer_destroy(game_data->red->effects->fall_buffer);
    sfSound_destroy(game_data->red->effects->kill);
    sfSoundBuffer_destroy(game_data->red->effects->kill_buffer);
    sfSound_destroy(game_data->red->effects->swing);
    sfSoundBuffer_destroy(game_data->red->effects->swing_buffer);
    sfSound_destroy(game_data->red->effects->slash);
    sfSoundBuffer_destroy(game_data->red->effects->slash_buffer);
    sfSound_destroy(game_data->red->effects->hit);
    sfSoundBuffer_destroy(game_data->red->effects->hit_buffer);
    sfSound_destroy(game_data->red->effects->xp);
    sfSoundBuffer_destroy(game_data->red->effects->xp_buffer);
    sfSound_destroy(game_data->red->effects->vent);
    sfSoundBuffer_destroy(game_data->red->effects->vent_buffer);
}

static void free_player(data_t *game_data)
{
    free_sounds(game_data);
    sfClock_destroy(game_data->red->clock);
    sfView_destroy(game_data->red->view);
    sfSprite_destroy(game_data->red->player_sprite);
    sfSprite_destroy(game_data->red->attack_sprite);
    free(game_data->red->player_rect);
    free(game_data->red->attack_rect);
    sfClock_destroy(game_data->red->attack_clock);
    free(game_data->red->stats);
    free(game_data->red);
}

void free_data(data_t *game_data)
{
    if (game_data == NULL)
        return;
    free_scenes(game_data->scene_list);
    free_player(game_data);
    free(game_data);
}
