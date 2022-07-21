/*
** EPITECH PROJECT, 2021
** MyRPG
** File description:
** button_callback4.c
*/

#include "build_callback.h"

static void set_volumes(data_t *game_data, sfVector2i mouse_pos)
{
    int volume = 1250 - mouse_pos.x;
    int ratio = 100 - (((float)volume / 420) * 100);
    for (int index = 0; game_data->scene_list[index] != NULL; index++) {
        if (game_data->scene_list[index]->music != NULL)
            sfSound_setVolume(game_data->scene_list[index]->music, ratio);
    }
}

int main_volume_bar(data_t *game_data, char **scenes_name, int *index_run)
{
    (void) scenes_name;
    (void) index_run;
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(game_data->window);
    scene_t *option_scene = get_scene(game_data->scene_list, "main_options");
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

int home(data_t *game_data, char **scenes_name, int *index_run)
{
    (void)game_data;
    for (int index = 0; scenes_name[index] != NULL; index++) {
        if (my_strcmp(scenes_name[index], "home_scene") == 1)
            *index_run = index;
    }
    return (0);
}

int defeat(data_t *game_data, char **scenes_name, int *index_run)
{
    (void)game_data;
    for (int index = 0; scenes_name[index] != NULL; index++) {
        if (my_strcmp(scenes_name[index], "defeat") == 1)
            *index_run = index;
    }
    return (0);
}

int victory(data_t *game_data, char **scenes_name, int *index_run)
{
    (void)game_data;
    for (int index = 0; scenes_name[index] != NULL; index++) {
        if (my_strcmp(scenes_name[index], "victory") == 1)
            *index_run = index;
    }
    return (0);
}
