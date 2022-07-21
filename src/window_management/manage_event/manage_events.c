/*
** EPITECH PROJECT, 2021
** manage_event
** File description:
** Source code to manage event
*/

#include "event_management.h"
#include "movement.h"
#include <stdlib.h>
#include <math.h>

float get_distance(sfVector2f p1, sfVector2f p2);

void push_enemies(data_t *gd);

void is_interact_pnj(data_t *game_data)
{
    entity_t *tmp_ent = game_data->scene_list[game_data->run_index]->entities;
    float distance = 0;

    while (tmp_ent != NULL) {
        distance = get_distance(tmp_ent->position, game_data->red->pos);
        interact_pnj(game_data, distance, tmp_ent);
        tmp_ent = tmp_ent->next;
    }
}

void kbd_input(data_t *gd, sfEvent event, sfVector2i mouse_loc)
{
    if (event.key.code == sfKeyY)
        add_enem(gd->enemies, (sfVector2f) {(float) mouse_loc.x / 1920 *
        VIEW_WIDTH + gd->red->pos.x - VIEW_WIDTH / 2, (float) mouse_loc.y /
        1080 * VIEW_HEIGHT + gd->red->pos.y - VIEW_HEIGHT / 2});
    if (event.key.code == sfKeyK)
        if (gd->enemies->next != NULL)
            destroy_next_enemies(gd->enemies);
    if (event.key.code == sfKeySpace) {
        sfSound_play(gd->red->effects->swing);
        push_enemies(gd);
    }
    if (event.key.code == sfKeyN) {
        gd->quest_state += 1;
        if (gd->quest_state > 2)
            gd->quest_state = 0;
    }
}

static void init_hud(sfRenderWindow *window, data_t *game_data)
{
    sfFloatRect view_rect = {0, 0, WINDOW_WIDTH, WINDOW_HEIGHT};

    sfView_reset(game_data->red->view, view_rect);
    sfRenderWindow_setView(window, game_data->red->view);
}

static void events_conditions(sfEvent event, data_t *game_data,
scene_t *scene, sfVector2i mouse_loc)
{
        manage_hover_buttons(scene->buttons, mouse_loc);
        if (event.type == sfEvtMouseButtonReleased) {
            manage_clic_buttons(game_data, scene->buttons, mouse_loc);
        }
        if (event.type == sfEvtMouseButtonPressed) {
            push_enemies(game_data);
            game_data->red->attack_state = 0;
        }
        if (event.type == sfEvtKeyPressed) {
            kbd_input(game_data, event, mouse_loc);
        }
}

void event_handling(sfRenderWindow *window, data_t *game_data, scene_t *scene)
{
    sfEvent event;
    sfVector2i mouse_loc = sfMouse_getPositionRenderWindow(window);

    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed) {
            sfRenderWindow_close(game_data->window);
        }
        if (event.key.code == sfKeyEscape &&
                    my_strcmp(scene->name, "game_scene") == 1) {
            options(game_data, game_data->scene_names, &game_data->run_index);
            init_hud(game_data->window, game_data);
        }
        if (my_strcmp(scene->name, "game_scene") == 1
                                && event.key.code == sfKeyE)
            is_interact_pnj(game_data);
        events_conditions(event, game_data, scene, mouse_loc);
    }
}
