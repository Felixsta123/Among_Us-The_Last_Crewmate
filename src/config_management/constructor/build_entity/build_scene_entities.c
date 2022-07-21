/*
** EPITECH PROJECT, 2022
** build_scene_entities
** File description:
** Source code to build a scene
*/
#include "build_scene_entities.h"

void init_default_entity(entity_t *entity)
{
    entity->name = NULL;
    entity->position = (sfVector2f) {100, 100};
    entity->width = 50;
    entity->height = 50;
    entity->scale = (sfVector2f) {1, 1};
    entity->rotation = 0;
    entity->sprite = NULL;
    entity->texture = NULL;
    entity->action_sound = NULL;
    entity->sound_buffer = NULL;
    entity->dialogue = NULL;
}

int build_entities_opt(entity_t *entity, char *opt, char *value)
{
    if (opt == NULL || value == NULL)
        return (0);
    for (int index = 0; ENT_OPT_TAB[index].name != NULL; index++) {
        if (my_strcmp(opt, ENT_OPT_TAB[index].name) == 1)
            (*ENT_OPT_TAB[index].func)(entity, value);
    }
    free(opt);
    free(value);
    return (1);
}

int build_entities(entity_t **head_ref, char **content, int *line)
{
    char *opt = NULL;
    char *value = NULL;
    entity_t *new_entity = malloc(sizeof(entity_t));

    init_default_entity(new_entity);
    for (int index = 0; content[*line][index] != '\0'; index++) {
        opt = get_obj_opt(content, line, &index);
        value = get_opt_value(content, line, &index);
        build_entities_opt(new_entity, opt, value);
    }
    if ((*head_ref) == NULL) {
        new_entity->next = NULL;
        *head_ref = new_entity;
    } else {
        new_entity->next = *head_ref;
        *head_ref = new_entity;
    }
    return (0);
}

int build_scene_entities(scene_t *scene, char **content, int *line)
{
    *line += 1;
    while (content[*line] != NULL && is_a_scene_opt(content, line) == NULL) {
        build_entities(&(scene->entities), content, line);
        if (is_a_scene_opt(content, line) == NULL)
            break;
        *line += 1;
    }
    return (0);
}
