/*
** EPITECH PROJECT, 2021
** MyRPG
** File description:
** button_callback3.c
*/
#include "build_callback.h"

static void set_volumes(data_t *game_data, sfVector2i mouse_pos)
{
    int volume = 1640 - mouse_pos.x;
    int ratio = 100 - (((float)volume / 420) * 100);
    for (int index = 0; game_data->scene_list[index] != NULL; index++) {
        if (game_data->scene_list[index]->music != NULL)
            sfSound_setVolume(game_data->scene_list[index]->music, ratio);
    }
}

int volume_bar(data_t *game_data, char **scenes_name, int *index_run)
{
    (void) scenes_name;
    (void) index_run;
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(game_data->window);
    scene_t *option_scene = get_scene(game_data->scene_list, "option_menu");
    button_t *slider = get_button(option_scene->buttons, "slider");

    slider->position.x = mouse_pos.x;
    slider->hitbox->position.x = mouse_pos.x;
    sfSprite_setPosition(slider->ho_sprite, slider->position);
    sfSprite_setPosition(slider->sprite, slider->position);
    sfRectangleShape_setPosition(slider->hitbox->rectangle,
                                    slider->position);
    load_vertices(slider->hitbox);
    set_volumes(game_data, mouse_pos);
    return (0);
}

int update_att(data_t *game_data, char **scenes_name, int *index_run)
{
    (void) scenes_name;
    (void) index_run;

    if (game_data->red->stats->xp >= 5) {
        game_data->red->stats->att += 1;
        game_data->red->stats->xp -= 5;
    }
    return (0);
}

int update_heal(data_t *game_data, char **scenes_name, int *index_run)
{
    (void) scenes_name;
    (void) index_run;
    if (game_data->red->stats->xp >= 5) {
        game_data->red->stats->heal += 1;
        game_data->red->stats->xp -= 5;
    }
    return (0);
}

int update_spd(data_t *game_data, char **scenes_name, int *index_run)
{
    (void) scenes_name;
    (void) index_run;

    if (game_data->red->stats->xp >= 5) {
        game_data->red->stats->spd += 1;
        game_data->red->stats->xp -= 5;
    }
    return (0);
}
