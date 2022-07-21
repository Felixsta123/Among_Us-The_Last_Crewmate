/*
** EPITECH PROJECT, 2022
** entity_opt3
** File description:
** SOurce code of entities's options
*/
#include "build_scene_entities.h"

static button_t *build_quest_button(entity_t *entity)
{
    button_t *button = malloc(sizeof(button_t));

    button->name = "quest_button";
    button->position = entity->position;
    button->width = 36;
    button->height = 36;
    button->scale = (sfVector2f) {1, 1};
    button->rotation = 0;
    button->is_hovered = 0;
    build_butt_texture(button, "assets/img/buttons/check_button_still.png");
    build_butt_ho_texture(button,
        "assets/img/buttons/check_button_hovered.png");
    build_butt_sound(button, "assets/snd/toggle.ogg");
    button->callback = NULL;
    return (button);
}

static button_t *build_quit_button(entity_t *entity)
{
    button_t *button = malloc(sizeof(button_t));

    button->name = "quest_button";
    button->position = entity->position;
    button->width = 36;
    button->height = 36;
    button->scale = (sfVector2f) {1, 1};
    button->rotation = 0;
    button->is_hovered = 0;
    build_butt_texture(button, "assets/img/buttons/cross_button_still.png");
    build_butt_ho_texture(button,
        "assets/img/buttons/cross_button_hovered.png");
    build_butt_sound(button, "assets/snd/toggle.ogg");
    button->callback = NULL;
    return (button);
}

int build_ent_back_texture(entity_t *entity, char *value)
{
    sfVector2f origin = (sfVector2f) {entity->width / (2 * entity->scale.x),
    entity->height / (2 * entity->scale.y)};

    entity->back_sprite = sfSprite_create();
    entity->back_texture = sfTexture_createFromFile(value, NULL);
    if (entity->back_texture == NULL) {
        write_error("Enable to load texture:");
        write_error(value);
        write_error(".\n");
        return (-1);
    }
    sfSprite_setRotation(entity->back_sprite, entity->rotation);
    sfSprite_setScale(entity->back_sprite, entity->scale);
    sfSprite_setOrigin(entity->back_sprite, origin);
    sfSprite_setPosition(entity->back_sprite, entity->position);
    sfSprite_setTexture(entity->back_sprite, entity->back_texture, sfFalse);
    return (0);
}

int build_ent_quest(entity_t *entity, char *value)
{
    (void) value;

    entity->quest = build_quest_button(entity);
    entity->quit = build_quit_button(entity);
    return (0);
}
