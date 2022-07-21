/*
** EPITECH PROJECT, 2022
** button_opt
** File description:
** SOurce code to build option of a button
*/
#include "build_scene_buttons.h"

int build_butt_name(button_t *button, char *value)
{
    button->name = my_strdup(value);
    return (0);
}

int build_butt_posx(button_t *button, char *value)
{
    int coord_x = my_getnbr(value);

    button->position.x = coord_x;
    return (0);
}

int build_butt_posy(button_t *button, char *value)
{
    int posy = my_getnbr(value);

    button->position.y = posy;
    return (0);
}

int build_butt_width(button_t *button, char *value)
{
    int width = my_getnbr(value);

    button->width = width;
    return (0);
}

int build_butt_height(button_t *button, char *value)
{
    int height = my_getnbr(value);

    button->height = height;
    return (0);
}
