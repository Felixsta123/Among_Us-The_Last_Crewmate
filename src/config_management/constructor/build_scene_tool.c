/*
** EPITECH PROJECT, 2022
** construct_tools
** File description:
** Source code of the tools for construct element
*/
#include "stddef.h"
#include <stdlib.h>

char *parse_opt(char **content, int *line, int *index)
{
    char *opt = NULL;
    int tmp_index = *index + 1;

    while (content[*line][tmp_index] != '\'' &&
    content[*line][tmp_index] != '\0')
        tmp_index++;
    if (content[*line][tmp_index] != '\'')
        return (NULL);
    opt = malloc(sizeof(char) * (tmp_index - *index + 1));
    tmp_index = 0;
    while (content[*line][*index + 1] != '\'') {
        opt[tmp_index] = content[*line][*index + 1];
        tmp_index++;
        *index += 1;
    }
    opt[tmp_index] = '\0';
    return (opt);
}

char *parse_opt_value(char **content, int *line, int *index)
{
    char *opt = NULL;
    int tmp_index = *index + 1;

    while (content[*line][tmp_index] != '\"' &&
    content[*line][tmp_index] != '\0')
        tmp_index++;
    if (content[*line][tmp_index] != '\"')
        return (NULL);
    opt = malloc(sizeof(char) * (tmp_index - *index + 1));
    tmp_index = 0;
    while (content[*line][*index + 1] != '\"') {
        opt[tmp_index] = content[*line][*index + 1];
        tmp_index++;
        *index += 1;
    }
    opt[tmp_index] = '\0';
    return (opt);
}

char *get_obj_opt(char **content, int *line, int *index)
{
    char *opt = NULL;

    for (*index = *index; content[*line][*index] != '>' &&
    content[*line] != NULL; *index += 1) {
        if (content[*line][*index] == '\0' && content[*line + 1] != NULL) {
            *index = 0;
            *line += 1;
        }
        if (content[*line][*index] == '\'') {
            opt = parse_opt(content, line, index);
            *index += 1;
            break;
        }
    }
    return (opt);
}

char *get_opt_value(char **content, int *line, int *index)
{
    char *opt = NULL;

    for (*index = *index; content[*line][*index] != '>' &&
    content[*line] != NULL; *index += 1) {
        if (content[*line][*index] == '\0' && content[*line + 1] != NULL) {
            *index = 0;
            *line += 1;
        }
        if (content[*line][*index] == '\"') {
            opt = parse_opt_value(content, line, index);
            *index += 1;
            break;
        }
    }
    return (opt);
}
