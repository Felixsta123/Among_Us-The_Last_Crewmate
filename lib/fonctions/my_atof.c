/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** my_atof.c
*/

#include <stdlib.h>

int count_char(char *str, char c);

int my_getnbr(char *str);

void destroy_strlist(char **strlist)
{
    int i;
    for (i = 0; strlist[i] != NULL; i++)
        free(strlist[i]);
    free(strlist);
}

float belowzero(float nbr)
{
    if (nbr < 1)
        return nbr;
    return belowzero(nbr / 10);
}

int indexnextchar(char *str, char c, int start)
{
    int i;
    for (i = start; str[i] != c && str[i] != '\0'; ++i);
    ++i;
    return i;
}

char **splitstr(char *str, char c)
{
    int i;
    int j;
    int previ;
    int nexti;
    int cnum = count_char(str, c);
    char **strlist = malloc((cnum + 2) * sizeof(char *));

    previ = 0;
    for (i = 0; i < cnum + 1; i++) {
        nexti = indexnextchar(str, c, previ);
        strlist[i] = malloc(nexti - previ + 1);
        for (j = 0; j < nexti - previ; j++)
            strlist[i][j] = str[j + previ];
        strlist[i][j - 1] = 0;
        previ = nexti;
    }
    strlist[i] = NULL;
    return strlist;
}

float my_atof(char *str)
{
    char **splited = splitstr(str, '.');
    float result = my_getnbr(splited[0]);

    if (splited[1] != NULL)
        result += belowzero(my_getnbr(splited[1]));
    destroy_strlist(splited);
    return result;
}
