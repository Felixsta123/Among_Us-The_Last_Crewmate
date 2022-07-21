/*
** EPITECH PROJECT, 2021
** MyRPG
** File description:
** free_obj.c
*/

#include "free_data.h"

void free_images(image_t *images)
{
    image_t *next_image = NULL;

    while (images != NULL) {
        next_image = images->next;
        free(images->name);
        free(images);
        images = next_image;
    }
}

void free_texts(text_t *texts)
{
    text_t *next_text = NULL;

    while (texts != NULL) {
        next_text = texts->next;
        free(texts->name);
        free(texts);
        texts = next_text;
    }
}

void free_buttons(button_t *buttons)
{
    button_t *next_button = NULL;

    while (buttons != NULL) {
        next_button = buttons->next;
        free(buttons->name);
        free(buttons);
        buttons = next_button;
    }
}

void free_entities(entity_t *entities)
{
    entity_t *next_entity = NULL;

    while (entities != NULL) {
        next_entity = entities->next;
        free(entities->name);
        free(entities);
        entities = next_entity;
    }
}

void free_scenes(scene_t **scene_list)
{
    if (scene_list == NULL)
        return;
    for (int index = 0; scene_list[index] != NULL; index++) {
        free(scene_list[index]->name);
        free_buttons(scene_list[index]->buttons);
        free_entities(scene_list[index]->entities);
        free_texts(scene_list[index]->texts);
        free_images(scene_list[index]->images);
        free(scene_list[index]);
    }
    free(scene_list);
}
