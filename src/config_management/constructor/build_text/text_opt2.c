/*
** EPITECH PROJECT, 2022
** text_opt2
** File description:
** Source code
*/
#include "build_scene_texts.h"

int build_text_size(text_t *text, char *value)
{
    text->size = my_getnbr(value);
    sfText_setCharacterSize(text->text, text->size);
    return (0);
}

int build_text_rotation(text_t *text, char *value)
{
    text->rotation = my_atof(value);
    sfText_setRotation(text->text, text->rotation);
    return (0);
}

int build_text_style(text_t *text, char *value)
{
    int flag = 0;

    for (int index = 0; TEXT_STYLE[index].name != NULL; index++) {
        if (my_strcmp(TEXT_STYLE[index].name, value) == 1) {
            text->style = TEXT_STYLE[index].style;
            sfText_setStyle(text->text, text->style);
            flag = 1;
        }
    }
    if (flag == 0) {
        write_error("Invalid argument for text style \"");
        write_error(value);
        write_error("\".\n");
        return (-1);
    }
    return (0);
}

int build_text_color(text_t *text, char *value)
{
    char **rgb_a_value = my_split(value, ';');
    sfUint8 r = 0;
    sfUint8 g = 0;
    sfUint8 b = 0;
    sfUint8 a = 255;
    sfColor color = {255, 255, 255, 255};

    r = my_getnbr(rgb_a_value[0]);
    g = my_getnbr(rgb_a_value[1]);
    b = my_getnbr(rgb_a_value[2]);
    if (rgb_a_value[3])
        a = my_getnbr(rgb_a_value[3]);
    color = sfColor_fromRGBA(r, g, b, a);
    text->color = color;
    sfText_setColor(text->text, text->color);
    free_str_tab(rgb_a_value);
    return (0);
}

int build_text_outline_color(text_t *text, char *value)
{
    char **rgb_a_value = my_split(value, ';');
    sfUint8 r = 0;
    sfUint8 g = 0;
    sfUint8 b = 0;
    sfUint8 a = 255;
    sfColor color = {255, 255, 255, 255};

    r = my_getnbr(rgb_a_value[0]);
    g = my_getnbr(rgb_a_value[1]);
    b = my_getnbr(rgb_a_value[2]);
    if (rgb_a_value[3])
        a = my_getnbr(rgb_a_value[3]);
    color = sfColor_fromRGBA(r, g, b, a);
    text->color = color;
    sfText_setOutlineColor(text->text, text->color);
    free_str_tab(rgb_a_value);
    return (0);
}
