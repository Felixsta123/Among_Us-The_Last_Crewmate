/*
** EPITECH PROJECT, 2022
** construct_scene
** File description:
** Source code to parse a config file
*/
#include "build_scene.h"

int parse_line(scene_t *scene, char **content, int *line)
{
    char *id = NULL;
    int return_value = 0;

    id = is_a_scene_opt(content, line);
    if (id != NULL)
        if (find_scene_opt(scene, id, content, line) == -1)
            return_value = -1;
    free(id);
    return (return_value);
}

void init_default_scene(scene_t *new_scene)
{
    new_scene->name = my_strdup("insert_name");
    new_scene->buttons = NULL;
    new_scene->entities = NULL;
    new_scene->images = NULL;
    new_scene->texts = NULL;
    new_scene->music = NULL;
    new_scene->music_buffer = NULL;
    new_scene->map = NULL;
    new_scene->background_sprite = NULL;
    new_scene->background_texture = NULL;
    new_scene->partic = malloc(sizeof(partic_ll_t));
    new_scene->partic->partic_arr = NULL;
    new_scene->partic->next = NULL;
}

scene_t *build_scene(char **content)
{
    scene_t *new_scene = malloc(sizeof(scene_t));

    init_default_scene(new_scene);
    if (content == NULL)
        return (new_scene);
    for (int lines = 0; content[lines] != NULL; lines++) {
        if (parse_line(new_scene, content, &lines) == -1) {
            my_printf("Unable to load %s\n", content[lines]);
        }
    }
    free_str_tab(content);
    return (new_scene);
}
