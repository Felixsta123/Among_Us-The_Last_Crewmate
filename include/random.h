/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** random.h
*/

#ifndef _RAND_H_
    #define _RAND_H_
    #include <stdlib.h>
    #include <time.h>

double get_rdm(void);
float rdm_float(float min, float max);
float rdm_exp(float dispersion);
int rdm_int(int min, int max);
#endif
