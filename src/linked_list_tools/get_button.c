/*
** EPITECH PROJECT, 2022
** get_node
** File description:
** Source code to get a button
*/

#include "structures.h"

int my_strcmp(char *str1, char *str2);

button_t *get_button(button_t *buttons, char *name)
{
    button_t *tmp_head_but = buttons;

    while (tmp_head_but != NULL) {
        if (my_strcmp(name, tmp_head_but->name))
            break;
        tmp_head_but = tmp_head_but->next;
    }
    return (tmp_head_but);
}
