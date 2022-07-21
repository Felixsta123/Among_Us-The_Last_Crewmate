/*
** EPITECH PROJECT, 2022
** scene_option.c
** File description:
** Source code of the scene option
*/
#include "scene_option.h"

char *malloc_id(char **content, int *line, int counter, int tmp_index)
{
    char *id = malloc(sizeof(char) * (counter + 1));
    int id_index = 0;

    while (content[*line][tmp_index] != ':') {
        id[id_index] = content[*line][tmp_index];
        tmp_index++;
        id_index++;
    }
    id[id_index] = '\0';
    return (id);
}

char *get_id(char **content, int *line, int index)
{
    int flag = 0;
    int counter = 0;
    char *id = NULL;
    int tmp_index = index + 1;

    while (content[*line][tmp_index] != '>' &&
    content[*line][tmp_index] != '\0') {
        if (content[*line][tmp_index] == ':')
            flag = 1;
        counter++;
        tmp_index++;
    }
    if (flag == 0)
        return (NULL);
    tmp_index = index + 1;
    id = malloc_id(content, line, counter, tmp_index);
    return (id);
}

char *is_a_scene_opt(char **content, int *line)
{
    char *id = NULL;

    for (int index = 0; content[*line][index] != '\0'; index++) {
        if (content[*line][index] == '<')
            id = get_id(content, line, index);
    }
    return (id);
}

int find_scene_opt(scene_t *scene, char *id, char **content, int *line)
{
    int func = 0;

    for (func = 0; TAB_SOPT[func].name != NULL; func++) {
        if (my_strcmp(id, TAB_SOPT[func].name) == 1)
            break;
    }
    if ((*TAB_SOPT[func].func)(scene, content, line) == -1)
            return (-1);
    return (0);
}
