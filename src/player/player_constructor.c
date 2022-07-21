/*
** EPITECH PROJECT, 2021
** MyRPG
** File description:
** player_constructor.c
*/
#include "player.h"
#include <stdlib.h>

static stats_t *setup_stats(void)
{
    stats_t *stats = malloc(sizeof(stats_t));
    stats->att = PLAYER_DAMAGES;
    stats->heal = PLAYER_HEAL_PER_MINUTES;
    stats->spd = PLAYER_SPEED;
    stats->xp = 0;
    return stats;
}

static void set_player_values(player_t *player)
{
    player->pos.x = 13 * 32;
    player->pos.y = 11 * 32;
    player->attack_state = 0;
    player->stats = setup_stats();
    player->facing = 0;
    player->kb_dir = 0;
    player->kb_speed = 0;
    player->percentage = 0;
    player->view = sfView_create();
    player->is_in_house = false;
    player->kill_streak = 0;
}

static void get_sound(sfSound **sound, sfSoundBuffer **buffer, char *path)
{
    *sound = sfSound_create();
    *buffer = sfSoundBuffer_createFromFile(path);
    sfSound_setBuffer(*sound, *buffer);
}

static sounds_t *get_sounds(void)
{
    sounds_t *effects = malloc(sizeof(sounds_t));

    get_sound(&effects->kill, &effects->kill_buffer, "assets/snd/kill.ogg");
    get_sound(&effects->swing,
    &effects->swing_buffer, "assets/snd/swing.ogg");
    get_sound(&effects->slash,
    &effects->slash_buffer, "assets/snd/slash.ogg");
    get_sound(&effects->hit,
    &effects->hit_buffer, "assets/snd/player_hit.ogg");
    get_sound(&effects->fall, &effects->fall_buffer, "assets/snd/fall.ogg");
    get_sound(&effects->xp,
    &effects->xp_buffer, "assets/snd/minecraft-xp.ogg");
    get_sound(&effects->vent, &effects->vent_buffer, "assets/snd/vent.ogg");
    return effects;
}

player_t *player_constructor(void)
{
    player_t *player = malloc(sizeof(player_t));
    sfClock *clk = sfClock_create();
    sfClock *att_clk = sfClock_create();
    sfTime tm = sfClock_getElapsedTime(clk);
    sfTime att_tm = sfClock_getElapsedTime(att_clk);

    set_player_values(player);
    player->player_sprite =
    create_sprite("assets/img/player/player_ss.png", 2, 2);
    player->player_rect = set_rect(16);
    player->attack_sprite =
    create_sprite("assets/img/player/attack_ss.png", 2, 2);
    player->attack_rect = set_rect(32);
    player->attack_clock = att_clk;
    player->attack_time = att_tm;
    player->clock = clk;
    player->time = tm;
    player->stats = setup_stats();
    player->effects = get_sounds();
    return player;
}
