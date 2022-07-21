/*
** EPITECH PROJECT, 2022
** map_parser.c
** File description:
** Source code to load a map from a config file
*/
#include "map_parser.h"
#include "random.h"

int **malloc_int(int width, int height)
{
    int **map_int = malloc(height * sizeof(int *));
    int rows;

    for (rows = 0; rows < height; rows++)
        map_int[rows] = malloc(width * sizeof(int));
    return (map_int);
}

int **tiles_parser(map_t *map_data)
{
    int line;
    int number;
    char **map = get_content_file("config_files/map_config/map.config");
    map_data->size_x = count_char(map[0], ',') + 1;
    map_data->size_y = get_nb_row(map);
    int **tiles = malloc_int(map_data->size_x, map_data->size_y);
    char **temp;

    for (line = 0; map[line] != NULL; line++) {
        temp = my_split(map[line], ',');
        for (number = 0; temp[number] != NULL; number++) {
            tiles[line][number] = (my_getnbr(temp[number]) - 10);
        }
        free(temp);
    }
    free_str_tab(map);
    return (tiles);
}

sfIntRect fill_int_rect(int left, int top, int width, int height)
{
    sfIntRect rect;
    rect.left = left;
    rect.top = top;
    rect.width = width;
    rect.height = height;
    return (rect);
}

map_t *map_constructor(void)
{
    map_t *map_data = malloc(sizeof(map_t));
    sfTexture *tile_texture = sfTexture_createFromFile(
                                "assets/img/map/map_ss.png", NULL);
    sfSprite *tile_sprite = sfSprite_create();

    sfSprite_setTexture(tile_sprite, tile_texture, sfFalse);
    map_data->tiles_sprite = tile_sprite;
    map_data->tiles = tiles_parser(map_data);
    return (map_data);
}

void display_map(sfRenderWindow *window, map_t *map_data)
{
    sfIntRect limit = fill_int_rect(0, 0, TILE_SIZE, TILE_SIZE);
    sfVector2f pos = {0, 0};

    for (int i = 0; i < 43; i++) {
        for (int j = 0; j < 87; j++) {
            if (map_data->tiles[i][j] == 4)
                map_data->tiles[i][j] = rdm_int(4, 7);
            if (map_data->tiles[i][j] == 0)
                map_data->tiles[i][j] = rdm_int(0, 3);
            limit.left = map_data->tiles[i][j] * TILE_SIZE;
            pos.x = (j * TILE_SIZE);
            pos.y = (i * TILE_SIZE);
            sfSprite_setPosition(map_data->tiles_sprite, pos);
            sfSprite_setTextureRect(map_data->tiles_sprite, limit);
            sfRenderWindow_drawSprite(window, map_data->tiles_sprite, NULL);
        }
    }
}
