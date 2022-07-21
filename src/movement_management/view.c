/*
** EPITECH PROJECT, 2021
** MyRPG
** File description:
** view.c
*/

#include "movement.h"

void init_view(sfRenderWindow *window, data_t *game_data)
{
    sfFloatRect view_rect = {0, 0, VIEW_WIDTH, VIEW_HEIGHT};
    sfVector2f center_player_cam = {0, 0};

    sfView_reset(game_data->red->view, view_rect);
    sfView_setCenter(game_data->red->view, game_data->red->pos);
    sfView_move(game_data->red->view, center_player_cam);
    sfRenderWindow_setView(window, game_data->red->view);
}
