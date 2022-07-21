/*
** EPITECH PROJECT, 2022
** text_opt
** File description:
** Source code
*/
#include "build_scene_texts.h"

int build_text_name(text_t *text, char *value)
{
    text->name = my_strdup(value);
    return (0);
}

int build_text_posx(text_t *text, char *value)
{
    float coord_x = my_atof(value);

    text->position.x = coord_x;
    return (0);
}

int build_text_posy(text_t *text, char *value)
{
    float coord_y = my_atof(value);

    text->position.y = coord_y;
    sfText_setPosition(text->text, text->position);
    return (0);
}

int build_text_text(text_t *text, char *value)
{
    text->str = my_strdup(value);
    sfText_setString(text->text, text->str);
    return (0);
}

int build_text_font(text_t *text, char *value)
{
    sfFont *font = sfFont_createFromFile(value);

    if (font == NULL) {
        write_error("Error while loading font\n");
        return (-1);
    }
    text->font = font;
    sfText_setFont(text->text, font);
    return (0);
}
