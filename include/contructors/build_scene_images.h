/*
** EPITECH PROJECT, 2022
** build_scene_images
** File description:
** Header
*/

#ifndef BUILD_SCENE_IMAGES_H_
    #define BUILD_SCENE_IMAGES_H_
    #include "stddef.h"
    #include "structures.h"
    #include <stdlib.h>

typedef struct img_opt_s {
    char *name;
    int (*func)(image_t *image, char *value);
} img_opt_t;

int build_img_name(image_t *image, char *value);
int build_img_posx(image_t *image, char *value);
int build_img_posy(image_t *image, char *value);
int build_img_width(image_t *image, char *value);
int build_img_height(image_t *image, char *value);
int build_img_scale(image_t *image, char *value);
int build_img_rotation(image_t *image, char *value);
int build_img_texture(image_t *image, char *value);

__attribute__((unused)) static img_opt_t IMG_OPT_TAB[] = {
    {"name", build_img_name},
    {"posx", build_img_posx},
    {"posy", build_img_posy},
    {"width", build_img_width},
    {"height", build_img_height},
    {"scale", build_img_scale},
    {"rotation", build_img_rotation},
    {"texture", build_img_texture},
    {NULL, NULL}
};

char *is_a_scene_opt(char **content, int *line);
char *get_obj_opt(char **content, int *line, int *index);
char *get_opt_value(char **content, int *line, int *index);
int my_strcmp(char *str1, char *str2);
char *my_strdup(char const *src);
int write_error(char const *str);
float my_atof(char *str);
int my_getnbr(char *str);
#endif /* !BUILD_SCENE_IMAGES_H_ */
