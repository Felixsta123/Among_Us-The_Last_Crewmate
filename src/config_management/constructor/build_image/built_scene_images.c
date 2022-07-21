/*
** EPITECH PROJECT, 2022
** build_scene_images
** File description:
** Source code to build a scene
*/
#include "build_scene_images.h"

void init_default_image(image_t *image)
{
    image->name = NULL;
    image->position = (sfVector2f) {150, 150};
    image->width = 50;
    image->height = 50;
    image->scale = (sfVector2f) {1, 1};
    image->rotation = 0;
    image->sprite = NULL;
    image->texture = NULL;
}

int build_images_opt(image_t *image, char *opt, char *value)
{
    if (opt == NULL || value == NULL)
        return (0);
    for (int index = 0; IMG_OPT_TAB[index].name != NULL; index++) {
        if (my_strcmp(opt, IMG_OPT_TAB[index].name) == 1)
            (*IMG_OPT_TAB[index].func)(image, value);
    }
    free(opt);
    free(value);
    return (1);
}

int build_images(image_t **head_ref, char **content, int *line)
{
    char *opt = NULL;
    char *value = NULL;
    image_t *new_image = malloc(sizeof(image_t));

    init_default_image(new_image);
    for (int index = 0; content[*line][index] != '\0'; index++) {
        opt = get_obj_opt(content, line, &index);
        value = get_opt_value(content, line, &index);
        build_images_opt(new_image, opt, value);
    }
    if ((*head_ref) == NULL) {
        new_image->next = NULL;
        *head_ref = new_image;
    } else {
        new_image->next = *head_ref;
        *head_ref = new_image;
    }
    return (0);
}

int build_scene_images(scene_t *scene, char **content, int *line)
{
    *line += 1;
    while (content[*line] != NULL && is_a_scene_opt(content, line) == NULL) {
        build_images(&(scene->images), content, line);
        if (is_a_scene_opt(content, line) == NULL)
            break;
        *line += 1;
    }
    return (0);
}
