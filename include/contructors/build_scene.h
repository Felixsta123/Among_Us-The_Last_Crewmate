/*
** EPITECH PROJECT, 2022
** error_handling
** File description:
** Header
*/

#ifndef ERR_H_
    #define ERR_H_
    #include <stddef.h>
    #include <stdlib.h>
    #include "structures.h"

int write_error(char const *str);
int my_strcmp(char *str1, char *str2);
char *get_keyword(char *str);
void my_printf(char *str, ...);
int find_scene_opt(scene_t *scene, char *id, char **content, int *line);
char *is_a_scene_opt(char **content, int *line);
void free_str_tab(char **tab);
char *my_strdup(char const *src);
#endif /*ERR_H_*/
