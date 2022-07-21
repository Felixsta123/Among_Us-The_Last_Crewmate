/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** Source code to open a window in csfml
*/

#include "open_window.h"

void create_window(sfRenderWindow **window, int width, int height)
{
    sfVideoMode mode = {width, height, 32};

    *window = sfRenderWindow_create(mode, "MyRpg", sfDefaultStyle, NULL);
    sfRenderWindow_setFramerateLimit(*window, 60);
}

void scene_selector(sfRenderWindow *window, data_t *game_data)
{
    event_handling(window, game_data,
                        game_data->scene_list[game_data->run_index]);
    if (game_data->run_index == -1)
        return;
    display_scene(window, game_data,
    game_data->scene_list[game_data->run_index]);
    is_blocking_tile(game_data->scene_list[game_data->run_index]->map,
                            game_data->red->pos);
}

void open_window(int width, int height, data_t *game_data)
{
    sfRenderWindow *window;

    create_window(&window, width, height);
    game_data->window = window;
    sfSound_play(game_data->scene_list[game_data->run_index]->music);
    while (sfRenderWindow_isOpen(game_data->window)) {
        sfRenderWindow_clear(game_data->window, sfBlack);
        scene_selector(game_data->window, game_data);
        if (game_data->run_index == -1) {
            sfRenderWindow_close(game_data->window);
            break;
        }
        sfRenderWindow_display(game_data->window);
        game_data->frame_count += 1;
    }
    sfRenderWindow_destroy(game_data->window);
}
