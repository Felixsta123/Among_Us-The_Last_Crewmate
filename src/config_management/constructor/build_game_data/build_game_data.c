/*
** EPITECH PROJECT, 2022
** build_game_data
** File description:
** Source cod to build game data
*/
#include "build_game_data.h"

int data_constructor(data_t *game_data)
{
    scene_t *game_scene = get_scene(game_data->scene_list, "game_scene");

    game_data->framerate = 60;
    game_data->keys = build_keys();
    game_data->scene_names = get_names_scene(game_data->scene_list);
    game_data->run_index = get_run_index(game_data->scene_names, "home_scene");
    game_data->red = player_constructor();
    if (game_scene == NULL)
        return (-1);
    game_data->scene_list[1]->partic = malloc(sizeof(partic_ll_t));
    game_data->scene_list[1]->partic->next = NULL;
    game_data->enemies = malloc(sizeof(enemies_t));
    game_data->enemies->next = NULL;
    game_data->frame_count = 0;
    game_data->quest_state = 0;
    return (0);
}
