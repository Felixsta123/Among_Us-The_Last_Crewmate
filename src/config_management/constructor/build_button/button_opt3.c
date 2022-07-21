/*
** EPITECH PROJECT, 2022
** button_opt
** File description:
** SOurce code to build option of a button
*/
#include "build_scene_buttons.h"
#include "build_callback.h"

int build_butt_callback(button_t *button, char *value)
{
    for (int index = 0; BUT_CALL[index].name != NULL; index++) {
        if (my_strcmp(BUT_CALL[index].name, value) == 1) {
            button->callback = BUT_CALL[index].func;
            return (0);
        }
    }
    write_error("Unable to find :\"");
    write_error(value);
    write_error("\".\n");
    return (-1);
}
