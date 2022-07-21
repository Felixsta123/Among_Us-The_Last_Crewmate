/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-3-mydefender-felix.stavonhagen
** File description:
** map_parser.h
*/

#ifndef PARS_H_
    #define PARS_H_
    #include <stddef.h>
    #include <stdlib.h>
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <fcntl.h>
    #include "structures.h"

static const int TILE_SIZE = 32;
static const int SPRITE_SCALE = 3;

void constructor(scene_t *scene, char **content, int index);
int is_in_list(char **list, char *str);
char *get_keyword(char *str);
int nb_char_in_str(char *str, char c);
int write_error(char const *str);
char *get_content(int fd);
char **my_split(char *str, char splitter);
int error_handling(char **content);
void display_map(sfRenderWindow *window, map_t *map_data);
char **get_content_file(char *pathname);
int my_getnbr(char *str);
int count_char(char *str, char c);
int **tiles_parser(map_t *map_data);
sfIntRect fill_int_rect(int left, int top, int width, int height);
int get_nb_row(char **tab);
void free_str_tab(char **tab);

#endif
