/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** get_image.c
*/

#include "structures.h"

int my_strcmp(char *str1, char *str2);

image_t *get_image(image_t *images, char *name)
{
    image_t *tmp_head_txt = images;

    while (tmp_head_txt != NULL) {
        if (my_strcmp(name, tmp_head_txt->name))
            break;
        tmp_head_txt = tmp_head_txt->next;
    }
    return (tmp_head_txt);
}
