/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** manage_particules.c
*/

#include "particles.h"
#include <stdlib.h>
#include <stdbool.h>
#include "movement.h"

void add_partic_group(partic_ll_t *groups, partic_ll_t *node)
{
    if (groups->next == NULL) {
        groups->next = node;
        return;
    }
    add_partic_group(groups->next, node);
}

void sup_partic_groups(partic_ll_t *groups) {
    partic_ll_t *temp;
    if (groups == NULL || groups->next == NULL) {
        return;
    }
    if (groups->next->partic_arr->duration <= 0) {
        destroy_partic_arr(groups->next->partic_arr);
        temp = groups->next;
        groups->next = groups->next->next;
        free(temp->partic_arr);
        free(temp);
        sup_partic_groups(groups);
        return;
    }
    sup_partic_groups(groups->next);
}

bool is_in_screen(data_t *gd, sfVector2f pos)
{
    sfVector2f player_pos = gd->red->pos;
    float left_limit = player_pos.x - VIEW_WIDTH / 2;
    float right_limit = player_pos.x + VIEW_WIDTH / 2;
    float up_limit = player_pos.y - VIEW_HEIGHT / 2;
    float down_limit = player_pos.y + VIEW_HEIGHT / 2;

    if (pos.x > left_limit && pos.x < right_limit &&
    pos.y > up_limit && pos.y < down_limit) {
        return true;
    }
    return false;
}
