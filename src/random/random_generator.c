/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** random_generator.c
*/

#include "random.h"
#include <math.h>

double get_rdm(void)
{
    return (double)rand() / (double)RAND_MAX;
}

int rdm_int(int min, int max)
{
    int num = (rand() % (max - min + 1)) + min;
    return (num);
}

float rdm_float(float min, float max)
{
    float range = max - min;
    float num = get_rdm();
    num *= range;
    num += min;
    return num;
}

float rdm_exp(float dispersion)
{
    return pow((-1 / ((get_rdm() * 0.999) - 1)), dispersion) - 1;
}
