/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** quest.c
*/

#include "structures.h"

int my_strcmp(char *str1, char *str2);

int victory(data_t *game_data, char **scenes_name, int *index_run);

void init_quest(data_t *gd)
{
    if (gd->quest_state == 0) {
        gd->quest_state = 1;
        gd->red->kill_streak = 0;
    }
}

void valid_quest(data_t *gd, scene_t *scene)
{
    image_t *image = get_image(scene->images, "open_vent");

    if (gd->quest_state == 1) {
        gd->quest_state = 2;
        image->position = (sfVector2f) {1216, 508};
        sfSprite_setPosition(image->sprite, image->position);
    }
}

void win_game(data_t *gd, map_t *map, sfVector2f pos)
{
    if (gd->quest_state == 2 &&
    map->tiles[(int) pos.y / 32][(int) pos.x / 32] == 70) {
        sfSound_play(gd->red->effects->vent);
        victory(gd, gd->scene_names, &gd->run_index);
    }
}
