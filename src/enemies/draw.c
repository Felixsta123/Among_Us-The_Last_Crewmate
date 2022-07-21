/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** draw.c
*/

#include "enemies.h"
#include "particles.h"
#include "structures.h"
#include "random.h"

void valid_quest(data_t *gd, scene_t *scene);

void draw_enem(sfRenderWindow *win, enem_t *enem)
{
    sfRenderWindow_drawSprite(win, enem->sprite, NULL);
}

void draw_enemies(sfRenderWindow *win, enemies_t *enemies)
{
    if (enemies == NULL || enemies->next == NULL)
        return;
    draw_enem(win, enemies->next->enem);
    draw_enemies(win, enemies->next);
}

void spawn_xp_orbs(scene_t *scene, sfVector2f pos)
{
    partic_ll_t *node;
    particle_param_t param = setup_xp_param();

    if (get_rdm() > 0.2) {
        param.pos = pos;
        node = setup_partic_node(&param);
        add_partic_group(scene->partic, node);
    }
}

void spawn_enem_blood(data_t *gd, enemies_t *enem)
{
    partic_ll_t *node;
    particle_param_t param;
    scene_t *game_scene = get_scene(gd->scene_list, "game_scene");

    param = setup_blood_param();
    param.pos = (sfVector2f) enem->enem->pos;
    param.color = (sfColor) {150, 0, 150, 255};
    if (enem->enem->life <= 0) {
        param.count = 90;
        gd->red->kill_streak += 1;
        if (gd->quest_state == 1 && gd->red->kill_streak >= 20)
            valid_quest(gd, game_scene);
        for (int i = 0; i < 3; ++i)
            spawn_xp_orbs(game_scene, enem->enem->pos);
    } else {
        param.count = 10;
    }
    node = setup_partic_node(&param);
    add_partic_group(game_scene->partic, node);
}
