/*
** EPITECH PROJECT, 2022
** sound_opt
** File description:
** Source code of sound option
*/
#include "build_scene_sounds.h"

int build_sound_path(scene_t *scene, char *value)
{
    scene->music_buffer = sfSoundBuffer_createFromFile(value);
    if (scene->music_buffer == NULL) {
        write_error("Sound path not found\n");
        return (-1);
    }
    sfSound_setBuffer(scene->music, scene->music_buffer);
    return (0);
}

int build_sound_volume(scene_t *scene, char *value)
{
    float volume = my_atof(value);

    sfSound_setVolume(scene->music, volume);
    return (0);
}

int build_sound_pitch(scene_t *scene, char *value)
{
    float pitch = my_atof(value);

    sfSound_setPitch(scene->music, pitch);
    return (0);
}

int build_sound_looping(scene_t *scene, char *value)
{
    if (my_strcmp(value, "no"))
        sfSound_setLoop(scene->music, sfFalse);
    if (my_strcmp(value, "yes"))
        sfSound_setLoop(scene->music, sfTrue);
    return (0);
}
