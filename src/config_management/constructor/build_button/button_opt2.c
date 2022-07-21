/*
** EPITECH PROJECT, 2022
** button_opt
** File description:
** SOurce code to build option of a button
*/
#include "build_scene_buttons.h"

int build_butt_scale(button_t *button, char *value)
{
    sfVector2f scale = (sfVector2f) {my_atof(value), my_atof(value)};

    button->scale = scale;
    return (0);
}

int build_butt_rotation(button_t *button, char *value)
{
    float rot = my_atof(value);

    button->rotation = rot;
    return (0);
}

int build_butt_texture(button_t *button, char *value)
{
    sfVector2f origin = (sfVector2f) {button->width * button->scale.x /
    (2 * button->scale.x), button->height * button->scale.y /
    (2 * button->scale.y)};

    button->sprite = sfSprite_create();
    button->texture = sfTexture_createFromFile(value, NULL);
    if (button->texture == NULL) {
        write_error("Enable to load texture:");
        write_error(value);
        write_error(".\n");
        return (-1);
    }
    sfSprite_setRotation(button->sprite, button->rotation);
    sfSprite_setScale(button->sprite, button->scale);
    sfSprite_setOrigin(button->sprite, origin);
    sfSprite_setPosition(button->sprite, button->position);
    sfSprite_setTexture(button->sprite, button->texture, sfFalse);
    return (0);
}

int build_butt_ho_texture(button_t *button, char *value)
{
    sfVector2f origin = (sfVector2f) {button->width * button->scale.x /
    (2 * button->scale.x), button->height * button->scale.y /
    (2 * button->scale.y)};

    button->ho_sprite = sfSprite_create();
    button->ho_texture = sfTexture_createFromFile(value, NULL);
    if (button->ho_texture == NULL) {
        write_error("Enable to load texture:");
        write_error(value);
        write_error(".\n");
        return (-1);
    }
    sfSprite_setRotation(button->ho_sprite, button->rotation);
    sfSprite_setScale(button->ho_sprite, button->scale);
    sfSprite_setOrigin(button->ho_sprite, origin);
    sfSprite_setPosition(button->ho_sprite, button->position);
    sfSprite_setTexture(button->ho_sprite, button->ho_texture, sfFalse);
    return (0);
}

int build_butt_sound(button_t *button, char *value)
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
    button->clic_sound = sound;
    button->sound_buffer = sound_buffer;
    return (0);
}
