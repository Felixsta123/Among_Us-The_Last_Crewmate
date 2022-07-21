/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-3-mydefender-felix.stavonhagen
** File description:
** get_file_names.c
*/
#include "get_config_files.h"

int count_files(DIR *d, struct dirent *file)
{
    int file_count = 0;
    d = opendir("config_files/scene_config/");
    if (d == NULL)
        return (-1);
    while ((file = readdir(d)) != NULL) {
        if (file->d_name[0] != '.') {
            file_count += 1;
        }
    }
    closedir(d);
    return (file_count);
}

char **get_file_names(DIR *d, struct dirent *file, int nb_files)
{
    int index = 0;
    char **file_names = malloc((nb_files + 1) * sizeof(char *));
    d = opendir("config_files/scene_config/");
    if (d == NULL)
        return (NULL);
    for (int loop = 0; (file = readdir(d)) != NULL; loop++) {
        if (file->d_name[0] != '.') {
            file_names[index] = malloc((my_strlen(file->d_name) + 1) *
                                    sizeof(char));
            file_names[index] = my_strcpy( file_names[index], file->d_name);
            file_names[index][my_strlen(file->d_name)] = '\0';
            index += 1;
        }
    }
    file_names[index] = NULL;
    closedir(d);
    return (file_names);
}

scene_t **create_scene_list(int nb_config_files, char **file_name)
{
    char **content = NULL;
    char *path_name = NULL;
    int index = 0;
    scene_t **scene_list = malloc((nb_config_files + 1) * sizeof(scene_t));

    for (int files = 0; file_name[files] != NULL; files++) {
        path_name = my_strconc("config_files/scene_config/", file_name[files]);
        content = get_content_file(path_name);
        free(path_name);
        scene_list[index] = build_scene(content);
        index++;
    }
    scene_list[index] = NULL;
    return (scene_list);
}

scene_t **get_scene_list(void)
{
    DIR *d = NULL;
    struct dirent *file = NULL;
    scene_t **scene_list = NULL;
    char **file_name = NULL;
    int nb_config_files = count_files(d, file);

    if (nb_config_files == 0 || nb_config_files == -1) {
        my_putstr("No scene was found in config_file/scene_config/\n");
        return (scene_list);
    }
    file_name = get_file_names(d, file, nb_config_files);
    scene_list = create_scene_list(nb_config_files, file_name);
    free_str_tab(file_name);
    return (scene_list);
}
