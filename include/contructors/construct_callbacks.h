/*
** EPITECH PROJECT, 2022
** construct_callbacks
** File description:
** Header
*/

#ifndef CALL_H_
    #define CALL_H_
    #include "structures.h"

typedef struct but_call_s {
    char *name;
    int (*func)(data_t *game_data, char **scenes_name, int *index_run);
} but_call_t;

int nothing(data_t *game_data, char **scenes_name, int *index_run);
int play(data_t *game_data, char **scenes_name, int *index_run);
int quit(data_t *game_data, char **scenes_name, int *index_run);
int options(data_t *game_data, char **scenes_name, int *index_run);
int arrows(data_t *game_data, char **scenes_name, int *index_run);
int zqsd(data_t *game_data, char **scenes_name, int *index_run);
int thirty_fps(data_t *game_data, char **scenes_name, int *index_run);
int sixty_fps(data_t *game_data, char **scenes_name, int *index_run);
int hundred_and_twenty_fps(data_t *game_data,
char **scenes_name, int *index_run);
int volume_bar(data_t *game_data, char **scenes_name, int *index_run);

static const but_call_t BUT_CALL[11] = {
    {"no", nothing},
    {"play", play},
    {"quit", quit},
    {"options", options},
    {"arrows", arrows},
    {"zqsd", zqsd},
    {"30", thirty_fps},
    {"60", sixty_fps},
    {"120", hundred_and_twenty_fps},
    {"volume_bar", volume_bar},
    {NULL, NULL}
};

#endif /*CALL_H_*/
