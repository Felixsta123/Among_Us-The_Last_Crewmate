/*
** EPITECH PROJECT, 2022
** build_scene_texts
** File description:
** Source code to build a scene
*/
#include "build_scene_texts.h"

void init_default_text(text_t *text)
{
    text->name = NULL;
    text->text = sfText_create();
    text->position = (sfVector2f) {150, 150};
    text->str = my_strdup("Insert text");
    text->font = sfFont_createFromFile("assets/font/DeterminationMono.ttf");
    text->size = 10;
    text->style = sfTextRegular;
    text->rotation = 0;
    text->color = (sfColor) {255, 255, 255, 255};
    text->outline_color = (sfColor) {0, 0, 0, 255};
    text->outline_thickness = 1.5;
    text->line_spacing = 1.5;
    text->letter_spacing = 1.5;
}

int build_texts_opt(text_t *text, char *opt, char *value)
{
    if (opt == NULL || value == NULL)
        return (0);
    for (int index = 0; TEXT_OPT_TAB[index].name != NULL; index++) {
        if (my_strcmp(opt, TEXT_OPT_TAB[index].name) == 1)
            (*TEXT_OPT_TAB[index].func)(text, value);
    }
    free(opt);
    free(value);
    return (1);
}

int build_texts(text_t **head_ref, char **content, int *line)
{
    char *opt = NULL;
    char *value = NULL;
    text_t *new_text = malloc(sizeof(text_t));

    init_default_text(new_text);
    for (int index = 0; content[*line][index] != '\0'; index++) {
        opt = get_obj_opt(content, line, &index);
        value = get_opt_value(content, line, &index);
        build_texts_opt(new_text, opt, value);
    }
    if ((*head_ref) == NULL) {
        new_text->next = NULL;
        *head_ref = new_text;
    } else {
        new_text->next = *head_ref;
        *head_ref = new_text;
    }
    return (0);
}

int build_scene_texts(scene_t *scene, char **content, int *line)
{
    *line += 1;
    while (content[*line] != NULL && is_a_scene_opt(content, line) == NULL) {
        build_texts(&(scene->texts), content, line);
        if (is_a_scene_opt(content, line) == NULL)
            break;
        *line += 1;
    }
    return (0);
}
