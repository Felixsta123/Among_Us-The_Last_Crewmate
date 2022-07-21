/*
** EPITECH PROJECT, 2022
** entity_opt2
** File description:
** SOurce code of entities's options
*/
#include "build_scene_entities.h"

int build_ent_scale(entity_t *entity, char *value)
{
    sfVector2f scale = (sfVector2f) {my_atof(value), my_atof(value)};

    entity->scale = scale;
    return (0);
}

int build_ent_rotation(entity_t *entity, char *value)
{
    float rot = my_atof(value);

    entity->rotation = rot;
    return (0);
}

int build_ent_texture(entity_t *entity, char *value)
{
    sfVector2f origin = (sfVector2f) {entity->width / (2 * entity->scale.x),
    entity->height / (2 * entity->scale.y)};

    entity->sprite = sfSprite_create();
    entity->texture = sfTexture_createFromFile(value, NULL);
    if (entity->texture == NULL) {
        write_error("Enable to load texture:");
        write_error(value);
        write_error(".\n");
        return (-1);
    }
    sfSprite_setRotation(entity->sprite, entity->rotation);
    sfSprite_setScale(entity->sprite, entity->scale);
    sfSprite_setOrigin(entity->sprite, origin);
    sfSprite_setPosition(entity->sprite, entity->position);
    sfSprite_setTexture(entity->sprite, entity->texture, sfFalse);
    return (0);
}

int build_ent_action_sound(entity_t *entity, char *value)
{
    sfSoundBuffer *sound_buffer = sfSoundBuffer_createFromFile(value);
    sfSound *sound = sfSound_create();

    if (sound_buffer == NULL) {
        write_error("Enable to load sound:\"");
        write_error(value);
        write_error("\".\n");
        return (-1);
    }
    sfSound_setBuffer(sound, sound_buffer);
    entity->action_sound = sound;
    entity->sound_buffer = sound_buffer;
    return (0);
}

int build_ent_dialogue(entity_t *entity, char *value)
{
    sfText *dialogue = sfText_create();
    sfFont *font = sfFont_createFromFile
        ("assets/font/DeterminationSansWebRegular-369X.ttf");

    entity->is_interact = 0;
    sfText_setPosition(dialogue, (sfVector2f) {0, 0});
    sfText_setString(dialogue, value);
    sfText_setFont(dialogue, font);
    sfText_setCharacterSize(dialogue, 8);
    sfText_setStyle(dialogue, sfTextRegular);
    sfText_setColor(dialogue, (sfColor) {200, 200, 255, 255});
    sfText_setOutlineColor(dialogue, (sfColor) {0, 0, 0, 255});
    sfText_setOutlineThickness(dialogue, 0.8);
    sfText_setLineSpacing(dialogue, 1);
    sfText_setLetterSpacing(dialogue, 0.8);
    entity->dialogue = dialogue;
    return (0);
}
