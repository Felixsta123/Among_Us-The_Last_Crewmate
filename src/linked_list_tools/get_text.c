/*
** EPITECH PROJECT, 2022
** get_node
** File description:
** Source code to get a button
*/

#include "structures.h"

int my_strcmp(char *str1, char *str2);

text_t *get_text(text_t *texts, char *name)
{
    text_t *tmp_head_txt = texts;

    while (tmp_head_txt != NULL) {
        if (my_strcmp(name, tmp_head_txt->name))
            break;
        tmp_head_txt = tmp_head_txt->next;
    }
    return (tmp_head_txt);
}
