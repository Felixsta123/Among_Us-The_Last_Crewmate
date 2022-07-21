/*
** EPITECH PROJECT, 2022
** get_node
** File description:
** Source code to get a button
*/

#include "structures.h"

int my_strcmp(char *str1, char *str2);

entity_t *get_entity(entity_t *entities, char *name)
{
    entity_t *tmp_head_ent = entities;

    while (tmp_head_ent != NULL) {
        if (my_strcmp(name, tmp_head_ent->name))
            break;
        tmp_head_ent = tmp_head_ent->next;
    }
    return (tmp_head_ent);
}
