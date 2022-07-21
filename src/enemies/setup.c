/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** setup.c
*/

#include "enemies.h"
#include <stdlib.h>
#include <structures.h>
#include "random.h"
#include "math.h"
#include <stdio.h>

static enem_t *setup_enem(sfVector2f pos)
{
    enem_t *enem = malloc(sizeof(enem_t));
    sfClock *clk = sfClock_create();
    sfTime tm = sfClock_getElapsedTime(clk);

    setup_values_enem(enem);
    enem->time = tm;
    enem->anim = clk;
    enem->pos = pos;
    sfSprite *sprite = sfSprite_create();
    sfTexture *texture = random_enemy_texture();
    enem->rect = set_enemy_rect();
    sfSprite_setTexture(sprite, texture, sfFalse);
    sfSprite_setScale(sprite, (sfVector2f) {1.25, 1.25});
    sfSprite_setOrigin(sprite, (sfVector2f) {16, 16});
    sfSprite_setTextureRect(sprite, *enem->rect);
    enem->sprite = sprite;
    enem->destination = pos;
    enem->last_attack = 0;
    return enem;
}

enemies_t *setup_enemies_node(sfVector2f pos)
{
    enemies_t *enemies = malloc(sizeof(enemies_t));

    enemies->enem = setup_enem(pos);
    enemies->next = NULL;
    return enemies;
}

static void add_enemies_node(enemies_t *enemies, enemies_t *node)
{
    if (enemies->next == NULL) {
        enemies->next = node;
        return;
    }
    add_enemies_node(enemies->next, node);
}

void add_enem(enemies_t *enemies, sfVector2f pos)
{
    enemies_t *node = setup_enemies_node(pos);

    add_enemies_node(enemies, node);
}

void spawn_enem(data_t *gd)
{
    float angle = rdm_float(0, 2 * M_PI);
    float dist = rdm_float(500, 1000);
    if (gd->quest_state == 0 && !gd->red->is_in_house) {
        if (enem_count(gd->enemies) < 15)
            add_enem(gd->enemies, (sfVector2f) {gd->red->pos.x + cos(angle) *
            dist, gd->red->pos.y + sin(angle) * dist});
        return;
    }
    if (!gd->red->is_in_house && enem_count(gd->enemies) < 50)
        add_enem(gd->enemies, (sfVector2f) {gd->red->pos.x + cos(angle) *
        dist, gd->red->pos.y + sin(angle) * dist});
}
