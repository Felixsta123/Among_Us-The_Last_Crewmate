/*
** EPITECH PROJECT, 2022
** display_objects
** File description:
** Source code to display object
*/

#include "structures.h"
#include <stdlib.h>

void display_hitbox(sfRenderWindow *window, hitbox_t *hitbox)
{
    sfRenderWindow_drawRectangleShape(window, hitbox->rectangle, sfFalse);
    for (int index = 0; hitbox->circle[index] != NULL; index++) {
        sfRenderWindow_drawCircleShape(window, hitbox->circle[index], sfFalse);
    }
}

void draw_buttons(sfRenderWindow *window, data_t *game_data, scene_t *scene)
{
    button_t *head_ref_but = scene->buttons;

    while (head_ref_but != NULL) {
        if (head_ref_but->is_hovered == 0) {
            sfRenderWindow_drawSprite(window,
                head_ref_but->sprite, NULL);
        } else if (head_ref_but->is_hovered == 1) {
            sfRenderWindow_drawSprite(window,
                head_ref_but->ho_sprite, NULL);
        }
        if (game_data->debug_mode == 1)
            display_hitbox(window, head_ref_but->hitbox);
        head_ref_but = head_ref_but->next;
    }
}

void draw_images(sfRenderWindow *window, scene_t *scene)
{
    image_t *head_ref_img = scene->images;

    while (head_ref_img != NULL) {
        sfRenderWindow_drawSprite(window, head_ref_img->sprite, NULL);
        head_ref_img = head_ref_img->next;
    }
}

void draw_texts(sfRenderWindow *window, scene_t *scene)
{
    text_t *head_ref_txt = scene->texts;

    while (head_ref_txt != NULL) {
        sfRenderWindow_drawText(window, head_ref_txt->text, NULL);
        head_ref_txt = head_ref_txt->next;
    }
}

void draw_entities(sfRenderWindow *window,  data_t *game_data, scene_t *scene)
{
    entity_t *head_ref_ent = scene->entities;
    sfVector2f position = (sfVector2f)
    {game_data->red->pos.x - 280, game_data->red->pos.y + 100};

    while (head_ref_ent != NULL) {
        if (head_ref_ent->is_interact == 1) {
            sfText_setPosition(head_ref_ent->dialogue, position);
            sfSprite_setPosition(head_ref_ent->back_sprite, position);
            sfRenderWindow_drawSprite(window, head_ref_ent->back_sprite, NULL);
            sfRenderWindow_drawText(window, head_ref_ent->dialogue, NULL);
        }
        sfRenderWindow_drawSprite(window, head_ref_ent->sprite, NULL);
        head_ref_ent = head_ref_ent->next;
    }
}
