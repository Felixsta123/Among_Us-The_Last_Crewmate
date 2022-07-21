/*
** EPITECH PROJECT, 2021
** get_config_files.h
** File description:
** header
*/

#ifndef CONF_H_
    #define CONF_H_
    #include <dirent.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include "structures.h"

int my_strlen(char const *str);
int my_putstr(char *str);
char *my_strconc(char *str1, char *str2);
char **get_content_file(char *pathname);
scene_t *build_scene(char **content);
char *my_strcpy(char *dest, char const *src);
void free_str_tab(char **tab);
#endif /*CONF_H_*/
