/*
** EPITECH PROJECT, 2022
** pnj_interaction
** File description:
** SOurce code of pnj_interaction
*/

#include "structures.h"

void interact_pnj(data_t *game_data, float distance, entity_t *tmp_ent)
{

    if (tmp_ent->is_interact == 0 && distance < 40) {
        sfSound_play(tmp_ent->action_sound);
        tmp_ent->is_interact = 1;
        init_quest(game_data);
    }
    if (distance > 50) {
        tmp_ent->is_interact = 0;
    }
}
