/*
** EPITECH PROJECT, 2022
** manage_buttons
** File description:
** Source code to manage buttons
*/

#include "manage_buttons.h"

void exec_button_clicked(data_t *game_data, button_t *button)
{
    if (game_data->scene_list[game_data->run_index]->music != NULL)
        sfSound_stop(game_data->scene_list[game_data->run_index]->music);
    sfSound_play(button->clic_sound);
    (*button->callback)(game_data, game_data->scene_names,
    &(game_data->run_index));
    if (game_data->run_index == -1) {
        return;
    }
    if (game_data->scene_list[game_data->run_index]->music != NULL)
        sfSound_play(game_data->scene_list[game_data->run_index]->music);
}

void manage_clic_buttons(data_t *game_data, button_t *buttons,
sfVector2i mouse_loc)
{
    button_t *head_ref_but = buttons;

    while (head_ref_but != NULL) {
        if (button_collision(mouse_loc, head_ref_but) == 1) {
            exec_button_clicked(game_data, head_ref_but);
        }
        head_ref_but = head_ref_but->next;
    }
}

void manage_hover_buttons(button_t *buttons, sfVector2i mouse_loc)
{
    button_t *head_ref_but = buttons;

    while (head_ref_but != NULL) {
        if (button_collision(mouse_loc, head_ref_but) == 1)
            head_ref_but->is_hovered = 1;
        else
            head_ref_but->is_hovered = 0;
        head_ref_but = head_ref_but->next;
    }
}
