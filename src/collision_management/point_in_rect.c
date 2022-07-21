/*
** EPITECH PROJECT, 2022
** point_in_rec
** File description:
** Source code to know if a point is in a rectangle
*/

#include "point_in_rec.h"

int point_in_rec(sfVector2f point, sfVector2f **verts, int width, int height)
{
    double area1 = fabs((verts[1]->x * verts[0]->y -
        verts[0]->x * verts[1]->y) + (point.x * verts[1]->y -
        verts[1]->x * point.y) + (verts[0]->x * point.y -
        point.x * verts[0]->y)) / 2;
    double area2 = fabs((verts[2]->x * verts[1]->y -
        verts[1]->x * verts[2]->y) + (point.x * verts[2]->y -
        verts[2]->x * point.y) + (verts[1]->x * point.y -
        point.x * verts[1]->y)) / 2;
    double area3 = fabs((verts[3]->x * verts[2]->y - verts[2]->x
        * verts[3]->y) + (point.x * verts[3]->y - verts[3]->x *
        point.y) + (verts[2]->x * point.y - point.x * verts[2]->y)) / 2;
    double area4 = fabs((verts[3]->x * verts[0]->y - verts[0]->x
        * verts[3]->y) + (point.x * verts[3]->y - verts[3]->x * point.y)
        + (verts[0]->x * point.y - point.x * verts[0]->y)) / 2;
    int rec_area = width * height;
    int total_area = area1 + area2 + area3 + area4;
    if (total_area > rec_area)
        return (0);
    return (1);
}

int button_collision(sfVector2i mouse_loc, button_t *button)
{
    sfVector2f mouse_pos = (sfVector2f) {mouse_loc.x, mouse_loc.y};
    int flag = 0;

    if (point_in_rec(mouse_pos, button->hitbox->vertices,
        button->hitbox->width, button->hitbox->height) == 1) {
            flag = 1;
    }
    return (flag);
}
