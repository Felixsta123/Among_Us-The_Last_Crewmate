/*
** EPITECH PROJECT, 2021
** manage_display
** File description:
** Source code to manage display
*/
#include "manage_display.h"
#include "particles.h"
#include "random.h"
#include "movement.h"

void init_view(sfRenderWindow *window, data_t *game_data);

void spawn_enem(data_t *gd);

void handle_xp_points(data_t *gd, scene_t *scene);

static void game_scene(sfRenderWindow *window,
data_t *game_data, scene_t *scene)
{
    player_move(game_data, game_data->scene_list[game_data->run_index]);
    spawn_enem(game_data);
    update_enemies(game_data, game_data->enemies);
    display_map(window, scene->map);
    init_view(window, game_data);
    sfSprite_setTextureRect(game_data->red->player_sprite,
    *game_data->red->player_rect);
    sfRenderWindow_drawSprite(window, game_data->red->player_sprite, NULL);
    sfSprite_setTextureRect(game_data->red->attack_sprite,
    *game_data->red->attack_rect);
    draw_enemies(window, game_data->enemies);
    knife(game_data);
}

void display_other_scene(data_t *game_data, scene_t *scene)
{
    if (my_strcmp(scene->name, "option_menu") == 1) {
        update_stats(game_data, scene);
        print_xp(game_data, scene);
    }
}

void display_scene(sfRenderWindow *window, data_t *game_data, scene_t *scene)
{
    sfFloatRect view_rect = {0, 0, WINDOW_WIDTH, WINDOW_HEIGHT};

    if (scene->background_sprite != NULL) {
        sfRenderWindow_drawSprite(window, scene->background_sprite, NULL);
        display_other_scene(game_data, scene);
    } else if (scene->map != NULL) {
        game_scene(window, game_data, scene);
        handle_percentage(game_data, scene);
        handle_xp_points(game_data, scene);
    } else {
        sfView_setCenter(game_data->red->view, (sfVector2f) {0, 0});
        sfView_move(game_data->red->view, (sfVector2f) {0, 0});
        sfView_reset(game_data->red->view, view_rect);
        sfRenderWindow_setView(window, game_data->red->view);
    }
    draw_images(window, scene);
    handle_particles(window, game_data, scene);
    draw_texts(window, scene);
    draw_entities(window, game_data, scene);
    draw_buttons(window, game_data, scene);
}
